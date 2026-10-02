#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"
#include "ListaSequencial.c"
#include "lista4.c"

void imprime_lista(Lista* li, const char* titulo) {
    if (li == NULL) {
        printf("Lista invalida!\n");
    return;
    }

    printf("\n=== %s (Qtd: %d) =\n", titulo, li->qtd);
    for (int i = 0; i < li->qtd; i++) {
        printf("Cod: %03d | Nome: %-15s | Preco: R$ %.2f\n",
        li->dados[i].codigo,
        li->dados[i].nome,
        li->dados[i].preco);
    }
printf("================================\n");
}

struct produto cria_produto(int codigo, const char* nome, float preco) {
    struct produto p;
        p.codigo = codigo;
        strcpy(p.nome, nome);
        p.preco = preco;
    return p;
}

int main() {
    printf("Iniciando testes da Lista Sequencial...\n\n");

    Lista* lista1 = cria_lista();
    if (lista1 != NULL) {
    printf("[OK] Lista 1 criada com sucesso.\n");
    }

// 2. Teste lista_tem_espaco
    if (lista_tem_espaco(lista1, 5)) {
    printf("[OK] A lista tem espaco para 5 novos elementos.\n");
    }

// 3. Teste insere_lista_decrescente
    printf("\n--- Inserindo produtos em ordem decrescente de preco ---\n");
    insere_lista_decrescente(lista1, cria_produto(1, "Feijao", 8.50));
    insere_lista_decrescente(lista1, cria_produto(2, "Arroz", 25.00));
    insere_lista_decrescente(lista1, cria_produto(3, "Carne", 45.00));
    insere_lista_decrescente(lista1, cria_produto(4, "Macarrao", 5.50));
    insere_lista_decrescente(lista1, cria_produto(5, "Azeite", 35.00));
    imprime_lista(lista1, "Lista Apos Insercoes (Esperado: Decrescente)");

// 4. Teste soma_precos
    float soma = soma_precos(lista1);
    printf("\n[Teste] Soma dos precos: R$ %.2f (Esperado: 119.00)\n", soma);

// 5. Teste busca_por_nome
    struct produto p_busca;
    printf("\n--- Buscando produto por nome ---\n");
    if (busca_por_nome(lista1, "Arroz", &p_busca)) {
        printf("[OK] Encontrado: %s - R$ %.2f\n", p_busca.nome, p_busca.preco);
    } else {
        printf("[FALHA] Produto nao encontrado.\n");
    }

    if (!busca_por_nome(lista1, "Lasanha", &p_busca)) {
        printf("[OK] 'Lasanha' corretamente nao encontrado.\n");
    }

// 6. Teste conta_faixa_preco
    int qtd_faixa = conta_faixa_preco(lista1, 10.0, 40.0);
    printf("\n[Teste] Produtos entre R$10 e R$40: %d (Esperado: 2 - Azeite e Arroz)\n", qtd_faixa);

// 7. Teste remove_mais_caro
    struct produto p_removido;
    if (remove_mais_caro(lista1, &p_removido)) {
        printf("\n[Teste] Removendo o mais caro: %s - R$ %.2f (Esperado: Carne - 45.00)\n", 
        p_removido.nome, p_removido.preco);
    }
    imprime_lista(lista1, "Lista Apos Remover o Mais Caro");

// 8. Teste remove_abaixo_de
    int qtd_removidos = remove_abaixo_de(lista1, 15.00);
    printf("\n[Teste] Removendo abaixo de R$ 15.00. Quantidade removida: %d (Esperado: 2 - Feijao e Macarrao)\n", qtd_removidos);
    imprime_lista(lista1, "Lista Apos Remover Abaixo de R$15");

// 9. Teste mescla_listas
    Lista* lista2 = cria_lista();

    printf("\n--- Testando Mescla de Listas ---\n");

    // Inserindo um item que já existe na lista1 (codigo 2 - Arroz)
    insere_lista_decrescente(lista2, cria_produto(2, "Arroz Tipo 1", 28.00)); 
    
    // Inserindo novos itens
    insere_lista_decrescente(lista2, cria_produto(6, "Sal", 3.00));
    insere_lista_decrescente(lista2, cria_produto(7, "Pimenta", 12.00));

    imprime_lista(lista2, "Lista 2 (Origem)");

    int inseridos_mescla = mescla_listas(lista1, lista2);
    printf("[Teste] Itens mesclados para a lista 1: %d (Esperado: 2 - Sal e Pimenta. O codigo 2 deve ser ignorado)\n",
    inseridos_mescla);
    imprime_lista(lista1, "Lista 1 Apos a Mescla");

    libera_lista(lista1);
    libera_lista(lista2);
    printf("\n[OK] Listas liberadas da memoria.\n");

    return 0;
}