#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char msg;
  struct node *next;
}node;

typedef struct {
    struct node *front;
    struct node *rear;
} Queue;

void enqueue(Queue *q, char element) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->msg = element;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

char dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return '\0';
    }
    struct node *temp = q->front;
    char dequeued = temp->msg;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return dequeued;
}

char front(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return '\0';
    }
    return q->front->msg;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

void printQueue(Queue *q) {
    struct node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%c -> ", temp->msg);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeQueue(Queue *q) {
    struct node *temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
}

int main() {
    Queue q = {NULL, NULL};
    
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    
    printQueue(&q);
    printf("Front element: %c\n", front(&q));
    
    printf("Dequeued element: %c\n", dequeue(&q));
    printQueue(&q);
    
    printf("Is queue empty? %s\n", isQueueEmpty(&q) ? "Yes" : "No");
    
    freeQueue(&q);
    return 0;
}
