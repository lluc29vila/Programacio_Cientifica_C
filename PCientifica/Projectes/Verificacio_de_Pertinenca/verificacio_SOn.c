/*Aquest programa calcula la aproximació exponencial matricial amb l'objectiu de comprobar si la matriu pertany al grups de espais ortogonals SO(n).
 * Per pretanyer a SO(n) s'ha de complir A*AT = I && det(A) = 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **llegir_matriu_antisimetrica(char* nom_fitxer, int* n);
void multiplicar_matrius(double** A, double **B, double** resultat, int n);
double ** exponencial_matriu(double** A, int n, int ordre);
int es_ortogonal(double** A, int n, double tol);
double norma_frobenius(double** A, double **B, int n);
void imprimir_matriu_fitxer(double** A, int n); /*Funció no utilitzada. S'ha fet sortida per pantalla*/
double** crear_matriu(int n);

int main(void){
	
	char nomE[30];
	double tol = 1e-5, det, frobenius;
	int n, ordre, i, j, k, ortogonal;
	double** A, **expA, **I, **AAT;
	
	
	printf("Nom arxiu de entrada de dades: ");
	scanf(" %s", nomE);

	A = llegir_matriu_antisimetrica(nomE, &n);

	printf("Nombre de truncament de la serie de Taylor: ");
	scanf(" %d", &ordre);


	I = crear_matriu(n);

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == j){
				I[i][j] = 1.;
			}
			else{
				I[i][j] = 0.;
			}
		}
	}

	AAT = crear_matriu(n);

	expA = exponencial_matriu(A, n, ordre);

	/*Calcul AAT*/

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			AAT[i][j] = 0.;
			for(k = 0; k < n; k++){
				AAT[i][j] += expA[i][k]*expA[j][k];
			}
		}
	}

	/*Calcul del determinant*/

	if(n== 2){
		det = expA[0][0]*expA[1][1] - expA[0][1]*expA[1][0];
	}
	else{
		det = expA[0][0]*(expA[1][1]*expA[2][2] - expA[1][2]*expA[2][1])
		- expA[0][1]*(expA[1][0]*expA[2][2] - expA[1][2]*expA[2][0])
		+ expA[0][2]*(expA[1][0]*expA[2][1] - expA[1][1]*expA[2][0]);
	}

	/*Norma de frobenius*/
	
	frobenius = norma_frobenius(AAT, I, n);

	/*Comprovacio si es ortogonal*/

	ortogonal = es_ortogonal(expA, n, tol);

	/*Impresió per pantalla dels valors*/

	printf("\nMatriu Antisimetrica A:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %13.6le", A[i][j]);
		}
		printf("\n");
	}
	printf("\nExponencial de la matriu A (e^A):\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %13.6le", expA[i][j]);
		}
		printf("\n");
	}
	printf("\nDeterminant de e^A: %+.6le\n", det);
	printf("\nLa norma de Frobenius entre e^A*(e^A)T i I és: %+.6le\n", frobenius);
	if(ortogonal == 1){
		printf("\nLa matriu es ortogonal amb aquesta tolerancia.\n=>e^A pertany a SO(%d)\n", n);
	}
	else{
		printf("\nNo es ortogonal\n");
	}

	for(i = 0; i < n; i++) free(A[i]);
	free(A);
	for(i = 0; i < n; i++) free(I[i]);
	free(I);
	for(i = 0; i < n; i++) free(AAT[i]);
	free(AAT);
	for(i = 0; i < n; i++) free(expA[i]);
	free(expA);

	return 0;
}



void imprimir_matriu_fitxer(double** A, int n){
	FILE *out;
	char nomS[30];
	int i, j;

	printf("Nom fitxer sortida: ");
	scanf(" %s", nomS);
	out = fopen(nomS, "w");
	if(out == NULL){
		printf("Error al escriure fitxer sortida\n");
		exit(1);
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			fprintf(out, "%+3.2lf ", A[i][j]);
		}
		fprintf(out, "\n");
	}
	fclose(out);
}

