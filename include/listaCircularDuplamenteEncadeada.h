#ifndef LISTA_CIRCULAR_DUPLAMENTE_ENCADEADA_H
#define LISTA_CIRCULAR_DUPLAMENTE_ENCADEADA_H

#include <stdbool.h>

typedef struct No {
    char* nome; 
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct {
    No* inicio; 
    int tamanho;
} ListaCircularDupla;

ListaCircularDupla* criarLista();
void destruirLista(ListaCircularDupla* lista);
bool inserirInicio(ListaCircularDupla* lista, const char* nome);

#endif
