#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

int remove_mais_caro(Lista* li, struct produto *removido){
    if (li == NULL || li->qtd == 0)
        return 0;
    int mais_caro = 0;
    for (int i = 1; i < li->qtd; i++){
        if(li->dados[i].preco > li->dados[mais_caro].preco){
            mais_caro = i ;
        }
    }
    li->qtd--;
    *removido = li->dados[mais_caro];
    li->dados[mais_caro] = li->dados[li->qtd];

    return 1;

}