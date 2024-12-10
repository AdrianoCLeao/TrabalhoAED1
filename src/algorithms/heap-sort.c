#include "../include/algorithms/heap-sort.h"

void criaHeapVetorNumeros(int* vetor, int inicio, int fim) {
    int maior = inicio;
    int esquerda = 2 * inicio + 1;
    int direita = 2 * inicio + 2;

    if (esquerda < fim && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    if (direita < fim && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    if (maior != inicio) {
        int temp = vetor[inicio];
        vetor[inicio] = vetor[maior];
        vetor[maior] = temp;

        criaHeapVetorNumeros(vetor, maior, fim);
    }
}

void heapSortVetorNumeros(int* vetor, int tamanho) {
    if (!vetor || tamanho < 2) return;

    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        criaHeapVetorNumeros(vetor, i, tamanho);
    }

    for (int i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        criaHeapVetorNumeros(vetor, 0, i);
    }
}