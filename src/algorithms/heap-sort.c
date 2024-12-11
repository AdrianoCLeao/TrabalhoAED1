#include "../include/algorithms/heap-sort.h"
#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include <string.h>

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
    int i;
    if (!vetor || tamanho < 2) return;

    for (i = tamanho / 2 - 1; i >= 0; i--) {
        criaHeapVetorNumeros(vetor, i, tamanho);
    }

    for (i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        criaHeapVetorNumeros(vetor, 0, i);
    }
}

void criaHeapVetorCaracteres(char** vetor, int inicio, int fim) {
    int maior = inicio;
    int esquerda = 2 * inicio + 1;
    int direita = 2 * inicio + 2;

    if (esquerda < fim && strcmp(vetor[esquerda], vetor[maior]) > 0) {
        maior = esquerda;
    }

    if (direita < fim && strcmp(vetor[direita], vetor[maior]) > 0) {
        maior = direita;
    }

    if (maior != inicio) {
        char* temp = vetor[inicio];
        vetor[inicio] = vetor[maior];
        vetor[maior] = temp;

        criaHeapVetorCaracteres(vetor, maior, fim);
    }
}

void heapSortVetorCaracteres(char** vetor, int tamanho) {
    int i;

    if (!vetor || tamanho < 2) return;

    double inicio = obterTempoAtual();
    int quantidadeTrocas = 0;

    for (i = tamanho / 2 - 1; i >= 0; i--) {
        criaHeapVetorCaracteres(vetor, i, tamanho);
    }

    for (i = tamanho - 1; i > 0; i--) {
        char* temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        quantidadeTrocas++;

        criaHeapVetorCaracteres(vetor, 0, i);
    }

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);

    registrarDados("heap_sort_vetor", tamanho, tempoExecucao, quantidadeTrocas);
}

void criaHeapListaCaracteres(ListaCircularDupla* lista, int inicio, int tamanho) {
    int maior = inicio;
    int esquerda = 2 * inicio + 1;
    int direita = 2 * inicio + 2;

    No* noMaior = obterNoPorIndice(lista, maior);
    No* noEsquerda = (esquerda < tamanho) ? obterNoPorIndice(lista, esquerda) : NULL;
    No* noDireita = (direita < tamanho) ? obterNoPorIndice(lista, direita) : NULL;

    if (noEsquerda && strcmp(noEsquerda->nome, noMaior->nome) > 0) {
        maior = esquerda;
        noMaior = noEsquerda;
    }

    if (noDireita && strcmp(noDireita->nome, noMaior->nome) > 0) {
        maior = direita;
        noMaior = noDireita;
    }

    if (maior != inicio) {
        No* noAtual = obterNoPorIndice(lista, inicio);

        char* temp = noAtual->nome;
        noAtual->nome = noMaior->nome;
        noMaior->nome = temp;

        criaHeapListaCaracteres(lista, maior, tamanho);
    }
}

void heapSortListaCaracteres(ListaCircularDupla* lista) {
    int i;
    
    if (!lista || lista->tamanho < 2) return;

    double inicio = obterTempoAtual();
    int quantidadeTrocas = 0;

    int tamanho = lista->tamanho;

    for (i = tamanho / 2 - 1; i >= 0; i--) {
        criaHeapListaCaracteres(lista, i, tamanho);
    }

    for (i = tamanho - 1; i > 0; i--) {
        No* noInicio = obterNoPorIndice(lista, 0);
        No* noFinal = obterNoPorIndice(lista, i);

        char* temp = noInicio->nome;
        noInicio->nome = noFinal->nome;
        noFinal->nome = temp;
        quantidadeTrocas++;

        criaHeapListaCaracteres(lista, 0, i);
    }

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);

    registrarDados("heap_sort_lista", lista->tamanho, tempoExecucao, quantidadeTrocas);
}