#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int numVertices;
int visited[MAX];

void dfsRecursive(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfsRecursive(i);
        }
    }
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

void dfsTraversal(int startVertex) {
    if (startVertex >= numVertices) {
        printf("Error: Invalid start vertex.\n");
        return;
    }

    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from %d: ", startVertex);
    
    dfsRecursive(startVertex);
    
    for(int i = 0; i < numVertices; i++) {
        if(visited[i] == 0) {
            dfsRecursive(i);
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
        printf("2. Run DFS Traversal\n");
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
                printf("Enter the start vertex for DFS (0 to %d): ", numVertices - 1);
                if (scanf("%d", &start) != 1) {
                    while (getchar() != '\n');
                    printf("Invalid input. Please enter one number.\n");
                } else {
                    dfsTraversal(start);
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
