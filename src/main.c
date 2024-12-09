#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/algorithms/selection-sort.h"
#include <stdio.h>

int main() {
    ListaCircularDupla* lista = criarLista();

    inserirInicio(lista, "Maria");
    inserirInicio(lista, "João");
    inserirInicio(lista, "Ana");
    inserirInicio(lista, "Carlos");

    printf("Lista antes da ordenação:\n");
    exibirLista(lista);

    selectionSort(lista);

    printf("Lista após a ordenação:\n");
    exibirLista(lista);

    destruirLista(lista);
    return 0;
}
