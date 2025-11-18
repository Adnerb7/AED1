#include <stdio.h>

#define MAXV 26  

int adj[MAXV][MAXV];  
int visited[MAXV];

void dfs(int v, int V, char *comp, int *idx) {
    visited[v] = 1;
    comp[(*idx)++] = (char)('a' + v);

    for (int u = 0; u < V; u++) {
        if (adj[v][u] && !visited[u]) {
            dfs(u, V, comp, idx);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int V, E;
        scanf("%d %d", &V, &E);

        for (int i = 0; i < MAXV; i++) {
            for (int j = 0; j < MAXV; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < MAXV; i++) {
            visited[i] = 0;
        }

        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int u = a - 'a';
            int v = b - 'a';
            adj[u][v] = adj[v][u] = 1;
        }

        printf("Case #%d:\n", caseNum);

        int numComp = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                char comp[30];
                int idx = 0;

                dfs(i, V, comp, &idx);


                for (int a = 0; a < idx; a++) {
                    for (int b = a + 1; b < idx; b++) {
                        if (comp[a] > comp[b]) {
                            char tmp = comp[a];
                            comp[a] = comp[b];
                            comp[b] = tmp;
                        }
                    }
                }

                for (int k = 0; k < idx; k++) {
                    printf("%c,", comp[k]);
                }
                printf("\n");

                numComp++;
            }
        }

        printf("%d connected components\n", numComp);
        printf("\n");
    }

    return 0;
}
