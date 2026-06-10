#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int maestro, alumno;
}pareja;

double prob_n_m(int n, int m);
void exper_n(int n, pareja *v);
int cond(int n, pareja *v);
int comp(const void *p, const void *q);

int main(void){
	int a, b, aux, m, n;
	double prob;

	srand(time(NULL));

	printf("Valor [a, b]: ");
	scanf(" %d %d", &a, &b);

	if(a > b){
		aux = a;
		a = b;
		b = aux;
	}	

	printf("m = ");
	scanf(" %d", &m);

	for(n = a; n <= b; n++){
		prob = prob_n_m(n, m);

		printf("n = %d, p = %lf\n", n, prob);
	}

	return 0;
}

double prob_n_m(int n, int m){
	pareja *v;
	int i;
	int k = 0;

	v = (pareja*)malloc(n*sizeof(pareja));
	if(v == NULL){
		printf("Error al reservar memoria\n");
		exit(1);
	}

	for(i = 0; i < m; i++){
		exper_n(n, v);

		if(cond(n, v) == 1) k++;
	}

	free(v);

	return (double)k/m;

}

void exper_n(int n, pareja *v){
	int i;

	for(i = 0; i < n; i++){
		v[i].maestro = rand()%365+1;
		v[i].alumno = rand()%365+1;
	}
	qsort(v, n, sizeof(pareja), comp);
}

int cond(int n, pareja *v){
	
	int i, j, iguals = 0;

	for(i = 0; i < n-1 && iguals == 0; i++){
		for(j = i+1; j < n && iguals == 0; j++){
			if(v[i].maestro == v[j].maestro && v[i].alumno == v[j].alumno) iguals = 1;
		}
	}
	return iguals;
}

int comp(const void *p, const void *q){
	int m1 = (*(pareja*)p).maestro;
	int a1 = (*(pareja*)p).alumno;
	int m2 = (*(pareja*)q).maestro;
	int a2 = (*(pareja*)q).alumno;

	if(m1 < m2) return -1;
	else if(m2 < m1) return 1;
	else{
		if(a1 < a2) return -1;
		else return 1;
	}
}

