### **Line-by-Line Explanation of the Stack Implementation in C**

---

### **1. Include Necessary Headers**
```c
#include <stdio.h>
#include <stdlib.h>
```
- `#include <stdio.h>`: Provides functions like `printf()` for input/output.
- `#include <stdlib.h>`: Not used here but generally needed for memory allocation (`malloc()` etc.).

---

### **2. Define the Stack Size**
```c
#define STACK_SIZE 5
```
- Defines a constant `STACK_SIZE` (5 elements). This makes the stack **fixed-size**, ensuring it does not dynamically grow.

---

### **3. Define the Stack Structure**
```c
typedef struct {
    char stack[STACK_SIZE];
    int top;
} Stack;
```
- Defines a structure `Stack`:
  - `stack[STACK_SIZE]`: Array to store elements.
  - `top`: Index of the **topmost** element.  
  - Initially, `top = -1`, meaning the stack is empty.

---

### **4. Push Operation**
```c
void push(Stack *s, char element) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack is full! Cannot push %c\n", element);
        return;
    }
    s->stack[++s->top] = element;
}
```
- **Checks if the stack is full** → `if (s->top == STACK_SIZE - 1)`, prints a warning.
- **Increments `top` (`++s->top`) and inserts the new element.**

Example:
```
push('A') → Stack: [A]
push('B') → Stack: [A, B]
```

---

### **5. Pop Operation**
```c
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return s->stack[s->top--];
}
```
- **Checks if the stack is empty** → `if (s->top == -1)`, prints a warning.
- **Returns the top element** and **decrements `top` (`s->top--`)**.

Example:
```
Stack: [A, B, C]
pop() → Returns 'C', Stack: [A, B]
```

---

### **6. Peek Operation**
```c
char peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return s->stack[s->top];
}
```
- **Checks if the stack is empty**.
- **Returns the top element without removing it.**

Example:
```
Stack: [A, B, C]
peek() → Returns 'C', Stack remains: [A, B, C]
```

---

### **7. Check If Stack is Empty**
```c
int isEmpty(Stack *s) {
    return s->top == -1;
}
```
- Returns `1` (`true`) if `top == -1`, meaning **no elements are present**.

---

### **8. Check If Stack is Full**
```c
int isFull(Stack *s) {
    return s->top == STACK_SIZE - 1;
}
```
- Returns `1` (`true`) if `top == STACK_SIZE - 1`, meaning **stack is full**.

---

### **9. Print Stack**
```c
void printStack(Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c ", s->stack[i]);
    }
    printf("\n");
}
```
- **Iterates through the stack and prints each element.**
- If the stack contains `[A, B, C]`, it prints:
  ```
  Stack: A B C
  ```

---

### **10. Main Function**
```c
int main() {
    Stack s = {{0}, -1}; // Initialize stack with top = -1
    
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
```
### **Execution Flow**
1. **Initialize the stack** (`top = -1`).
2. **Push elements** ('A' → 'E'), 6th push fails.
3. **Print the stack**.
4. **Pop the top element** ('E'), print updated stack.
5. **Peek at the top element**.
6. **Check if the stack is empty**.

---

### **Example Output**
```
Stack is full! Cannot push F
Stack: A B C D E
Popped element: E
Stack: A B C D
Top element: D
Is stack empty? No
```

---

### **Key Takeaways**
- **Fixed-size stack** implementation using an array.
- **Efficient O(1) time complexity** for push, pop, and peek.
- **Useful for embedded systems** (no dynamic memory allocation).

🚀 **Now try modifying it to handle integers instead of characters!**
