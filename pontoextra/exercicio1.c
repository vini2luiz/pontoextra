#include <stdio.h>

#define MAX_VERTICES 100

int grafo[MAX_VERTICES][MAX_VERTICES];
int numVertices;

// Função para inserir uma rua entre duas interseções
void inserirRua(int origem, int destino) {
  // Verifica se a rua já existe
  if (grafo[origem][destino] == 1 || grafo[destino][origem] == 1) {
    printf("A rua entre %d e %d já existe.\n", origem, destino);
  } else {
    // Insere a rua nos dois sentidos
    grafo[origem][destino] = 1;
    grafo[destino][origem] = 1;
    printf("Rua inserida entre %d e %d.\n", origem, destino);
  }
}

// Função principal para demonstrar a inserção de rua
int main() {
  int opcao, origem, destino;
  numVertices = 5; // Exemplo: grafo com 5 interseções

  // Inicializa matriz de adjacências com zeros (sem ruas)
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      grafo[i][j] = 0;
    }
  }

  // Exemplo de inserção de ruas
  inserirRua(0, 1);
  inserirRua(1, 2);
  inserirRua(2, 3);

  // Exemplo: tentar inserir uma rua já existente
  inserirRua(1, 0);

  // Exemplo: inserir uma nova rua
  inserirRua(3, 4);

  // Mostra a matriz de adjacências atual
  printf("\nMatriz de Adjacências:\n");
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      printf("%d ", grafo[i][j]);
    }
    printf("\n");
  }

  return 0;
}
