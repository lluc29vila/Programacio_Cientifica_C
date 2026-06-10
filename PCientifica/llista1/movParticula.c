#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359

int main(void){
	FILE *out;
	int n, i = 0;
	double x = 0., y = 0., alpha;
	char nomS[30];

	printf("Nom document sortida: ");
	scanf(" %s", nomS);


	printf("Quants segons s'esta movent la particula?\n");
	scanf(" %d", &n);
	
	/*Obro fitxer de sortida*/

	out = fopen(nomS, "w");
	if(out == NULL){
		printf("Error obrir fitxer de sortida\n");
		return 0;
	}

	srand(time(NULL));

	fprintf(out," %lf %lf", x, y);

	for(i = 0; i < n; i++){
		alpha = ((double) rand()/RAND_MAX * 2 * PI);

		x += cos(alpha);
		y += sin(alpha);

		fprintf(out," %lf %lf", x, y);
	}
	fclose(out);

	return 0;

}

