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