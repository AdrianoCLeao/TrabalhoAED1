#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/algorithms/selection-sort.h"
#include "../include/algorithms/heap-sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#ifdef _WIN32
    #define PATH_SEPARATOR "\\"
#else
    #define PATH_SEPARATOR "/"
#endif

void construirCaminho(char* basePath, const char* relativePath, char* result) {
    snprintf(result, 1024, "%s%s%s", basePath, PATH_SEPARATOR, relativePath);
}

void salvarNumerosArquivo(const char* filePath, int* numeros, int tamanho) {
    FILE* file = fopen(filePath, "w");
    if (!file) {
        perror("Erro ao criar o arquivo");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%d\n", numeros[i]);
    }
    fclose(file);
}

void salvarStringsArquivo(const char* filePath, char** strings, int tamanho) {
    FILE* file = fopen(filePath, "w");
    if (!file) {
        perror("Erro ao criar o arquivo");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%s\n", strings[i]);
    }
    fclose(file);
}

void ordenarNumeros(void* estrutura, int tamanho, const char* algoritmo, const char* tipoEstrutura, int crescente, const char* basePath, const char* tipoSequencia) {
    char filePath[1024];

    if (strcmp(tipoEstrutura, "vetor") == 0) {
        int* numeros = (int*) estrutura;

        if (strcmp(algoritmo, "heap-sort") == 0) {
            heapSortVetorNumeros(numeros, tamanho, crescente);
        } else if (strcmp(algoritmo, "selection-sort") == 0) {
            selectionSortVetorNumeros(numeros, tamanho, crescente);
        }

        snprintf(filePath, 1024, "%s/data/%s_%s_%s_%d_ordenados_%s.txt", basePath, algoritmo, tipoEstrutura, tipoSequencia, tamanho, crescente ? "crescente" : "decrescente");
        salvarNumerosArquivo(filePath, numeros, tamanho);
    } else if (strcmp(tipoEstrutura, "lista-circular") == 0) {
        ListaCircularDupla* lista = (ListaCircularDupla*) estrutura;

        if (strcmp(algoritmo, "heap-sort") == 0) {
            heapSortListaNumeros(lista, crescente);
        } else if (strcmp(algoritmo, "selection-sort") == 0) {
            selectionSortListaNumeros(lista, crescente);
        }

        snprintf(filePath, 1024, "%s/data/%s_%s_%s_%d_ordenados_%s.txt", basePath, algoritmo, tipoEstrutura, tipoSequencia, tamanho, crescente ? "crescente" : "decrescente");
        FILE* file = fopen(filePath, "w");
        if (file) {
            No* atual = lista->inicio;
            for (int i = 0; i < lista->tamanho; i++) {
                fprintf(file, "%d\n", *(int*) atual->dado);
                atual = atual->proximo;
            }
            fclose(file);
        }
    }
}

void ordenarStrings(void* estrutura, int tamanho, const char* algoritmo, const char* tipoEstrutura, int crescente, const char* basePath) {
    char filePath[1024];

    if (strcmp(tipoEstrutura, "vetor") == 0) {
        char** strings = (char**) estrutura;

        if (strcmp(algoritmo, "heap-sort") == 0) {
            heapSortVetorCaracteres(strings, tamanho, crescente);
        } else if (strcmp(algoritmo, "selection-sort") == 0) {
            selectionSortVetorCaracteres(strings, tamanho, crescente);
        }

        snprintf(filePath, 1024, "%s/data/%s_%s_nomes_aleatorios_ordenados_%s.txt", basePath, algoritmo, tipoEstrutura, crescente ? "crescente" : "decrescente");
        salvarStringsArquivo(filePath, strings, tamanho);
    } else if (strcmp(tipoEstrutura, "lista-circular") == 0) {
        ListaCircularDupla* lista = (ListaCircularDupla*) estrutura;

        if (strcmp(algoritmo, "heap-sort") == 0) {
            heapSortListaCaracteres(lista, crescente);
        } else if (strcmp(algoritmo, "selection-sort") == 0) {
            selectionSortListaCaracteres(lista, crescente);
        }

        snprintf(filePath, 1024, "%s/data/%s_%s_nomes_aleatorios_ordenados_%s.txt", basePath, algoritmo, tipoEstrutura, crescente ? "crescente" : "decrescente");
        FILE* file = fopen(filePath, "w");
        if (file) {
            No* atual = lista->inicio;
            for (int i = 0; i < lista->tamanho; i++) {
                fprintf(file, "%s\n", (char*) atual->dado);
                atual = atual->proximo;
            }
            fclose(file);
        }
    }
}

void gerarSequenciasNumericas(int tamanho, const char* basePath) {
    char filePath[1024];
    int* numeros = malloc(tamanho * sizeof(int));

    snprintf(filePath, 1024, "%s/data/numeros_aleatorios_%d.txt", basePath, tamanho);
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        numeros[i] = rand() % 100000;
    }
    salvarNumerosArquivo(filePath, numeros, tamanho);

    snprintf(filePath, 1024, "%s/data/numeros_crescentes_%d.txt", basePath, tamanho);
    for (int i = 0; i < tamanho; i++) {
        numeros[i] = i;
    }
    salvarNumerosArquivo(filePath, numeros, tamanho);

    free(numeros);
}

