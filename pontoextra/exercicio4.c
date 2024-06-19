#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Número máximo de vértices

// Estrutura para um nó na lista de adjacência
struct Node {
    int vertex;
    struct Node* next;
};

// Estrutura para o grafo
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Estrutura para a fila
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Função para criar um nó
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Função para adicionar aresta
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona aresta do src para dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Adiciona aresta do dest para src, pois o grafo é não-direcionado
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Função para criar uma fila
struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Verifica se a fila está vazia
int isEmpty(struct Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Enfileira um elemento
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nFila cheia");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Desenfileira um elemento
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Fila vazia");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Função BFS
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visitando %d\n", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// Função principal
int main() {
    struct Graph* graph = createGraph(MAX);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    BFS(graph, 0);

    return 0;
}
