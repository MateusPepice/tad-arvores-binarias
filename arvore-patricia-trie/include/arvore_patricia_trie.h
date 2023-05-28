#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 

typedef struct No No;

/*Tipos que podem ser chaves: INT, CHAR, UNSIGNED*/
int bits(int chave, int nivel);

No* criar_arvore();
void destruir_arvore(No **p);

No* inserir (No* p, int chave);
No* buscar (No* p, int busca);
No* buscar_rec(No *p, int busca, int nivel);

void imprimir_avore (No* p, int nivel);