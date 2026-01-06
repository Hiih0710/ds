#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   /* Turbo C ke liye; modern compiler me optional */

#define MAX 10   /* Maximum number of vertices */

/* Program that performs Depth First Search (DFS). */

int adj[MAX][MAX];   /* Adjacency matrix */
int visited[MAX];
int vertices;

/* ---------- Add Edge ---------- */
void addEdge(int src, int dest) {
    adj[src][dest] = 1;
    adj[dest][src] = 1;  /* For undirected graph */
}

/* ---------- Display Graph ---------- */
void displayGraph() {
    int i, j;

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

/* ---------- DFS Function ---------- */
void DFS(int vertex) {
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < vertices; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

/* ---------- Main Function ---------- */
int main() {
    int choice, src, dest, start;
    int i, j;
    int running = 1;

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);

    /* Initialize adjacency matrix and visited array */
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    while (running) {
        printf("\n===== GRAPH MENU =====\n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. Perform DFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter source and destination vertex: ");
            scanf("%d %d", &src, &dest);
            if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                addEdge(src, dest);
            } else {
                printf("Invalid vertices!\n");
            }
            break;

        case 2:
            displayGraph();
            break;

        case 3:
            for (i = 0; i < vertices; i++) {
                visited[i] = 0;
            }

            printf("Enter starting vertex: ");
            scanf("%d", &start);
            if (start >= 0 && start < vertices) {
                printf("\nDFS Traversal starting from vertex %d:\n", start);
                DFS(start);
                printf("\n");
            } else {
                printf("Invalid vertex!\n");
            }
            break;

        case 4:
            printf("Exiting program...\n");
            running = 0;     /* loop se bahar aa jao */
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
