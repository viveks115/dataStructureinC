#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char msg;
  struct node *next;
}node;

void insert(struct node **head, char element) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->msg = element;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct node *head) {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%c -> ", temp->msg);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void search(struct node *head, char key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->msg == key) {
            printf("Element %c found in the list.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %c not found in the list.\n", key);
}

void deleteNode(struct node **head, char key) {
    struct node *temp = *head, *prev = NULL;
    
    if (temp != NULL && temp->msg == key) {
        *head = temp->next;
        free(temp);
        printf("Element %c deleted from the list.\n", key);
        return;
    }
    
    while (temp != NULL && temp->msg != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element %c not found in the list.\n", key);
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("Element %c deleted from the list.\n", key);
}

void reverseList(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("Linked list reversed successfully.\n");
}

int countNodes(struct node *head) {
    int count = 0;
    struct node *temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

int main() {
    struct node *head = NULL;
    
    insert(&head, 'A');
    insert(&head, 'B');
    insert(&head, 'C');
    
    printList(head);
    printf("Total nodes: %d\n", countNodes(head));
    
    search(head, 'B'); // Test case for searching
    search(head, 'Z'); // Test case for not found
    
    deleteNode(&head, 'B'); // Test case for deletion
    printList(head);
    printf("Total nodes: %d\n", countNodes(head));
    
    reverseList(&head);
    printList(head);
    
    freeList(head);
    
    return 0;
}
