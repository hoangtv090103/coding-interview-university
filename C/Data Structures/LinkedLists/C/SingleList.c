#include <stdio.h>
#include <stdlib.h>
typedef struct LinkedList
{
    int val;
    struct linkedList *next;
} LinkedList;

LinkedList *createLinkedList();
void displayLinkedList(LinkedList *linkedList);
void insertLinkedList(LinkedList **linkedList, int num, int index);

int main()
{
    int choice;
    int insertNum, index;
    LinkedList *linkedList = NULL;
    do
    {
        printf("\n\t1. Create Linked List");
        printf("\n\t2. Display Linked List");
        printf("\n\t3. Insert Linked List");
        printf("\n\t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linkedList = createLinkedList();
            break;
        case 2:
            displayLinkedList(linkedList);
            break;
        case 3:
        {
            printf("\nEnter the number you want to insert: ");
            scanf("%d", &insertNum);
            printf("\nEnter index you want to insert: ");
            scanf("%d", &index);
            insertLinkedList(&linkedList, insertNum, index);
            break;
        }
        case 4:
        {
            printf("\nEnter the index you want to remove from the Linked List: ");
            scanf("%d", &insertNum);
        }
        default:
            break;
        }
    } while (choice != 4);
    return 0;
}

LinkedList *createLinkedList()
{
    LinkedList *head = NULL;
    LinkedList *tail = NULL;
    LinkedList *node = NULL;
    char c;
    int num;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        node = (LinkedList *)malloc(sizeof(LinkedList));
        node->val = num;
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
        printf("Enter C to enter more: ");
        scanf(" %c", &c);
    } while (c == 'c' || c == 'C');
    return head;
}

void displayLinkedList(LinkedList *linkedList)
{
    LinkedList *pointer = linkedList;
    int i = 1;
    while (pointer != NULL)
    {
        printf("The %dth element in the Linked List is: %d\n", i, pointer->val);
        pointer = pointer->next;
        i++;
    }
}

void insertLinkedList(LinkedList **linkedList, int num, int index)
{
    /*  **linkedList is the address of the head of the Linked List
    *   1. Create a new node
    *   2. If index is 1, then make the new node the head
    *   3. Else, traverse to the index - 1 node
    *   4. Make the new node point to the index node
    *   5. Make the index - 1 node point to the new node
    *   6. Increment the size of the Linked List
    */
    int i = 1;
    LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->val = num;
    node->next = NULL;

    if (index == 1)
    {
        node->next = *linkedList;
        *linkedList = node;
    }
    else
    {
        LinkedList *pointer = *linkedList;
        while (pointer != NULL && i < index - 1)
        {
            pointer = pointer->next;
            i++;
        }
        LinkedList *next_node = pointer->next;
        pointer->next = node;
        node->next = next_node;
    }
}


void removeLinkedList(LinkedList *linkedList, int index)
{
    int i = 1;
    LinkedList *pointer = linkedList;

    while (pointer != NULL && i < index - 1)
    {
        pointer = pointer->next;
        i++;
    }

    LinkedList *indexNode = pointer->next;
    LinkedList *next_node = indexNode->next;
    pointer->next = next_node->next;
    free(indexNode);
}
