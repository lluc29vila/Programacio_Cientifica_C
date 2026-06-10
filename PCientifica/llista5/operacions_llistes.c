#include <stdio.h>
#include <stdlib.h>

struct elem{
	int clau;
	float info;
	struct elem *seg;
};

void nodefinal(struct elem **);
void nodenou(struct elem **inici);
void deletinici(struct elem **);
void deletfinal(struct elem **);
void deletmig(struct elem *);


int main(void){

	struct elem *inici, *w;
	int x;


	inici = (struct elem*)malloc(sizeof(struct elem));
	if((inici) == NULL){
		printf("Error al reservar memoria\n");
		return 1;
	}

	/*Menu d'opcions*/
	printf("\n----------- Elegeix el número del que vulguis fer ------------\n");
	printf("1. Afegir un node al final de la llista\n2. Afegir un node abans de ser valor\n3. Eliminar el primer node de la llista\n4. Eliminar l'últim node de la llista\n5. Eliminar un node del mig\n");

	scanf(" %d", &x);

	switch(x){
		case 1:
			nodefinal(&inici);
			break;
		case 2:
			nodenou(&inici);
			break;
		case 3:
			deletinici(&inici);
			break;
		case 4:
			deletfinal(&inici);
			break;
		case 5:
			deletmig(inici);
			break;
		default:
			printf("Opció no vàlida\n");
			return 1;
	}
	
	/*Alliberar memoria*/
	while(inici != NULL){
		w = (inici)->seg;
		free(inici);
		inici = w;
	}

	return 0;

}

void nodefinal(struct elem **inici){
	int clau;
	struct elem *w, *aux;
	float info;

	w = *inici;
	while(w != NULL){
		aux = w;
		w = w->seg;
	}


	w = (struct elem*)malloc(sizeof(struct elem));
	if(w == NULL){
		printf("Error\n");
		exit(1);
	}
	printf("Dona'm info clau: ");
	scanf(" %d %f", &clau, &info);

	w->clau = clau;
	w->info = info;
	w->seg = NULL;

	if(*inici != NULL){
		aux->seg = w;
	}
	else{
		*inici = w;
	}

}

void nodenou(struct elem **inici){

	int clau, postclau;
	float info;

	struct elem *w, *ant, *post;

	printf("Clau posterior al lloc que es vol posar:\n");
	scanf(" %d", &postclau);

	w = malloc(sizeof(struct elem));

 	if(w == NULL){
 		printf("Error\n");
 		exit(1);
  	}

	printf("Dona'm info clau: ");
	scanf("%d %f", &clau, &info);

	w->clau = clau;
	w->info = info;

	if(*inici == NULL){
		w->seg = NULL;
		*inici = w;
		printf("No hi havia cap element a la llista així que ha estat posat com a primer element\n");
		return;
	}

	if((*inici)->clau == postclau){
		w->seg = *inici;
		*inici = w;
		return;
	}

	ant = *inici;
	post = ant->seg;

	while(post != NULL && post->clau != postclau){
		ant = post;
		post = post->seg;
	}


	if(post == NULL){
		free(w);
		return;
	}

	w->seg = post;
	ant->seg = w;
}

void deletinici(struct elem **inici){
	struct elem *w;

	if(*inici == NULL){
		printf("No hi ha cap element a la llista\n");
		return;
	}

	w = *inici;

	*inici = (*inici)->seg;

	free(w);
}

void deletfinal(struct elem **inici){
	struct elem *w, *ant;

	if(*inici == NULL){
		printf("No es pot eliminar perque no hi ha cap element a la llista\n");
		return;
	}

	if((*inici)->seg == NULL){
		free(*inici);
		*inici = NULL;
		return;
	}

	w = *inici;

	while(w->seg != NULL){
		ant = w;
		w = w->seg;
	}
	ant->seg = NULL;
	
	free(w);
}

void deletmig(struct elem *inici){
	struct elem *w, *aux, *post;
	int postclau;

	printf("Clau element anterior al eliminar\n");
	scanf(" %d", &postclau);
	
	if(inici == NULL || inici->seg == NULL) return;

	post = inici;
	while(post->clau != postclau){
		post = post->seg;
	}

	aux = inici;
	w = inici->seg;

	while(w->seg != post){
		aux = w;
		w = w->seg;
	}

	aux->seg = post;

	free(w);
}




