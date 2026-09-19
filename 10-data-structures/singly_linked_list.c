#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insertAtEnd(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void display(void) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;

    printf("List: ");
    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
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
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    Node *previous = NULL;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
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
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
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
                insertAtEnd(value);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;

            case 5:
                freeList();
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
