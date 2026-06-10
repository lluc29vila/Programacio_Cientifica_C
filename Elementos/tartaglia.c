#include <stdio.h>
#define N 100

int main(void){
	int n;
	int i = 0, j = 0;
	int v[N], ant[N];
	int aux;

	printf("Dame un n no mayor que 100: ");
	scanf(" %d", &n);

	if(n < 1 || n > N){
		printf("n no valido\n");
	}
	else{
		for(i = 0; i < N; i++){
			v[i] = 0;
			ant[i] = 0;
		}

		/*Primera fila*/

		v[(2*n+1)/2] = 1;

		for(i = 0; i < 2*n+1; i++){
			aux = v[i];
			v[i] = 0;

			if (aux == 1){
				printf("%d", aux);
			}
			else{
				printf("   ");
			}
		}
		printf("\n");

		/*Segona fila*/

		v[(2*n+1)/2] = 0;
		v[((2*n+1)/2)+1] = 1;
		v[((2*n+1)/2)-1] = 1;

		for(i = 0; i < 2*n+1; i++){

			if(v[i] == 1){
				printf("%d", v[i]);
			}
			else{
				printf("   ");
			}
			ant[i] = v[i];
		}
		printf("\n");
			
		/*files posteriors*/


		for(i = 2; i <= n; i++){

			for(j= 0; j < 2*n+1; j++){
				v[j] = 0;
			}
			v[((2*n+1)/2)+i] = 1;
			v[((2*n+1)/2)-i] = 1;

			if(i == n){
				printf("%d", v[0]);
			}
			for(j = 1; j < 2*n; j++){

				v[j] = ant[j-1] + ant[j+1];

				if(v[j] == 0){
					printf("   ");
				}
				else{
					printf("%3d", v[j]);
				}
			}
			if(i == n){
				printf("1");
			}
			printf("\n");

			/*Guardo la fila*/

			for(j= 0; j<2*n+1; j++){
				ant[j] = v[j];
			}
		}
	}
	return 0;
}



