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

int pop(Stack **stack) {
    int val = (*stack)->val;
    Stack *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return val;
}

int main() {
    Stack *stack = NULL;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    printf("%d ", pop(&stack));

    return 0;
}