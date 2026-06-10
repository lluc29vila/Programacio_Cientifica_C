#include <stdio.h>

#define N 30

int main(void){
	
	FILE *inp, *out;
	char nomE[80], nomS[80];
	int n, i = 0, j = 0, v[N], visitat[N];

	/*obro fitxer i llegeixo les n i la permutació*/

	scanf(" %s", nomE);
	inp = fopen(nomE, "r");
	if(inp == NULL){
		printf("Error lectura documento\n");
		return 0;
	}

	fscanf(inp, " %d", &n);
	for(i = 0; i < n; i++){ /*Lectura de la permutació*/
		fscanf(inp, " %d", &v[i]);
	}

	scanf(" %s", nomS);
	out = fopen(nomS, "w");
	if(out == NULL){
		fclose(inp);
		printf("Error al abrir documento de salida\n");
		return 0;
	}

	/*Comprobació de que la permutació es correcte
	 * 1) Te elements de 0 a n-1
	 * 2) No hi ha elements repetits */

	for(i = 0; i < n; i++){
		if(v[i] < 0 || v[i] >= n){
			fclose(out);
			printf("Permutació no vàlida\n");
			return 1;
		}
		for(j = i+1; j < n; j++){
			if(v[i] == v[j]){
				fclose(out);
				printf("Permutació no vàlida\n");
				return 1;
			}
		}
	}

	/*Creació dels cicles mitjançant un vector que guarda els valors visitats. Si el seguent valor es un valor visitat tanca el cicle*/

	for(i = 0; i < n; i++){
		visitat[i] = 0;
	}

	fprintf(out, "Cicles:\n");

	for(i = 0; i < n; i++){
		if(!visitat[i]){

			j = i;
			fprintf(out, "(");

			while(!visitat[j]){
				fprintf(out, "%d", j);
				visitat[j] = 1;
				j = v[j];
				if(!visitat[j]){
					fprintf(out,", ");
				}
			}
			fprintf(out, ")\n");
		}
	}
	fclose(out);
	return 0;
}


