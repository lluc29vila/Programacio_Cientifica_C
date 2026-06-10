#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double det(double **Mat, int n);

int main(void){
	double **M;
	int i, j, n;
	double deter;

	srand(time(NULL));

	printf("Valor de n: ");
	scanf(" %d", &n);

	M = (double**)malloc(n*sizeof(double*));
	if(M == NULL){
		printf("Error al guardar memoria\n");
		return 1;
	}
	for(i = 0; i < n; i++){
		M[i] = (double*)malloc(n*sizeof(double));
		if(M[i] == NULL){
			printf("Error al reservar memoria\n");
			free(M);
			return 1;
		}

		/*Generar la funció de Hessemberg*/

		for(j = 0; j < n; j++){
			if(j > i+1) M[i][j] = 0.;
			else M[i][j] = ((double)rand()/RAND_MAX)*200. - 100; /*Generació aleatoria d'elements entre -100 i 100*/
		}
	}

	deter = det(M, n);

	printf("Determinant = %.3lf\n", deter);

	for(i = 0; i < n; i++)free(M[i]);
	free(M);

	return 0;
}


double det(double **M, int n){

	int i, j, z;
	double sum = 0.;
	double ** aux;
	double sign = -1.;

	/*Casos simples*/
	if(n == 1) return M[0][0];

	if(n == 2) return M[0][0]*M[1][1] - M[1][0]*M[0][1];

	/*Reserva de memoria matriu dimensió n-1*/
	aux = (double**)malloc((n-1)*sizeof(double*));
	if(aux == NULL){
		printf("Error al guardar memoria\n");
		exit(1);
	}
	for(i = 0; i < n-1; i++){
		aux[i] = (double*)malloc((n-1)*sizeof(double));
		if(aux[i] == NULL){
			printf("Error al reservar memoria\n");
			free(aux);
			exit(1);
		}
	}

	for(i = 0; i < n; i++){
		/*Eliminem fila i i columna 0*/
		for(j = 0; j < n-1; j++){
		       for(z = 0; z < i; z++){
			       aux[z][j] = M[z][j];
		       }
		       for(z = i+1; z < n; z++){
			       aux[z-1][j] = M[z][j];
		       }
		}
		
		/*Producte del determinant adjunt per a M[i][n-1] amb canvis de signe*/
		sum += M[i][n-1]*sign*det(aux, n-1);
		sign = -sign;
	}
	for(i = 0; i < n-1; i++)free(aux[i]);
	free(aux);

	return sum;
}
		
		
