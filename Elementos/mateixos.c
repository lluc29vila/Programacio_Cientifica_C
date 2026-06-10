#include <stdio.h>
#define N 200

int main(void){
	int n;
	int sec1[N], sec2[N];
	int i = 0, j = 0;
	int cont = 0;

	scanf(" %d", &n);

	if(n > N || n < 0){
		printf("El nombre enter no es vàlid.\n");
	}
	else{
		printf("Primera secuencia:");
		scanf(" %d", &sec1[0]);
		for(i = 0; i < n && sec1[i] != 0; i++){
			scanf(" %d", &sec1[i+1]);
			
		}

		printf("Segona secuencia:");
		scanf(" %d", &sec2[0]);
		for(j = 0; j < n && sec2[j] != 0; j++){
			scanf(" %d", &sec2[j+1]);
			
		}


		/* for per comprobar que llegueix correctament les secuencies
		for(i = 0; i < n && sec2[i] != 0; i++){
			printf(" %d", sec2[i]);
		}
		*/

/*Comparació cadenes*/

		for(i = 0; i < n && sec1[i] != 0; i++){
			for(j = 0; j < n && sec2[j] != 0; j++){
				if(sec1[i] == sec2[j]){
					cont++;
				}
			}
		}
		if(i == cont){
			printf("La primera secuencia y la segona tenen els mateixos números.\n");
		}
		else{
			printf("La primera secuencia y la segona tenen numeros diferents.\n");
		}
	}
	return 0;
}


