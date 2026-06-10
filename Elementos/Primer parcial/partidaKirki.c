#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tirada_kirki(void){
	int dado1, dado2;
	int compt1 = 0;
	int compt2 = 0;
	int win = 0;
	srand((unsigned) time(0));

	printf("Calienta los dados jugador 1.\n");
	scanf(" %d", &dado1);

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
	
	printf("Tu turno jugador 2\n");
	scanf(" %d", &dado1);
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
		printf("El resultado de las tiradas es %d para judagor1 y %d para jugador dos!\n", compt1, compt2);
		if(compt1 < compt2){
			win = 2;
		}
		if(compt1 > compt2){
			win = 1;
		}
		if(compt1 == 50){
			win = 3;
		}
		if(compt2 == 50){
			win = 4;
		}
		if(compt2 == compt1){
			win = 0;
		}
		compt1 = 0;
		compt2 = 0;
			
		return win;
}

int main(void){
	int cont1 = 0;
	int cont2 = 0;
	int numpartides = 0;
	int win;

	while(numpartides < 5){

		win = tirada_kirki();
		if(win == 1){
			cont1++;
			numpartides++;
			printf("Molt bé jugador1!!!!!. Aneu jugador1: %d vs jugador2: %d \n", cont1, cont2); 
		}

		if(win == 2){
			cont2++;
			numpartides++;
			printf("Molt bé jugador2!!!!!. Aneu jugador1: %d vs jugador2: %d \n", cont1, cont2); 
		}
		if(win == 3){
			cont1 = 100;
			numpartides = 5;
			printf("Ets el putu amo jugador1!!!! Guanyes el joc!\n"); 
		}

		if(win == 4){
			cont2 = 100;
			numpartides = 5;
			printf("Ets el putu amo jugador2!!!! Guanyes el joc!\n"); 
		}
	}
	if(cont1 < 99){
		printf("Heu quedat jugador1: %d a jugador2: %d \n", cont1, cont2);
	}
	return 0;
	
}

