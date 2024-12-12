#include "../include/algorithms/selection-sort.h"
#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/utils/utils.h"
#include <string.h>
#include <time.h>

void selectionSortVetorNumeros(int* vetor, int tamanho, int crescente) {
    if (!vetor || tamanho < 2) return;

    double inicio = obterTempoAtual();
    int trocas = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        int index = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (crescente) {
                if (vetor[j] < vetor[index]) {
                    index = j;
                }
            } else {
                if (vetor[j] > vetor[index]) {
                    index = j;
                }
            }
        }

        if (index != i) {
            int temp = vetor[i];
            vetor[i] = vetor[index];
            vetor[index] = temp;
            trocas++;
        }
    }

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("selection_sort_vetor_numeros", tamanho, tempoExecucao, trocas);
}

void selectionSortVetorCaracteres(char** vetor, int tamanho, int crescente) {
    if (!vetor || tamanho < 2) return;

    double inicio = obterTempoAtual();
    int trocas = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        int index = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (crescente) {
                if (strcmp(vetor[j], vetor[index]) < 0) {
                    index = j;
                }
            } else {
                if (strcmp(vetor[j], vetor[index]) > 0) {
                    index = j;
                }
            }
        }

        if (index != i) {
            char* temp = vetor[i];
            vetor[i] = vetor[index];
            vetor[index] = temp;
            trocas++;
        }
    }

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("selection_sort_vetor_caracteres", tamanho, tempoExecucao, trocas);
}

void selectionSortListaCaracteres(ListaCircularDupla* lista, int crescente) {
    if (!lista || lista->tamanho < 2) return;

    double inicio = obterTempoAtual();
    int trocas = 0;

    No* atual = lista->inicio;
    do {
        No* menor = atual;
        No* proximo = atual->proximo;

        while (proximo != lista->inicio) {
            if (crescente) {
                if (strcmp(proximo->dado, menor->dado) < 0) {
                    menor = proximo;
                }
            } else {
                if (strcmp(proximo->dado, menor->dado) > 0) {
                    menor = proximo;
                }
            }
            proximo = proximo->proximo;
        }

        if (menor != atual) {
            char* temp = atual->dado;
            atual->dado = menor->dado;
            menor->dado = temp;
            trocas++;
        }

        atual = atual->proximo;
    } while (atual != lista->inicio);

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("selection_sort_lista_caracteres", lista->tamanho, tempoExecucao, trocas);
}

void selectionSortListaNumeros(ListaCircularDupla* lista, int crescente) {
    if (!lista || lista->tamanho < 2) return;

    double inicio = obterTempoAtual();
    int trocas = 0;

    No* atual = lista->inicio;
    do {
        No* menor = atual;
        No* proximo = atual->proximo;

        while (proximo != lista->inicio) {
            if (crescente) {
                if (*(int*)proximo->dado < *(int*)menor->dado) {
                    menor = proximo;
                }
            } else {
                if (*(int*)proximo->dado > *(int*)menor->dado) {
                    menor = proximo;
                }
            }
            proximo = proximo->proximo;
        }

        if (menor != atual) {
            int temp = *(int*)atual->dado;
            *(int*)atual->dado = *(int*)menor->dado;
            *(int*)menor->dado = temp;
            trocas++;
        }

        atual = atual->proximo;
    } while (atual != lista->inicio);

    double fim = obterTempoAtual();
    double tempoExecucao = calcularTempo(inicio, fim);
    registrarDados("selection_sort_lista_numeros", lista->tamanho, tempoExecucao, trocas);
}
