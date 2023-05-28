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

No* criar_arvore(){
    return NULL;
}

void destruir_arvore(No **p){
    if(*p == NULL) return;

    destruir_arvore(&((*p)->chave_esq));
    destruir_arvore(&((*p)->chave_dir));
    free(*p);
    *p = NULL;
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