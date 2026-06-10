#include <stdio.h>
#include <stdlib.h>

#define N 10000

double horner(double p[], int n, double k);
int prodpol(int n, double *p, int m, double *q, double *pq);

int main(void){
	int n, k, grau, i = 0;
	double *p, *rest, *pq;

	printf("Grau màx del polinomi: ");
	scanf(" %d", &n);
	if(n < 0 || n > 30){
		printf("Grau no vàlid\n");
		return 1;
	}

	p = (double*) malloc((n+1)*sizeof(double)); /*Es reserva la memoria per el vector*/
	if(p == NULL){
		printf("Error memoria\n");
		return 1;
	}

	printf("Coeficients del polinomi de menor a major grau:\n");
	for(i = 0; i <= n; i++){
		scanf(" %lf", &p[i]);
	}

	printf("Valor de k: ");
	scanf(" %d", &k);

	/*Cas especial en el que k = 0 i el resultat seria 1*/

	if(k == 0){
		printf("Grau = 0\nCoeficient = 1\n");
		free(p);
		return 0;
	}

	rest = (double*) malloc((n+1)*sizeof(double));
	if(rest == NULL){
		printf("Error memoria\n");
		return 1;
	}

	for(i = 0; i <= n; i++){
		rest[i] = p[i];
	}

	grau = n;

	for(i = 1; i < k; i++){
		pq = (double*)malloc((2*grau+1)*sizeof(double));
		if(pq == NULL){
			printf("Error memoria\n");
			return 1;
		}

		grau = prodpol(n, p, grau, rest, pq);

		free(rest);
		rest = pq;
	}

	printf("Grau: %d\n", grau);
	printf("Coeficients:\n");
	for(i = 0; i <= grau; i++){
		printf("%.4lf ", rest[i]);
	}
	printf("\n");
	free(rest);
	free(p);

	return 0;
}

double horner(double p[], int n, double k){
	double rest = 0.;
	int i = 0;

	for(i = n; i >= 0; i--){
		rest = rest * k + p[i];
	}
	return rest;
}

int prodpol(int n, double *p, int m, double *q, double *pq){
	int i, j;

	/*Inicialitzem el resultat*/
	for(i = 0; i <= n; i++){
		pq[i] = 0.;
	}

	/*Calculem el producte*/

	for(i = 0; i <= n; i++){
		for(j = 0; j <= m; j++){
			pq[i+j] += p[i]+q[j];
		}
	}
	return m+n;

}
