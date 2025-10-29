#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CollegeNode {
    char name[100];
    char city[100];
    struct CollegeNode *next;
};

typedef struct CollegeNode Node;

Node* createNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter College Name: ");
    getchar(); 
    fgets(newNode->name, 100, stdin);
    newNode->name[strcspn(newNode->name, "\n")] = 0; 
    printf("Enter City: ");
    fgets(newNode->city, 100, stdin);
    newNode->city[strcspn(newNode->city, "\n")] = 0; 
    newNode->next = NULL;
    return newNode;
}

void displayList(Node *last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = last->next; 
    printf("Circular Linked List:\n");
    printf("... -> ");
    do {
        printf("[Name: %s, City: %s] -> ", temp->name, temp->city);
        temp = temp->next;
    } while (temp != last->next);
    printf("...\n");
}

Node* insertAtFront(Node *last) {
    Node *newNode = createNode();

    if (last == NULL) {
        last = newNode;
        last->next = last; 
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("College inserted at the front.\n");
    return last;
}

Node* deleteAtEnd(Node *last) {
    if (last == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    Node *temp = last->next;
    Node *prev = NULL;

    if (last->next == last) {
        printf("College [Name: %s, City: %s] deleted.\n", last->name, last->city);
        free(last);
        return NULL;
    }

    while (temp != last) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = last->next;
    printf("College [Name: %s, City: %s] deleted.\n", last->name, last->city);
    free(last); 
    last = prev;

    return last;
}

int main() {
    Node *last = NULL; 
    int choice;

    while (1) {
        printf("\n--- College Circular Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Delete at end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                last = insertAtFront(last);
                displayList(last);
                break;
            case 2:
                last = deleteAtEnd(last);
                displayList(last);
                break;
            case 3:
                displayList(last);
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