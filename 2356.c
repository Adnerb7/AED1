#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101 // 100 caracteres + \0

int main() {
    char D[MAX_SIZE]; 
    char S[MAX_SIZE];

    while (scanf("%s", D) != EOF) {
        if (scanf("%s", S) != 1) break;

        if (strstr(D, S) != NULL) {
            printf("Resistente\n");
        } else {
            printf("Nao resistente\n");
        }
    }

    return 0;
}
