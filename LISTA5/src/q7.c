#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

int remove_abaixo_de(Lista* li, float precoMinimo){
    if (li == NULL){
        return 0;
    }

    int i = 0;
    int removidos = 0;
    while (i < li ->qtd){
        if (li->dados[i].preco < precoMinimo){
            li->dados[i] = li->dados[li->qtd - 1];
            li->qtd--;
            removidos++;
        } else {
            i++;
        }
    }
    return removidos;
}