#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000

typedef struct No {
    int v;
    struct No* proximo;
} No;

No* adj[MAXN + 1];      
int estado[MAXN + 1];   
int achou_ciclo;
int N;

void adicionaAresta(int A, int B) {
    No* novo = (No*)malloc(sizeof(No));
    novo->v = B;
    novo->proximo = adj[A];
    adj[A] = novo;
}

void dfs(int u) {
    if (achou_ciclo) return;

    estado[u] = 1;

    No* p = adj[u];
    while (p != NULL) {
        int v = p->v;

        if (estado[v] == 1) {
            achou_ciclo = 1;
            return;
        } 
        else if (estado[v] == 0) {
            dfs(v);
        }

        p = p->proximo;
    }

    estado[u] = 2; 
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {

        int M;
        scanf("%d %d", &N, &M);


        for (int i = 1; i <= N; i++) {
            adj[i] = NULL;
        }

        for (int i = 1; i <= N; i++) {
            estado[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adicionaAresta(A, B);
        }

        achou_ciclo = 0;

        for (int i = 1; i <= N && !achou_ciclo; i++) {
            if (estado[i] == 0) {
                dfs(i);
            }
        }

        if (achou_ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
