/*La funcio utilitzada és: f(z) = (z-1)(z-2-i)(z-2i)*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	double real;
	double imag;
}comp;

comp suma(comp a, comp b);
comp resta(comp a, comp b);
comp producte(comp a, comp b);
comp divisio(comp a, comp b);
double modul(comp z);
comp funcio(comp z);
comp derivada(comp z);
double distancia(comp a, comp b);
int newtonRaphson(comp z0, double tol, double prec, int iter, comp arrel1, comp arrel2, comp arrel3);


int main(void){
	
	FILE *f0, *f1, *f2, *f3, *f4;

	double h = 1e-2;
	double tol = 1e-2;
	double prec = 1e-10;
	int iter = 12;

	double xmax = 3., ymax = 3., x, y;
	int c;

	comp arrel1, arrel2, arrel3, z;

	arrel1.real = 1;
	arrel1.imag = 0.;

	arrel2.real = 2;
	arrel2.imag = 1;

	arrel3.real = 0.;
	arrel3.imag = 2;

	f0 = fopen("53.res0", "w");
	if(f0 == NULL) return 1;
	f1 = fopen("53.res1", "w");
	if(f1 == NULL) return 1;
	f2 = fopen("53.res2", "w");
	if(f2 == NULL) return 1;
	f3 = fopen("53.res3", "w");
	if(f3 == NULL) return 1;
	f4 = fopen("53.res4", "w");
	if(f4 == NULL) return 1;

	for(x = -3.; xmax > x; x+=h){
		for(y = -3.; ymax > y; y+=h){

			z.real = x;
			z.imag = y;
			
			c = newtonRaphson(z, tol, prec, iter, arrel1, arrel2, arrel3);

			if(c==0){
				fprintf(f0, "%lf %lf ", x, y);
			}
			else if(c==1){
				fprintf(f1, "%lf %lf ", x, y);
			}
			else if(c==2){
				fprintf(f2, "%lf %lf ", x, y);
			}
			else if(c==3){
				fprintf(f3, "%lf %lf ", x, y);
			}
			else {
				fprintf(f4, "%lf %lf ", x, y);
			}
		}
	}

	fclose(f0);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);

	return 0;
}

comp suma(comp a, comp b){
	comp res;
	res.real = a.real + b.real;
	res.imag = a.imag + b.imag;
	return res;
}

comp resta(comp a, comp b){
	comp res;
	res.real = a.real - b.real;
	res.imag = a.imag - b.imag;
	return res;
}
	
comp producte(comp a, comp b){
	comp res;
	res.real = a.real*b.real - a.imag*b.imag;
	res.imag = a.real*b.imag + b.real*a.imag;
	return res;
}

comp divisio(comp a, comp b){
	comp res;
	double d = b.real*b.real + b.imag*b.imag;
	res.real = (a.real*b.real + a.imag*b.imag)/d;
	res.imag = (a.imag*b.real - a.real*b.imag)/d;
	return res;
}

double modul(comp z){
	return sqrt(z.real*z.real + z.imag*z.imag);
}

comp funcio(comp z){
	comp arrel1, arrel2, arrel3;

	arrel1.real = 1;
	arrel1.imag = 0.;

	arrel2.real = 2;
	arrel2.imag = 1;

	arrel3.real = 0.;
	arrel3.imag = 2;

	return producte(producte(resta(z,arrel1), resta(z,arrel2)), resta(z, arrel3));
}
comp derivada(comp z){	/* f'(z) = (z-1)(z-2-i) + (z-1)(z-2i) + (z-2i)(z-2-i) */
	comp r;

	r.real = 3*(z.real*z.real - z.imag*z.imag) - 6*z.real + 6*z.imag + 2;
	r.imag = 6*(z.real*z.imag) - 6*z.imag - 6*z.real + 8;

	return r;
}

double distancia(comp a, comp b){
	return modul(resta(a,b));
}


int newtonRaphson(comp z0, double tol, double prec, int iter, comp arrel1, comp arrel2, comp arrel3){
	int i;
	comp z = z0;
	comp d, f;
	
	for(i = 0; i < iter; i++){
		
		d = derivada(z);
		f = funcio(z);
	/*No es pot generar succesio*/
		
		if(modul(d) < tol) return 0;

		z = resta(z, divisio(f, d));

	/*Succesio convergeix a arrel1*/
		
		if(distancia(z, arrel1) < prec) return 1;

	/*Succesio convergeix a arrel2*/

		if(distancia(z, arrel2) < prec) return 2;

	/*Succesio convergeix a arrel3*/

		if(distancia(z, arrel3) < prec) return 3;
	}
	
	/*Succesio no convergeix*/
	
	return 4;
}

