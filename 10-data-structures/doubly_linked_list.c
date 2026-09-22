#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insertAtEnd(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = tail;
    newNode->next = NULL;

    if (tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void displayForward(void) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;

    printf("Forward: ");
    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" <-> ");
        }

        current = current->next;
    }

    printf(" -> NULL\n");
}

void displayBackward(void) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = tail;

    printf("Backward: ");
    while (current != NULL) {
        printf("%d", current->data);

        if (current->prev != NULL) {
            printf(" <-> ");
        }

        current = current->prev;
    }

    printf(" -> NULL\n");
}

void search(int value) {
    Node *current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == value) {
            printf("%d found at position %d.\n", value, position);
            return;
        }

        current = current->next;
        position++;
    }

    printf("%d not found in the list.\n", value);
}

void deleteValue(int value) {
    Node *current = head;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    free(current);
    printf("%d deleted successfully.\n", value);
}

void freeList(void) {
    Node *current = head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
    tail = NULL;
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Display forward\n");
        printf("3. Display backward\n");
        printf("4. Search\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeList();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1) {
                    insertAtEnd(value);
                } else {
                    printf("Invalid value.\n");
                    freeList();
                    return 1;
                }
                break;

            case 2:
                displayForward();
                break;

            case 3:
                displayBackward();
                break;

            case 4:
                printf("Enter value to search: ");
                if (scanf("%d", &value) == 1) {
                    search(value);
                } else {
                    printf("Invalid value.\n");
                    freeList();
                    return 1;
                }
                break;

            case 5:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) == 1) {
                    deleteValue(value);
                } else {
                    printf("Invalid value.\n");
                    freeList();
                    return 1;
                }
                break;

            case 6:
                freeList();
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
