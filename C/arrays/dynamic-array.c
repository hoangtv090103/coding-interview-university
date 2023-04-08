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