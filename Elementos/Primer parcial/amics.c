#include <stdio.h>

int main(void){
	int num1, num2;
	int divisor = 0, divisor2 = 0;
	int cont1 = 0, cont2 = 0;
	int i = 0;

	printf("Dona'm dos nombres enters.\n");
	scanf(" %d %d", &num1, &num2);

	printf("Els divisors propis de %d són ", num1);
	while((num1/2) > divisor){
		i++;
		if ((num1%i) == 0){
			divisor = i;
			cont1 = cont1 + divisor;
			printf("%d, ", divisor);
		}
	}
	printf("que sumen %d.\n", cont1);
	
	i = 0;
	printf("Els divisors propis de %d són ", num2);
	while((num2/2) > divisor2){
		i++;
		if ((num2%i) == 0){
			divisor2 = i;
			cont2 = cont2 + divisor2;
			printf("%d, ", divisor2);
		}
	}
		printf("que sumen %d.\n", cont2);
	if(num1 == cont2 && num2 == cont1){
		printf(" %d i %d són amics.\n", num1, num2);
	}
	else{
		printf(" %d i %d no són amics.\n", num1, num2);
	}
	return 0;
}
