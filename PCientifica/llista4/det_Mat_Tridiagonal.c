/*Volem calcular el determinant d'una matriu tridiagonal mitjançant la recurrencia: dn = a*dn-1 - b²*dn-2 .
 * ai,i= a --> Per tant, d1 = a
 * ai,i+1 = ai+1,i = b --> Per tant, d2 = b²-a²		*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double fn_recursiva(double a, double b, int n);
double fn_iteracio(double a, double b, int n);

int main(void){
	int n;
	double a, b;
	double res_rec, res_iter;

	double time_rec, time_iter;

	printf("Valor de a: ");
	scanf(" %lf", &a);
	printf("Valor de b: ");
	scanf(" %lf", &b);
	printf("Valor de n (>30): ");
	scanf(" %d", &n);

	if(n <= 30) return 1;

	clock_t start, end;

	/*Recursiva*/
	start = clock();
	res_rec = fn_recursiva(a, b, n);
	end = clock();
	time_rec = (double)(end - start) / CLOCKS_PER_SEC;

	/*Interativa*/
	start = clock();
	res_iter = fn_iteracio(a, b, n);
	end = clock();
	time_iter = (double)(end - start) / CLOCKS_PER_SEC;

	/*Imprimir resultats*/

	printf("El resutltat de la recursiva es: %.5lf i ha tardat: %lf\n", res_rec, time_rec);
	printf("El resutltat de la iterativa es: %.5lf i ha tardat: %lf\n", res_iter, time_iter);

	return 0;
}








double fn_recursiva(double a, double b, int n){

	if(n == 1) return a;
	
	else if(n == 2) return a*a - b*b;

	else{
		return a*fn_recursiva(a, b, n-1) - (b*b)*fn_recursiva(a, b, n-2);
	}
}


double fn_iteracio(double a, double b, int n){
	int i = 3;
	double dn;
	double d1 = a;
	double d2 = a*a - b*b;

	while(i <= n){
		dn = a*d2 - (b*b)*d1;
		
		d1 = d2;
		d2 = dn;
		i++;
	}
	
	return dn;
}


		




