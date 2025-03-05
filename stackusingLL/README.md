### **Explanation of Stack Implementation Using Linked List**
This program implements a **stack** using a **linked list** in C.

---

## **1️⃣ Struct Definition**
```c
typedef struct node{
  char msg;
  struct node *next;
}node;
```
- **`msg`**: Holds the character data.
- **`next`**: Points to the next node in the stack.
- This forms a **linked list** where the `top` of the stack is the **head node**.

---

## **2️⃣ Push Function (Insertion)**
```c
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
```
### **How it works?**
- **Allocates memory** for a new node.
- **Stores the given `element`** in the node.
- **Links new node to `top`** (existing first node).
- **Updates `top`** to point to this new node.

---

## **3️⃣ Pop Function (Deletion)**
```c
char pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return '\0';
    }
    struct node *temp = *top;
    char popped = temp->msg;
    *top = temp->next;
    free(temp);
    return popped;
}
```
### **How it works?**
- **Checks if stack is empty** (`top == NULL`).
- **Stores the value of `top`** before deletion.
- **Moves `top` to the next node**.
- **Frees memory** of removed node.
- **Returns the deleted value**.

---

## **4️⃣ Peek Function (Get Top Element)**
```c
char peek(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return top->msg;
}
```
### **How it works?**
- **Checks if stack is empty** (`top == NULL`).
- **Returns `top` value** without removing it.

---

## **5️⃣ isEmpty Function**
```c
int isEmpty(struct node *top) {
    return top == NULL;
}
```
### **How it works?**
- **Returns 1 (true)** if stack is empty (`top == NULL`).
- **Returns 0 (false)** otherwise.

---

## **6️⃣ Print Stack Function**
```c
void printStack(struct node *top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%c -> ", top->msg);
        top = top->next;
    }
    printf("NULL\n");
}
```
### **How it works?**
- **Traverses the stack** and prints each node’s `msg`.
- **Ends with `NULL`** to indicate the stack’s bottom.

---

## **7️⃣ Free Stack Memory**
```c
void freeStack(struct node *top) {
    struct node *temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}
```
### **How it works?**
- **Traverses stack** and **frees memory** node by node.
- **Prevents memory leaks**.

---

## **8️⃣ Main Function (Testing)**
```c
int main() {
    struct node *top = NULL;
    
    push(&top, 'A');
    push(&top, 'B');
    push(&top, 'C');
    
    printStack(top);
    printf("Top element: %c\n", peek(top));
    
    printf("Popped element: %c\n", pop(&top));
    printStack(top);
    
    printf("Is stack empty? %s\n", isEmpty(top) ? "Yes" : "No");
    
    freeStack(top);
    return 0;
}
```
### **Execution Flow**
1. **Push ‘A’, ‘B’, ‘C’** → Stack: `C -> B -> A -> NULL`
2. **Print stack** → `C -> B -> A -> NULL`
3. **Peek (Top Element)** → `C`
4. **Pop (Remove `C`)** → Stack: `B -> A -> NULL`
5. **Check if empty** → `No`
6. **Free memory** before exit.

---

### **Example Output**
```
Stack: C -> B -> A -> NULL
Top element: C
Popped element: C
Stack: B -> A -> NULL
Is stack empty? No
```

---

## **Next Steps**
- Implement **reverse stack** using recursion.
- Implement **stack using an array**.

Let me know if you have any doubts! 🚀
