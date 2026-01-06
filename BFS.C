#include <stdio.h>
#include <stdlib.h>

#define MAX 10   /* maximum number of vertices */

int adj[MAX][MAX];   /* adjacency matrix */
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int vertices;

/* ---------- Queue Operations ---------- */
void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = v;
}

int dequeue() {
    int x;
    if (front == -1 || front > rear)
        return -1;
    x = queue[front];
    front = front + 1;
    return x;
}

int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    return 0;
}

/* ---------- Add Edge ---------- */
void addEdge(int src, int dest) {
    adj[src][dest] = 1;
    adj[dest][src] = 1;  /* undirected graph */
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

/* ---------- BFS ---------- */
void BFS(int start) {
    int i, current;

    for (i = 0; i < vertices; i++)
        visited[i] = 0;

    front = -1;
    rear = -1;
    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Traversal starting from vertex %d:\n", start);

    while (!isEmpty()) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

/* ---------- Main Function ---------- */
int main() {
    int choice, src, dest, start;
    int i, j;
    int running = 1;

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);

    /* Initialize adjacency matrix */
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    while (running) {
        printf("\n===== GRAPH MENU =====\n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. Perform BFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter source and destination vertex: ");
            scanf("%d %d", &src, &dest);
            if (src >= 0 && src < vertices && dest >= 0 && dest < vertices)
                addEdge(src, dest);
            else
                printf("Invalid vertices!\n");
            break;

        case 2:
            displayGraph();
            break;

        case 3:
            printf("Enter starting vertex: ");
            scanf("%d", &start);
            if (start >= 0 && start < vertices)
                BFS(start);
            else
                printf("Invalid vertex!\n");
            break;

        case 4:
            printf("Exiting program...\n");
            running = 0;   /* loop se bahar nikalne ke liye */
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;   /* ab ye reachable hai, warning nahi aayegi */
}
