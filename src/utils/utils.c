#include "../include/utils/utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <sys/time.h>
#endif

double obterTempoAtual() {
#if defined(_WIN32) || defined(_WIN64)
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)freq.QuadPart;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts); 
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
#endif
}

double calcularTempo(double inicio, double fim) {
    return fim - inicio;
}

void registrarDados(const char* algoritmo, int tamanhoEntrada, double tempoExecucao, int quantidadeTrocas) {
    struct stat st = {0};

    if (stat("stats", &st) == -1) {
        if (mkdir("stats", 0777) != 0) {
            perror("Erro ao criar diretório stats");
            return;
        }
    }

    char caminhoArquivo[256];
    snprintf(caminhoArquivo, sizeof(caminhoArquivo), "stats/%s.csv", algoritmo);

    FILE* arquivo = fopen(caminhoArquivo, "a");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de registro");
        return;
    }

    if (ftell(arquivo) == 0) {
        fprintf(arquivo, "TamanhoEntrada,TempoExecucao,QuantidadeTrocas\n");
    }

    fprintf(arquivo, "%d,%.10f,%d\n", tamanhoEntrada, tempoExecucao, quantidadeTrocas);

    fclose(arquivo);
}

