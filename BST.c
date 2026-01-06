#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   /* Turbo C ke liye; agar modern compiler ho to hata sakta hai */

/* Structure for a node */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Function to create a new node */
struct Node* createNode(int value) {
    struct Node* newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a node */
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    /* equal value ignore (no duplicates) */
    return root;
}

/* Function for inorder traversal */
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Function to search for a value */
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

/* Function to find the minimum node in a tree */
struct Node* findMin(struct Node* node) {
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/* Function to delete a node */
struct Node* deleteNode(struct Node* root, int key) {
    struct Node* temp;

    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        /* Node found */

        /* Case 1: leaf node */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
            return root;
        }
        /* Case 2: only right child */
        else if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        /* Case 3: only left child */
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Case 4: two children */
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

/* ---------- Main Function ---------- */
int main() {
    struct Node* root = NULL;
    int choice, value;
    int running = 1;

    while (running) {
        printf("\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value) != NULL) {
                printf("Value %d found in the tree.\n", value);
            } else {
                printf("Value %d not found.\n", value);
            }
            break;

        case 4:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            running = 0;   /* exit loop */
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    printf("Exiting program...\n");
    return 0;
}
