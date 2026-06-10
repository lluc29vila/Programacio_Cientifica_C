#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 10000000

int main(void){
	int n, i = 0, j = 0, z = 0, k = 0;
	double prob, probReal = 1.0, v[365];

	srand(time(NULL));

	printf("De quan es el grup: ");
	scanf(" %d", &n);
	if(n > 365){
	  printf("El grup no pot ser mes gran que 365\n");
	  return 1;
	  }

	for(i = 0; i < M; i++){
		for(j = 0; j < n; j++){
			v[j] = rand()%365 +1;
		}
		j = 0;
		do{
		       	j++;
			for(z = j+1; z < n; z++){

				if(v[j] == v[z]){
					k++;
					break;
				}
			}
		}while(j < n);
	}
	prob = (double) k / M;
	
	/*Calcul probabilitat real*/

	for(i = 0; i < n; i++){
		probReal = probReal*(365. - i)/365.;
	}
	probReal = 1 - probReal;

	printf("Probabilitat real: %lf\nProbabilitat calculada per %d persones amb %d repeticions: %lf\n", probReal, n, M, prob);

	return 0;
}
