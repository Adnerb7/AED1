#include <stdio.h>

int main(void) {
    int n[110];     
    int cartas;

    while (1) {
        scanf("%d", &cartas);
        if (cartas == 0) break; //Recebe o valor para a quantidade de cartas e finaliza o programa caso seja igual a 0 

        for (int i = 0; i < cartas; i++) {
            n[i] = i + 1;   
        } //Preenche o vetor com valores que vão de 1 até o numero digitado

        int ini = 0;       
        int fim = cartas;  
        int descartadas[110], qtdDescartadas = 0;

        while (fim - ini > 1) {
            descartadas[qtdDescartadas++] = n[ini++];
            n[fim++] = n[ini++]; ////Processo que transfere a carta seguinte para a ultima posicao 
        }

        printf("Discarded cards:");
        if (qtdDescartadas > 0) { //Descarte das cartas e forma um montinho 
            printf(" %d", descartadas[0]);
            for (int i = 1; i < qtdDescartadas; i++) {
                printf(", %d", descartadas[i]);
            }
        }
        printf("\n");

        printf("Remaining card: %d\n", n[ini]);
    }

    return 0;
}
