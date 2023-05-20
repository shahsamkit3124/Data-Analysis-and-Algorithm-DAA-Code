// Q11 Greedy Dijkstra

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int visited[MAX_VERTICES];

int get_min_vertex(int num_vertices) {
    int min_distance = INT_MAX, min_vertex;
    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i] && distance[i] < min_distance) {
            min_distance = distance[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void dijkstra(int start_vertex, int num_vertices) {
    // Initialize distance and visited arrays
    for (int i = 0; i < num_vertices; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[start_vertex] = 0;

    for (int i = 0; i < num_vertices; i++) {
        int current_vertex = get_min_vertex(num_vertices);
        visited[current_vertex] = 1;
        for (int j = 0; j < num_vertices; j++) {
            if (graph[current_vertex][j] && !visited[j] && distance[current_vertex] != INT_MAX &&
                distance[current_vertex] + graph[current_vertex][j] < distance[j]) {
                distance[j] = distance[current_vertex] + graph[current_vertex][j];
            }
        }
    }
}

int main() {
    int num_vertices, num_edges, start_vertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the edges and weights:\n");
    for (int i = 0; i < num_edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    dijkstra(start_vertex, num_vertices);

    printf("Shortest distances from the starting vertex:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d -> %d: %d\n", start_vertex, i, distance[i]);
    }

    return 0;
}

