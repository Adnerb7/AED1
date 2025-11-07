#include <stdio.h>
#include <stdlib.h>

int main() {
    int numCasos;
    scanf("%d", &numCasos);

    while (numCasos > 0) {

        int numPessoas;
        scanf("%d", &numPessoas);
        int altura[231] = {0};

        for (int i = 0; i < numPessoas; i++) {
            int h;
            scanf("%d", &h);
            altura[h]++;
        }

        int primeiro = 1;
        for (int i = 20; i <= 230; i++) {
            if (altura[i] > 0) {
                for (int j = 0; j < altura[i]; j++) {
                    if (!primeiro)
                        printf(" ");
                    printf("%d", i);
                    primeiro = 0;
                }
            }
        }

        printf("\n");
        numCasos--;
    }

    return 0;
}
