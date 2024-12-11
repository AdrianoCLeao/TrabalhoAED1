#ifndef LISTA_CIRCULAR_DUPLAMENTE_ENCADEADA_H
#define LISTA_CIRCULAR_DUPLAMENTE_ENCADEADA_H

#include <stdbool.h>

typedef enum {
    TIPO_STRING,
    TIPO_INT
} TipoDado;

typedef struct No {
    void* dado;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct {
    No* inicio;
    int tamanho;
    TipoDado tipo;
} ListaCircularDupla;

ListaCircularDupla* criarLista(TipoDado tipo);
void destruirLista(ListaCircularDupla* lista);
bool inserirInicio(ListaCircularDupla* lista, void* dado);
bool inserirFim(ListaCircularDupla* lista, void* dado);
bool removerInicio(ListaCircularDupla* lista);
bool removerFim(ListaCircularDupla* lista);
void exibirLista(ListaCircularDupla* lista);

#endif
