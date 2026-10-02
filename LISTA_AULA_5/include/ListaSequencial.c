#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

#ifndef LISTA_SEQUENCIAL_C
#define LISTA_SEQUENCIAL_C

struct lista {
    int qtd;
    struct produto dados[MAX];
};

#endif