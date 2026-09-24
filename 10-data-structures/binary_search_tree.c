#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node *search(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

void inorder(const Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

Node *find_min(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

void free_tree(Node *root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    Node *root = NULL;
    const int values[] = {50, 30, 70, 20, 40, 60, 80};
    const size_t count = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < count; i++) {
        root = insert(root, values[i]);
    }

    printf("Binary Search Tree (inorder): ");
    inorder(root);
    printf("\n");

    int target = 60;
    Node *result = search(root, target);

    if (result != NULL) {
        printf("%d found in the tree.\n", target);
    } else {
        printf("%d not found in the tree.\n", target);
    }

    Node *minimum = find_min(root);

    if (minimum != NULL) {
        printf("Minimum value: %d\n", minimum->data);
    }

    free_tree(root);

    return 0;
}
