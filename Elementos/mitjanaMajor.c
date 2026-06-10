#include <stdio.h>
#define N 40
double mitjana(double[], int);

int main(void){
	int i = 0, n;
	double primeraAssaig[N], segonaAssaig[N], mitjana1, mitjana2;

	printf("Número d'alumnes: ");
	scanf(" %d", &n);

	if(n>N || n < 0){
		printf("Número d'alumnes no válid\n");
	}
	else{
		printf("Notes de la primera assignatura: ");
		for(i = 0; i < n; i++){
			scanf(" %lf", &primeraAssaig[i]);
		}
		printf("Notes de la segona assignatura: ");
		for(i = 0; i < n; i++){
			scanf(" %lf", &segonaAssaig[i]);
		}
		mitjana1 = mitjana(primeraAssaig, n);
		mitjana2 = mitjana(segonaAssaig, n);

		if(mitjana1 < mitjana2){
			printf("Mitjana primera assignatura: %.2lf Mitjana segona assignatura: %.2lf\n La segona assignatura te millor mitjana.\n", mitjana1, mitjana2);
		} else if(mitjana1 == mitjana2){
			printf("Mitjana primera assignatura: %.2lf Mitjana segona assignatura: %.2lf\n Tenen exactament la mateixa mitjana.\n", mitjana1, mitjana2);
		} else{
			printf("Mitjana primera assignatura: %.2lf Mitjana segona assignatura: %.2lf\n La primera assignatura te millor mitjana.\n", mitjana1, mitjana2);
		}
	}
	return 0;
}

double mitjana(double v[], int n){
	int i = 0;
	double mitjana = 0.;
	for(i = 0; i < n; i++){
		mitjana += v[i];
	}
	return mitjana /= n;
}
