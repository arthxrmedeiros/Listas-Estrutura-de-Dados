#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

int mescla_listas(Lista* destino, Lista* origem){
    if (destino == NULL || origem == NULL)
        return 0;

    int inseridos = 0;

    for (int i = 0; i < origem->qtd; i++){
        if (destino->qtd == MAX)
            break;
        int existe = 0;
        for (int j = 0; j < destino->qtd; j++){
            if (destino->dados[j].codigo == origem->dados[i].codigo){
                existe = 1;
            }
        }

        if (!existe){
        destino->dados[destino->qtd] = origem->dados[i];
        destino->qtd++;
        inseridos++;
        }
    }
    return inseridos;
}