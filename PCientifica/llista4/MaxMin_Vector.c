#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void no_recMaxMin(float *v, int p, int q, float *max, float *min);
void recMaxMin(float *v, int p, int q, float *max, float *min);

int main(void){
	float max_rec, min_rec;
	float max_norec, min_norec;
	float *v;
	int p, q, n;
	int i;

	printf("Valor de n: ");
	scanf(" %d", &n);
	if(n < 1) return 1;

	p = 0;
	q = n-1;
	
	v = (float*)malloc(n*sizeof(float));
	if(v == NULL){
		printf("Error al guardar memoria\n");
		return 1;
	}

	/*Generar valors random entre -100 i 100*/

	srand(time(NULL));

	for(i = 0; i < n; i++){
		v[i] = -100. + ((float)rand()/RAND_MAX)*200.;
	}

	no_recMaxMin(v, p, q, &max_norec, &min_norec);

	recMaxMin(v, p, q, &max_rec, &min_rec);

	printf("\n------------ Resultats --------------\n");
	printf("No recursiva:\n");
	printf("Min: %f\n", min_norec);
	printf("Max: %f\n", max_norec);
	printf("Recursiva:\n");
	printf("Min: %f\n", min_rec);
	printf("Max: %f\n", max_rec);

	free(v);

	return 0;
}
	


void no_recMaxMin(float *v, int p, int q, float *max, float *min){
	
	*min = v[p];
	*max = v[p];

	for(; p <= q; p++){
		if(v[p] < *min) *min = v[p];
		if(v[p] > *max) *max = v[p];
	}
}

void recMaxMin(float *v, int p, int q, float *max, float *min){
	int r;
	float max1, max2;
	float min1, min2;

	if(p == q){
	       	*max = v[p];
		*min = v[p];
		return;
	}
	else{
		r = (p+q)/2;
		recMaxMin(v, p, r, &max1, &min1);
		recMaxMin(v, r+1, q, &max2, &min2);
	}

	if(max1 > max2) *max = max1;
	else *max = max2;

	if(min1 < min2) *min = min1;
	else *min = min2;


}

