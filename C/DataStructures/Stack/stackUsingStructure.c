#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int val;
    Stack *next;
} Stack;

Stack *createStack(int val) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->val = val;
    stack->next = NULL;
    return stack;
}

void push(Stack **stack, int val) {
    Stack *node = createStack(val);
    node->next = *stack;
    *stack = node;
}

int isEmpty(Stack *stack) {
    return stack == NULL;
}

void pop(Stack **stack) {
    if (*stack == NULL) {
        printf("Stack is empty");
        return -1;
    }
    int val = (*stack)->val;
    Stack *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

int top(Stack *stack) {
    return stack->val;
}

int main() {
    Stack *stack = NULL;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printf("%d", top(stack));
    pop(&stack);
    printf("%d", top(stack));
    return 0;
}