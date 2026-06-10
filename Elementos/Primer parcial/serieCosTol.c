#include <stdio.h>
#include <math.h>

double aprox_cos(double x, double epsilon){

	int i = 0;
	double terme = 1;
	double suma = 1;

	for(i = 1; fabs(terme) >= epsilon; i++){
		terme = terme * (-1) * x*x/((2*i - 1)*(2*i));
	        suma = suma + terme;
	}

	return suma;
}	

int main(void){
	int i = 0;
	double epsilon = 1e-6;
	const double PI = 3.141592653589793;
	double a = -PI, b = PI;
	int p;

	printf("Introduce el valor de p:");
	scanf(" %d", &p);
	
	double h = (b - a)/ p;

	for(i = 0; i <= p; i++){
		double x = a + i*h;
		double aprox = aprox_cos(x, epsilon);
		double real = cos(x);

		printf("%-10.6lf %-20.10le %-20.10le \n", x, aprox, real);
	}
	return 0;
}
