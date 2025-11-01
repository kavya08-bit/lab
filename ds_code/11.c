#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int roll_no) {
    if (top == MAX - 1) {
        printf("Error: Stack Overflow! Cannot push %d.\n", roll_no);
    } else {
        top = top + 1;
        stack[top] = roll_no;
        printf("%d was pushed onto the stack.\n", roll_no);
    }
}

int pop(void) {
    int popped_item;

    if (top == -1) {
        printf("Error: Stack Underflow! The stack is empty.\n");
        return -1;
    } else {
        popped_item = stack[top];
        top = top - 1;
        return popped_item;
    }
}

void display(void) {
    int i;
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements (from top to bottom):\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, roll_no, popped_item;

    printf("--- Stack Operations Menu ---\n");
    while (1) {
        printf("\n1. Push (Add a roll number)\n");
        printf("2. Pop (Remove a roll number)\n");
        printf("3. Display (Show all roll numbers)\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the roll number to push: ");
                if (scanf("%d", &roll_no) != 1) {
                     while (getchar() != '\n');
                     printf("Invalid input. Please enter an integer.\n");
                } else {
                    push(roll_no);
                }
                break;

            case 2:
                popped_item = pop();
                if (popped_item != -1) {
                    printf("Popped roll number is: %d\n", popped_item);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

