#include <stdio.h>

int main(void){
	int num1, num2;
	int digit1, digit2;
	int cont = 0;

	printf("Dona'm dos números.\n");
	scanf(" %d %d", &num1, &num2);

	while(num1 != 0){
		digit1 = num1%10;
		digit2 = num2%10;
		cont++;
		if(digit1 == digit2){
			printf("En la posición %d se repite el %d.\n", cont, digit1);
		}
		num1 = num1/10;
		num2 = num2/10;
	}
	return 0;
}

