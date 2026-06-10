#include <stdio.h>
#include <stdlib.h>

double horner(int n, double *pol, double x0);
double **reserva_mem(int n);
void liberar_mem(double **pol, int n);

int main(void){
	int i, j, n;
	double **pol, x0;

	printf("Dona'm el grau del polinomi: ");
	scanf(" %d", &n);

	pol = reserva_mem(n);

	/*Guardo els coefiecients del polinomi en la primera fila de la matriu. La matriu triangular serà superior*/

	printf("Dona`m els coeficinets del polinomi de menor a major grau:\n");
	for(i = 0; i <= n; i++){
		scanf(" %lf", &pol[0][i]);
	}

	printf("Dona'm un punt per calcular els polinomis: ");
	scanf(" %lf", &x0);


	/*Calcul coeficients derivada*/

	for(i = 1; i <= n; i++){
		for(j = 0; j <= n-i; j++){
			pol[i][j] = pol[i-1][j+1]*(j+1);
		}
	}

	for(i = 0; i < n; i++){
		printf("\np^(%d) grau %d, coeficients:\n", i, n-i); 
		for(j = 0; j <= n-i; j++){
			printf(" %+.2lf", pol[i][j]);
		}
	}	

	/*Avaluació del polinomi i les seves derivades en el punt x0*/

	for(i = 0; i <= n; i++){
		printf("\np^(%d)(x0) = %+.4lf\n", i, horner(n, pol[i], x0));
	}

	/*Alliberament de memoria*/

	liberar_mem(pol, n);

	return 0;
}



double horner(int n, double *pol, double x0){
	double result = 0.;
	int i;

	for(i = n; i >= 0; i--){
		result = result*x0 + pol[i];
	}

	return result;
}

double **reserva_mem(int n){
	double **a;
	int i;

	a = (double**)malloc((n+1)*sizeof(double*));
	if(a == NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i = 0; i <= n; i++){
		a[i] = (double*)malloc((n+1)*sizeof(double));
		if(a[i] == NULL){
			printf("Error de memoria\n");
			exit(1);
		}
	}
	return a;
}

void liberar_mem(double **pol, int n){
	int i;

	for(i = 0; i <= n; i++) free(pol[i]);
	free(pol);
}
	
