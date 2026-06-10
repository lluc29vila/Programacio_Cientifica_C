#include <stdio.h>
#define N 15

int main(void){

	int n;
	double u[N], v[N];
	float l;
	int i = 0;
	double w[N], z[N];

	scanf(" %d", &n);

	if(n>N){
		printf("n no valida");
	}
	else{

		for(i = 0; i < n; i++){

			scanf(" %le", &u[i]);
		}	
		for(i = 0; i < n; i++){

			scanf(" %le", &v[i]);
		}

		scanf(" %f", &l);
		
		printf("w = (");
		for(i = 0; i < n; i++){
		
			w[i] = v[i] + u[i];

			printf(" %.2lf", w[i]);
		}
		printf(") \n z = (");

		for(i = 0; i < n-1; i++){

			z[i] = l * u[i];
			printf(" %.2le, ", z[i]);

		}
		z[i] = l * u[i];
		printf("%.2lf) \n", z[i]);
	}
	return 0;
}
