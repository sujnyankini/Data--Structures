#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue implementation
typedef struct {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

void enqueue(Queue *q, int value) {
    q->items[q->rear++] = value;
}

int dequeue(Queue *q) {
    return q->items[q->front++];
}


int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

int vertices, edges;


void bfs(int startVertex) {
    Queue q;
    q.front = 0;
    q.rear = 0;

    visited[startVertex] = 1;
    printf("BFS traversal starting from vertex %d: ", startVertex);

    enqueue(&q, startVertex);

    while (q.front != q.rear) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        int i;

        for ( i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Initialize graph and visited array
    int i;
    for ( i = 0; i < vertices; i++) {
        visited[i] = 0;
        int j;
        for ( j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges of the graph
    printf("Enter the edges (format: vertex1 vertex2):\n");
    
    for ( i = 0; i < edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1; // Assuming an undirected graph
    }

    // Choose the starting vertex for BFS
    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(startVertex);

    return 0;
}

