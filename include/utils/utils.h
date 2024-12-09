#ifndef UTILS_H
#define UTILS_H

#include <time.h>

double calcularTempo(clock_t inicio, clock_t fim);
void registrarDados(const char* algoritmo, double tempoExecucao, int quantidadeTrocas);

#endif