void ordenarSequencias(int tamanho, const char* basePath) {
    char filePath[1024];
    int* numeros = malloc(tamanho * sizeof(int));

    snprintf(filePath, 1024, "%s/data/numeros_aleatorios_%d.txt", basePath, tamanho);
    FILE* file = fopen(filePath, "r");
    for (int i = 0; i < tamanho; i++) {
        fscanf(file, "%d", &numeros[i]);
    }
    fclose(file);

    ordenarNumeros(numeros, tamanho, "heap-sort", "vetor", 1, basePath, "numeros_aleatorios");
    ordenarNumeros(numeros, tamanho, "selection-sort", "vetor", 1, basePath, "numeros_aleatorios");

    ListaCircularDupla* listaAleatorios = criarLista(TIPO_INT);
    for (int i = 0; i < tamanho; i++) {
        inserirFim(listaAleatorios, &numeros[i]);
    }

    ordenarNumeros(listaAleatorios, tamanho, "heap-sort", "lista-circular", 1, basePath, "numeros_aleatorios");
    ordenarNumeros(listaAleatorios, tamanho, "selection-sort", "lista-circular", 1, basePath, "numeros_aleatorios");
    destruirLista(listaAleatorios);

    snprintf(filePath, 1024, "%s/data/numeros_crescentes_%d.txt", basePath, tamanho);
    file = fopen(filePath, "r");
    for (int i = 0; i < tamanho; i++) {
        fscanf(file, "%d", &numeros[i]);
    }
    fclose(file);

    ordenarNumeros(numeros, tamanho, "heap-sort", "vetor", 1, basePath, "numeros_crescentes");
    ordenarNumeros(numeros, tamanho, "heap-sort", "vetor", 0, basePath, "numeros_crescentes");
    ordenarNumeros(numeros, tamanho, "selection-sort", "vetor", 1, basePath, "numeros_crescentes");
    ordenarNumeros(numeros, tamanho, "selection-sort", "vetor", 0, basePath, "numeros_crescentes");

    ListaCircularDupla* listaCrescentes = criarLista(TIPO_INT);
    for (int i = 0; i < tamanho; i++) {
        inserirFim(listaCrescentes, &numeros[i]);
    }

    ordenarNumeros(listaCrescentes, tamanho, "heap-sort", "lista-circular", 1, basePath, "numeros_crescentes");
    ordenarNumeros(listaCrescentes, tamanho, "heap-sort", "lista-circular", 0, basePath, "numeros_crescentes");
    ordenarNumeros(listaCrescentes, tamanho, "selection-sort", "lista-circular", 1, basePath, "numeros_crescentes");
    ordenarNumeros(listaCrescentes, tamanho, "selection-sort", "lista-circular", 0, basePath, "numeros_crescentes");
    destruirLista(listaCrescentes);

    free(numeros);
}

void ordenarElementosTextuais(const char* basePath) {
    char filePath[1024];
    snprintf(filePath, 1024, "%s/data/nomes_aleatorios.txt", basePath);

    FILE* file = fopen(filePath, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo nomes_aleatorios.txt");
        return;
    }

    char** strings = malloc(100000 * sizeof(char*));
    int tamanho = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        strings[tamanho++] = strdup(buffer);
    }
    fclose(file);

    ordenarStrings(strings, tamanho, "heap-sort", "vetor", 1, basePath);
    ordenarStrings(strings, tamanho, "heap-sort", "vetor", 0, basePath);
    ordenarStrings(strings, tamanho, "selection-sort", "vetor", 1, basePath);
    ordenarStrings(strings, tamanho, "selection-sort", "vetor", 0, basePath);

    ListaCircularDupla* listaTextos = criarLista(TIPO_STRING);
    for (int i = 0; i < tamanho; i++) {
        inserirFim(listaTextos, strings[i]);
    }

    ordenarStrings(listaTextos, tamanho, "heap-sort", "lista-circular", 1, basePath);
    ordenarStrings(listaTextos, tamanho, "heap-sort", "lista-circular", 0, basePath);
    ordenarStrings(listaTextos, tamanho, "selection-sort", "lista-circular", 1, basePath);
    ordenarStrings(listaTextos, tamanho, "selection-sort", "lista-circular", 0, basePath);
    destruirLista(listaTextos);

    for (int i = 0; i < tamanho; i++) {
        free(strings[i]);
    }
    free(strings);
}

int main() {
    char basePath[1024];
    if (getcwd(basePath, sizeof(basePath)) == NULL) {
        perror("Erro ao obter o diretório atual");
        return 1;
    }

    int opcoes[] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    int opcao;

    while (1) {
        printf("Escolha uma opção:\n");
        for (int i = 0; i < 7; i++) {
            printf("%d) Ordenar %d elementos\n", i + 1, opcoes[i]);
        }
        printf("8) Ordenar elementos textuais\n");
        printf("0) Sair\n");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        if (opcao >= 1 && opcao <= 7) {
            gerarSequenciasNumericas(opcoes[opcao - 1], basePath);
            ordenarSequencias(opcoes[opcao - 1], basePath);
        } else if (opcao == 8) {
            ordenarElementosTextuais(basePath);
        } else {
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
