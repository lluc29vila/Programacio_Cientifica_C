#include <stdio.h>
#define N 20

int main(void){
	int i = 0, n, m;
	double p[N], q[N];
	char letra_leida;

	printf("Dona'm el dos polinomis on a l'inici s'inidiqui el grau màxim un a un odrenats de major grau a menor\n");

	scanf(" %d", &n);
	for(i = 0; i <= n; i++){
	       scanf(" %lf", &p[i]);
	}	       

	scanf(" %d", &m);
	for(i = 0; i <= m; i++){
	       scanf(" %lf", &q[i]);
	}
	
	printf("p(x)    ");
	for(i = 0; i <= n; i++){
		printf("%e    ", p[i]);
	}
	
	printf("\nq(x)    ");
	for(i = 0; i <= m; i++){
		printf("%e    ", q[i]);
	}

	printf("\nVols sumar-los o restar-los?\n");
	scanf(" %1c", &letra_leida);
	if(letra_leida == 'S' || letra_leida == 's'){
		for(i = 0; i <= n; i++){
			p[i] = p[i] + q[i];
			printf(" %e", p[i]);
		}
		if(m > n){
			while(i <= m){
				printf(" %e", q[i]);
				i++;
			}
		}
	}
	else if(letra_leida == 'R' || letra_leida == 'r'){
		for(i = 0; i <= n; i++){
			p[i] = p[i] - q[i];
			printf(" %e", p[i]);
		}
		if(m > n){
			while(i <= m){
				printf(" %e", q[i]);
				i++;
			}
		}
	}
	else{
		printf("No se ha entendido la indicación\n");
	}
	return 0;
}

