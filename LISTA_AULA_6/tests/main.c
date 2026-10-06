#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinamicaEncadeada.h"
#include "ListaDinamicaEncadeada.c"

void imprime_lista(ListaTarefas* li, const char* titulo) {
    if (li == NULL) {
        printf("Lista invalida!\n");
        return;
    }

    printf("\n=== %s ===\n", titulo);
    if (*li == NULL) {
        printf("(lista vazia)\n");
    }
    Elem* aux = *li;
    while (aux != NULL) {
        printf("Cod: %03d | Desc: %-15s | Prioridade: %d\n",
               aux->dados.codigo,
               aux->dados.descricao,
               aux->dados.prioridade);
        aux = aux->prox;
    }
    printf("================================\n");
}

struct tarefa cria_tarefa(int codigo, const char* descricao, int prioridade) {
    struct tarefa t;
    t.codigo = codigo;
    strcpy(t.descricao, descricao);
    t.prioridade = prioridade;
    return t;
}

int main() {
    printf("Iniciando testes da Lista Dinamica Encadeada...\n\n");

    ListaTarefas* lista1 = cria_lista();
    if (lista1 != NULL) {
        printf("[OK] Lista 1 criada com sucesso.\n");
    }

    // Monta a lista inicial (insercao no final)
    insere_tarefa_final_prioridade(lista1, cria_tarefa(1, "Estudar C", 2));
    insere_tarefa_final_prioridade(lista1, cria_tarefa(2, "Lavar carro", 1));
    insere_tarefa_final_prioridade(lista1, cria_tarefa(3, "Estudar listas", 2));
    insere_tarefa_final_prioridade(lista1, cria_tarefa(4, "Pagar conta", 3));
    insere_tarefa_final_prioridade(lista1, cria_tarefa(5, "Ler livro", 1));
    imprime_lista(lista1, "Lista Inicial (Esperado: 1 2 3 4 5)");

// 1. Teste conta_tarefas_prioridade
    printf("\n[Teste] Tarefas com prioridade 2: %d (Esperado: 2)\n",
           conta_tarefas_prioridade(lista1, 2));
    printf("[Teste] Tarefas com prioridade 9: %d (Esperado: 0)\n",
           conta_tarefas_prioridade(lista1, 9));
    printf("[Teste] Lista NULL: %d (Esperado: -1)\n",
           conta_tarefas_prioridade(NULL, 2));

// 2. Teste tarefa_mais_urgente
    struct tarefa t;
    if (tarefa_mais_urgente(lista1, &t)) {
        printf("\n[Teste] Mais urgente: %s - prioridade %d (Esperado: Lavar carro - 1, primeira do empate)\n",
               t.descricao, t.prioridade);
    } else {
        printf("\n[FALHA] tarefa_mais_urgente devolveu 0.\n");
    }

// 3. Teste busca_tarefa_desc
    printf("\n--- Buscando tarefa por descricao ---\n");
    if (busca_tarefa_desc(lista1, "Estudar", &t)) {
        printf("[OK] Encontrado: cod %d - %s (Esperado: cod 1, a primeira)\n",
               t.codigo, t.descricao);
    } else {
        printf("[FALHA] Tarefa nao encontrada.\n");
    }

    if (!busca_tarefa_desc(lista1, "xyz", &t)) {
        printf("[OK] 'xyz' corretamente nao encontrado.\n");
    }

// 4. Teste insere_tarefa_final_prioridade
    printf("\n--- Inserindo apos a ultima tarefa de mesma prioridade ---\n");
    insere_tarefa_final_prioridade(lista1, cria_tarefa(9, "Nova prio 2", 2));
    imprime_lista(lista1, "Apos inserir prio 2 (Esperado: 1 2 3 9 4 5)");

    insere_tarefa_final_prioridade(lista1, cria_tarefa(8, "Nova prio 7", 7));
    imprime_lista(lista1, "Apos inserir prio 7 inexistente (Esperado: 1 2 3 9 4 5 8)");

// 6. Teste inverte_lista
    printf("\n[Teste] inverte_lista devolveu: %d (Esperado: 1)\n", inverte_lista(lista1));
    imprime_lista(lista1, "Lista Invertida (Esperado: 8 5 4 9 3 2 1)");
    inverte_lista(lista1);   // volta a ordem original

// 7. Teste remove_tarefa_pos
    printf("\n[Teste] Removendo posicao 1: %d (Esperado: 1)\n", remove_tarefa_pos(lista1, 1));
    printf("[Teste] Removendo posicao 99: %d (Esperado: 0)\n", remove_tarefa_pos(lista1, 99));
    imprime_lista(lista1, "Apos remover pos 1 (Esperado: 2 3 9 4 5 8)");

// 5. Teste remove_tarefas_prioridade
    int removidas = remove_tarefas_prioridade(lista1, 2);
    printf("\n[Teste] Removendo prioridade 2. Quantidade removida: %d (Esperado: 2 - cod 3 e 9)\n",
           removidas);
    imprime_lista(lista1, "Apos remover prio 2 (Esperado: 2 4 5 8)");

// 8. Teste mescla_tarefas
    ListaTarefas* lista2 = cria_lista();

    printf("\n--- Testando Mescla de Listas ---\n");
    insere_tarefa_final_prioridade(lista2, cria_tarefa(10, "Tarefa A", 1));
    insere_tarefa_final_prioridade(lista2, cria_tarefa(11, "Tarefa B", 1));
    imprime_lista(lista2, "Lista 2 (Origem)");

    int transferidas = mescla_tarefas(lista1, lista2);
    printf("[Teste] Tarefas transferidas para a lista 1: %d (Esperado: 2)\n", transferidas);
    imprime_lista(lista1, "Lista 1 Apos a Mescla (Esperado: 2 4 5 8 10 11)");
    imprime_lista(lista2, "Lista 2 Apos a Mescla (Esperado: vazia)");

    libera_lista(lista1);
    libera_lista(lista2);
    printf("\n[OK] Listas liberadas da memoria.\n");

    return 0;
}