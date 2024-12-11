#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/algorithms/selection-sort.h"
#include "../include/algorithms/heap-sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define PATH_SEPARATOR "\\"
#else
    #define PATH_SEPARATOR "/"
#endif

void construirCaminho(char* basePath, const char* relativePath, char* result) {
    snprintf(result, 1024, "%s%s%s", basePath, PATH_SEPARATOR, relativePath);
}

int main() {
    ListaCircularDupla* listaSelection = criarLista();
    ListaCircularDupla* listaHeap = criarLista();

    char basePath[1024];
    char filePath[1024];
    char sortedFilePathSelection[1024];
    char sortedFilePathHeap[1024];

    if (getcwd(basePath, sizeof(basePath)) == NULL) {
        perror("Erro ao obter o diretório atual");
        return 1;
    }

    construirCaminho(basePath, "data/nomes_aleatorios.txt", filePath);
    construirCaminho(basePath, "data/nomes_ordenados_selection.txt", sortedFilePathSelection);
    construirCaminho(basePath, "data/nomes_ordenados_heap.txt", sortedFilePathHeap);

    printf("Tentando abrir o arquivo: %s\n", filePath);

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

        inserirInicio(listaSelection, nome);
        inserirInicio(listaHeap, nome);
    }

    fclose(file);

    selectionSort(listaSelection);

    FILE* sortedFileSelection = fopen(sortedFilePathSelection, "w");
    if (sortedFileSelection == NULL) {
        perror("Erro ao criar o arquivo de lista ordenada (Selection Sort)");
        destruirLista(listaSelection);
        destruirLista(listaHeap);
        return 1;
    }

    No* atual = listaSelection->inicio;
    do {
        fprintf(sortedFileSelection, "%s\n", atual->nome);
        atual = atual->proximo;
    } while (atual != listaSelection->inicio);

    fclose(sortedFileSelection);

    heapSortListaCaracteres(listaHeap);

    FILE* sortedFileHeap = fopen(sortedFilePathHeap, "w");
    if (sortedFileHeap == NULL) {
        perror("Erro ao criar o arquivo de lista ordenada (Heap Sort)");
        destruirLista(listaSelection);
        destruirLista(listaHeap);
        return 1;
    }

    atual = listaHeap->inicio;
    do {
        fprintf(sortedFileHeap, "%s\n", atual->nome);
        atual = atual->proximo;
    } while (atual != listaHeap->inicio);

    fclose(sortedFileHeap);

    printf("Listas ordenadas gravadas em:\n");
    printf(" - %s (Selection Sort)\n", sortedFilePathSelection);
    printf(" - %s (Heap Sort)\n", sortedFilePathHeap);

    destruirLista(listaSelection);
    destruirLista(listaHeap);
    return 0;
}
