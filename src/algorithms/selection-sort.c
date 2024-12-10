#include "../include/algorithms/selection-sort.h"
#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/utils/utils.h"
#include <string.h>
#include <time.h>

void selectionSortVetorNumeros(int* vetor, int tamanho) {
    if (!vetor || tamanho < 2) return;
    
    for (int i = 0;  i < tamanho - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

void selectionSortVetorCaracteres(char** vetor, int tamanho) {
    if (!vetor || tamanho < 2) return;

    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (strcmp(vetor[j], vetor[menor]) < 0) {
                menor = j;
            }
        }

        if (menor != i) {
            char* temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

void selectionSort(ListaCircularDupla* lista) {
    if (!lista || lista->tamanho < 2) return;

    double inicio = obterTempoAtual();
    int quantidadeTrocas = 0;

    No* atual = lista->inicio;
    do {
        No* menor = atual;
        No* proximo = atual->proximo;
        while (proximo != lista->inicio) {
            if (strcmp(proximo->nome, menor->nome) < 0) {
                menor = proximo;
            }
            proximo = proximo->proximo;
        }

        if (menor != atual) {
            char* temp = atual->nome;
            atual->nome = menor->nome;
            menor->nome = temp;
            quantidadeTrocas++;
        }

        atual = atual->proximo;
    } while (atual != lista->inicio);

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("selection_sort", tempoExecucao, quantidadeTrocas);
}

