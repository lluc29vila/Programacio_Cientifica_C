#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seleccio_linial(int *v, int x, int n);
int seleccio_binaria(int *v, int x, int n);
int comp(const void *, const void *);

int main(void){
	int n = 1000000;
       	int *v;
	int i, trobat, x;

	clock_t inici, fi;
	double tlinial, tbinari;

	/*Creació de valors*/

	srand(time(NULL));

	v = (int*)malloc(n*sizeof(int));
	if(v == NULL){
		printf("Error al reservar memoria\n");
		return 1;
	}

	for(i = 0; i < n; i++){
		v[i] = (rand()%20001 -10000);
	}

	/*Utilització de qsort per ordenacio*/
	qsort(v, n, sizeof(int), comp);

	printf("Quin valor enter vols buscar a la llista: ");
	scanf(" %d", &x);

	/*Seleccio linial*/
	inici = clock();
	trobat = seleccio_linial(v, x, n);
	fi = clock();
	tlinial = ((double)(fi-inici))/CLOCKS_PER_SEC;

	if(trobat != n){
		printf("El num. %d está a la posició %d\nS'ha tardat %lf\n", x, trobat+1, tlinial);
	}
	else{
		printf("El num. %d no está a la llista\nS'ha tardat %lf\n", x, tlinial);
	}

	/*Seleccio binaria*/
	inici = clock();
	trobat = seleccio_binaria(v, x, n);
	fi = clock();
	tbinari = ((double)(fi-inici))/CLOCKS_PER_SEC;

	if(trobat != n){
		printf("El num. %d está a la posició %d\nS'ha tardat %lf\n", x, trobat+1, tbinari);
	}
	else{
		printf("El num. %d no está a la llista\nS'ha tardat %lf\n", x, tbinari);
	}

	free(v);

	return 0;
}


int seleccio_linial(int *v, int x, int n){
	int i;

	for(i = 0; i < n; i++){
		if(v[i] == x){
			return i;
		}
	}
	return n;
}




int seleccio_binaria(int *v, int x, int n){
	int esq = 0;
	int dret = n-1;
	int i = 0;

	while(esq <= dret){
		i = (esq+dret)/2;
		if(v[i] < x){
			esq = i + 1;
		}
		else if(v[i] > x){
			dret = i - 1;
		}
		else{
			return i;
		}
	}
	return n;
}

int comp(const void *a, const void *b){
	int ant = *(const int*)a;
	int post = *(const int*)b;

	if(ant < post) return -1;
	else if(post < ant) return 1;
	else return 0;
}
