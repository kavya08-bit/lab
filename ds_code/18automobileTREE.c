#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Automobile {
    char type[50];
    char company[50];
    int year;
} Automobile;

typedef struct Node {
    Automobile data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(Automobile auto_data);
Node* insert(Node* root, Automobile auto_data);
Node* deleteNode(Node* root, int year);
Node* findMin(Node* node);
void displayInOrder(Node* root);
void displayPreOrder(Node* root);
void displayPostOrder(Node* root);
void printAutoData(Automobile data);

int main() {
    Node* root = NULL;
    int choice, year;
    Automobile auto_data;

    printf("--- BST for Automobile Details (Key: Year) ---\n");
    while (1) {
        printf("\n1. Insert Automobile\n");
        printf("2. Delete Automobile (by Year)\n");
        printf("3. Display In-Order (Sorted by Year)\n");
        printf("4. Display Pre-Order\n");
        printf("5. Display Post-Order\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter Year of Make: ");
                scanf("%d", &auto_data.year);

                while (getchar() != '\n'); 

                printf("Enter Company: ");
                fgets(auto_data.company, 50, stdin);
                auto_data.company[strcspn(auto_data.company, "\n")] = '\0';

                printf("Enter Type (e.g., SUV, Sedan): ");
                fgets(auto_data.type, 50, stdin);
                auto_data.type[strcspn(auto_data.type, "\n")] = '\0';

                root = insert(root, auto_data);
                printf("Inserted: Year %d\n", auto_data.year);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty. Cannot delete.\n");
                } else {
                    printf("Enter Year of Make to delete: ");
                    scanf("%d", &year);
                    root = deleteNode(root, year);
                }
                break;

            case 3:
                printf("\n--- In-Order Traversal (Sorted) ---\n");
                if (root == NULL) printf("Tree is empty.\n");
                displayInOrder(root);
                break;

            case 4:
                printf("\n--- Pre-Order Traversal ---\n");
                if (root == NULL) printf("Tree is empty.\n");
                displayPreOrder(root);
                break;

            case 5:
                printf("\n--- Post-Order Traversal ---\n");
                if (root == NULL) printf("Tree is empty.\n");
                displayPostOrder(root);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}

Node* createNode(Automobile auto_data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = auto_data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printAutoData(Automobile data) {
    printf("  - Year: %d, Company: %s, Type: %s\n", 
           data.year, data.company, data.type);
}

Node* insert(Node* root, Automobile auto_data) {
    if (root == NULL) {
        return createNode(auto_data);
    }

    if (auto_data.year < root->data.year) {
        root->left = insert(root->left, auto_data);
    } else if (auto_data.year > root->data.year) {
        root->right = insert(root->right, auto_data);
    } else {
        printf("Error: Automobile with year %d already exists.\n", auto_data.year);
    }

    return root;
}

Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int year) {
    if (root == NULL) {
        printf("Automobile with year %d not found.\n", year);
        return root;
    }

    if (year < root->data.year) {
        root->left = deleteNode(root->left, year);
    } else if (year > root->data.year) {
        root->right = deleteNode(root->right, year);
    } else {
        printf("Found and deleting: Year %d\n", root->data.year);

        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.year);
    }
    return root;
}

void displayInOrder(Node* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printAutoData(root->data);
        displayInOrder(root->right);
    }
}

void displayPreOrder(Node* root) {
    if (root != NULL) {
        printAutoData(root->data);
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }
}

void displayPostOrder(Node* root) {
    if (root != NULL) {
        displayPostOrder(root->left);
        displayPostOrder(root->right);
        printAutoData(root->data);
    }
}
