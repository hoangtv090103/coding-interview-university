#include <stdio.h>
#include <stdlib.h>
/*
We can create a dynamic array in C by using the following methods:
    1. Using malloc() Function
    2. Using calloc() Function
    3. Resizing Array Using realloc() Function
    4. Using Variable Length Arrays(VLAs)
    5. Using Flexible Array Members
*/
void usingMalloc();
void usingCalloc();
void usingRealloc();
void usingVariableLengthArrays();
void flexibleArrayMembers();

int main()
{
    usingMalloc();
    usingCalloc();
    usingRealloc();
    usingVariableLengthArrays();
    flexibleArrayMembers();
    return 0;
}

void usingMalloc()
{
    /*
        The “malloc” or “memory allocation” method in C is used to dynamically allocate a single large block of memory with the specified size.
        It returns a pointer of type void which can be cast into a pointer of any form.
        It is defined inside <stdlib.h> header file.
        Syntax: ptr = (cast-type*) malloc(byte-size);
    */

    // address of the block created hold by this pointer
    int *p;
    int size;

    // Size of the Array
    printf("Enter size of elements: ");
    scanf("%d", &size);

    //  Memory allocates dynamically using malloc()
    p = (int *)malloc(size * sizeof(int));

    if (p == NULL)
    {
        printf("Memory not allocated.\n");
    }
    else
    {
        // Memory allocated
        printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (int j = 0; j < size; ++j)
        {
            p[j] = j + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int k = 0; k < size; ++k)
        {
            printf("%d, ", p[k]);
        }
    }
}

void usingCalloc()
{
    /*
    The “calloc” or “contiguous allocation” method in C
     is used to dynamically allocate the specified number of blocks of memory of the specified type and initialized each block
     with a default value of 0.
     Syntax: ptr = (cast-type*)calloc(n, element-size);
    */

    // address of the block created hold by this pointer
    int *ptr;
    int size;

    // Size of the array
    printf("Enter size of elements:");
    scanf("%d", &size);

    //  Memory allocates dynamically using calloc()
    ptr = (int *)calloc(size, sizeof(int));

    // Checking for memory allocation
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
    }
    else
    {

        // Memory allocated
        printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (int j = 0; j < size; ++j)
        {
            ptr[j] = j + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int k = 0; k < size; ++k)
        {
            printf("%d, ", ptr[k]);
        }
    }
}

void usingRealloc()
{
    /*
    The “realloc” or “re-allocation” method in C is used to dynamically change the memory allocation of a previously allocated memory.
    Using this function we can create a new array or change the size of an already existing array.
    Syntax: realloc(ptr, newSize)
    */

    // address of the block created hold by this pointer
    int *ptr;
    int size = 5;

    //  Memory allocates dynamically using calloc()
    ptr = (int *)calloc(size, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using "
               "calloc.\n");
    }

    // inserting elements
    for (int j = 0; j < size; ++j)
    {
        ptr[j] = j + 1;
    }

    printf("The elements of the array are: ");
    for (int k = 0; k < size; ++k)
    {
        printf("%d, ", ptr[k]);
    }

    printf("\n");

    size = 10;

    int *temp = ptr;

    //  using realloc
    ptr = realloc(ptr, size * sizeof(int));
    if (!ptr)
    {
        printf("Memory Re-allocation failed.");
        ptr = temp;
    }
    else
    {
        printf("Memory successfully re-allocated using "
               "realloc.\n");
    }

    // inserting new elements
    for (int j = 5; j < size; ++j)
    {
        ptr[j] = j + 10;
    }

    printf("The new elements of the array are: ");
    for (int k = 0; k < size; ++k)
    {
        printf("%d, ", ptr[k]);
    }
}

void usingVariableLengthArrays()
{
    /*
        Variable length arrays or VLAs, are those arrays in which we can determine the size of the array at the run time. It allocates the memory in the stack and it’s based on the local scope level.
        The size of a variable length array cannot be changed once it is defined and using variable length array as its found down sides as compared to above methods.
    */
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");

    for (int i = 0; i < n; ++i)
    {

        scanf("%d", &arr[i]);
    }

    printf("Elements of VLA of Given Size: ");
    for (int i = 0; i < n; ++i)
    {

        printf("%d ", arr[i]);
    }
}

// Using Flexible Array Members
typedef struct
{
    int len;
    int arr[];
} fam;

void flexibleArrayMembers()
{
    // creating an array member of size 5
    fam *fam1 = (fam *)malloc(sizeof(fam *) + 5 * sizeof(int));

    // creating an array member of size 10
    fam *fam2 = (fam *)malloc(sizeof(fam *) + 10 * sizeof(int));

    // inserting elements
    for (int i = 0; i < 5; i++)
    {
        fam1->arr[i] = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        fam2->arr[i] = i + 10;
    }

    //  printing elements
    printf("Array of Size 5:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", fam1->arr[i]);
    }
    printf("\n");

    printf("Array of size 10:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", fam2->arr[i]);
    }
}