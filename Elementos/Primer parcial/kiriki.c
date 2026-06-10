#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int dado1, dado2;
	int compt1 = 0;
	int compt2 = 0;
	srand((unsigned) time(0));

	printf("Calienta los dados jugador 1.\n");
	dado2 = rand()%6 + 1;
	dado1 = rand()%6 +1;
	if (dado1 + dado2 == 3){
		compt1 = compt1 + 50;
		printf("Tremendo tiradon [%d,%d]\n", dado1, dado2);
	}
	if (dado1 == dado2){
		compt1 = compt1 + 20 + 2*dado1;
		printf("Parejas! [%d,%d]\n", dado1, dado2);
	}
	if (dado1 + dado2 != 3 && dado1 != dado2){
		compt1 = compt1 + dado1 + dado2;
		printf("Mierdon [%d,%d]\n", dado1, dado2);
	}

	dado1 = rand()%6 + 1;
	dado2 = rand()%6 + 1;

	if (dado1 + dado2 == 3){
		compt2 = compt2 + 50;
		printf("Tremendo tiradon [%d,%d]\n", dado1, dado2);
	}
	if (dado1 == dado2){
		compt2 = compt2 + 20 + 2*dado1;
		printf("Parejas! [%d,%d]\n", dado1, dado2);
	}
	if (dado1 + dado2 != 3 && dado1 != dado2){
		compt2 = compt2 + dado1 + dado2;
		printf("Mierdon [%d,%d]\n", dado1, dado2);
	}
		printf("El resultado final es %d para judagor1 y %d para jugador dos!\n", compt1, compt2);
		return 0;
}


