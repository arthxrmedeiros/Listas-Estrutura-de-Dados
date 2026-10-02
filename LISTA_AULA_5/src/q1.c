#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

int lista_tem_espaco(Lista* li, int n){
    if (li == NULL || n < 0 || li->qtd + n > MAX)
        return 0;
    if (li->qtd + n <= MAX)
    return 1;
}
