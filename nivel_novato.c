#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct Item
// Cada item terá um nome, um tipo (ex: arma, munição, cura) e a quantidade
typedef struct
{
  char nome[30];
  char tipo[20];
  int quantidade;
} Item;

// Capacidade máxima da mochila
#define MAX_ITENS 10

// Vetor global para armazenar os itens
Item mochila[MAX_ITENS];
int totalItens = 0; // Quantos itens estão cadastrados atualmente

// Função para inserir item na mochila
void inserirItem()
{
  if (totalItens >= MAX_ITENS)
  {
    printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
    return;
  }

  Item novo;
  printf("\n=== Cadastro de Item ===\n");
  printf("Nome do item: ");
  scanf("%s", novo.nome); // lê string simples
  printf("Tipo do item (arma, municao, cura...): ");
  scanf("%s", novo.tipo);
  printf("Quantidade: ");
  scanf("%d", &novo.quantidade);

  // Adiciona o item ao vetor
  mochila[totalItens] = novo;
  totalItens++;

  printf("\nItem cadastrado com sucesso!\n");
}

// Função para remover item da mochila pelo nome
void removerItem()
{
  if (totalItens == 0)
  {
    printf("\nA mochila está vazia. Nada para remover.\n");
    return;
  }

  char nomeRemover[30];
  printf("\nDigite o nome do item que deseja remover: ");
  scanf("%s", nomeRemover);

  int encontrado = -1;
  for (int i = 0; i < totalItens; i++)
  {
    if (strcmp(mochila[i].nome, nomeRemover) == 0)
    {
      encontrado = i;
      break;
    }
  }

  if (encontrado == -1)
  {
    printf("\nItem não encontrado na mochila.\n");
    return;
  }

  // "Puxa" os itens seguintes para frente para preencher o espaço
  for (int i = encontrado; i < totalItens - 1; i++)
  {
    mochila[i] = mochila[i + 1];
  }
  totalItens--;

  printf("\nItem removido com sucesso!\n");
}

// Função para listar todos os itens
void listarItens()
{
  if (totalItens == 0)
  {
    printf("\nA mochila está vazia.\n");
    return;
  }

  printf("\n=== Itens na Mochila ===\n");
  for (int i = 0; i < totalItens; i++)
  {
    printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
           i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
  }
}

// Função de busca sequencial
void buscarItem()
{
  if (totalItens == 0)
  {
    printf("\nA mochila está vazia. Nada para buscar.\n");
    return;
  }

  char nomeBusca[30];
  printf("\nDigite o nome do item que deseja buscar: ");
  scanf("%s", nomeBusca);

  for (int i = 0; i < totalItens; i++)
  {
    if (strcmp(mochila[i].nome, nomeBusca) == 0)
    {
      printf("\nItem encontrado!\n");
      printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
             mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
      return;
    }
  }

  printf("\nItem não encontrado na mochila.\n");
}

// Função principal com menu
int main()
{
  int opcao;

  do
  {
    printf("\n=== Sistema de Inventário ===\n");
    printf("1. Inserir item\n");
    printf("2. Remover item\n");
    printf("3. Listar itens\n");
    printf("4. Buscar item\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      inserirItem();
      listarItens();
      break;
    case 2:
      removerItem();
      listarItens();
      break;
    case 3:
      listarItens();
      break;
    case 4:
      buscarItem();
      break;
    case 0:
      printf("\nSaindo do jogo... Até logo!\n");
      break;
    default:
      printf("\nOpção inválida! Tente novamente.\n");
    }
  } while (opcao != 0);

  return 0;
}
