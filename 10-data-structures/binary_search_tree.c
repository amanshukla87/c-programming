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

void preorder(const Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(const Node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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

Node *delete_node(Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *right_child = root->right;
            free(root);
            return right_child;
        }

        if (root->right == NULL) {
            Node *left_child = root->left;
            free(root);
            return left_child;
        }

        Node *successor = find_min(root->right);
        root->data = successor->data;
        root->right = delete_node(root->right, successor->data);
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

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
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

    root = delete_node(root, 70);

    printf("After deleting 70: ");
    inorder(root);
    printf("\n");

    free_tree(root);

    return 0;
}
