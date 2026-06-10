#include <stdio.h>
#define N 20
double prodMatVec(double[][], double[], int, int);


double prodMatVec(double matriz[][], double v[], int n, int m){
	int i = 0, j = 0;
	double resultat[m];

	for(i = 0; i < n; i++){
		resultat[i] = 0;		
		for(j = 0; j < m; j++){
			resultat[i] += matriz[i][j]*v[j];
		}
	}
	return resultat;
}

			
