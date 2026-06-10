#include <stdio.h>
#define N 20
double prodMatMat(int, int, int, double[][], double[][]);
double prodMatVect(int, double[][], double[]);

int main(void){
	int i = 0, m, n, p, j = 0, k = 0;
	double x[N], y[N], A[N][N], B[N][N], C[N][N];

	/*Lectura de tamanys A*/
	do{
		printf("Dona'm el tamany de la matriu A (nxm): ");
		scanf(" %d %d", &n, &m);

		if(n > N || m > N){
			printf("Massa gran torneu a introduir\n");
		}
	}while(n > N || m > N);
	
	/*Lectura de tamanys B*/
	do{
		printf("Dona'm el tamany de la matriu B (mxp): ");
		scanf(" %d %d", &m, &p);

		if(p > N || m > N){
			printf("Massa gran torneu a introduir\n");
		}
	}while(m > N || p > N);

	/*Lectura de vectors*/

	printf("Introdueix els valors de la primera matriu:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf(" %lf", &A[i][j]);
		}
	}

	printf("Introudeix els valors de la segona matriu:\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < p; j++){
			scanf(" %lf", &B[i][j]);
		}
	}
	
	printf("Dona'm el vector:\n");
	for(i = 0; i < n; i++){
		scanf(" %lf", &v[i]);
	}

	/*producte de les matrius*/
	C = prodMatMat(n, m, p, A, B);

	/*producte de la matriu resultant pel vector*/
	y = prodMatVect(n, C, x);

	/*Imprimir resultats*/
	
	printf("A=\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%lf ", A[i][j]);
		}
		printf("\n");
	}
	printf("\nB=\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < p; j++){
			printf("%lf ", B[i][j]);
		}
		printf("\n");
	}
	printf("\nx = (");
	for(i = 0; i < m; i++){
		printf("%lf ", x[i]);
	}
	printf(")\nEl resultat y = (");
	for(i = 0; i < m; i++){
		printf("%lf ", y[i]);
	}

	return 0;
}




double prodMatVect(int n, double A[][], v[]){
	int i = 0, j = 0;
	double result[n];

	for(i = 0; i < n; i++){
		result[i] = 0.;
		for(j = 0; j < n; j++){
			result[i] += A[i][j] * v[i];
		}
	}
	return result;
}

double prodMatMat(int n, int m, int p, double v[][], double w[][]){
	int i = 0, j = 0, k = 0;
	double result[n][p]
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			result[i][j] = 0.;
			for(k = 0; k < p; k++){
				result[i][j] += v[i][k] * w[k][j];
			}
		}
	}
	return result;
}


