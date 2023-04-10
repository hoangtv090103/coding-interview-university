#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    void *data;
    size_t size; // size_t = size of the type
    size_t capacity;
    size_t elem_size;
} vector;

void init_vector(vector *v, size_t elem_size)
{
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->elem_size = elem_size;
}

void resize(vector *v, size_t new_size)
{
    v->data = realloc(v->data, new_size * v->elem_size);
    v->capacity = new_size;
}

void push_back(vector *v, const void *value)
{
    if (v->size == v->capacity)
    {
        size_t new_capacity = v->capacity ? v->capacity * 2 : 1;
        resize(v, new_capacity);
    }
    // Explanation: (char *)v->data: converts the pointer to char pointer
    // (char *)v->data + v->size * v->elem_size: moves the pointer to the end of the array
    // memcpy: copies n bytes from memory area src to memory area dest
    memcpy((char *)v->data + v->size * v->elem_size, value, v->elem_size);

    v->size++;
}

size_t size(vector* v)
{
    return v->size;
}

void clear(vector* v)
{
    free(v->data);
    v->capacity = 0;
    v->size = 0;
}



int main()
{
    vector v;
    init_vector(&v, sizeof(int));
    push_back(&v, &(int){1});
    push_back(&v,&(int){2});

    // print the integers in the vector
    for (int i = 0; i < v.size; ++i) {
        int* value = (int*)((char*)v.data + i * v.elem_size);
        printf("%d ", *value);
    }
    
    // %zu is used to print size_t
    printf("\nSize: %zu", size(&v));
    printf("\nCapacity: %zu", v.capacity);
}