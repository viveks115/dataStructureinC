#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char msg;
  struct node *next;
}node;

void push(struct node **top, char element) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->msg = element;
    newNode->next = *top;
    *top = newNode;
}

char pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return '
