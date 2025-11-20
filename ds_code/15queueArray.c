#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert(int emp_no);
void delete_item(void);
void display(void);

int main() {
    int choice, emp_no;

    printf("--- Queue Operations Menu (Array) ---\n");
    while (1) {
        printf("\n1. Insert (Enqueue) an Employee Number\n");
        printf("2. Delete (Dequeue) an Employee Number\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the employee number to insert: ");
                if (scanf("%d", &emp_no) != 1) {
                     while (getchar() != '\n');
                     printf("Invalid input. Please enter an integer.\n");
                } else {
                    insert(emp_no);
                }
                break;

            case 2:
                delete_item();
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

void insert(int emp_no) {
    if ((rear + 1) % MAX == front) {
        printf("Error: Queue Overflow! Cannot insert %d.\n", emp_no);
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue_array[rear] = emp_no;
    printf("%d was inserted into the queue.\n", emp_no);
}

void delete_item(void) {
    int deleted_emp_no;

    if (front == -1) {
        printf("Error: Queue Underflow! The queue is empty.\n");
        return;
    }

    deleted_emp_no = queue_array[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    printf("%d was deleted from the queue.\n", deleted_emp_no);
}

void display(void) {
    int i;
    if (front == -1) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Queue elements (from Front to Rear):\n");
    
    for (i = front; ; i = (i + 1) % MAX) {
        printf("%d\n", queue_array[i]);
        
        if (i == rear) {
            break;
        }
    }
}
