#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed onto the stack.\n", value);
}

void pop(void) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Node *temp = top;
    printf("%d popped from the stack.\n", temp->data);

    top = top->next;
    free(temp);
}

void peek(void) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void display(void) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Node *current = top;

    printf("Stack: ");
    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf(" -> NULL\n");
}

void freeStack(void) {
    Node *current = top;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    top = NULL;
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n--- Stack Using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                freeStack();
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
