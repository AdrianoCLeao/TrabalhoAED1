#ifndef UTILS_H
#define UTILS_H

#include <time.h>

double obterTempoAtual();
double calcularTempo(double inicio, double fim);
void registrarDados(const char* algoritmo, int tamanhoEntrada, double tempoExecucao, int quantidadeTrocas);

#endif
