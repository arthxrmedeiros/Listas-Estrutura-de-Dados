#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"

Lista* cria_lista() {
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

int lista_tem_espaco(Lista* li, int n){
    if (li == NULL || n < 0 || li->qtd + n > MAX)
        return 0;
    return 1;
}

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

void libera_lista(Lista* li) {
    free(li);
}