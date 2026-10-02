#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

int conta_faixa_preco(Lista* li, float min, float max){
    if (li == NULL || min > max)
        return 0;
    int cont = 0;
    for (int i = 0; i < li->qtd; i++){
        if (li->dados[i].preco >= min && li->dados[i].preco <= max){
            cont++;
        }
    }
    return cont;
}