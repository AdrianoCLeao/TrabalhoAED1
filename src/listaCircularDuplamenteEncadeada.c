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

bool inserirFim(ListaCircularDupla* lista, const char* nome) {
    if (!lista) return false;
    if (lista->tamanho == 0) {
        return inserirInicio(lista, nome);
    }

    No* novoNo = (No*) malloc(sizeof(No));
    if (!novoNo) return false;

    novoNo->nome = strdup(nome);
    if (!novoNo->nome) {
        free(novoNo);
        return false;
    }

    No* ultimo = lista->inicio->anterior;
    novoNo->proximo = lista->inicio;
    novoNo->anterior = ultimo;
    ultimo->proximo = novoNo;
    lista->inicio->anterior = novoNo;

    lista->tamanho++;
    return true;
}

bool removerInicio(ListaCircularDupla* lista) {
    if (!lista || lista->tamanho == 0) return false;

    No* removido = lista->inicio;
    if (lista->tamanho == 1) {
        lista->inicio = NULL;
    } else {
        No* ultimo = lista->inicio->anterior;
        lista->inicio = removido->proximo;
        lista->inicio->anterior = ultimo;
        ultimo->proximo = lista->inicio;
    }
    free(removido->nome);
    free(removido);
    lista->tamanho--;
    return true;
}

bool removerFim(ListaCircularDupla* lista) {
    if (!lista || lista->tamanho == 0) return false;
    if (lista->tamanho == 1) {
        return removerInicio(lista);
    }

    No* ultimo = lista->inicio->anterior;
    No* penultimo = ultimo->anterior;

    penultimo->proximo = lista->inicio;
    lista->inicio->anterior = penultimo;

    free(ultimo->nome);
    free(ultimo);

    lista->tamanho--;
    return true;
}

void exibirLista(ListaCircularDupla* lista) {
    if (!lista || lista->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = lista->inicio;
    printf("Elementos da lista: ");
    do {
        printf("%s ", atual->nome);
        atual = atual->proximo;
    } while (atual != lista->inicio);
    printf("\n");
}
