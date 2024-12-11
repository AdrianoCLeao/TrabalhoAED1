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
    ListaCircularDupla* lista = criarLista();

    char basePath[1024];
    char filePath[1024];
    char sortedFilePath[1024];

    if (getcwd(basePath, sizeof(basePath)) == NULL) {
        perror("Erro ao obter o diretório atual");
        return 1;
    }

    construirCaminho(basePath, "data/nomes_aleatorios.txt", filePath);
    construirCaminho(basePath, "data/nomes_ordenados.txt", sortedFilePath);

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

        inserirInicio(lista, nome);
    }

    fclose(file);

    selectionSort(lista);

    printf("Lista apos a ordenacao (gravando em arquivo):\n");

    FILE* sortedFile = fopen(sortedFilePath, "w");
    if (sortedFile == NULL) {
        perror("Erro ao criar o arquivo de lista ordenada");
        destruirLista(lista);
        return 1;
    }

    No* atual = lista->inicio;
    do {
        fprintf(sortedFile, "%s\n", atual->nome);
        atual = atual->proximo;
    } while (atual != lista->inicio);

    fclose(sortedFile);
    printf("Lista ordenada gravada em: %s\n", sortedFilePath);

    destruirLista(lista);
    return 0;
}
