#include "../include/listaCircularDuplamenteEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

ListaCircularDupla* criarLista() {
    ListaCircularDupla* lista = (ListaCircularDupla*) malloc(sizeof(ListaCircularDupla));
    if (lista) {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void destruirLista(ListaCircularDupla* lista) {
    if (lista) {
        while (lista->tamanho > 0) {
            removerInicio(lista);
        }
        free(lista);
    }
}

bool inserirInicio(ListaCircularDupla* lista, const char* nome) {
    if (!lista) return false;

    No* novoNo = (No*) malloc(sizeof(No));
    if (!novoNo) return false;

    novoNo->nome = strdup(nome); 
    if (!novoNo->nome) {
        free(novoNo);
        return false;
    }

    if (lista->tamanho == 0) {
        novoNo->proximo = novoNo->anterior = novoNo;
        lista->inicio = novoNo;
    } else {
        No* ultimo = lista->inicio->anterior;
        novoNo->proximo = lista->inicio;
        novoNo->anterior = ultimo;
        lista->inicio->anterior = novoNo;
        ultimo->proximo = novoNo;
        lista->inicio = novoNo;
    }
    lista->tamanho++;
    return true;
}

