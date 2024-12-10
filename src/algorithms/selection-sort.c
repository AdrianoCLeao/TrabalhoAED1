#include "../include/algorithms/selection-sort.h"
#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/utils/utils.h"
#include <string.h>
#include <time.h>

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

