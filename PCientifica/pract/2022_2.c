#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dist(int n, double *x, double *y);
double f(int m, int n, double **q, double *x);
int iter(int m, int n, double **q, double *x, double *fx, double h);


int main(void){


	return 0;
}

double dist(int n, double *x, double *y){
	int i;
	double suma = 0.;

	for(i = 0; i < n; i++){
		suma += (x[i] - y[i])*(x[i] - y[i]);
	}
	
	return sqrt(suma);
}

double f(int m, int n, double **q, double *x){
	double result = 0.;
	int i;

	for(i = 0; i < m; i++){
		result += dist(n, x, q[i]);
	}
	return result;
}
		
int iter(int m, int n, double **q, double *x, double *fx, double h){
	double *y;

	y = (double*)malloc(n*sizeof(double));
	if(y == NULL){
		printf("Error al reservar memoria\n");
		exit(1);
	}

	for(i = 0; i < n; i++){
		y[i] = x[i];
	}

	for(i = 0; i < n; i++){
		y[i] = x[i]+h;

		if(f(m, n, q, y) < f(m, n, q, x)){
			x[i] = y[i];
			fx = f(m, n, q, y);
			free(y);
			return 1;
		}
		x[i] = y[i];
	}
	free(y);
	return 0;
}


	


