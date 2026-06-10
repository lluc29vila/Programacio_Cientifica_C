#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp_enters(const void *, const void *);

int main(void){
	int n, *v;
	int i;

	printf("Quants elements te la llista: ");
	scanf(" %d", &n);

	v = (int*)malloc(n*sizeof(int));
	if(v == NULL){
		printf("Error al reservar memoria\n");
		return 1;
	}

	printf("Diguem els %d valors: ", n);
	for(i = 0; i < n; i++){
		scanf(" %d", &v[i]);
	}

	qsort(v, n, sizeof(int), cmp_enters);

	printf("\nLlista dels valors ordenats:\n\n");
	for(i = 0; i < n-1; i++){
		printf("%d - ", v[i]);
	}
	printf("%d\n", v[n-1]);

	free(v);

	return 0;
}


int cmp_enters(const void *a, const void *b){
	int ant = *(int*)a;
	int post = *(int*)b;

	if(abs(ant)%2 == 1 && abs(post)%2 == 0) return -1;
		
	else if(abs(ant)%2 == 0 && abs(post)%2 == 1) return 1;
	
	else if(abs(ant)%2 == 0 && abs(post)%2 == 0){
		if(ant < 0 && post < ant) return 1;
		else return -1;
	}
	else{
		if(ant < 0 && post < ant) return -1;
		else return 1;
	}

}
		


