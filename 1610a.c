#include <stdio.h>

#define MAXN 10000

char mat[MAXN + 1][MAXN + 1];  
int estado[MAXN + 1]; 
int achou_ciclo;
int N;

void dfs(int u) {
    if (achou_ciclo) return;

    estado[u] = 1; 


    for (int v = 1; v <= N; v++) {

        if (mat[u][v]) {

        
            if (estado[v] == 1) {
                achou_ciclo = 1;
                return;
            }

            else if (estado[v] == 0) {
                dfs(v);
            }
        }
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
            for (int j = 1; j <= N; j++) {
                mat[i][j] = 0;
            }
        }

        for (int i = 1; i <= N; i++) {
            estado[i] = 0;
        }


        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            mat[A][B] = 1; 
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
