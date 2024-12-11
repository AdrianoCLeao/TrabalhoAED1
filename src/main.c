#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/algorithms/selection-sort.h"
#include "../include/algorithms/heap-sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    ListaCircularDupla* lista = criarLista();

    char filePath[] = "../data/nomes_aleatorios.txt";

    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de nomes");
        return 1;
    }

    char nome[100];
    while (fgets(nome, sizeof(nome), file)) {
        char* newline = strchr(nome, '\n');
        if (newline) {
            *newline = '\0';
        }

        inserirInicio(lista, nome);
    }

    fclose(file);

    printf("Lista antes da ordenacao:\n");
    exibirLista(lista);

    selectionSort(lista);

    printf("Lista apos a ordenacao:\n");
    exibirLista(lista);

    destruirLista(lista);
    return 0;
}
