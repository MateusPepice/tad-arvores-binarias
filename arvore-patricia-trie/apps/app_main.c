#include "../include/arvore_patricia_trie.h" 
#include <stdio.h>
#include <stdlib.h> 

int chaveGlobal;

void adicionarChave(){
   printf("VALOR QUE DESEJA INSERIR: \n");
   scanf("%d", &chaveGlobal);
}

void removerChave(){
   printf("VALOR QUE DESEJA REMOVER: \n");
   scanf("%d", &chaveGlobal);
}

void buscarChave(){
   printf("VALOR QUE DESEJA BUSCAR: \n");
   scanf("%d", &chaveGlobal);
}

int main() { 
   int escolha; 
   No *trie = criar_arvore();

   printf("\n--- Arvore Digital de Busca, Tries e Patricia Tries ---\n\n");

   do
   {
      printf("------------------------------------------------\n");
      printf("ESCOLHA UMA FUNCAO PARA REALIZAR:\n");
      printf("1 - ADICIONAR CHAVE\n");
      printf("2 - REMOVER CHAVE\n");
      printf("3 - IMPRIMIR ARVORE\n");
      printf("4 - BUSCAR VALOR\n");
      printf("5 - DESTRUIR ARVORE\n");
      printf("0 - SAIR\n");
      printf("------------------------------------------------\n");

      scanf("%i", &escolha);

      switch (escolha)
      {
      case 1:
         adicionarChave();
         trie = inserir(trie, chaveGlobal);
         break;
      case 2:
         removerChave();
         trie = remover_chave(trie, chaveGlobal);
         break;
      case 3:
         imprimir_arvore(trie, 0);
         break;
      case 4:
         buscarChave();
         buscar(trie, chaveGlobal);
         break;
      case 5:
         destruir_arvore(&trie);
         printf("ARVORE DESTRUIDA!\n");
         break;
      case 0:
         printf("SAINDO DO PROGRAMA...");
         break;
      default:
      printf("OPCAO INVALIDA!!\n");
         break;
      }
   } while (escolha !=0);

   return 0;

}