#include <stdio.h>
#include <math.h>

#define N 100

void calcul_normes(int, double [], double *, double *, double *);

int main(void){
	int n, i = 0;
	double v[N], n1, n2, n3;

	printf("Diguem la dimensió del vector: ");
	scanf(" %d", &n);

	printf("Diguem els elements del vector: ");
	for(i = 0; i < n; i++){
		scanf(" %lf", &v[i]);
	}

	calcul_normes(n, v, &n1, &n2, &n3);

	printf("v = (%.4lf,", v[0]);
	for(i = 1; i < n-1; i++){
		printf(" %.4lf,", v[i]);
	}
	printf(" %.4lf)\n", v[n-1]);

	printf("Norma 1: %.4lf\n", n1);
	printf("Norma 2: %.4lf\n", n2);
	printf("Norma 3: %.4lf\n", n3);

	return 0;
}

void calcul_normes(int n, double v[], double *n1, double *n2, double *n3){

	int i = 0;
	*n1 = 0.;
	*n2 = 0.;
	*n3 = 0.;

	/*Cálcul norma 1*/

	for(i = 0; i < n; i++){
		*n1 += fabs(v[i]);
	}

	/*Cálcul norma 2*/

	for(i = 0; i < n; i++){
		*n2 += v[i]*v[i];
	}
	*n2 = sqrt(*n2);

	/*Càlcul norma 3*/

	for(i = 0; i < n; i++){
		if(fabs(v[i] > *n3)) *n3 = fabs(v[i]);
	}
}
