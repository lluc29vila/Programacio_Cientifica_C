#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define k 2
#define a 1
#define c 1

void recfun(int n, double h0, double p0, double*hn, double *pn);
void iterfun(int n, double h0, double p0, double*hn, double *pn);


int main(void){
	
	double h0, p0;
	double hn_rec, pn_rec;
	double hn_iter, pn_iter;
	int n;

	printf("Valor de H0: ");
	scanf(" %lf", &h0);
	printf("Valor de P0: ");
	scanf(" %lf", &p0);
	printf("Valor de n: ");
	scanf(" %d", &n);

	recfun(n, h0, p0, &hn_rec, &pn_rec);

	iterfun(n, h0, p0, &hn_iter, &pn_iter); /*Aquesta funció modifica h0 i p0. Si es vol evitar s'ha de modificar la funció*/
	
	printf("\n------------- Resultats ---------------\n");
	printf("Metode Recursiu:\n");
	printf("H_%d = %.3lf\n", n, hn_rec);
	printf("P_%d = %.3lf\n", n, pn_rec);

	printf("Metode Iteratiu:\n");
	printf("H_%d = %.3lf\n", n, hn_iter);
	printf("P_%d = %.3lf\n", n, pn_iter);

	return 0;
}

	
	
void recfun(int n, double h0, double p0, double*hn, double *pn){

	double h_ant, p_ant;
	
	if(n == 0){
		*hn = h0;
		*pn = p0;
		return;
	}
	else{
		recfun(n-1, h0, p0, &h_ant, &p_ant);

		*hn = k*h_ant*exp(-a*p_ant);
		*pn = c*h_ant*(1.-exp(-a*p_ant));
	}
}

void iterfun(int n, double h0, double p0, double*hn, double *pn){
	int i;

	if(n == 0){
		*hn = h0;
		*pn = p0;
		return;
	}
	else{
		for(i = 1; i <= n; i++){
			*hn = k*h0*exp(-a*p0);
			*pn = c*h0*(1.-exp(-a*p0));

			p0 = *pn;
			h0 = *hn;
		}
	}
}

