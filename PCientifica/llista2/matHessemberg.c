#include <stdio.h>
#include <stdlib.h>

void scanHessemberg(int n, double**A, double **B);
void memDinMat(int n, double ***A);
double **AB(int n, double **A, double **B);
void freeMat(int n, double **A);

int main(void){
	FILE *inp;
	int n, i, j;
	double **A, **B, **C;

	printf("Dimensió matrius: ");
	scanf(" %d", &n);

	memDinMat(n, &A);
	memDinMat(n, &B);

	scanHessemberg(n, A, B);

	C = AB(n, A, B);

	/*Escritura de matrius*/

	printf("\n-------- A --------\n");
	for(i = 0; i < n; i++){
		for(j = 0; j <= i+1 && j < n; j++){
			printf(" %.2lf ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n-------- B --------\n");
	for(i = 0; i < n; i++){
		for(j = 0; j <= i+1 && j < n; j++){
			printf(" %.2lf ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n-------- A*B --------\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %.2lf ", C[i][j]);
		}
		printf("\n");
	}
	freeMat(n, A);
	freeMat(n, B);
	freeMat(n, C);

	return 0;
}


void freeMat(int n, double **A){
	int i;
	for(i = 0; i < n; i++){
		free(A[i]);
	}
	free(A);
}

void scanHessemberg(int n, double **A, double **B){
	FILE *inp;
	int i, j;
	char nomE[80];

	printf("Nom del arxiu on es llegirant les dades: ");
	scanf(" %s", nomE);
	inp = fopen(nomE, "r");
	if(inp == NULL){
		printf("Error al obrir fitxer de dades\n");
		exit(1);
	}

	/*Lectura de les dades essencials en matriu Hessemberg inferior (HI)*/

	for(i = 0; i < n; i++){
		for(j = 0; j <= i+1 && j < n; j++){
			fscanf(inp, " %lf", &A[i][j]);
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j <= i+1 && j < n; j++){
			fscanf(inp, " %lf", &B[i][j]);
		}
	}
	fclose(inp);
}

void memDinMat(int n, double **A){
	int i;

	A = (double**)malloc(n*sizeof(double*));
	if(A == NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i = 0; i < n; i++){
		A[i] = (double*)malloc(n*sizeof(double));
		if(A[i] == NULL){
			printf("Error de memoria\n");
			exit(1);
		}
	}
}

double **AB(int n, double **A, double **B){
	int i, j, k;
	int kmax;
	double **result;

	memDinMat(n, &result);

	for(i = 0; i < n; i++){
		kmax = (i + 1 < n) ? i + 1: 0;
		for(j = 0; j < n; j++){
			result[i][j] = 0.;
			for(k = 0; k <= kmax; k++){
				if (k <= j+1) result[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	return result;
}


