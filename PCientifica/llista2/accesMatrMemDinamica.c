/*No es poden utilitzar parentesis quadrats p[]*/

#include <stdio.h>
#include <stdlib.h>

#define N 100

double *producteMatrius_Vector(int n, double **a, double *v);
double *producteMatVector_Matriu(int n, double **a, double *v);

int main(void){
	int n, i, j;
	double *v, **a, *result1, *result2;

	printf("Tamany de la matriu i el vector? ");
	scanf(" %d", &n);

	if(n < 0 || n > N){
		printf("Dimensió massa gran\n");
		return 1;
	}

	a = (double**)malloc(n*sizeof(double*));
	if(a==NULL){
		printf("Error de memoria\n");
		return 1;
	}

	printf("La matriu és:\n");

	for(i = 0; i < n; i++){
		*(a+i) = (double*)malloc(n*sizeof(double));
		if(*(a+i) == NULL){
			printf("Error de memoria\n");
			return 1;
		}

		/*Aprofito el bucle de guardar memoria per escanejar les dades*/

		for(j = 0; j < n; j++){
			scanf(" %lf", *(a + i) + j);
		}
	}

	v = (double*)malloc(n*sizeof(double));
	if(v == NULL){
		printf("Error memoria\n");
		return 1;
	}

	printf("El vector és:\n");
	for(i = 0; i < n; i++){
		scanf(" %lf", v+i);
	}

	/*Crido les funcions*/

	result1 = producteMatrius_Vector(n, a, v);
	result2 = producteMatVector_Matriu(n, a, v);

	printf("El resultat de (AA)x és:\n");
	for(i = 0; i < n; i++){
		printf(" %+.2lf", *(result1+i));
	}
	printf("\n");

	printf("El resultat de A(Ax) és:\n");
	for(i = 0; i < n; i++){
		printf(" %+.2lf", *(result2+i));
	}
	printf("\n");

	
	for(i = 0; i < n; i++){
		free(*(a+i));
	}
	free(a);
	free(v);
	free(result1);
	free(result2);


	return 0;
}




double *producteMatrius_Vector(int n, double **a, double *v){
	int i, j, k;
	double **aa, *result;

	result = (double*)malloc(n*sizeof(double));
	if(result == NULL){
		printf("Error de memoria\n");
		exit(1);
	}

	aa = (double**)malloc(n*sizeof(double*));
	if(aa==NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i = 0; i < n; i++){
		*(aa+i) = (double*)malloc(n*sizeof(double));
		if(*(aa+i) == NULL){
			printf("Error de memoria\n");
			exit(1);
		}
	}

	/*producte de matrius*/
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			*(*(aa +i) +j) = 0.;
			for(k = 0; k < n; k++){
				*(*(aa+i)+j) += *(*(a + i)+k) * *(*(a + k)+j);
			}
		}
	}

	/*producte de matriu i vector*/
	for(i = 0; i < n; i++){
		*(result+i) = 0.;
		for(j = 0; j < n; j++){
			*(result + i) += *(*(aa+i)+j) * *(v+j);
		}
	}
	for(i = 0; i < n; i++){
		free(*(aa+i));
	}
	free(aa);
	return result;
}	


double *producteMatVector_Matriu(int n, double **a, double *v){
	int i, j;
	double *aux, *result;
	
	aux = (double*)malloc(n*sizeof(double));
	if(aux==NULL){
		printf("Error de memoria\n");
		exit(1);
	}

	result = (double*)malloc(n*sizeof(double));
	if(result==NULL){
		printf("Error de memoria\n");
		exit(1);
	}

	/*producte de matriu i vector*/
	for(i = 0; i < n; i++){
		*(aux+i) = 0.;
		for(j = 0; j < n; j++){
			*(aux + i) += *(*(a+i)+j) * *(v+j);
		}
	}

	/*producte matriu per vector resultant*/
	for(i = 0; i < n; i++){
		*(result+i) = 0.;
		for(j = 0; j < n; j++){
			*(result + i) += *(*(a+i)+j) * *(aux+j);
		}
	}
	free(aux);
	return result;
}	
