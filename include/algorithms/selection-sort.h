#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"

void selectionSortVetorNumeros(int* vetor, int tamanho);
void selectionSortVetorCaracteres(char** vetor, int tamanho);

void selectionSortListaCaracteres(ListaCircularDupla* lista);
void selectionSortListaNumeros(ListaCircularDupla* lista);

#endif
