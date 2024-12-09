#include "../include/utils/utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

double calcularTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void registrarDados(const char* algoritmo, double tempoExecucao, int quantidadeTrocas) {
    struct stat st = {0};
    if (stat("stats", &st) == -1) {
        if (mkdir("stats", 0777) != 0) {
            perror("Erro ao criar diretório stats");
            return;
        }
    }

    char caminhoArquivo[256];
    snprintf(caminhoArquivo, sizeof(caminhoArquivo), "stats/%s.txt", algoritmo);

    FILE* arquivo = fopen(caminhoArquivo, "a");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de registro");
        return;
    }

    fprintf(arquivo, "Algoritmo: %s\n", algoritmo);
    fprintf(arquivo, "Tempo de execução: %.6f segundos\n", tempoExecucao);
    fprintf(arquivo, "Quantidade de trocas: %d\n\n", quantidadeTrocas);

    fclose(arquivo);
}
