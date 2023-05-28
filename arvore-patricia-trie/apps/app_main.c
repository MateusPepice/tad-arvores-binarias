#include "arvore_patricia_trie.h"
#include <stdio.h>
#include <stdlib.h>

No* arvore = NULL;

void adicionarChave() {
    int chave;
    printf("VALOR QUE DESEJA INSERIR: ");
    scanf("%d", &chave);
    arvore = inserir(arvore, chave);
    printf("CHAVE INSERIDA COM SUCESSO!\n");
}

void removerChave() {
    // Implement the removal of a key from the trie
}

void imprimirArvore() {
    printf("--- IMPRIMIR ARVORE ---\n");
    imprimir_arvore(arvore, 0);
}

void buscarValor() {
    int busca;
    printf("VALOR QUE DESEJA BUSCAR: ");
    scanf("%d", &busca);
    No* resultado = buscar(arvore, busca);
    if (resultado != NULL)
        printf("CHAVE ENCONTRADA!\n");
    else
        printf("CHAVE NAO ENCONTRADA!\n");
}

void destruirArvore() {
    destruir_arvore(&arvore);
    printf("ARVORE DESTRUÍDA COM SUCESSO!\n");
}

int main() {
    int escolha;
    printf("--- Arvore Digital de Busca, Tries e Patricia Tries ---\n\n");

    do {
        printf("\nESCOLHA UMA FUNCAO PARA REALIZAR:\n");
        printf("1 - ADICIONAR CHAVE\n");
        printf("2 - REMOVER CHAVE\n");
        printf("3 - IMPRIMIR ARVORE\n");
        printf("4 - BUSCAR VALOR\n");
        printf("5 - DESTRUIR ARVORE\n");
        printf("0 - SAIR\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarChave();
                break;
            case 2:
                removerChave();
                break;
            case 3:
                imprimirArvore();
                break;
            case 4:
                buscarValor();
                break;
            case 5:
                destruirArvore();
                break;
            case 0:
                printf("SAINDO DO PROGRAMA...\n");
                break;
            default:
                printf("OPCAO INVALIDA!!\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}
