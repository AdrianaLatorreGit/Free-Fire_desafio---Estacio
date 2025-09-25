#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa um item (nome, tipo e quantidade)
typedef struct
{
  char nome[30];
  char tipo[20];
  int quantidade;
} Item;

// Nó para a lista encadeada (contém um Item e ponteiro para o próximo)
typedef struct No
{
  Item dados;
  struct No *proximo;
} No;

/* -------------------- Variáveis globais -------------------- */
Item mochilaVetor[MAX_ITENS];
int totalVetor = 0;      // quantidade atual de itens no vetor
No *mochilaLista = NULL; // cabeça da lista encadeada

// Contadores de comparações para buscas sequenciais
int comparacoesSeqVetor = 0;
int comparacoesSeqLista = 0;

/* -------------------- Funções para o VETOR -------------------- */

// Insere um item no vetor (até MAX_ITENS)
void inserirItemVetor()
{
  if (totalVetor >= MAX_ITENS)
  {
    printf("\nMochila (vetor) cheia! Não é possível adicionar mais itens.\n");
    return;
  }
  Item novo;
  printf("\n== Inserir no Vetor ==\n");
  printf("Nome: ");
  scanf(" %29s", novo.nome); // usa width para evitar overflow
  printf("Tipo: ");
  scanf(" %19s", novo.tipo);
  printf("Quantidade: ");
  scanf("%d", &novo.quantidade);

  mochilaVetor[totalVetor++] = novo;
  printf("Item adicionado ao vetor!\n");
}

// Remove um item do vetor pelo nome (desloca elementos para preencher)
void removerItemVetor()
{
  if (totalVetor == 0)
  {
    printf("\nMochila (vetor) vazia! Nada para remover.\n");
    return;
  }
  char nome[30];
  printf("\nNome do item a remover: ");
  scanf(" %29s", nome);

  int encontrado = -1;
  for (int i = 0; i < totalVetor; i++)
  {
    if (strcmp(mochilaVetor[i].nome, nome) == 0)
    {
      encontrado = i;
      break;
    }
  }
  if (encontrado == -1)
  {
    printf("Item não encontrado no vetor.\n");
    return;
  }
  // desloca para a esquerda
  for (int i = encontrado; i < totalVetor - 1; i++)
  {
    mochilaVetor[i] = mochilaVetor[i + 1];
  }
  totalVetor--;
  printf("Item removido do vetor com sucesso!\n");
}

// Lista todos os itens do vetor
void listarItensVetor()
{
  if (totalVetor == 0)
  {
    printf("\nMochila (vetor) vazia.\n");
    return;
  }
  printf("\n=== Itens na Mochila (Vetor) ===\n");
  for (int i = 0; i < totalVetor; i++)
  {
    printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
           i + 1, mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
  }
}

// Busca sequencial no vetor (conta comparações)
void buscarSequencialVetor()
{
  if (totalVetor == 0)
  {
    printf("\nMochila (vetor) vazia. Nada para buscar.\n");
    return;
  }
  char nome[30];
  printf("\nNome do item a buscar (sequencial no vetor): ");
  scanf(" %29s", nome);

  comparacoesSeqVetor = 0;
  for (int i = 0; i < totalVetor; i++)
  {
    comparacoesSeqVetor++;
    if (strcmp(mochilaVetor[i].nome, nome) == 0)
    {
      printf("Item encontrado no vetor! Nome: %s | Tipo: %s | Quantidade: %d\n",
             mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
      printf("Comparações (sequencial - vetor): %d\n", comparacoesSeqVetor);
      return;
    }
  }
  printf("Item não encontrado no vetor.\n");
  printf("Comparações (sequencial - vetor): %d\n", comparacoesSeqVetor);
}

// Ordena o vetor por nome (Bubble Sort). Necessário para demonstrar ordenação.

void ordenarVetor()
{
  if (totalVetor <= 1)
  {
    printf("\nNada a ordenar (0 ou 1 item).\n");
    return;
  }
  for (int i = 0; i < totalVetor - 1; i++)
  {
    for (int j = 0; j < totalVetor - i - 1; j++)
    {
      if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0)
      {
        Item tmp = mochilaVetor[j];
        mochilaVetor[j] = mochilaVetor[j + 1];
        mochilaVetor[j + 1] = tmp;
      }
    }
  }
  printf("\nVetor ordenado por nome (Bubble Sort).\n");
}

/* -------------------- Funções para a LISTA ENCADEADA -------------------- */

