#include <stdio.h>

void arrayInitialization()
{
    // array initialization using initialier list
    int arr[5] = {1, 2, 3, 4, 5};

    // array initialization using initializer list without
    // specifying size
    int arr1[] = {1, 2, 3, 4, 5};

    // array initialization using for loop
    float arr2[5];
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = (float)i * 2.1;
    }
}

void arrayAccessing()
{

    // array declaration and initialization
    int arr[5] = {15, 25, 35, 45, 55};

    // accessing element at index 2 i.e 3rd element
    printf("Element at arr[2]: %d\n", arr[2]);

    // accessing element at index 4 i.e last element
    printf("Element at arr[4]: %d\n", arr[4]);

    // accessing element at index 0 i.e first element
    printf("Element at arr[0]: %d", arr[0]);
}

void twoDimensionalArray()
{
    // declaring and initializing 2d array
    int arr[2][3] = {10, 20, 30, 40, 50, 60};

    printf("2D Array:\n");
    // printing 2d array
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void threeDimensionalArray()
{
    // 3D array declaration
    int arr[2][2][2] = {10, 20, 30, 40, 50, 60};

    // printing elements
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n \n");
    }
}

void pointer()
{
    // Pointer to an integer
    int *p;

    // Pointer to an array of 5 integers
    int(*ptr)[5];
    int arr[5];

    // Points to 0th element of the arr.
    p = arr;

    // Points to the whole array arr.
    ptr = &arr;

    printf("p = %p, ptr = %p\n", p, ptr);
    p++;
    ptr++;
    printf("p = %p, ptr = %p", p, ptr);
}

void passingArrayToFunction(int arr[])
{
    /*
    An array is always passed as pointers to a function in C.
    Whenever we try to pass an array to a function, it decays to the pointer and then passed as a pointer to the first element of an array.*/
    printf("The size of the Array in function passingArrayToFunction: %d\n", sizeof(arr));
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}

int *returnArrayFromFunction()
{
    static int array[5] = {1, 2, 3, 4, 5};
    return array;
}

void main ()
{
    arrayInitialization();
    arrayAccessing();
    twoDimensionalArray();
    threeDimensionalArray();
    
    int arr[5] = {10, 20, 30, 40, 50};
    // size = quantity * neededByte
    printf("The size of the Array in main: %lu\n", sizeof(arr));
    passingArrayToFunction(arr);

    int *ptr = returnArrayFromFunction();

    printf("Array Elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr + i));
    }
}