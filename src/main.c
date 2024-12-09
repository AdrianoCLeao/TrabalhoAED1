#include "../include/data-structures/listaCircularDuplamenteEncadeada.h"
#include "../include/algorithms/selection-sort.h"
#include <stdio.h>

int main() {
    ListaCircularDupla* lista = criarLista();

    inserirInicio(lista, "Maria");
    inserirInicio(lista, "João");
    inserirInicio(lista, "Ana");
    inserirInicio(lista, "Carlos");
    inserirInicio(lista, "Beatriz");
    inserirInicio(lista, "Fernando");
    inserirInicio(lista, "Laura");
    inserirInicio(lista, "Paulo");
    inserirInicio(lista, "Clara");
    inserirInicio(lista, "Ricardo");
    inserirInicio(lista, "Sofia");
    inserirInicio(lista, "Gabriel");
    inserirInicio(lista, "Isabela");
    inserirInicio(lista, "Lucas");
    inserirInicio(lista, "Mariana");
    inserirInicio(lista, "Felipe");
    inserirInicio(lista, "Juliana");
    inserirInicio(lista, "Luiz");
    inserirInicio(lista, "Camila");
    inserirInicio(lista, "Pedro");
    inserirInicio(lista, "Renata");
    inserirInicio(lista, "Rafael");
    inserirInicio(lista, "Thiago");
    inserirInicio(lista, "Larissa");
    inserirInicio(lista, "Carolina");
    inserirInicio(lista, "André");
    inserirInicio(lista, "Eduarda");
    inserirInicio(lista, "Henrique");
    inserirInicio(lista, "Lúcia");
    inserirInicio(lista, "Bruno");
    inserirInicio(lista, "Natália");
    inserirInicio(lista, "Antônio");
    inserirInicio(lista, "Viviane");
    inserirInicio(lista, "Catarina");
    inserirInicio(lista, "Vinícius");
    inserirInicio(lista, "Helena");
    inserirInicio(lista, "Roberto");
    inserirInicio(lista, "Patrícia");
    inserirInicio(lista, "Flávia");
    inserirInicio(lista, "Márcio");
    inserirInicio(lista, "Yasmin");
    inserirInicio(lista, "Cláudio");
    inserirInicio(lista, "Débora");
    inserirInicio(lista, "Marcela");
    inserirInicio(lista, "Otávio");
    inserirInicio(lista, "Sandra");
    inserirInicio(lista, "Augusto");
    inserirInicio(lista, "Elaine");
    inserirInicio(lista, "Cristina");
    inserirInicio(lista, "Fábio");
    inserirInicio(lista, "Monique");
    inserirInicio(lista, "César");
    inserirInicio(lista, "Tereza");
    inserirInicio(lista, "Simone");
    inserirInicio(lista, "Leandro");
    inserirInicio(lista, "Raquel");
    inserirInicio(lista, "Gustavo");
    inserirInicio(lista, "Silvana");
    inserirInicio(lista, "Marcelo");
    inserirInicio(lista, "Valéria");
    inserirInicio(lista, "Vitor");
    inserirInicio(lista, "Kelly");
    inserirInicio(lista, "Sérgio");
    inserirInicio(lista, "Luciana");
    inserirInicio(lista, "Hugo");
    inserirInicio(lista, "Mônica");
    inserirInicio(lista, "Alexandre");
    inserirInicio(lista, "Tânia");
    inserirInicio(lista, "Regina");
    inserirInicio(lista, "Murilo");
    inserirInicio(lista, "Daiane");
    inserirInicio(lista, "Cristiano");
    inserirInicio(lista, "Adriana");
    inserirInicio(lista, "Ítalo");
    inserirInicio(lista, "Jéssica");
    inserirInicio(lista, "Daniel");
    inserirInicio(lista, "Priscila");
    inserirInicio(lista, "Rodrigo");
    inserirInicio(lista, "Elaisa");

    printf("Lista antes da ordenação:\n");
    exibirLista(lista);

    selectionSort(lista);

    printf("Lista após a ordenação:\n");
    exibirLista(lista);

    destruirLista(lista);
    return 0;
}
