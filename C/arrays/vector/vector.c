#include <stdio.h>
#include <stdlib.h>

long *vector;
int size = 0;
long idx = 0;
long *end;
long *begin;

void pushback(long number)
{
    if (vector == NULL)
    {
        vector = malloc(sizeof(long) * 1);
        begin = vector;
        end = vector;
        *(vector + idx) = number;
    }
    else
    {
        vector = realloc(vector, sizeof(long) * 1);
        *(vector + idx) = number;
        end = vector + idx;
    }
    idx++;
}

int main()
{
    pushback(1);
    pushback(2);

    for (long* i = begin; i <= end; i++)
    {
        printf("%ld ", *(i));
    }
}