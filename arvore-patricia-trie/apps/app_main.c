#include "arvore_patricia_trie.h"
#include <stdio.h>
#include <stdlib.h> 

void adicionarChave(){
   printf("VALOR QUE DESEJA INSERIR: \n");
}

void removerChave(){

}

void imprimirArvore(){

}

void buscarValor(){

}

int main() { 
   int escolha; 
   
   printf("\n--- Arvore Digital de Busca, Tries e Patricia Tries ---\n\n");

   do
   {
      printf("ESCOLHA UMA FUNCAO PARA REALIZAR:\n");
      printf("1 - ADICIONAR CHAVE\n");
      printf("2 - REMOVER CHAVE\n");
      printf("3 - IMPRIMIR ARVORE\n");
      printf("4 - BUSCAR VALOR\n");
      printf("5 - DESTRUIR ARVORE\n");
      printf("0 - SAIR\n");

      scanf("%i", &escolha);

      switch (escolha)
      {
      case 1:
         
         break;
      case 2:
         /* code */
         break;
      case 3:
         /* code */
         break;
      case 4:
         /* code */
         break;
      case 5:
         /* code */
         break;
      case 0:
         printf("SAINDO DO PROGRAMA...");
         break;
      default:
      printf("OPCAO INVALIDA!!");
         break;
      }
   } while (escolha !=0);

   return 0;

}