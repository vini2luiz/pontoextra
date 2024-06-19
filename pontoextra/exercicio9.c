#include <stdio.h>

// Função para implementar o Shell Sort
void shellSort(int arr[], int n) {
    // Inicializa o intervalo (gap)
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Realiza a ordenação por inserção para este intervalo
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