// Insere item no início da lista
void inserirItemLista()
{
  No *novo = (No *)malloc(sizeof(No));
  if (!novo)
  {
    printf("Erro de alocação de memória.\n");
    return;
  }
  printf("\n== Inserir na Lista ==\n");
  printf("Nome: ");
  scanf(" %29s", novo->dados.nome);
  printf("Tipo: ");
  scanf(" %19s", novo->dados.tipo);
  printf("Quantidade: ");
  scanf("%d", &novo->dados.quantidade);

  novo->proximo = mochilaLista; // insere no início
  mochilaLista = novo;
  printf("Item adicionado à lista encadeada!\n");
}

// Remove um item da lista pelo nome
void removerItemLista()
{
  if (mochilaLista == NULL)
  {
    printf("\nMochila (lista) vazia! Nada para remover.\n");
    return;
  }
  char nome[30];
  printf("\nNome do item a remover da lista: ");
  scanf(" %29s", nome);

  No *atual = mochilaLista;
  No *anterior = NULL;

  while (atual != NULL && strcmp(atual->dados.nome, nome) != 0)
  {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL)
  {
    printf("Item não encontrado na lista.\n");
    return;
  }

  if (anterior == NULL)
  {
    // removendo o primeiro nó
    mochilaLista = atual->proximo;
  }
  else
  {
    anterior->proximo = atual->proximo;
  }
  free(atual);
  printf("Item removido da lista com sucesso!\n");
}

// Lista todos os itens na lista encadeada
void listarItensLista()
{
  if (mochilaLista == NULL)
  {
    printf("\nMochila (lista) vazia.\n");
    return;
  }
  printf("\n=== Itens na Mochila (Lista Encadeada) ===\n");
  No *atual = mochilaLista;
  int i = 1;
  while (atual != NULL)
  {
    printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
           i, atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
    atual = atual->proximo;
    i++;
  }
}

// Busca sequencial na lista encadeada (conta comparações)
void buscarItemLista()
{
  if (mochilaLista == NULL)
  {
    printf("\nMochila (lista) vazia. Nada para buscar.\n");
    return;
  }
  char nome[30];
  printf("\nNome do item a buscar (sequencial na lista): ");
  scanf(" %29s", nome);

  comparacoesSeqLista = 0;
  No *atual = mochilaLista;
  while (atual != NULL)
  {
    comparacoesSeqLista++;
    if (strcmp(atual->dados.nome, nome) == 0)
    {
      printf("Item encontrado na lista! Nome: %s | Tipo: %s | Quantidade: %d\n",
             atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
      printf("Comparações (sequencial - lista): %d\n", comparacoesSeqLista);
      return;
    }
    atual = atual->proximo;
  }
  printf("Item não encontrado na lista.\n");
  printf("Comparações (sequencial - lista): %d\n", comparacoesSeqLista);
}

/* Libera todos os nós da lista antes de sair */
void liberarLista()
{
  No *atual = mochilaLista;
  while (atual != NULL)
  {
    No *prox = atual->proximo;
    free(atual);
    atual = prox;
  }
  mochilaLista = NULL;
}

/* -------------------- Função principal (menu) -------------------- */

int main()
{
  int estrutura = -1;
  int opcao = -1;

  do
  {
    printf("\n=== Sistema de Inventário (Nível Aventureiro) ===\n");
    printf("Escolha a estrutura para operar:\n");
    printf("1 - Vetor (lista sequencial)\n");
    printf("2 - Lista encadeada\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &estrutura);

    if (estrutura == 1)
    {
      do
      {
        printf("\n--- Menu: Vetor ---\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar (sequencial)\n");
        printf("5 - Ordenar vetor (por nome)\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
          inserirItemVetor();
          break;
        case 2:
          removerItemVetor();
          break;
        case 3:
          listarItensVetor();
          break;
        case 4:
          buscarSequencialVetor();
          break;
        case 5:
          ordenarVetor();
          break;
        case 0:
          break;
        default:
          printf("Opção inválida. Tente novamente.\n");
        }
      } while (opcao != 0);
    }
    else if (estrutura == 2)
    {
      do
      {
        printf("\n--- Menu: Lista Encadeada ---\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar (sequencial)\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
          inserirItemLista();
          break;
        case 2:
          removerItemLista();
          break;
        case 3:
          listarItensLista();
          break;
        case 4:
          buscarItemLista();
          break;
        case 0:
          break;
        default:
          printf("Opção inválida. Tente novamente.\n");
        }
      } while (opcao != 0);
    }
    else if (estrutura != 0)
    {
      printf("Escolha inválida. Digite 1, 2 ou 0.\n");
    }

  } while (estrutura != 0);

  // libera memória antes de sair
  liberarLista();
  printf("\nEncerrando. Até a próxima!\n");
  return 0;
}
