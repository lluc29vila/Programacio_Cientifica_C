#include <stdio.h>
#include <math.h>

#define N 20

double polinomi(double p[], int, double);
double derivada(double p[], int, double);
double newtonRaphson(double p[], int,  double, double, int, double *);

int main(void){
	int n, i = 0;
	int maxiter, result;
	double c, max, xmin, xmax, p[N];
	double h, tol, x, f1, f2, x0;
	double arrel;

	printf("Grau del polinomi: ");
	scanf(" %d", &n);

	/*Lectura del polinomi*/

	for(i = 0; i <= n; i++){
		scanf(" %lf", &p[i]);
	}

	/*Metode de Cauchy per trobar un interval amb totes les arrels reals*/

	max = 0.;
	for(i = 0; i < n; i++){
		if (fabs(p[i]/p[n]) > max) max = fabs(p[i]/p[n]);
	}
	c = 1 + max;
	xmin = -c;
	xmax = c;

	printf("Interval en el que es busquen les arrels: [%.4lf, %.4lf]\n", xmin, xmax);

	/*Detecció de canvis de signe amb un pas h fixat*/

	h = 0.01;
	tol = 1e-8;
	maxiter = 100;
	x = xmin;

	while(x < xmax){
		f1 = polinomi(p, n, x);
		x = x + h;
		f2 = polinomi(p, n, x);

		if(f1*f2 < 0){
			x0 = (x-h + x)/2.;
			
			result = newtonRaphson(p, n, x0, tol, maxiter, &arrel);

			if(result == 0){
				printf("Arrel trobada: %.10lf\n", arrel);
			}	
			else if(result == 1){
				printf("No es pot aplicar NR (derivada = 0)\n");
			}
			else{
				printf("El mètode NR no convergeix\n");
			}
		}
	}
	return 0;
}



/*Esquemas de Horner per calcular el polinomi i la derivada en un punt x*/

double polinomi(double p[], int n, double x){
	double resultat = 0.;
	int i = 0;
	for(i = n; i >= 0; i--){
		resultat = resultat * x + p[i];
	}
	return resultat;
}

double derivada(double p[], int n, double x){ 
	double resultat = 0.;
	int i = 0;
	for(i = n; i >= 1; i--){
		resultat = resultat * x + p[i];
	}
	return resultat;
}

/*Metode NR*/

double newtonRaphson(double p[],int n,  double x0, double tol, int maxiter, double *arrel){
	
	int i = 0;
	double x = x0, x1, fx, dfx;

	for(i = 0; i < maxiter; i++){

		fx = polinomi(p, n, x);
		dfx = derivada(p, n, x);

		/*Per evitar divisions per 0*/

		if(fabs(dfx) < 1e-12) return 1;

		x1 = x - fx/dfx;

		/*En cas de convergencia*/

		if(fabs(x1-x) < tol){
			*arrel = x1;
			return 0;
		}

		x = x1;
	}
	/*En cas de no convergir*/

	return 2;
}
