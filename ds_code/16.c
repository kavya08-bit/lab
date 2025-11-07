#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int empNum;
    struct Node* next;
};

struct QueueLinkedList {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct QueueLinkedList *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct QueueLinkedList *q) {
    return q->front == NULL;
}

void insert(struct QueueLinkedList *q, int empNum) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert.\n");
        return;
    }
    newNode->empNum = empNum;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Inserted employee #%d\n", empNum);
}

void del(struct QueueLinkedList *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Cannot delete.\n");
        return;
    }

    struct Node* temp = q->front;
    int empNum = temp->empNum;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    printf("Deleted employee #%d\n", empNum);
}

void display(struct QueueLinkedList *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Employee numbers in queue (Front to Rear): ");
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->empNum);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct QueueLinkedList empQueue;
    initQueue(&empQueue);

    display(&empQueue);
    insert(&empQueue, 101);
    insert(&empQueue, 102);
    insert(&empQueue, 103);
    display(&empQueue);

    del(&empQueue);
    display(&empQueue);

    insert(&empQueue, 104);
    del(&empQueue);
    del(&empQueue);
    del(&empQueue);
    display(&empQueue);

    del(&empQueue);
    
    return 0;
}
