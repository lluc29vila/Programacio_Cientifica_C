#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	char nom[20];
	float periode;
	float radi;
	float radi_estrella;
	float teq;
	float insolacio;
}Exoplaneta;

int llegir_csv(const char *nom_fitxer, Exoplaneta exos[], int max);
void mostrar(Exoplaneta exos[], int total, int quants);
int cmp_radi(const void *a, const void *b);
int cmp_radi_estrella_planeta(const void *a, const void *b);
int cmp_habitabilitat(const void *a, const void *b);

int main(void){
	char dades[20];
	Exoplaneta *exos;
	int max = 1000;
	int quants;
	int total;
	int elegir;

	printf("Nom fitxer amb dades: ");
	scanf(" %19s", dades);

	exos = (Exoplaneta*)malloc(max*sizeof(Exoplaneta));
	if(exos == NULL){
		printf("Error al reservar memoria\n");
		return 1;
	}

	total = llegir_csv(dades, exos, max);

	printf("Quants valors vols que et mostri (tots = -1): ");
	scanf(" %d", &quants);

	/*MENU*/

	printf("--------Com ho vols ordenar?--------\n");
	printf("1. Per radi de Planeta\n2. Per radi d'estrella\n3. Per Habitabilitat\n");
	scanf(" %d", &elegir);
	
	switch(elegir){
		case 1:
			qsort(exos, total, sizeof(Exoplaneta), cmp_radi);
			mostrar(exos, total, quants);
			break;
		case 2:
			qsort(exos, total, sizeof(Exoplaneta), cmp_radi_estrella_planeta);
			mostrar(exos, total, quants);
			break;
		case 3:
			qsort(exos, total, sizeof(Exoplaneta), cmp_habitabilitat);
			mostrar(exos, total, quants);
			break;
		default:
			printf("Valor no vàlid\n");
			break;
	}

	return 0;
}


int llegir_csv(const char *nom_fitxer, Exoplaneta exos[], int max){
	FILE *inp;
	int i;

	inp = fopen(nom_fitxer, "r");
	if(inp == NULL){
		printf("Error al obrir fixer amb les dades\n");
		exit(1);
	}

	for(i = 0; i < max && fscanf(inp, " %19s %f %f %f %f %f", exos[i].nom, &exos[i].periode, &exos[i].radi, &exos[i].radi_estrella, &exos[i].teq, &exos[i].insolacio) != EOF; i++){
		fscanf(inp, " %19s %f %f %f %f %f", exos[i].nom, &exos[i].periode, &exos[i].radi, &exos[i].radi_estrella, &exos[i].teq, &exos[i].insolacio);
	}
	return i;
}


void mostrar(Exoplaneta exos[], int total, int quants){
	int i;
	
	if(quants == -1){
		quants = total;
	}
	printf("----------Dades---------\n");
	for(i = 0; i < quants; i++){
		printf("%s: %10.5f %10.5f %10.5f %10.5f %10.5f\n", exos[i].nom, exos[i].periode, exos[i].radi, exos[i].radi_estrella, exos[i].teq, exos[i].insolacio);
	}

}

int cmp_radi(const void *a, const void *b){
	float ant = (*(Exoplaneta*)a).radi;
	float post = (*(Exoplaneta*)b).radi;

	if(ant < post) return -1;
	else if(ant > post) return 1;
	else return 0;
}

int cmp_radi_estrella_planeta(const void *a, const void *b){
	
	Exoplaneta ant = *(Exoplaneta*)a;
	Exoplaneta post = *(Exoplaneta*)b;

	
	if(ant.radi_estrella < post.radi_estrella) return -1;
	else if(ant.radi_estrella > post.radi_estrella) return 1;
	else{
		if(ant.radi < post.radi) return -1;
		else if(ant.radi > post.radi) return 1;
		else return 0;
	}
}
		
int cmp_habitabilitat(const void *a, const void *b){
	Exoplaneta ant = *(Exoplaneta*)a;
	Exoplaneta post = *(Exoplaneta*)b;
	float dist1, dist2;

	dist1 = sqrt((ant.radi - 1)*(ant.radi-1)+(ant.insolacio-1)*(ant.insolacio-1)+(ant.teq-1)*(ant.teq-1));

	dist2 = sqrt((post.radi - 1)*(post.radi-1)+(post.insolacio-1)*(post.insolacio-1)+(post.teq-1)*(post.teq-1));

	if(dist1 < dist2) return -1;
	else if(dist1 > dist2) return 1;
	else return 0;
}
