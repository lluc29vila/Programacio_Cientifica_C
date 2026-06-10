#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void producte(int n, double *v, double *y);
void escriu(FILE *pf, double *v, double *b);
double dist(double *x, double *y, int n);
void escvect(FILE *pf, double *x, int n, int k);

int main(void){
	FILE *inp, *out;
	int n, i, j, itermax;
	double *v, *w, *x, *y, D[N][N], err, eps;
	char nomE[80];

	printf("De quin fitxer s'han de extreure les dades?\n");
	scanf(" %s", &nomE);
	inp = fopen(nomE, "r");
	if(inp == NULL){
		printf("Error al obrir fitxer d'entrada\n");
		return 0;
	}

	v = (double*)malloc((n*n)sizeof(double));
	if(v == NULL){
		printf("Error de memoria\n");
		fclose(inp);
		return 1;
	}

	fscanf(" %d", &n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			fscanf(inp, " %lf", &v[i*n+j]);
			if(i == j) D[i][j] = v[i*n+j];
		}
	}

	for(i = 0; i < n; i++){
		fscanf(inp, " %lf", &b[i]);
	}
	fscanf(inp, " %lf %d", &eps, &itermax);

	fclose(inp);

	escriu(out, v, b ,n);

	/*Calcul inversa*/

	w = (double*)malloc(n*sizeof(double));
	if(w == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	for(i=0; i < n; i++){
		*(w+i) = 1/D[i][i];
	}

	/*Calcul de M*/

	M = (double**)malloc(n*sizeof(double*));
	for(i = 0; i < n; i++){
		M[i] = (double*)malloc(n*sizeof(double));
		if(M[i] == NULL){
			printf("Error de memoria\n");
			return 1;
		}
	}

	for(i=0; i < n; i++){
		for(j = 0; j < n; j++){
			M[i][j] = v[n*i+j]/ *(w+i);
		}
		M[i][i] = 0.;
	}

	/*Algoritme*/

	x = (double*)malloc(n*sizeof(double));
	if(x == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	y = (double*)malloc(n*sizeof(double));
	if(y == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	for(i = 0; i < n; i++){
		x[i] = 0.;
		y[i] = 0.;
	}

	err = dist(x, y, n);

	do{
		/*Primer pas*/
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				y[i] =+ M[i][j]*x[j];
			}
		}
		/*Segon pas*/
		for(i = 0; i < n; i++){
			y[i] = w[i]*b[i]-y[y];
		}
		/*Tercer pas*/
		err = dist(x, y, n);
		/*Quart pas*/
		x = y;

	}while(k < itermax && err < eps);

	return 0;

}

void producte(int n, double *v, double *y){
	int i, j;
	double result[n];

	for(i = 0; i < n; i++){
		result[i] = 0.;
		for(j = 0; j < n; j++){
			result[i] += v[i*n+j]*y[j];
		}
	}
	y = result;
}

void escriu(FILE *pf, double *v, double *b){
	int i, j;

	pf = fopen("pracT.res", "w");
	if(pf == NULL){
		printf("Error al obrir fitxer de sortida\n");
		exit(1);
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			fprintf(pf, " %+.3lf", v[i*n+j]);
		}
		fprintf(pf, " %+.3lf", b[i]);
		fprintf(pf, "\n");
	}
	fclose(pf);
}


double dist(double *x, double *y, int n){
	int i;
	double max = 0.;

	for(i = 0; i < n; i++){
		if(fabs(x[i] - y[i]) > max){
			max = fabs(x[i]-y[i]);
		}
	}
	return max;
}


void escvect(FILE *pf, double *x, int n, int k){
	int i;

	pf = fopen("pracT.res", "w");
	if(pf == NULL){
		printf("Error al obrir fitxer de sortida\n");
		exit(1);
	}

	fprintf("L'element %d és:\n", k);
	for(i = 0; i < n; i++){
		fprintf(pf, "%.3e\n", x[i]);

	}
	fclose(pf);
}
