#include <stdio.h>
#include <stdlib.h>
#define N 20

void ordenar(int *perm, int inici, int fi);
int seguent_permutacio(int n, int *perm);
void escriure_permutacio(FILE *f, int *perm, int n);

int main(void){
	int n, i;
	int *perm;
	FILE *out;
	char nameE[20];

	printf("n = ");
	scanf(" %d", &n);
	if( n > N || n < 2) return 1;

	perm = (int*)malloc(n*sizeof(int));
	if(perm == NULL){
		printf("Error de memoria\n");
		return 1;
	}

	printf("Nom fitxer sortida: ");
	scanf(" %s", nameE);

	out = fopen(nameE, "w");
	if(out == NULL){
		printf("Error obrir fitxer de sortida\n");
		free(perm);
		return 1;
	}

	/*Permutació inicial*/
	for(i = 0; i < n; i++){
		perm[i] = i+1;
	}

	escriure_permutacio(out, perm, n);

	while(seguent_permutacio(n, perm) == 0){
		escriure_permutacio(out, perm, n);
	}
	fclose(out);
	free(perm);

	return 0;
}




void ordenar(int *perm, int inici, int fi){
	int i, j, aux;

	for(i = inici; i < fi; i++){
		for(j = inici; j < fi - (i - inici); j++){
			
			if(perm[j] > perm[j+1]){
				aux = perm[j];
				perm[j] = perm[j+1];
				perm[j+1] = aux;
			}
		}
	}
}


int seguent_permutacio(int n, int *perm){
	int i = n-1;
	int j = n-1;
	int aux;

	/*Busco quan di-1 > di */
	while(i > 0 && perm[i] <= perm[i-1]){
		i--;
	}
	if(i == 0) return 1; /*No s'ha trobat seguent*/


	/*Busco el més petit a partir de di-1*/
	while(perm[j] <= perm[i-1]){
		j--;
	}

	/*Ordenar*/
	aux = perm[i-1];
	perm[i-1] = perm[j];
	perm[j] = aux;

	/*Ordenar tros final*/
	ordenar(perm, i, n-1);

	return 0;
}

void escriure_permutacio(FILE *f, int *perm, int n){
	int i;

	for(i = 0; i < n; i++){
		fprintf(f, "%d ", perm[i]);
	}
	fprintf(f, "\n");
}
