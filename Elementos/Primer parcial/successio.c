#include <stdio.h>

int main(void){
	float a, b, x0, x1;
	float terme, terme1, terme2;
	int i = 0;
	float yn = 0;

	printf("Dona'm a, b, x0 i x1 en aquest ordre i sense comes.\n");
	scanf(" %f %f %f %f", &a, &b, &x0, &x1);
	
	terme1 = x0;
	terme2 = x1;

	/*Capçalera*/
	printf(" n               xn              quocient\n");
	printf("===       ===============  ==============\n");

	printf(" 0 %20.10e \n 1 %20.10e \n", x0, x1);
	for(i = 2; i < 50; i++){
		printf("%2d", i);
		terme = a*terme1 + b*terme2;
		printf(" %20.10e", terme);

		yn = terme/terme1;
		printf(" %20.10e \n", yn);

		terme1 = terme2;
		terme1 = terme;
	}
	return 0;
}

