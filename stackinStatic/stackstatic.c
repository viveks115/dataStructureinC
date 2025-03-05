#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

typedef struct {
    char stack[STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, char element) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack is full! Cannot push %c\n", element);
        return;
    }
    s->stack[++s->top] = element;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return s->stack[s->top--];
}

char peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return s->stack[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == STACK_SIZE - 1;
}

void printStack(Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c ", s->stack[i]);
    }
    printf("\n");
}

int main() {
    Stack s = {{0}, -1};
    
    push(&s, 'A');
    push(&s, 'B');
    push(&s, 'C');
    push(&s, 'D');
    push(&s, 'E');
    push(&s, 'F'); // Should print "Stack is full"
    
    printStack(&s);
    
    printf("Popped element: %c\n", pop(&s));
    printStack(&s);
    
    printf("Top element: %c\n", peek(&s));
    printf("Is stack empty? %s\n", isEmpty(&s) ? "Yes" : "No");
    
    return 0;
}