double norma_frobenius(double** A, double **B, int n){
	int i, j;
	double** aux;
	double suma = 0.;

	aux = crear_matriu(n);

	/*Calcul norma frobenius*/

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			aux[i][j] = A[i][j] - B[i][j];
			aux[i][j] = aux[i][j]*aux[i][j];
			suma += aux[i][j];
		}
	}

	for(i = 0; i < n; i++) free(aux[i]);
	free(aux);

	return sqrt(suma);
}



int es_ortogonal(double** A, int n, double tol){
	int i, j, k;
	double** aux, **I;
	int comprovacio = 0;
	double frobenius;

	aux = crear_matriu(n);
	I = crear_matriu(n);

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			aux[i][j] = 0.;
			for(k = 0; k < n; k++){
				aux[i][j] += A[i][k]*A[j][k];
			}

			/*Creació identitat*/
			if(i == j){
				I[i][j] = 1.;
			}
			else{
				I[i][j] = 0.;
			}
		}
	}
		
	/*Comprovació de si es ortogonal (propera a la identitat)*/
	
	frobenius = norma_frobenius(aux, I, n);

	if(fabs(frobenius) < tol){
		comprovacio = 1;
	}
	else{
		comprovacio = 0;
	}

	for(i = 0; i < n; i++) free(aux[i]);
	free(aux);
	for(i = 0; i < n; i++) free(I[i]);
	free(I);

	return comprovacio;
}	




double ** exponencial_matriu(double** A, int n, int ordre){
	int i, j, k;
       	double kfact;
	double** aux, **aux2, **suma;

	/*Reserva de memoria dinaimica aux i suma*/

	aux = crear_matriu(n);
	aux2 = crear_matriu(n);
	suma = crear_matriu(n);


	/* Inicialitzem aux com A elevat a 0 (identitat) i kfact elevat a 0 (primera iteracio) i suma en 0.*/
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){

			if(i == j){
				aux[i][j] = 1.;
				suma[i][j] = 1.;
			}
			else{
			       	aux[i][j] = 0.;
				suma[i][j] = 0.;
			}
		}
	}
	
	kfact = 1.;

	for(k = 1; k <= ordre; k++){
		/* k! */
		kfact *= k;
		/* A elevat a k i suma de taylor*/

		multiplicar_matrius(aux, A, aux2, n);
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){

				suma[i][j] += aux2[i][j]/kfact;

				aux[i][j] = aux2[i][j];
		
			}
		}
	}

	for(i = 0; i < n; i++) free(aux[i]);
	free(aux);
	for(i = 0; i < n; i++) free(aux2[i]);
	free(aux2);

	return suma;
}



void multiplicar_matrius(double** A, double **B, double** resultat, int n){
	int i, j, k;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			resultat[i][j] = 0.;
			for(k = 0; k < n; k++){
				resultat[i][j] += A[i][k]*B[k][j];
			}
		}
	}
}



double **llegir_matriu_antisimetrica(char* nom_fitxer, int* n){
	FILE *inp;
	int i, j;
	double **A;

	inp = fopen(nom_fitxer, "r");
	if(inp == NULL){
		printf("Error obrir fitxer d'entrada\n");
		exit(1);
	}

	fscanf(inp, " %d", n);
	if(*n > 3 || *n < 2){
		printf("Error en la dimensió\n");
		fclose(inp);
		exit(1);
	}

	A = (double**)malloc((*n)*sizeof(double*));
	if(A == NULL){
		printf("Error de memoria\n");
		fclose(inp);
		exit(1);
	}
	for(i = 0; i < *n; i++){
		A[i] = (double*)malloc((*n)*sizeof(double));
		if(A[i] == NULL){
			printf("Error de memoria\n");
			free(A);
			fclose(inp);
			exit(1);
		}
	}

	for(i = 0; i < *n; i++){
		for(j = 0; j < *n; j++){
			fscanf(inp, " %lf", &A[i][j]);
		}
	}
	fclose(inp);

	return A;
}

double** crear_matriu(int n){
	double **M;
	int i;
	
	M = (double**)malloc(n*sizeof(double*));
	if(M == NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i = 0; i < n; i++){
		M[i] = (double*)malloc(n*sizeof(double));
		if(M[i] == NULL){
			printf("Error de memoria\n");
			exit(1);
		}
	}
	return M;
}
