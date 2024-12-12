#include "../include/algorithms/heap-sort.h"
#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/utils/utils.h"
#include <string.h>
#include <stdlib.h>

void criaHeapVetorNumeros(int* vetor, int inicio, int fim, int crescente, int* trocas) {
    int maiorMenor = inicio;
    int esquerda = 2 * inicio + 1;
    int direita = 2 * inicio + 2;

    if (crescente) {
        if (esquerda < fim && vetor[esquerda] > vetor[maiorMenor]) {
            maiorMenor = esquerda;
        }
        if (direita < fim && vetor[direita] > vetor[maiorMenor]) {
            maiorMenor = direita;
        }
    } else {
        if (esquerda < fim && vetor[esquerda] < vetor[maiorMenor]) {
            maiorMenor = esquerda;
        }
        if (direita < fim && vetor[direita] < vetor[maiorMenor]) {
            maiorMenor = direita;
        }
    }

    if (maiorMenor != inicio) {
        int temp = vetor[inicio];
        vetor[inicio] = vetor[maiorMenor];
        vetor[maiorMenor] = temp;
        (*trocas)++;

        criaHeapVetorNumeros(vetor, maiorMenor, fim, crescente, trocas);
    }
}

void heapSortVetorNumeros(int* vetor, int tamanho, int crescente) {
    if (!vetor || tamanho < 2) return;

    double inicio = obterTempoAtual();
    int trocas = 0;

    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        criaHeapVetorNumeros(vetor, i, tamanho, crescente, &trocas);
    }

    for (int i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        trocas++;

        criaHeapVetorNumeros(vetor, 0, i, crescente, &trocas);
    }

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("heap_sort_vetor_numeros", tamanho, tempoExecucao, trocas);
}

void criaHeapVetorCaracteres(char** vetor, int inicio, int fim, int crescente, int* trocas) {
    int maiorMenor = inicio;
    int esquerda = 2 * inicio + 1;
    int direita = 2 * inicio + 2;

    if (crescente) {
        if (esquerda < fim && strcmp(vetor[esquerda], vetor[maiorMenor]) > 0) {
            maiorMenor = esquerda;
        }
        if (direita < fim && strcmp(vetor[direita], vetor[maiorMenor]) > 0) {
            maiorMenor = direita;
        }
    } else {
        if (esquerda < fim && strcmp(vetor[esquerda], vetor[maiorMenor]) < 0) {
            maiorMenor = esquerda;
        }
        if (direita < fim && strcmp(vetor[direita], vetor[maiorMenor]) < 0) {
            maiorMenor = direita;
        }
    }

    if (maiorMenor != inicio) {
        char* temp = vetor[inicio];
        vetor[inicio] = vetor[maiorMenor];
        vetor[maiorMenor] = temp;
        (*trocas)++;

        criaHeapVetorCaracteres(vetor, maiorMenor, fim, crescente, trocas);
    }
}

void heapSortVetorCaracteres(char** vetor, int tamanho, int crescente) {
    if (!vetor || tamanho < 2) return;

    double inicio = obterTempoAtual();
    int trocas = 0;

    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        criaHeapVetorCaracteres(vetor, i, tamanho, crescente, &trocas);
    }

    for (int i = tamanho - 1; i > 0; i--) {
        char* temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        trocas++;

        criaHeapVetorCaracteres(vetor, 0, i, crescente, &trocas);
    }

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("heap_sort_vetor_caracteres", tamanho, tempoExecucao, trocas);
}

void heapSortListaCaracteres(ListaCircularDupla* lista, int crescente) {
    if (!lista || lista->tamanho < 2) return;

    double inicio = obterTempoAtual();
    int trocas = 0;
    int tamanho = lista->tamanho;

    char** vetor = (char**) malloc(tamanho * sizeof(char*));
    if (!vetor) return;

    No* atual = lista->inicio;
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = atual->dado;
        atual = atual->proximo;
    }

    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        criaHeapVetorCaracteres(vetor, i, tamanho, crescente, &trocas);
    }

    for (int i = tamanho - 1; i > 0; i--) {
        char* temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        trocas++;

        criaHeapVetorCaracteres(vetor, 0, i, crescente, &trocas);
    }

    atual = lista->inicio;
    for (int i = 0; i < tamanho; i++) {
        atual->dado = vetor[i];
        atual = atual->proximo;
    }

    free(vetor);

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("heap_sort_lista_caracteres", tamanho, tempoExecucao, trocas);
}

void heapSortListaNumeros(ListaCircularDupla* lista, int crescente) {
    if (!lista || lista->tamanho < 2) return;

    double inicio = obterTempoAtual();
    int trocas = 0;
    int tamanho = lista->tamanho;
    int* vetor = (int*) malloc(tamanho * sizeof(int));
    if (!vetor) return;

    No* atual = lista->inicio;
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *(int*) atual->dado;
        atual = atual->proximo;
    }

    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        criaHeapVetorNumeros(vetor, i, tamanho, crescente, &trocas);
    }

    for (int i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        trocas++;

        criaHeapVetorNumeros(vetor, 0, i, crescente, &trocas);
    }

    atual = lista->inicio;
    for (int i = 0; i < tamanho; i++) {
        *(int*) atual->dado = vetor[i];
        atual = atual->proximo;
    }

    free(vetor);

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("heap_sort_lista_numeros", tamanho, tempoExecucao, trocas);
}