#include <stdio.h>
#include <stdlib.h>

float **prodHessenberg(int n, float**A, float**B);
float **memDinMat(int n);
void freeMat(int n, float **A);

int main(void){
	FILE *inp;
	char nomE[30];
	int i, j, n;
	float **A, **B, **result;

	printf("Nom del archiu amb les dades: ");
	scanf(" %s", nomE);

	inp = fopen(nomE, "r");
	if(inp == NULL){
		printf("Error al llegir archiu de entrada.\n");
		return 1;
	}

	fscanf(inp, " %d", &n);
	if(n < 3){
		printf("Dimensió massa peitita\n");
		return 1;
	}

	A = memDinMat(n);
	B = memDinMat(n);

	for(i = 0; i < n; i++){
		for(j = 0; j <= i+1 && j < n; j++){
			fscanf(inp, " %f", &A[i][j]);
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j <= i+1 && j < n; j++){
			fscanf(inp, " %f", &B[i][j]);
		}
	}

	fclose(inp);

	result = prodHessenberg(n, A, B);

	printf("\n---------- A ----------\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(j > i+1){
				printf(" 0.00");
			}
			else{
				printf(" %.2f", A[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n---------- B ----------\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(j > i+1){
				printf(" 0.00");
			}
			else{
				printf(" %.2f", B[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n---------- A*B ----------\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %.2f", result[i][j]);
		}
		printf("\n");
	}

	freeMat(n, A);
	freeMat(n, B);
	freeMat(n, result);

	return 0;
}


void freeMat(int n, float **A){
	int i;

	for(i = 0; i < n; i++){
		free(A[i]);
	}
	free(A);
}


float **memDinMat(int n){
	int i;
	float **A;

	A = (float**)malloc(n*sizeof(float*));
	if(A == NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i = 0; i < n; i++){
		A[i] = (float*)malloc((i+2)*sizeof(float));
		if(A[i] == NULL){
			printf("Error de memoria\n");
			exit(1);
		}
	}
	return A;
}


float **prodHessenberg(int n, float **A, float **B){
    int i, j, k;
    float **C;
    C = (float**)malloc(n*sizeof(float*));
    if(C == NULL){
	    printf("Error de memoria\n");
	    exit(1);
    }
    for(i = 0; i < n; i++){
	    C[i] = (float*)malloc(n*sizeof(float));
	    if(C[i] == NULL){
		    printf("Error de memoria\n");
		    exit(1);
	    }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            C[i][j] = 0.0f;
            for(k = 0; k < n; k++){
                /* A[i][k] != 0  =>  k <= i+1 */
                /* B[k][j] != 0  =>  j <= k+1 */
                if(k <= i+1 && j <= k+1){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
    return C;
}
