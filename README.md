# Listas-Estrutura-de-Dados
# Lista Sequencial Estática de Produtos (TAD)

Implementação de funções sobre uma **lista sequencial estática** de produtos em C.

## Sumário

- [Estrutura do projeto](#estrutura-do-projeto)
- [Modelo de dados](#modelo-de-dados)
- [Como compilar e executar](#como-compilar-e-executar)

## Estrutura do projeto

```
.
├── include/
│   ├── ListaSequencial.h          # TAD público (protótipos, MAX, struct produto)
│   └── ListaSequencial.c          # No arquivo .c fica tudo o que é oculto do usuário
├── src/
│   ├── lista4.c         # todas funcoes para praticidade na main
│   ├── q1.c             # lista_tem_espaco
│   ├── q2.c             # soma_precos
│   ├── q3.c             # busca_por_nome
│   ├── q4.c             # insere_lista_decrescente
│   ├── q5.c             # remove_mais_caro
│   ├── q6.c             # conta_faixa_preco
│   ├── q7.c             # remove_abaixo_de
│   └── q8.c             # mescla_listas
├── tests/
│   └── main.c           # testes manuais das funções
└── README.md
```

## Modelo de dados

```c
#define MAX 100

struct produto {
    int   codigo;
    char  nome[30];
    float preco;
};

typedef struct lista Lista;
```

Definição interna (em `ListaSequencial.c`):

```c
struct lista {
    int qtd;                      // quantidade atual de elementos
    struct produto dados[MAX];    // armazenamento sequencial
};
```

## Como compilar e executar

```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/*.c tests/main.c -o programa
./programa
```

Para compilar uma questão isolada (junto com o restante do TAD):

```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/q5.c <demais arquivos do TAD> tests/main.c -o q5
```
