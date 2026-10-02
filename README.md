# Listas-Estrutura-de-Dados
# Lista Sequencial Estática de Produtos (TAD)

Implementação de funções sobre uma **lista sequencial estática** de produtos em C. Cada questão da lista de exercícios é resolvida em um arquivo próprio dentro de `src/`, seguindo o padrão `q1.c`, `q2.c`, `q3.c` e assim por diante.

## Sumário

- [Estrutura do projeto](#estrutura-do-projeto)
- [Modelo de dados](#modelo-de-dados)
- [Como compilar e executar](#como-compilar-e-executar)
- [Questões](#questões)
- [Convenções de retorno](#convenções-de-retorno)
- [Técnica de remoção otimizada](#técnica-de-remoção-otimizada)

## Estrutura do projeto

```
.
├── include/
│   ├── ListaSeuencial.h          # TAD público (protótipos, MAX, struct produto)
│   └── lista_struct.h   # definição interna de struct lista (qtd + dados)
├── src/
│   ├── lista4.c         # todas funcoes para praticidade na main
│   ├── q1.c             # lista_tem_espaco
│   ├── q2.c             # soma_precos
│   ├── q3.c             # busca_por_nome
│   ├── q4.c             # insere_lista_decrescente
│   ├── q5.c             # remove_mais_caro
│   ├── q6.c             # conta_faixa_preco
│   └── q7.c             # remove_abaixo_de
│   └── q8.c             # mescla_listas
├── tests/
│   └── main.c           # testes manuais das funções
└── README.md
```

> Como `struct lista` é opaca em `lista.h` (apenas `typedef struct lista Lista;`), cada `qN.c` inclui também `lista_struct.h` para acessar `li->qtd` e `li->dados`.

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

Definição interna (em `lista_struct.h`):

```c
struct lista {
    int qtd;                      // quantidade atual de elementos
    struct produto dados[MAX];    // armazenamento sequencial
};
```

> Ajuste os nomes dos campos (`qtd`, `dados`) caso a sua definição real seja diferente.

### Funções base do TAD

| Função | Descrição |
|---|---|
| `cria_lista` / `libera_lista` | criação e liberação da lista |
| `busca_lista_pos` / `busca_lista_cod` | busca por posição / código |
| `insere_lista_final` / `_inicio` / `_ordenada` | inserções |
| `remove_lista` / `_otimizado` / `_inicio` / `_final` | remoções |
| `tamanho_lista` / `lista_cheia` / `lista_vazia` | consultas de estado |

> Correção no `.h`: remova o `typedef struct lista Lista;` duplicado e o `;` solto, que podem gerar erro ou warning.

## Como compilar e executar

```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/*.c tests/main.c -o programa
./programa
```

Para compilar uma questão isolada (junto com o restante do TAD):

```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/q5.c <demais arquivos do TAD> tests/main.c -o q5
```
