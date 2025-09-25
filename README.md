# Desafio Free Fire – Sistema de Inventário e Torre de Fuga

Este projeto em C implementa três níveis de complexidade para praticar estruturas de dados, ordenação e busca eficiente.

---

## Nível Novato

**Estrutura:**  
- Vetor (array fixo de até 10 itens)

**Funcionalidades:**  
- Inserir item (nome, tipo, quantidade)  
- Remover item por nome  
- Listar itens  
- Buscar item (busca sequencial)  

---

## Nível Aventureiro

**Estruturas:**  
- Vetor (array fixo)  
- Lista encadeada  

**Funcionalidades:**  
- Inserir item  
- Remover item  
- Listar itens  
- Buscar item (busca sequencial)  
- Contagem de comparações realizadas em cada busca  

---

## Nível Mestre

**Estrutura:**  
- Vetor de componentes da torre de fuga (até 20 elementos)  

**Funcionalidades:**  
- Inserir componente (nome, tipo, prioridade)  
- Ordenações:  
  - Bubble Sort → por nome (string)  
  - Insertion Sort → por tipo (string)  
  - Selection Sort → por prioridade (int)  
- Medição de tempo de execução e comparações de cada algoritmo  
- Busca binária por nome para localizar componente-chave  
- Mostrar componentes ordenados  
- Confirmação visual da presença do componente-chave  

---

## Conceitos Estudados

- Vetor e lista encadeada  
- Inserção, remoção, listagem  
- Busca sequencial e binária  
- Contagem de comparações  
- Algoritmos de ordenação clássicos: Bubble, Insertion e Selection Sort  
- Medição de desempenho com `clock()`  
- Modularização de funções  

---

## Comparação Geral

| Nível       | Estruturas       | Operações principais |
|------------|-----------------|--------------------|
| Novato     | Vetor           | Inserir, remover, listar, busca sequencial |
| Aventureiro| Vetor + Lista   | Inserir, remover, listar, busca sequencial, comparações |
| Mestre     | Vetor           | Inserir, ordenar (3 algoritmos), busca binária, medir tempo e comparações |

---


Capturas de Tela
<img src="https://github.com/user-attachments/assets/18c067f0-46b8-49f8-976f-d3218d18bfaa" width="437" height="867" /> <img src="https://github.com/user-attachments/assets/6d84793a-fbde-41a4-b8dc-fe9742760248" width="467" height="769" /> <img src="https://github.com/user-attachments/assets/57267b43-0046-402b-b708-9d3c680eab0b" width="593" height="865" /> ```

## Como Compilar e Executar

```bash
gcc index_novato.c -o nivel_novato
./nivel_novato

gcc index_aventureiro.c -o nivel_aventureiro
./nivel_aventureiro

gcc index_mestre.c -o nivel_mestre
./nivel_mestre

