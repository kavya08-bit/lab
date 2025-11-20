#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentNode {
    int rollNumber;
    char name[100];
    struct StudentNode *next;
};

typedef struct StudentNode Node;

Node* createNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter Roll Number: ");
    scanf("%d", &newNode->rollNumber);
    printf("Enter Name: ");
    getchar(); 
    fgets(newNode->name, 100, stdin);
    newNode->name[strcspn(newNode->name, "\n")] = 0; 
    newNode->next = NULL;
    return newNode;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("Linked List:\n");
    while (temp != NULL) {
        printf("[Roll: %d, Name: %s] -> ", temp->rollNumber, temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

int getCount(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* insertAtPosition(Node *head) {
    int pos;
    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    int count = getCount(head);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position. Valid range is [1, %d]\n", count + 1);
        return head;
    }

    Node *newNode = createNode();

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* deleteByRollNumber(Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    Node *temp = head;
    Node *prev = NULL;

    if (temp != NULL && temp->rollNumber == roll) {
        head = temp->next; 
        free(temp); 
        printf("Student with Roll Number %d deleted.\n", roll);
        return head;
    }

    while (temp != NULL && temp->rollNumber != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with Roll Number %d not found.\n", roll);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student with Roll Number %d deleted.\n", roll);
    return head;
}

Node* reverseList(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;
        current = next;
    }
    head = prev;
    printf("List has been reversed.\n");
    return head;
}

int main() {
    Node *head = NULL;
    int choice;

    while (1) {
        printf("\n--- Student Linked List Menu ---\n");
        printf("1. Insert at specified position\n");
        printf("2. Delete by Roll Number\n");
        printf("3. Reverse the list\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertAtPosition(head);
                displayList(head);
                break;
            case 2:
                head = deleteByRollNumber(head);
                displayList(head);
                break;
            case 3:
                head = reverseList(head);
                displayList(head);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
