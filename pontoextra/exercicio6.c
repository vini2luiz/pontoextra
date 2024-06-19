#include <stdio.h>

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para implementar o Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Últimos i elementos já estão no lugar
        for (int j = 0; j < n-i-1; j++) {
            // Troca se o elemento encontrado for maior que o próximo elemento
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array original: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
