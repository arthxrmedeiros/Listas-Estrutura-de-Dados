#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDinamicaEncadeada.h"

struct elemento {
    struct tarefa dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

ListaTarefas* cria_lista(void) {
    ListaTarefas* li = (ListaTarefas*) malloc(sizeof(ListaTarefas));
    if (li != NULL)
        *li = NULL;               /* lista vazia: o inicio aponta para NULL */
    return li;
}

int conta_tarefas_prioridade(ListaTarefas* li, int prioridade) {
    if (li == NULL) {
        return -1;
    }

    int cont = 0;
    Elem* aux = *li;

    while(aux != NULL){
        if(aux->dados.prioridade == prioridade){
            cont++;
        }
        aux = aux->prox;
    }
    return cont;
}

int tarefa_mais_urgente(ListaTarefas* li, struct tarefa *t){
    if(li == NULL || *li == NULL || t == NULL ){
        return 0;
    }

    Elem* aux = *li;
    Elem* menor = aux;
    aux = aux->prox;

    while(aux != NULL){
        if(aux->dados.prioridade < menor->dados.prioridade){
            menor = aux;
        }
        aux = aux->prox;
    }

    *t = menor->dados;
    return 1;
}

int busca_tarefa_desc(ListaTarefas* li, char *texto, struct tarefa *t){
    if( li == NULL || *li == NULL || texto == NULL || t == NULL){
        return 0;
    }

    Elem* aux = *li;
    while(aux != NULL){
        if(strstr(aux->dados.descricao, texto) != NULL){
            *t = aux->dados;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

int insere_tarefa_final_prioridade(ListaTarefas* li, struct tarefa t){
    if(li == NULL){
        return 0;
    } 
    Elem* novo = (Elem*) malloc(sizeof(Elem));
    if(novo == NULL){
        return 0;
    }
    novo->dados = t;
    if(*li == NULL){
        novo->prox = NULL;
        *li = novo;
        return 1;
    }
    Elem* aux = *li;
    Elem* ultimo_igual = NULL;
    Elem* ultimo = NULL;

    while(aux != NULL){
        if(aux->dados.prioridade == t.prioridade){
            ultimo_igual = aux;
        }
        ultimo = aux;
        aux = aux->prox;
    }

    if(ultimo_igual != NULL){
        novo->prox = ultimo_igual->prox;
        ultimo_igual->prox = novo;
    } else {
        novo->prox = NULL;
        ultimo->prox = novo;
    }
    return 1;
}

int remove_tarefas_prioridade(ListaTarefas* li, int prioridade){
    if (li == NULL)
        return -1;

    int removidos = 0;
    Elem* ant = NULL;
    Elem* aux = *li;

    while (aux != NULL) {
        if (aux->dados.prioridade == prioridade) {
            if (ant == NULL){
                *li = aux->prox;
            } else {
                ant->prox = aux->prox;
            }

            Elem* lixo = aux;
            aux = aux->prox;          
            free(lixo);
            removidos++;
        } else {
            ant = aux;                
            aux = aux->prox;
        }
    }

    return removidos;
}

int inverte_lista(ListaTarefas* li) {
    if (li == NULL){
         return 0;
    }

    Elem* ant = NULL;
    Elem* atual = *li;
    Elem* prox;

    while (atual != NULL) {
        prox = atual->prox;     
        atual->prox = ant;     
        ant = atual;            
        atual = prox;           
    }

    *li = ant;            
    return 1;
}

int remove_tarefa_pos(ListaTarefas* li, int pos) {
    if (li == NULL || *li == NULL || pos < 1)
        return 0;

    Elem* ant = NULL;
    Elem* aux = *li;
    int i = 1;

    while (aux != NULL && i < pos) {
        ant = aux;
        aux = aux->prox;
        i++;
    }

    if (aux == NULL){
        return 0; 
    }              
    if (ant == NULL){
        *li = aux->prox;
    } else {
        ant->prox = aux->prox;
    }
    free(aux);
    return 1;
}

int mescla_tarefas(ListaTarefas* dst, ListaTarefas* src) {
    if (dst == NULL || src == NULL){
        return -1;
    }

    int transferidos = 0;
    Elem* aux = *src;
    while (aux != NULL) {
        transferidos++;
        aux = aux->prox;
    }

    if (transferidos == 0){
        return 0;
    }

    if (*dst == NULL) {
        *dst = *src;           
    } else {
        Elem* ultimo = *dst;
        while (ultimo->prox != NULL){
            ultimo = ultimo->prox;
        }
        ultimo->prox = *src;    
    }

    *src = NULL;                
    return transferidos;
}

void libera_lista(ListaTarefas* li) {
    if (li != NULL) {
        Elem* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;    /* avanca ANTES de liberar */
            free(no);
        }
        free(li);                 /* libera o bloco do inicio */
    }
}