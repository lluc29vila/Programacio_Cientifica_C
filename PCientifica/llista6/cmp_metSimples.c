#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seleccio(int n, double *v);
void intercanvi(int n, double *v);
void insercioLinial(int n, double *v);
void insercioBinaria(int n, double *v);

int main(void){
	int n, i;
	double *vs, *vi, *vl, *vb;

	clock_t inici, fi;
	double tsel, tint, tlin, tbi;

	printf("Número d'elements: ");
	scanf(" %d", &n);

	vs = (double*)malloc(n*sizeof(double));
	if(vs == NULL){
		printf("Error al reservar memoria\n");
		return 0;
	}
	vi = (double*)malloc(n*sizeof(double));
	if(vi == NULL){
		printf("Error al reservar memoria\n");
		return 0;
	}
	vl = (double*)malloc(n*sizeof(double));
	if(vl == NULL){
		printf("Error al reservar memoria\n");
		return 0;
	}
	vb = (double*)malloc(n*sizeof(double));
	if(vb == NULL){
		printf("Error al reservar memoria\n");
		return 0;
	}

	srand(time(NULL));

	for(i = 0; i < n; i++){
		vs[i] = (double)rand()/RAND_MAX;
		vi[i] = vs[i];
		vl[i] = vs[i];
		vb[i] = vs[i];
	}

	inici = clock();
	seleccio(n, vs);
	fi = clock();
	tsel = (double)(fi-inici)/CLOCKS_PER_SEC;

	inici = clock();
	intercanvi(n, vi);
	fi = clock();
	tint = (double)(fi-inici)/CLOCKS_PER_SEC;

	inici = clock();
	insercioLinial(n, vl);
	fi = clock();
	tlin = (double)(fi-inici)/CLOCKS_PER_SEC;
	
	inici = clock();
	insercioBinaria(n, vb);
	fi = clock();
	tbi = (double)(fi-inici)/CLOCKS_PER_SEC;

	printf("Mètode Selecció: %lf\n", tsel);
	if(n <= 10){
		for(i = 0; i < n; i++){
			printf("%5.3lf ", vs[i]);
		}
		printf("\n");
	}
	printf("Mètode Intercanvi: %lf\n", tint);
	if(n <= 10){
		for(i = 0; i < n; i++){
			printf("%5.3lf ", vi[i]);
		}
		printf("\n");
	}
	printf("Mètode Inserció Linial: %lf\n", tlin);
	if(n <= 10){
		for(i = 0; i < n; i++){
			printf("%5.3lf ", vl[i]);
		}
		printf("\n");
	}
	printf("Mètode Inserció Binaria: %lf\n", tbi);
	if(n <= 10){
		for(i = 0; i < n; i++){
			printf("%5.3lf ", vb[i]);
		}
		printf("\n");
	}

	free(vs);
	free(vi);
	free(vl);
	free(vb);

	return 0;
}



void seleccio(int n, double *v){
	int i, j, sel;
	double aux;

	for(i = 0; i < n-1; i++){
		sel = i;
		for(j = i+1; j < n; j++){
			if(v[j] < v[sel]) sel = j;
		}
		if(i != sel){
			aux = v[i];
			v[i] = v[sel];
			v[sel] = aux;
		}
	}
}

void intercanvi(int n, double *v){
	int i, j;
	double aux;

	for(i = 0; i < n-1; i++){
		for(j = n-1; j > i; j--){
			if(v[j] < v[j-1]){
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
			}
		}
	}
}

void insercioLinial(int n, double *v){
	int i, j;
	double aux;

	for(i = 0; i < n; i++){
		aux = v[i];
		for(j = i-1; j >= 0 && aux < v[j]; j--){
			v[j+1] = v[j];
		}
		v[j+1] = aux;
	}
}

void insercioBinaria(int n, double *v){
	int i, j, esq, drt;
	double aux;

	for(i = 1; i < n; i++){
		aux = v[i];
		esq = 0;
		drt = i-1;
		
		while(esq <= drt){
			j = (esq+drt)/2;
			if(aux < v[j]){
				drt = j-1;
			}
			else{
				esq = j+1;
			}
		}
		for(j = i-1; j >= esq; j--){
			v[j+1] = v[j];
		}
		v[esq] = aux;
	}
}
