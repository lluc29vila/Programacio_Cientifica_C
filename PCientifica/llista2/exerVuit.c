#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *Ax(int n, double **A, double *x);

int main(void){
	FILE *inp;
	char nomE[30];
	int n, i, j;
	int iter = 0, itermax = 50;
	double presicio = 1e-5, ymax = 0., ymax_prev;
	double **A, *x, *y;

	scanf(" %s", nomE);
	inp = fopen(nomE, "r");
	if(inp == NULL){
		printf("Error al obrir fitxer d'entrada\n");
		return 1;
	}

	fscanf(inp, " %d", &n);

	A = (double**)malloc(n*sizeof(double*));
	if(A == NULL){
		printf("Error de memoria\n");
		fclose(inp);
		return 1;
	}
	for(i = 0; i < n; i++){
		A[i] = (double*)malloc(n*sizeof(double));
		if(A[i] == NULL){
			printf("Error de memoria\n");
			fclose(inp);
			return 1;
		}
	}
	/*Lectura dels elements de la matrriu*/

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			fscanf(inp, " %lf", &A[i][j]);
		}
	}
	fclose(inp);

	/*Inicialització del vector*/
	x = (double*)malloc(n*sizeof(double));
	if(x == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	for(i = 0; i < n; i++) x[i] = 1.;

	/*Calcul iteracions*/
	do {
		ymax_prev = ymax;
		ymax = 0.;
		free(y);
		y = Ax(n, A, x);
		for(i = 0; i < n; i++){
			if(fabs(y[i]) > ymax)
				ymax = fabs(y[i]);
		}
		for(i = 0; i < n; i++)
			x[i] = y[i] / ymax;
		
		printf("\n----------- %d ------------\n", iter);
		printf("x = (");
		for(i = 0; i < n; i++) printf("%.2lf ", x[i]);
		printf(")\n");
		iter++;
	} while(iter <= itermax && fabs(ymax - ymax_prev) > presicio);

	
	if(fabs(ymax) < presicio){
		printf("Convergeix, per tant, ymax es un valor propi de la matriu A y x es un vector associat\n");
	}
	else{
		printf("No convergeix\n");
	}

	for(i = 0; i < n; i++) free(A[i]);
	free(A);
	free(x);
	free(y);

	return 0;
}



double *Ax(int n, double **A, double *x){
	double *y;
	int i, j;

	y = (double*)malloc(n*sizeof(double));
	if(y == NULL){
		printf("Error de memoria\n");
		exit(1);
	}

	/* y = Ax */
	for(i = 0; i < n; i++){
		y[i] = 0.;
		for(j = 0; j < n; j++){
			y[i] += A[i][j]*x[j];
		}
	}

	return y;
}



