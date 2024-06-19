#include <stdio.h>
#include <limits.h>

#define MAX 100  // Número máximo de vértices
#define INF INT_MAX  // Representação de infinito

// Função para encontrar o vértice com a menor distância
int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Função de Dijkstra para encontrar o caminho mais curto de src para todos os outros vértices
void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX];  // Array de distâncias
    int visited[MAX];  // Array de vértices visitados

    // Inicializa todas as distâncias como INFINITO e visited[] como falso
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distância do vértice origem para ele mesmo é sempre 0
    dist[src] = 0;

    // Encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    //
