#include "../include/algorithms/selection-sort.h"
#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/utils/utils.h"
#include <string.h>
#include <time.h>

void selectionSortVetorNumeros(int* vetor, int tamanho) {
    int i, j;
    if (!vetor || tamanho < 2) return;

    double inicio = obterTempoAtual();
    int quantidadeTrocas = 0;

    for (i = 0; i < tamanho - 1; i++) {
        int menor = i;

        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
            quantidadeTrocas++;
        }
    }

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);

    registrarDados("selection_sort_numeros", tamanho, tempoExecucao, quantidadeTrocas);
}

void selectionSortVetorCaracteres(char** vetor, int tamanho) {
    int i, j;
    if (!vetor || tamanho < 2) return;

    double inicio = obterTempoAtual();
    int quantidadeTrocas = 0;

    for (i = 0; i < tamanho - 1; i++) {
        int menor = i;

        for (j = i + 1; j < tamanho; j++) {
            if (strcmp(vetor[j], vetor[menor]) < 0) {
                menor = j;
            }
        }

        if (menor != i) {
            char* temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
            quantidadeTrocas++;
        }
    }

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);

    registrarDados("selection_sort_caracteres", tamanho, tempoExecucao, quantidadeTrocas);
}

void selectionSortListaCaracteres(ListaCircularDupla* lista) {
    if (!lista || lista->tamanho < 2) return;

    double inicio = obterTempoAtual();
    int quantidadeTrocas = 0;

    No* atual = lista->inicio;
    do {
        No* menor = atual;
        No* proximo = atual->proximo;
        while (proximo != lista->inicio) {
            if (strcmp(proximo->dado, menor->dado) < 0) {
                menor = proximo;
            }
            proximo = proximo->proximo;
        }

        if (menor != atual) {
            char* temp = atual->dado;
            atual->dado = menor->dado;
            menor->dado = temp;
            quantidadeTrocas++;
        }

        atual = atual->proximo;
    } while (atual != lista->inicio);

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);

    registrarDados("selection_sort", lista->tamanho, tempoExecucao, quantidadeTrocas);
}

void selectionSortListaNumeros(ListaCircularDupla* lista) {
    if (!lista || lista->tamanho < 2) return;

    No* atual = lista->inicio;
    do {
        No* menor = atual;
        No* proximo = atual->proximo;
        while (proximo != lista->inicio) {
            if (*(int*)proximo->dado < *(int*)menor->dado) {
                menor = proximo;
            }
            proximo = proximo->proximo;
        }

        if (menor != atual) {
            int temp = *(int*)atual->dado;
            *(int*)atual->dado = *(int*)menor->dado;
            *(int*)menor->dado = temp;
        }

        atual = atual->proximo;
    } while (atual != lista->inicio);
}
