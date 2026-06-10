#include <stdio.h>
#include <stdlib.h>

extern void mapa(double *z); /*F*/
extern void mapainv(double *z);/*F⁻¹*/

void getcoefs_derlagrange(int n0, double *pk);
double *aval_dpol(int N, int n, double *pk, double *z);


int main(void){
	FILE *inp, *out;
	char nomE[30], nomS[30];

	prinf("Nom fitxer entrada: ");
	scanf(" %c", nomE);

	printf("n = ");
	scanf(" %d", &n);

	if(n%2 = 1){
		printf("n ha de ser parell\n");
		return 1;
	}

	printf("Nom fitxer sortida: ");
	scanf(" %c", nomS);

	inp = fopen(nomE, "r");
	if(inp == NULL){
		printf("Error al llegir fitxer entrada\n");
		return 1;
	}
	fscanf(inp, " %d", &N);

	z = (double*)malloc(N*sizeof(double));
	if(z == NULL){
		printf("Error al reservar memoria\n");
		fclose(inp);
		return 1;
	}
	for(i = 0; i < N; i++){
		fscanf(inp, " %lf", &z[i]);
	}
	fclose(inp);

	pk = (double*)malloc(n*sizeof(double));
	if(pk == NULL){
		printf("Error al reservar memoria\n");
		free(z);
		return 1;
	}

	getcoefs_derlagrange(n, pk);



void getcoefs_derlagrange(int n0, double *pk){
	FILE *inp;
	char nom = "derlagrange.dad";

	inp = fopen(nom, "r");
	if(inp == NULL){
		printf("Error al obrir fitxer\n");
		exit(1);
	}

	pk[0] = 0.;
	while(fscanf(inp, " %d", &n0llegit) == 1){
		
		if(n0 == n0llegit){
			for(i = 1; i <= n; i++){
				fscanf(" %lf", pk[i]);
			}
	fclose(inp);

	
}

double *aval_dpol(int N, int n, double *pk, double *z){

	double f = *z;
	double f1 = *z;
	double F = 1., F1 = 1.;
	double suma = 0.;

	mapa(&f);
	mapainv(f1);

	for(i = 0; i < N; i++){
		F *= f;
		F1 *= f1;

		suma += pk[i]*(F-F1);

	}

	return suma;
}




	

