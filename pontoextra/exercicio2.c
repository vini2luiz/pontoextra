#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista de adjacências
typedef struct AdjListNode {
  int destino;
  struct AdjListNode *prox;
} AdjListNode;

// Estrutura para representar a lista de adjacências de um vértice
typedef struct AdjList {
  AdjListNode *cabecalho;
} AdjList;

// Estrutura para representar o grafo
typedef struct Grafo {
  int numVertices;
  AdjList *arrayListaAdj;
} Grafo;

// Função para criar um novo nó da lista de adjacências
AdjListNode *novoNoListaAdj(int destino) {
  AdjListNode *novoNo = (AdjListNode *)malloc(sizeof(AdjListNode));
  novoNo->destino = destino;
  novoNo->prox = NULL;
  return novoNo;
}

// Função para criar um grafo com numVertices vértices
Grafo *criarGrafo(int numVertices) {
  Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
  grafo->numVertices = numVertices;

  // Aloca memória para a lista de adjacências
  grafo->arrayListaAdj = (AdjList *)malloc(numVertices * sizeof(AdjList));

  // Inicializa cada lista de adjacências como vazia
  for (int i = 0; i < numVertices; ++i)
    grafo->arrayListaAdj[i].cabecalho = NULL;

  return grafo;
}

// Função para adicionar uma aresta no grafo
void adicionarAresta(Grafo *grafo, int origem, int destino) {
  // Adiciona aresta de origem para destino
  AdjListNode *novoNo = novoNoListaAdj(destino);
  novoNo->prox = grafo->arrayListaAdj[origem].cabecalho;
  grafo->arrayListaAdj[origem].cabecalho = novoNo;

  // Para grafo não-direcionado, adicionar também de destino para origem
  novoNo = novoNoListaAdj(origem);
  novoNo->prox = grafo->arrayListaAdj[destino].cabecalho;
  grafo->arrayListaAdj[destino].cabecalho = novoNo;
}

// Função para remover uma aresta do grafo
void removerAresta(Grafo *grafo, int origem, int destino) {
  // Encontrar e remover a aresta de origem para destino
  AdjListNode *atual = grafo->arrayListaAdj[origem].cabecalho;
  AdjListNode *anterior = NULL;

  while (atual != NULL && atual->destino != destino) {
    anterior = atual;
    atual = atual->prox;
  }

  // Se a aresta foi encontrada, remove-a
  if (atual != NULL) {
    if (anterior != NULL)
      anterior->prox = atual->prox;
    else
      grafo->arrayListaAdj[origem].cabecalho = atual->prox;

    free(atual);
  }

  // Encontrar e remover a aresta de destino para origem (para grafo
  // não-direcionado)
  atual = grafo->arrayListaAdj[destino].cabecalho;
  anterior = NULL;

  while (atual != NULL && atual->destino != origem) {
    anterior = atual;
    atual = atual->prox;
  }

  // Se a aresta foi encontrada, remove-a
  if (atual != NULL) {
    if (anterior != NULL)
      anterior->prox = atual->prox;
    else
      grafo->arrayListaAdj[destino].cabecalho = atual->prox;

    free(atual);
  }
}

// Função para imprimir o grafo
void imprimirGrafo(Grafo *grafo) {
  for (int i = 0; i < grafo->numVertices; ++i) {
    AdjListNode *atual = grafo->arrayListaAdj[i].cabecalho;
    printf("Lista de adjacências do vértice %d\n cabeçalho ", i);
    while (atual) {
      printf("-> %d", atual->destino);
      atual = atual->prox;
    }
    printf("\n");
  }
}

// Função principal para demonstrar a remoção de aresta
int main() {
  int numVertices = 5;
  Grafo *grafo = criarGrafo(numVertices);

  adicionarAresta(grafo, 0, 1);
  adicionarAresta(grafo, 0, 4);
  adicionarAresta(grafo, 1, 2);
  adicionarAresta(grafo, 1, 3);
  adicionarAresta(grafo, 1, 4);
  adicionarAresta(grafo, 2, 3);
  adicionarAresta(grafo, 3, 4);

  printf("Grafo original:\n");
  imprimirGrafo(grafo);

  removerAresta(grafo, 1, 3);
  removerAresta(grafo, 0, 4);

  printf("\nGrafo após remoção de arestas:\n");
  imprimirGrafo(grafo);

  return 0;
}
