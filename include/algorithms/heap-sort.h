#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"

void criaHeapVetorNumeros(int* vetor, int inicio, int fim, int crescente, int* trocas);
void heapSortVetorNumeros(int* vetor, int tamanho, int crescente);
void criaHeapVetorCaracteres(char** vetor, int inicio, int fim, int crescente, int* trocas);
void heapSortVetorCaracteres(char** vetor, int tamanho, int crescente);

void heapSortListaCaracteres(ListaCircularDupla* lista, int crescente);
void heapSortListaNumeros(ListaCircularDupla* lista, int crescente);

#endif