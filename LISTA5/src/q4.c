#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

int insere_lista_decrescente(Lista* li, struct produto p){
    int k, i = 0;
    if (li == NULL || li->qtd == MAX)
        return 0;
    while (i < li->qtd && li->dados[i].preco >= p.preco){
        i++;
    }
    for (k = li ->qtd; k > i; k--){
        li->dados[k] = li ->dados[k - 1];
    }
    li->dados[i] = p;
    li -> qtd++;

    return 1;
}   