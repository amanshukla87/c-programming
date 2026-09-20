#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d added to the queue.\n", value);
}

void dequeue(void) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = front;
    printf("%d removed from the queue.\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void peek(void) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

void display(void) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node *current = front;

    printf("Queue: ");
    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" <- ");
        }

        current = current->next;
    }

    printf(" <- NULL\n");
}

void freeQueue(void) {
    Node *current = front;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    front = NULL;
    rear = NULL;
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n--- Queue Using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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
                if (scanf("%d", &value) == 1) {
                    enqueue(value);
                } else {
                    printf("Invalid value.\n");
                    freeQueue();
                    return 1;
                }
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                freeQueue();
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    freeQueue();
    return 0;
}
