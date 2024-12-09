#include "../include/algorithms/selection-sort.h"
#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include <string.h>

void selectionSort(ListaCircularDupla* lista) {
    if (!lista || lista->tamanho < 2) return;

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
        }

        atual = atual->proximo;
    } while (atual != lista->inicio);
}
