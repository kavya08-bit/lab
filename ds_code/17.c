#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lab {
    char name[100];
    int num_computers;
} Lab;

typedef struct Node {
    Lab data;
    struct Node* next;
} Node;

Node* rear = NULL;

void insert(char* lab_name, int computers);
void delete_item(void);
void display(void);

int main() {
    int choice, computers;
    char lab_name[100];

    printf("--- Circular Queue (Linked List) ---\n");
    while (1) {
        printf("\n1. Insert Lab\n");
        printf("2. Delete Lab\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                while (getchar() != '\n'); 
                
                printf("Enter the Lab Name: ");
                fgets(lab_name, 100, stdin);
                lab_name[strcspn(lab_name, "\n")] = '\0';

                printf("Enter the number of computers: ");
                scanf("%d", &computers);

                insert(lab_name, computers);
                break;

            case 2:
                delete_item();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                while(rear != NULL) {
                    delete_item();
                }
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

void insert(char* lab_name, int computers) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Queue Overflow (Heap memory full). Cannot insert.\n");
        return;
    }

    strcpy(newNode->data.name, lab_name);
    newNode->data.num_computers = computers;

    if (rear == NULL) {
        rear = newNode;
        newNode->next = rear;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted: Lab '%s' (%d computers)\n", lab_name, computers);
}

void delete_item(void) {
    Node* front;
    Lab deleted_data;

    if (rear == NULL) {
        printf("Error: Queue Underflow! The queue is empty.\n");
        return;
    }

    front = rear->next;
    deleted_data = front->data;

    if (front == rear) {
        rear = NULL;
    } else {
        rear->next = front->next;
    }

    free(front);

    printf("Deleted: Lab '%s' (%d computers)\n", deleted_data.name, deleted_data.num_computers);
}

void display(void) {
    Node* current;

    if (rear == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    Node* front = rear->next;
    current = front;

    printf("Queue elements (from Front to Rear):\n");
    
    do {
        printf("  - Lab: %s, Computers: %d\n", current->data.name, current->data.num_computers);
        current = current->next;
    } while (current != front);
}