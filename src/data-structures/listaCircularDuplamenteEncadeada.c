#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
    - Essa implementação é da lista circular duplamente encadeada. 
      A lista é formada por "nós", que armazenam uma string e apontam para o próximo e o anterior.
    
    - Explicação das funções:

    1. **criarLista**: Cria e inicializa a lista. Retorna um ponteiro pra lista.

    2. **destruirLista**: Acaba com a lista. Mata todos os nós um por um 
       e, no final, libera a própria lista. 

    3. **inserirInicio**: Insere um nó no começo da lista. Se a lista for vazia, cria o primeiro nó e 
       conecta ele a ele mesmo (lembrando: circular). Se já tem coisa, liga o novo nó no início e no último nó.

    4. **inserirFim**: Quase igual ao "inserirInicio", mas joga o novo nó no final da lista. 
       Se a lista estiver vazia, só reaproveita o inserirInicio.

    5. **removerInicio**: Tira o nó que tá no início da lista. Ajusta os ponteiros pra não quebrar 
       a ligação entre o último e o novo início.

    6. **removerFim**: Parecido com o removerInicio, mas tira o nó do final. Se a lista só tiver 
       um nó, ele chama o removerInicio direto.

    7. **exibirLista**: Mostra todos os elementos da lista na ordem, começando do início. 
       Dá um "loop" nos elementos e imprime os valores. Se não tem nada na lista, diz que tá vazia.
*/
ListaCircularDupla* criarLista(TipoDado tipo) {
    ListaCircularDupla* lista = (ListaCircularDupla*) malloc(sizeof(ListaCircularDupla));
    if (lista) {
        lista->inicio = NULL;
        lista->tamanho = 0;
        lista->tipo = tipo;
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

bool inserirInicio(ListaCircularDupla* lista, void* dado) {
    if (!lista) return false;

    No* novoNo = (No*) malloc(sizeof(No));
    if (!novoNo) return false;

    if (lista->tipo == TIPO_STRING) {
        novoNo->dado = strdup((char*) dado);
        if (!novoNo->dado) {
            free(novoNo);
            return false;
        }
    } else if (lista->tipo == TIPO_INT) {
        novoNo->dado = malloc(sizeof(int));
        if (!novoNo->dado) {
            free(novoNo);
            return false;
        }
        *(int*)novoNo->dado = *(int*)dado;
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

bool inserirFim(ListaCircularDupla* lista, void* dado) {
    if (!lista) return false;

    if (lista->tamanho == 0) {
        return inserirInicio(lista, dado);
    }

    No* novoNo = (No*) malloc(sizeof(No));
    if (!novoNo) return false;

    if (lista->tipo == TIPO_STRING) {
        novoNo->dado = strdup((char*) dado);
        if (!novoNo->dado) {
            free(novoNo);
            return false;
        }
    } else if (lista->tipo == TIPO_INT) {
        novoNo->dado = malloc(sizeof(int));
        if (!novoNo->dado) {
            free(novoNo);
            return false;
        }
        *(int*)novoNo->dado = *(int*)dado;
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

    if (lista->tipo == TIPO_STRING) {
        free(removido->dado);
    } else if (lista->tipo == TIPO_INT) {
        free(removido->dado);
    }

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

    if (lista->tipo == TIPO_STRING) {
        free(ultimo->dado);
    } else if (lista->tipo == TIPO_INT) {
        free(ultimo->dado);
    }

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
        if (lista->tipo == TIPO_STRING) {
            printf("%s ", (char*) atual->dado);
        } else if (lista->tipo == TIPO_INT) {
            printf("%d ", *(int*) atual->dado);
        }
        atual = atual->proximo;
    } while (atual != lista->inicio);
    printf("\n");
}
