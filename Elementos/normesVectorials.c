#include <stdio.h>
#include <math.h>
#define DIM 10

int main (void){
	int n;
	double v[DIM];
	int i = 0, imax = 0;
	double sum = 0.;

	printf("Dona'm una n entre 1 i 10: ");
	scanf(" %d", &n);

	if(n < 1 || n > DIM){
		printf("n no vàlid\n");
		return 1;
	}
	else{
		printf("Donem el vector: "); /*llegir vector*/
		for(i = 0; i < n; i++){
			scanf(" %lf", &v[i]);
		}
		
		/*Imprimeixo el vector*/

		printf("[%.2lf,", v[0]);
		for(i = 1; i < n-1; i++){
			printf(" %.2lf,", v[i]);
		}
		printf("%.2lf]\n", v[i]);


		/*Primera Norma*/

		for(i = 0; i < n; i++){
			sum = sum + fabs(v[i]);
		}

		printf("||v||1 = %.2lf \n", sum);

		/*Segonda Norma*/

		for(i = 0; i < n; i++){
			sum = sum + v[i]*v[i];
		}
		sum = sqrt(sum);
		printf("||v||2 = %.2lf \n", sum);

		/*Tercera Norma*/
		
		imax = 0;
		for(i = 1; i < n; i++){

			if(fabs(v[i]) > fabs(v[imax])) imax = i;
		}

		printf("||v||oo = %.2lf \n", v[imax]);

	}
	return 0;
}
