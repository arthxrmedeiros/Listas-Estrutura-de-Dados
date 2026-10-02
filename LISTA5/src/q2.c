#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

float soma_precos(Lista* li){
    if (li == NULL){
        return 0;
    }
    float soma = 0;
    for (int i = 0; i < li->qtd; i++){
        soma += li->dados[i].preco;
    }
    return soma;
}
