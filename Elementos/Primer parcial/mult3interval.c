#include <stdio.h>

int main(void){
	int num;
	int cont = 0, contTotal = 0;
	float percent;

	scanf(" %d", &num);
	while(num < 50 && num > -50){
		if (num%3 == 0){
			cont++;
		}
		contTotal++;
		scanf(" %d", &num);
	}
	percent = (float) cont/contTotal*100;
	printf("El percentatge de nombres multiples de 3 és: %f per cent.\n", percent);
	return 0;
}
		

