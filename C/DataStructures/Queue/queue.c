#include <stdio.h>

long SIZE, FRONT = -1, REAR = -1;

void enqueue(long* queue, long val)
{
    if (REAR == SIZE - 1)
    {
        printf("\nOverflow");
    }
    else {
        FRONT = (FRONT == -1) ? 0 : FRONT;
        queue[++REAR] = val;
    }
}

void dequeue(long* queue)
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("Underflow");
    }
    else
    {
        FRONT++;
    }
}

void displayQueue(long* queue)
{
    for (int i = FRONT; i <= REAR; i++)
    {
        printf("\nThe %dth element is: %ld", (i - FRONT + 1), queue[i]);
    }
}

int main ()
{
    printf("\nEnter size of Queue: ");
    scanf("%ld", &SIZE);
    long queue[SIZE];

    int choice;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter value to be enqueued: ");
                long val;
                scanf("%ld", &val);
                enqueue(queue, val);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice");
        }
    } while (choice != 4);
}