#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

int busca_por_nome(Lista* li, char *nome, struct produto *p){
    if (li == NULL || nome == NULL || p == NULL){
        return 0;
    }
    for(int i = 0; i < li ->qtd; i++){
        if (strcmp(li -> dados[i].nome, nome ) == 0){
            *p = li -> dados[i];
            return 1;
        }
    }
    return 0;
}