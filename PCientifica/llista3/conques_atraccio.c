#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
double df(double x);
int newton(double *x);

int main(void){

	FILE *f0 = fopen("conca0.res", "w");
	FILE *f1 = fopen("conca1.res", "w");
	FILE *f2 = fopen("conca2.res", "w");

	double x, x0;
	int xini = -1;
	int xfin = 3;
	double xpas = 1e-5;

	if(!f1 || !f2 || !f0){
		printf("Error al obrir fitxers\n");
		return 1;
	}

	for(x0 = xini; x0 <= xfin; x0 += xpas){
		x = x0;
		
		if(newton(&x) == 0){	/*Ha convergit, per tant, classifiquem segons l'arrel*/
			if(fabs(x) < 1e-4){
				fprintf(f0, "%lf\n", x0);
			}
			else if(fabs(x - 1.) < 1e-4){
				fprintf(f1, "%lf\n", x0);
			}
			else if(fabs(x - 2.) < 1e-4){
				fprintf(f2, "%lf\n", x0);
			}
		}
	}

	fclose(f0);
	fclose(f1);
	fclose(f2);

	return 0;
}




double f(double x){
	return x*(x-1.)*(x-2.);
}
double df(double x){
	double h = 1e-5;

	return (f(x+h) - f(x-h)) / (2*h);
}

int newton(double *x){
	int i = 0, iter = 15;
	double prec = 1e-8;
	double tol = 1e-6;
	double x1;

	for(i = 0; i < iter; i++){

		/*Evitar divisions per 0*/
		if(fabs(df(*x)) < tol) return 1;
		x1 = (*x) - f(*x)/df(*x);

		/*En cas de convergencia*/
		if(fabs(x1-(*x)) < prec){
			*x = x1;
			return 0;
		}
		*x = x1;
	}
	/*En cas de que no convergis*/
	return 1;
}


