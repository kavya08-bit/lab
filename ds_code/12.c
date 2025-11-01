#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int roll_no;
    char name[50];
} Student;

typedef struct Node {
    Student data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(Student s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Stack Overflow (Heap memory full). Cannot push.\n");
        return;
    }

    newNode->data = s;
    newNode->next = top;
    top = newNode;

    printf("Pushed: Roll %d, Name %s\n", s.roll_no, s.name);
}

Student pop(void) {
    Node* temp;
    Student popped_data;

    if (top == NULL) {
        printf("Error: Stack Underflow! The stack is empty.\n");
        Student emptyStudent = {-1, "N/A"};
        return emptyStudent;
    }

    popped_data = top->data;
    temp = top;
    top = top->next;
    free(temp);

    return popped_data;
}

void display(void) {
    Node* current;

    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements (from top to bottom):\n");
        current = top;
        while (current != NULL) {
            printf("  Roll: %d, Name: %s\n", current->data.roll_no, current->data.name);
            current = current->next;
        }
    }
}

int main() {
    int choice;
    Student s;
    Student popped_student;

    printf("--- Stack Operations (Linked List) ---\n");
    while (1) {
        printf("\n1. Push (Add a student)\n");
        printf("2. Pop (Remove a student)\n");
        printf("3. Display (Show all students)\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the roll number: ");
                scanf("%d", &s.roll_no);

                while (getchar() != '\n'); 

                printf("Enter the name: ");
                fgets(s.name, 50, stdin);
                s.name[strcspn(s.name, "\n")] = '\0';

                push(s);
                break;

            case 2:
                popped_student = pop();
                if (popped_student.roll_no != -1) { 
                    printf("Popped student:\n");
                    printf("  Roll: %d, Name: %s\n", popped_student.roll_no, popped_student.name);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                while(top != NULL) {
                    Node* temp = top;
                    top = top->next;
                    free(temp);
                }
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

