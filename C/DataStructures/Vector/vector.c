#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    /*
        void *data: pointer to the first element of the vector
        size_t size: number of elements in the vector
        size_t capacity: number of elements that can be stored in the vector
        size_t elem_size: size of each element in the vector
    */
    void *data;
    size_t size; // size_t: store size of an object of any type of data.
    size_t capacity;
    size_t elem_size;
} vector;

void init_vector(vector *v, size_t elem_size);
void resize(vector *v, size_t new_size);
void push_back(vector *v, const void *value);
size_t size(vector *v);
void clear(vector *v);
void vprint(vector *v);
void *begin(vector *v);
void *end(vector *v);
size_t max_size(vector *v);
int empty(vector *v);
void shrink_to_fit(vector *v);
void pop_back(vector *v);
int front(vector *v);
int back(vector *v);

int main()
{
    vector v;
    init_vector(&v, sizeof(int));
    push_back(&v, &(int){1});
    push_back(&v, &(int){2});

    printf("\nFront element is: %ld", front(&v));
    printf("\nBack element is: %ld", front(&v));

    printf("\nSize: %zu", size(&v));
    printf("\nCapacity: %zu", max_size(&v));

    // print the integers in the vector
    vprint(&v);

    clear(&v);

    vprint(&v);

    // %zu is used to print size_t
    printf("\nSize: %zu", size(&v));
    printf("\nCapacity: %zu", max_size(&v));
}

void init_vector(vector *v, size_t elem_size)
{
    /*
        initialize the vector
    */
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->elem_size = elem_size;
}

void resize(vector *v, size_t new_size)
{
    /*
        resize the vector
    */
    v->data = realloc(v->data, new_size * v->elem_size);
    v->capacity = new_size;
}

void push_back(vector *v, const void *value) // add an element to the end of the vector
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

size_t size(vector *v) // return the number of elements in the vector
{
    /*
        what is size_t according to the C standard ?
        size_t is an unsigned integral type of at least 16 bits.
        It is used to represent the size of an object in bytes.
        It is the return type of the sizeof operator and is widely used in the standard library to represent sizes and counts.
    */
    return v->size;
}

void clear(vector *v) // clear the vector
{
    free(v->data);
    v->capacity = 0;
    v->size = 0;
}

void vprint(vector *v) // print the elements in the vector
{
    if (v->size == 0)
    {
        printf("\nThe vector is empty");
        return;
    }
    printf("\nThe elements in vector are: ");
    for (int i = 0; i < v->size; i++)
    {
        int *value = (int *)((char *)v->data + i * v->elem_size);
        printf("%d ", *value);
    }
}

void *begin(vector *v) // return an iterator to the first element of the vector
{
    return v->data;
}

void *end(vector *v) // return an iterator to the last element of the vector
{
    return (v->data + v->size * v->elem_size);
}

size_t max_size(vector *v) // return the number of elements that can be held in currently allocated storage
{
    return v->capacity;
}

int empty(vector *v) // check if the vector is empty
{
    if (v->size)
    {
        return 0;
    }
    return 1;
}

void shrink_to_fit(vector *v) // reduce the capacity of the vector to fit its size
{
    v->capacity = v->size;
}

void pop_back(vector *v) // remove the last element of the vector
{
    v->size--;
}

int front(vector *v)
{
    return *(int *)((char *)v->data);
}

int back(vector *v)
{
    return *(int *)((char *)v->data + (v->size - 1) * v->elem_size);
}
