#ifndef LISTA_DINAMICA_ENCADEADA_H
#define LISTA_DINAMICA_ENCADEADA_H

struct tarefa { 
    int codigo; 
    char descricao[30]; 
    int prioridade; 
};

typedef struct elemento* ListaTarefas;

ListaTarefas* cria_lista(void);
void libera_lista(ListaTarefas* li);
int conta_tarefas_prioridade(ListaTarefas* li, int prioridade);
int tarefa_mais_urgente(ListaTarefas* li, struct tarefa *t);
int busca_tarefa_desc(ListaTarefas* li, char *texto, struct tarefa *t);
int insere_tarefa_final_prioridade(ListaTarefas* li, struct tarefa t);
int remove_tarefas_prioridade(ListaTarefas* li, int prioridade);
int inverte_lista(ListaTarefas* li);
int remove_tarefa_pos(ListaTarefas* li, int pos);
int mescla_tarefas(ListaTarefas* dst, ListaTarefas* src);

#endif