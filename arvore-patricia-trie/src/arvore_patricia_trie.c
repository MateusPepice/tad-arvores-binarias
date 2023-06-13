#include "../include/arvore_patricia_trie.h" 
#include <stdio.h>
#define bits_na_chave 4

typedef struct No {
    int chave;
    struct No *chave_esq;
    struct No *chave_dir;
} No;

/* k representa o nivel em que está sendo feito a busca na arvore. Como vimos nos estudos sobre
Árvore Digitais de Busca, assim como a inserção a busca se faz olhando unicamente o k-ésimo valor binário
daquela chave. Sendo assim, no nível 0 será olhado para o primeiro bit, no nível 1 para o segundo bit 
e assim por diante.*/
int bits(int chave, int k){ 
    return (chave >> (bits_na_chave - 1 - k)) & 1;
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
    if (p == NULL){
        printf("REGISTRO NAO ENCONTRADO!\n");
        return NULL;
    }
    if (busca == p->chave){
        printf("CHAVE ENCONTRADA NO NIVEL %d\n", nivel);
        return p;
    }
    if (bits(busca, nivel) == 0){
        return buscar_rec(p->chave_esq, busca, nivel+1);
    }else{
        return buscar_rec(p->chave_dir, busca, nivel+1);
    }
}

No* inserir_rec(No *p, int chave, int nivel){
    if(p == NULL){
        No* novo = (No*) malloc(sizeof(No));
        //Como ambas as direções são novos, o NULL será igual para ambas
        novo->chave_esq = novo->chave_dir = NULL; 
        novo->chave = chave;
        return novo;
    }
    if(chave == p->chave){
        printf("\nVALOR JA INSERIDO!\n");
        return p;
    }
    if(bits(chave,nivel) == 0){
        p->chave_esq = inserir_rec(p->chave_esq, chave, nivel+1);
    } else {
        p->chave_dir = inserir_rec(p->chave_dir, chave, nivel+1);
    }
    return p;
}

No* inserir(No *p, int chave){
    return inserir_rec(p, chave, 0);
}

void imprimir_bits(int chave){
    size_t i;
    for(i = 0; i < bits_na_chave; i++){
        printf("%d", bits(chave, i));
    }
    printf("\t{%d}\n", chave);
}

void imprimir_arvore(No* p, int nivel) {
    if (p != NULL) {
        imprimir_arvore(p->chave_dir, nivel + 1);
        for (int i = 0; i < nivel; i++)
            printf("-");
        imprimir_bits(p->chave);
        imprimir_arvore(p->chave_esq, nivel + 1);
    }
}

int remover_chave(No **p, int chave){
    if(*p == NULL) return 0;
    return 0;
}