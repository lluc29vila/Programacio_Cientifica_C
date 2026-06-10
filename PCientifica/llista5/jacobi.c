#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int fil;
	int col;
	double val;
}ele;

double norma2(double *x, double *y, int n);

int main(void){

	FILE *inp;
	char nomE[30];
	
	int n, qu;
	int i, j, k, iter = 50, conv = 0;
	double prec = 1e-6;
	ele * A;
	double *b, *x, *aux;
	double suma, diagonal, error;

	scanf(" %s", nomE);
	inp = fopen(nomE, "r");
	if(inp == NULL){
		printf("Error al intentar obrir fitxer\n");
		return 1;
	}
	
	/*Lectura dades*/

	fscanf(inp, " %d %d", &n, &qu);
	
	A = (ele*)malloc(qu*sizeof(ele));
	if(A == NULL){
		printf("Error al reservar memoria\n");
		fclose(inp);
		return 1;
	}

	for(i = 0; i < qu; i++){
		fscanf(inp, " %d %d %lf", &A[i].fil, &A[i].col, &A[i].val);
	}

	b = (double*)malloc(n*sizeof(double));
	if(b == NULL){
		printf("Error la reservar memoria\n");
		fclose(inp);
		free(A);
	}

	for(i = 0; i < n; i++){
		fscanf(inp, " %lf", &b[i]);
	}

	fclose(inp);
		

	/*Vector x i aux*/
	x = (double*)malloc(n*sizeof(double));
	if(x == NULL){
		printf("Error al reservar memoria\n");
		free(A);
		free(b);
		return 1;
	}
	aux = (double*)malloc(n*sizeof(double));
	if(aux == NULL){
		printf("Error al reservar memoria\n");
		free(A);
		free(b);
		free(x);
		return 1;
	}

	/*Aproximacio inicial a 0*/
	for(i = 0; i < n; i++){
		x[i] = 0.;
	}

	/*Metode Jacobi*/

	i = 0;

	while(i < iter && conv == 0){
		for(k = 0; k < n; k++){

			suma = 0.;
			diagonal = 0.;

			for(j = 0; j < qu; j++){
				if(A[j].fil == k){
					if(A[j].col == k){
						diagonal = A[j].val;
					}
					else{
						suma += A[j].val * x[A[j].col];
					}
				}
			}

			if(diagonal == 0.){
				printf("Error per diagonal nula\n");
				free(A);
				free(b);
				free(x);
				free(aux);

				return 1;
			}

			aux[k] = (b[k] - suma)/diagonal;
		}

		error = norma2(x, aux, n);
	
		printf("Iteració = %d\nError = %lf\n", i+1, error);

		if(error < prec){
			conv = 1;
		}
		else{
			for(j = 0; j < n; j++){
				x[j] = aux[j];
			}
		}
		i++;
	}
	
	if(conv == 1){
		printf("Ha convegit a la solucio aprox.:\nx = (");
		for(i = 0; i < n; i++){
			printf("%.2lf ", aux[i]);
		}
		printf(")");
	}
	else{
		printf("El metode no ha convergit\n");
	}

	free(A);
	free(b);
	free(aux);
	free(x);

	return 0;
}

double norma2(double *x, double *y, int n){
	double suma = 0.;
	int i;

	for(i = 0; i < n; i++){
		suma += (y[i] - x[i]) * (y[i] - x[i]);
	}

	return suma;
}

