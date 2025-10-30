// Implementação de uma fila circular usando listas encadeadas em C. Exercício 5.4.2 da apostila do Feofiloff 

#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int dado;
    struct cel *prox;
} Celula;

Celula* cria_fila() {
    Celula *cabeca = (Celula*) malloc(sizeof(Celula));
    cabeca->prox = cabeca;
    return cabeca;
}
void enfileira(Celula *cabeca, int x) {
    Celula *novo = (Celula*) malloc(sizeof(Celula));
    novo->dado = x;

    Celula *p = cabeca;
    while (p->prox != cabeca) p = p->prox;
    p->prox = novo;
    novo->prox = cabeca;
}

int desenfileira(Celula *cabeca) {
    if (cabeca->prox == cabeca) {
        printf("Fila vazia!\n");
        return -1;
    }
    Celula *remover = cabeca->prox;
    int x = remover->dado;
    cabeca->prox = remover->prox;
    free(remover);
    return x;
}
void mostra_fila(Celula *cabeca) {
    Celula *p = cabeca->prox;
    while (p != cabeca) {
        printf("%d ", p->dado);
        p = p->prox;
    }
    printf("\n");

}
