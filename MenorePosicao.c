//Menor e Posição 


#include <stdio.h> 

int main () {
	int v[1000];
	int a;
	int posicao = 0;
	int menor;

scanf("%d", &a); 

for (int i = 0; i < a; i++) {
	scanf("%d", &v[i]);
}
	menor = v[0];
for (int i = 0; i < a; i++) {
	if (v[i] < menor) { 
	menor = v[i];
    posicao = i;}
}

	printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
return 0;

}