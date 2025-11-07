#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* novoNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}


void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d", raiz->valor);
        if (raiz->esq != NULL || raiz->dir != NULL) printf(" ");
        preOrdem(raiz->esq);
        if (raiz->esq != NULL && raiz->dir != NULL) printf(" ");
        preOrdem(raiz->dir);
    }
}


void inOrdem(No* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esq);
        printf("%d", raiz->valor);
        if (raiz->dir != NULL) printf(" ");
        inOrdem(raiz->dir);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d", raiz->valor);
        if (raiz->dir != NULL) printf(" ");
    }
}

void preOrdemPrint(No* raiz) {
    if (raiz != NULL) {
        printf("%d", raiz->valor);
        if (raiz->esq != NULL || raiz->dir != NULL) printf(" ");
        preOrdemPrint(raiz->esq);
        if (raiz->dir != NULL) printf(" ");
        preOrdemPrint(raiz->dir);
    }
}

void printPre(No* raiz) {
    if (raiz == NULL) return;
    printf("%d", raiz->valor);
    if (raiz->esq != NULL) printf(" ");
    printPre(raiz->esq);
    if (raiz->dir != NULL) printf(" ");
    printPre(raiz->dir);
}

int primeiro; 

void pre(No* r){
    if(r){
        if(!primeiro) printf(" ");
        printf("%d", r->valor);
        primeiro=0;
        pre(r->esq);
        pre(r->dir);
    }
}

void in(No* r){
    if(r){
        in(r->esq);
        if(!primeiro) printf(" ");
        printf("%d", r->valor);
        primeiro=0;
        in(r->dir);
    }
}

void pos(No* r){
    if(r){
        pos(r->esq);
        pos(r->dir);
        if(!primeiro) printf(" ");
        printf("%d", r->valor);
        primeiro=0;
    }
}


void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main() {
    int C;
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        int N;
        scanf("%d", &N);

        No* raiz = NULL;
        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso);

        primeiro = 1;
        printf("Pre.: ");
        pre(raiz);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        in(raiz);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        pos(raiz);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
