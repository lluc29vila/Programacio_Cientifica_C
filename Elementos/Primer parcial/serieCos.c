#include <stdio.h>
#include <math.h>

int main (void){
	double epsilon;
	double x;
	int i = 0;
	double terme = 1;
	double suma = 1;

	printf("Terme real per a la funció i un epsilon al que tendir.\n");
	scanf(" %lf %lf", &x, &epsilon);

	for(i = 1; fabs(terme) >= epsilon; i++){
		terme = terme * (-1) * x*x/((2*i - 1)*(2*i));
	        suma = suma + terme;
	}
	printf("La suma de Taylor per a la funció cos(x) = %lf\n", suma);

	return 0;
}	
