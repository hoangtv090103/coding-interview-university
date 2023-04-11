#include <stdio.h>
#include <stdlib.h>
int choice, capacity, size = -1, x, i;

void push(int *stack, int num)
{
    if (isFull(stack))
        printf("Stack is full");
    else
        stack[++size] = num;
}

void pop(int *stack)
{
    if (isEmpty(stack))
        printf("Stack is empty");
    else
        printf("The popped element is %d", stack[size--]);
}

void top(int *stack)
{
    if (isEmpty(stack))
        printf("Stack is empty");
    else
        printf("The top element is %d", stack[size]);
}

int isEmpty(int *stack)
{
    if (size == -1)
        return 1;
    else
        return 0;
}

int isFull(int* stack)
{
    if (size == capacity - 1)
        return 1;
    else
        return 0;
}

int main()
{
    printf("Enter the size (1-100):");
    scanf("%d", &capacity);
    int stack[capacity];
    do
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number to push: ");
            scanf("%d", &x);
            push(stack, x);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            top(stack);
            break;
        default:
            break;
        }
    } while (choice != 4);
}