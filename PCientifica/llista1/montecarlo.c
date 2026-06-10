#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define V 10

double punt(double x, double y);

int main(void){
	int n, k = 0, i = 0;
	double x, y, area, err;
	srand(time(NULL));

	printf("Número de punts per calcular l'area: ");
	scanf(" %d", &n);
	if(n < 1) return 1;

	for(i = 0; i < n; i++){
		x = V* (double) rand()/RAND_MAX;
		y = V* (double) rand()/RAND_MAX;
		if(punt(x, y) == 1) k++;
	}

	area = V* ((double) k/n);

	err = sqrt( ((double) k/n)*(1- ((double) k/n))/ (double) n);		/*Desviació estandar d'una proporcio*/
	err = V*err;


	printf("n = %d \nL'area és: %lf\n L'error és: %lf\n", n, area, err);

	return 0;

}

double punt(double x, double y){
	if(((x <= 3 && x >= 1) && (y <= 4 && y >= -1)) && (((pow(x,3) + pow(y,3)) <= 29) && ((exp(x) <= (2*y))))){
		return 1;
	}
	else {
		return 0;
	}
}
