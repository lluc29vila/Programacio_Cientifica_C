#include <stdio.h>
#define N 16

int main(void){
	int i = 0;
	int v[N];
	int suma = 0, cont = 0;

	
	for(i = 0; i < N; i++){
		scanf(" %1d", &v[i]);
	}

	printf("codi                correcte            correcció\n");
	
	do{

		if(v[0] == 0){
			return 1;
		}
		else{
			for(i = 0; i < N-1; i++){ /*Suma parells amb pes 2, imparells pes 1*/
				if(i%2 == 0){
			       		suma = suma + 2*v[i];
				}
				else{
					suma = suma + v[i];
				}
			}
			for(i = 0; i < N-1; i = i+2){
				if(v[i] > 4) cont++;
			}
			suma = suma + cont;
			suma = suma%10;

			/*Print resultats*/
		
			for(i = 0; i < N; i++){
				printf("%d", v[i]);
			}

			if((suma == 0 && v[15] == 0) || 10-suma == v[15]){
				printf("       Sí\n");
			}
			else{
				printf("       No       ");
				for(i = 0; i < N-1; i++){
					printf("%d", v[i]);
				}
				printf("%d\n", 10-suma);
			}
		}
		cont = 0;
		suma = 0;

		for(i = 0; i < N; i++){
			scanf(" %1d", &v[i]);
		}	
	}while(v[0] != 0);
	return 0;
}

