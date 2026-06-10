#include <stdio.h>
#include <math.h>

double exp_aprox(long double x, long double epsilon){
	double terme = 1;
	double suma = 1;
	int i = 0;
	
     	while(fabs(terme) >= epsilon){

		i++;
		terme = terme*x/i;
		suma = suma + terme;
	}
	return suma;
}

int main(void){
	int p;
	double epsilon = 1e-6;

	printf("Donam una xifra més gran que 1000.\n");
	scanf(" %d", &p);

	long double h = 50/p;
	int i = 0;
	for(i = 0; i <= p; i++){
		long double x = i*h;
		long double real = exp(x);
		long double aprox = exp_aprox(x, epsilon); 

		printf("%-10.4Lf %-20.10Le %-20.10Le \n", x, aprox, real);
	}
	
	return 0;
}
