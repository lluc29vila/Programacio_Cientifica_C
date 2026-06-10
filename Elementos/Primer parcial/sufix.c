#include <stdio.h>

int main(void){
	int num1, num2;
	int a, b;
	int adigit, bdigit;

	printf("Donam dos nombres enters positius:");
	scanf(" %d %d", &num1, &num2);

	if( num1 <= num2){
		a = num1;
		b = num2;
	} else{
		a = num2;
		b = num1;
		num1 = a;
		num2 = b;
	}

	while(a != 0){
		adigit = a%10;
		bdigit = b%10;

		if (adigit != bdigit){
			printf("Ningún dels números %d i %d és prefix de l'altre.\n", num1, num2);
			break;
		}
		a = a/10;
		b = b/10;
	}

	if (a == 0){
		printf("El %d és prefix de %d\n", num1, num2);
	}
	return 0;
}
