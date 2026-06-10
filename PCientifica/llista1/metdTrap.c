#include <stdio.h>

double f(double x);

int main(void){
	int n;
	double h;
	double xi, y = 0.0;

	printf("Dona'm una n major que 0: ");
	scanf(" %d", &n);

	if(n <= 0) return 1;


	printf("Dona'm els dos valors del interval: ");
	scanf(" %lf %lf", &a, &b);

	if (a > b){
		h = a;
		a = b;
		b = h;
	}
	
	h = (b - a)/n;
	
	for(i = 0; i <= n; i++){
		xi = a + i*h;
		y += f(xi);
	}


double f(double x){
	double y;
	if(fabs(x) < 10*exp(-12) || fabs(x) < 10*exp(-12)){
		y = log(x) *log(x-1);
		}
	else{
		return 0;
	}
	return y;
}


