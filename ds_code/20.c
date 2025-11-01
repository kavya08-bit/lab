#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int numVertices;

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = item;
}

int dequeue(void) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue[front];
    front = front + 1;
    return item;
}

int isEmpty(void) {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

void insertEdge(int u, int v) {
    if (u >= numVertices || v >= numVertices) {
        printf("Error: Invalid vertex number.\n");
        return;
    }
    graph[u][v] = 1;
    graph[v][u] = 1;
    printf("Edge inserted between %d and %d.\n", u, v);
}

void bfsTraversal(int startVertex) {
    if (startVertex >= numVertices) {
        printf("Error: Invalid start vertex.\n");
        return;
    }

    int visited[MAX] = {0};

    front = -1;
    rear = -1;

    visited[startVertex] = 1;
    enqueue(startVertex);

    printf("BFS Traversal starting from %d: ", startVertex);

    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

void initializeGraph(void) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }
}

int main() {
    int choice, u, v, start;

    initializeGraph();

    printf("Enter the number of vertices in the graph (e.g., 5): ");
    scanf("%d", &numVertices);
    printf("Graph created with %d vertices (numbered 0 to %d).\n", numVertices, numVertices - 1);

    while (1) {
        printf("\n--- Graph Menu ---\n");
        printf("1. Insert Edge (Insertion)\n");
        printf("2. Run BFS Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the two vertices to connect (e.g., 0 1): ");
                if (scanf("%d %d", &u, &v) != 2) {
                    while (getchar() != '\n');
                    printf("Invalid input. Please enter two numbers.\n");
                } else {
                    insertEdge(u, v);
                }
                break;

            case 2:
                printf("Enter the start vertex for BFS (0 to %d): ", numVertices - 1);
                if (scanf("%d", &start) != 1) {
                    while (getchar() != '\n');
                    printf("Invalid input. Please enter one number.\n");
                } else {
                    bfsTraversal(start);
                }
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    }

    return 0;
}