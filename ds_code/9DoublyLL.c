#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EmployeeNode {
    int empId;
    char name[100];
    struct EmployeeNode *prev;
    struct EmployeeNode *next;
};

typedef struct EmployeeNode Node;

Node* createNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter Employee ID: ");
    scanf("%d", &newNode->empId);
    printf("Enter Name: ");
    getchar(); 
    fgets(newNode->name, 100, stdin);
    newNode->name[strcspn(newNode->name, "\n")] = 0; 
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("Doubly Linked List (Forward):\n");
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("[ID: %d, Name: %s] <-> ", temp->empId, temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* insertAtFront(Node *head) {
    Node *newNode = createNode();
    
    if (head == NULL) {
        head = newNode;
        return head;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    printf("Employee inserted at the front.\n");
    return head;
}

Node* deleteAtEnd(Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    if (head->next == NULL) {
        printf("Employee [ID: %d, Name: %s] deleted.\n", head->empId, head->name);
        free(head);
        return NULL;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    printf("Employee [ID: %d, Name: %s] deleted.\n", temp->empId, temp->name);
    free(temp);

    return head;
}

int main() {
    Node *head = NULL;
    int choice;

    while (1) {
        printf("\n--- Employee Doubly Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Delete at end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertAtFront(head);
                displayList(head);
                break;
            case 2:
                head = deleteAtEnd(head);
                displayList(head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
