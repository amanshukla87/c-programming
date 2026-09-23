#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_end(Node **head, int data) {
    Node *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        new_node->next = *head;
        return;
    }

    Node *current = *head;
    while (current->next != *head) {
        current = current->next;
    }

    current->next = new_node;
    new_node->next = *head;
}

void insert_beginning(Node **head, int data) {
    Node *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        new_node->next = *head;
        return;
    }

    Node *last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    new_node->next = *head;
    last->next = new_node;
    *head = new_node;
}

int delete_value(Node **head, int value) {
    if (*head == NULL) {
        return 0;
    }

    Node *current = *head;
    Node *previous = NULL;

    do {
        if (current->data == value) {
            if (current == *head) {
                if (current->next == *head) {
                    *head = NULL;
                } else {
                    Node *last = *head;
                    while (last->next != *head) {
                        last = last->next;
                    }
                    *head = current->next;
                    last->next = *head;
                }
            } else {
                previous->next = current->next;
            }

            free(current);
            return 1;
        }

        previous = current;
        current = current->next;
    } while (current != *head);

    return 0;
}

void display(const Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    const Node *current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("HEAD\n");
}

void free_list(Node **head) {
    if (*head == NULL) {
        return;
    }

    Node *current = (*head)->next;
    while (current != *head) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(*head);
    *head = NULL;
}

int main(void) {
    Node *head = NULL;

    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_beginning(&head, 5);

    printf("Circular linked list: ");
    display(head);

    if (delete_value(&head, 20)) {
        printf("After deleting 20: ");
        display(head);
    }

    free_list(&head);
    return 0;
}
