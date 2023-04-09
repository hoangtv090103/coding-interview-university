/* Jagged Array or Array of Arrays in C
    1. Using array and a pointer (Static Jagged Array)
    2. Using an array of pointer (Dynamic Jagged Array)

*/
#include <stdio.h>
#include <stdlib.h>

//Declare methods
void staticJaggedArray();
void dynamicJaggedArray();

int main ()
{
    staticJaggedArray();
    dynamicJaggedArray();

    return 0;
}

void staticJaggedArray()
{
    /*
        First declare 1-D arrays with the number of rows you will need,
        The size of each array (array for the elements in the row) will be the number of columns (or elements) in the row,
        Then declare a 1-D array of pointers that will hold the addresses of the rows,
        The size of the 1-D array is the number of rows you want in the jagged array.
    */
    int row0[4] = {1, 2, 3, 4};
    int row1[2] = {5, 6};

    int *jagged[2] = {row0, row1};

    // Array to hold the size of each row
    int Size[2] = {4, 2}, k = 0;

    // To display elements of Jagged array
    for (int i = 0; i < 2; i++)
    {
        // pointer to hold the address of the row
        int *ptr = jagged[i];

        for (int j = 0; j < Size[k]; j++)
        {
            printf("%d ", *ptr);
            // move the pointer to the next element in the row
            ptr++;
        }
        printf("\n");
        k++;

        // move the pointer to the next row
        jagged[i]++;
    }
}

void dynamicJaggedArray()
{
    /*
        Declare an array of pointers (jagged array),
        The size of this array will be the number of rows required in the Jagged array
    Then for each pointer in the array allocate memory for the number of elements you want in this row.
    */

    // 2 rows
    int *jagged[2];

    // Allocate memory for elements in row 0
    jagged[0] = malloc(sizeof(int));

    // Allocate memory for elements in row 1
    jagged[1] = malloc(sizeof(int) * 3);

    // Array to hold the size of each row
    int Size[2] = {sizeof(jagged[0]) / sizeof(int), sizeof(jagged[1]) / sizeof(int)}, k = 0, number = 100;

    // User enters the numbers
    for (int i = 0; i < 2; i++)
    {

        int *p = jagged[i];

        for (int j = 0; j < Size[k]; j++)
        {
            *p = number++;

            // move the pointer
            p++;
        }
        k++;
    }

    k = 0;

    // Display elements in Jagged array
    for (int i = 0; i < 2; i++)
    {

        int *p = jagged[i];
        for (int j = 0; j < Size[k]; j++)
        {

            printf("%d ", *p);
            // move the pointer to the next element
            p++;
        }
        printf("\n");
        k++;
        // move the pointer to the next row
        jagged[i]++;
    }
}

