#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node *createLinkedList() {
    Node *head = NULL;
    Node *tail = NULL;
    Node *node = NULL;
    char c;
    int num;
    do {
        printf("Enter a number: ");
        scanf("%d", &num);
        node = createNode(num);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
        printf("Enter C to enter more: ");
        scanf("%c", &c);
    } while (c == 'c' || c == 'C');
    return head;
}

void displayLinkedList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void insertLinkedList(Node **head, int val, int index) {
    Node *node = createNode(val);
    Node *temp = *head;
    if (index == 1) {
        node->next = *head;
        (*head)->prev = node;
        *head = node;
    } else {
        for (int i = 1; i < index - 1; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = node;
        }
        temp->next = node;
        node->prev = temp;
    }
}

void removeLinkedList(Node **head, int index) {
    Node *temp = *head;
    if (index == 0) {
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        if (temp2->next != NULL) {
            temp2->next->prev = temp;
        }
        free(temp2);
    }
}

int main() {
    Node *linkedList = NULL;
    int choice, insertNum, index;
    do {
        printf("\n\t1. Create Linked List");
        printf("\n\t2. Display Linked List");
        printf("\n\t3. Insert in Linked List");
        printf("\n\t4. Remove from Linked List");
        printf("\n\t5. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            linkedList = createLinkedList();
            break;
        case 2:
            displayLinkedList(linkedList);
            break;
        case 3:
            printf("Enter the number you want to insert: ");
            scanf("%d", &insertNum);
            printf("Enter index you want to insert: ");
            scanf("%d", &index);
            insertLinkedList(&linkedList, insertNum, index);
            break;
        case 4:
            printf("Enter the index you want to remove from the Linked List: ");
            scanf("%d", &index);
            removeLinkedList(&linkedList, index);
            break;
        default:
            break;
        }
    } while (choice != 5);
    return 0;
}
