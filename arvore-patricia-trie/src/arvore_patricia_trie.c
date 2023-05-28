#include "arvore_patricia_trie.h" 
#include <stdio.h>

typedef struct No {
    unsigned chave;
    struct No *chave_esq;
    struct No *chave_dir;
} No;

/* k representa o nivel em que está sendo feito a busca na arvore. Como vimos nos estudos sobre
Árvore Digitais de Busca, assim como a inserção a busca se faz olhando unicamente o k-ésimo valor binário
daquela chave. Sendo assim, no nível 0 será olhado para o primeiro bit, no nível 1 para o segundo bit 
e assim por diante.*/
int bits(int chave, int k){ 
    /*Realizando esta função com o size_bits fica mais fácil manutenir o código pois, se quisermos
    alterar o tipo da chave iremos alterar SOMENTE o tipo da chave e o RETORNO, e não o 
    tipo e o tamanho do tipo*/
    int size_bits = sizeof(chave) * 8;
    printf("%d", size_bits);
    return chave >> (size_bits - 1 - k) & 1;

}

/*
Cria uma nova arvore.
*/
No* criar_arvore() {
    No* arvore = (No*)malloc(sizeof(No));
    arvore->chave = -1;
    arvore->chave_esq = NULL;
    arvore->chave_dir = NULL;
    return arvore;
}

/*
Função criada para compensar tempo ao não ter que
 ficar criando e dando Malloc toda vez que quiser criar um novo nó.
*/

No* criar_no(unsigned chave){
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = chave;
    novo->chave_esq = NULL;
    novo->chave_dir = NULL;
    return novo;
}


void destruir_arvore(No **p){
    if(*p == NULL) 
        return;

    destruir_arvore(&((*p)->chave_esq));
    destruir_arvore(&((*p)->chave_dir));
    free(*p);
    *p = NULL;
}


No* inserir(No* p, int chave) {
    if (p == NULL) {
        No* novo = criar_no(chave);
        return novo;
    }

    int nivel = 0;
    No* atual = p;
    No* pai = NULL;

    while (true) {
        if (bits(chave, nivel) == 0) {
            if (atual->chave_esq == NULL) {
                atual->chave_esq = criar_arvore();
            }
            pai = atual;
            atual = atual->chave_esq;
        } else {
            if (atual->chave_dir == NULL) {
                atual->chave_dir = criar_arvore();
            }
            pai = atual;
            atual = atual->chave_dir;
        }
        nivel++;

        if (bits(chave, nivel) != bits(atual->chave, nivel - 1))
            break;
    }

    No* novo = criar_no(chave);

    if (bits(chave, nivel) == 0) {
        pai->chave_esq = novo;
        novo->chave_esq = atual;
    } else {
        pai->chave_dir = novo;
        novo->chave_dir = atual;
    }

    return p;
}

No* buscar(No *p, int busca){
    return buscar_rec(p, busca, 0);
}

No* buscar_rec(No *p, int busca, int nivel){
    if (p == NULL)
        return NULL;
    if (busca == p->chave)
        return p;
    if (bits(busca, nivel) == 0)
        return buscar_rec(p->chave_esq, busca, nivel+1);
    else
        return buscar_rec(p->chave_dir, busca, nivel+1);
}

void imprimir_arvore(No* p, int nivel) {
    if (p != NULL) {
        imprimir_arvore(p->chave_esq, nivel + 1);
        for (int i = 0; i < nivel; i++)
            printf("  ");
        printf("%d\n", p->chave);
        imprimir_arvore(p->chave_dir, nivel + 1);
    }
}