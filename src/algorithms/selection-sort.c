#include "../include/algorithms/selection-sort.h"
#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/utils/utils.h"
#include <string.h>
#include <time.h>

void selectionSortVetorNumeros(int* vetor, int tamanho, int crescente) {
    int i, j;
    if (!vetor || tamanho < 2) return;

    for (i = 0; i < tamanho - 1; i++) {
        int index = i;

        for (j = i + 1; j < tamanho; j++) {
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
        }
    }
}

void selectionSortVetorCaracteres(char** vetor, int tamanho, int crescente) {
    int i, j;
    if (!vetor || tamanho < 2) return;

    for (i = 0; i < tamanho - 1; i++) {
        int index = i;

        for (j = i + 1; j < tamanho; j++) {
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
        }
    }
}

void selectionSortListaCaracteres(ListaCircularDupla* lista, int crescente) {
    if (!lista || lista->tamanho < 2) return;

    No* atual = lista->inicio;
    do {
        No* extremum = atual;
        No* proximo = atual->proximo;

        while (proximo != lista->inicio) {
            if (crescente) {
                if (strcmp(proximo->dado, extremum->dado) < 0) {
                    extremum = proximo;
                }
            } else {
                if (strcmp(proximo->dado, extremum->dado) > 0) {
                    extremum = proximo;
                }
            }
            proximo = proximo->proximo;
        }

        if (extremum != atual) {
            char* temp = atual->dado;
            atual->dado = extremum->dado;
            extremum->dado = temp;
        }

        atual = atual->proximo;
    } while (atual != lista->inicio);
}

void selectionSortListaNumeros(ListaCircularDupla* lista, int crescente) {
    if (!lista || lista->tamanho < 2) return;

    No* atual = lista->inicio;
    do {
        No* extremum = atual;
        No* proximo = atual->proximo;

        while (proximo != lista->inicio) {
            if (crescente) {
                if (*(int*)proximo->dado < *(int*)extremum->dado) {
                    extremum = proximo;
                }
            } else {
                if (*(int*)proximo->dado > *(int*)extremum->dado) {
                    extremum = proximo;
                }
            }
            proximo = proximo->proximo;
        }

        if (extremum != atual) {
            int temp = *(int*)atual->dado;
            *(int*)atual->dado = *(int*)extremum->dado;
            *(int*)extremum->dado = temp;
        }

        atual = atual->proximo;
    } while (atual != lista->inicio);
}