#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"

void criaHeapVetorNumeros(int* vetor, int inicio, int fim);
void heapSortVetorNumeros(int* vetor, int tamanho);
void criaHeapVetorCaracteres(char** vetor, int inicio, int fim);
void heapSortVetorCaracteres(char** vetor, int tamanho);

void criaHeapListaCaracteres(ListaCircularDupla* lista, int inicio, int tamanho);
void heapSortListaCaracteres(ListaCircularDupla* lista);

#endif