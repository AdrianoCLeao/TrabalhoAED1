#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"

void selectionSortVetorNumeros(int* vetor, int tamanho, int crescente);
void selectionSortVetorCaracteres(char** vetor, int tamanho, int crescente);

void selectionSortListaCaracteres(ListaCircularDupla* lista, int crescente);
void selectionSortListaNumeros(ListaCircularDupla* lista, int crescente);

#endif
