#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

typedef struct {
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void circular_enqueue(CircularBuffer *cb, char element) {
    if (cb->count == BUFFER_SIZE) {
        printf("Buffer is full! Cannot enqueue %c\n", element);
        return;
    }
    cb->buffer[cb->tail] = element;
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count++;
}

char circular_dequeue(CircularBuffer *cb) {
    if (cb->count == 0) {
        printf("Buffer is empty!\n");
        return '\0';
    }
    char dequeued = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count--;
    return dequeued;
}

int circular_isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

int circular_isFull(CircularBuffer *cb) {
    return cb->count == BUFFER_SIZE;
}

void circular_print(CircularBuffer *cb) {
    printf("Circular Buffer: ");
    for (int i = 0, idx = cb->head; i < cb->count; i++) {
        printf("%c ", cb->buffer[idx]);
        idx = (idx + 1) % BUFFER_SIZE;
    }
    printf("\n");
}

int main() {
    CircularBuffer cb = {{0}, 0, 0, 0};
    
    circular_enqueue(&cb, 'A');
    circular_enqueue(&cb, 'B');
    circular_enqueue(&cb, 'C');
    circular_enqueue(&cb, 'D');
    circular_enqueue(&cb, 'E');
    circular_enqueue(&cb, 'F'); // Should print "Buffer is full"
    
    circular_print(&cb);
    
    printf("Dequeued element: %c\n", circular_dequeue(&cb));
    circular_print(&cb);
    
    printf("Is buffer empty? %s\n", circular_isEmpty(&cb) ? "Yes" : "No");
    
    return 0;
}
