#include <stdio.h>
#define N 50
double horner(int, double[], double);

int main(void){
	int n, i = 0;
	double v[N], a, b;

	printf("Grado màxim del polinomi: ");
	scanf(" %d", &n);

	printf("coeficients del polinomi de menor a major: ");
	for(i = 0; i < n; i++){
		scanf(" %lf", &v[i]);
	}

	printf("Punts a b del interval a evaluar: ");
	scanf(" %lf, %lf", &a, &b);

	a = horner(n, v, a);
	b = horner(n, v, b);

	if(a * b < 0){
		printf("Hi ha algun zero\n");
	}
	else{
		printf("No hi ha cap zero\n");
	}
	
	return 0;
}

double horner(int n, double v[], double y){
	int i = 0;
	double suma = 0;

	for(i = n; i > 0; i--){
	       suma = (suma + v[i]) * y;
	}
	suma += v[0];

	return suma;
}
