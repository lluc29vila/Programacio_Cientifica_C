#include <stdio.h>
#define N 30
double mitjana(double[], int);
double varianca(double[], int);
double covarianca(double[], double[], int);

int main(void){
	int i = 0, n, continuar;
	double temp[N], pres[N], mitjTemp, mitjPres, cov, varPres, pendent;

	do{
		printf("Número de dades de la mostra: ");
		scanf(" %d", &n);
		if(n > N || n < 0){
			printf("Número de la mostra no vàlida\n");
			return 1;
		}
		else{
			printf("Dades temperatura i presió mostra: ");
			for(i = 0; i < n; i++){
				scanf(" %lf", &temp[i]);
				scanf(" %lf", &pres[i]);
			}
			mitjTemp = mitjana(temp, n);
			mitjPres = mitjana(pres, n);
			varPres = varianca(pres, n);
			cov = covarianca(pres, temp, n);
			pendent = cov / varPres;

			printf("La recta de regresió és: y - %.2lf = %.2lf *(x - %.2lf) \n", mitjTemp, pendent, mitjPres);
			
			printf("\n1 Per posar dades nova població 0 per parar el programa: ");
			scanf(" %d", &continuar);
		}
	}while(continuar== 1);

	return 0;
}



double mitjana(double v[], int n){
	int i = 0;
	double mitjana = 0.;

	for(i = 0; i < n; i++){
		mitjana += v[i];
	}
	return mitjana/n;
}

double varianca(double v[], int n){
	double mitj = mitjana(v, n);
	double suma = 0.;
	int i = 0;

	for(i = 0; i < n; i++){
		suma += (v[i] - mitj)* (v[i] - mitj);
	}
	return suma / n;
}

double covarianca(double v[], double w[], int n){
	double mitjanaV = mitjana(v, n);
	double mitjanaW = mitjana(w, n);
	double suma = 0.;
	int i = 0;

	for(i = 0; i < n; i++){
		suma += (v[i] - mitjanaV)*(w[i] - mitjanaW);
	}
	return suma / n;
}


