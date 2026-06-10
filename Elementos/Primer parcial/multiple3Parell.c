#include <stdio.h>

int main(void){
	int num = 0;
	int contpar = 0;

	while(num > -1){
		scanf(" %d", &num);
		if(num%3 == 0 && num%2 == 0){
			contpar++;
		}
	}
	printf("Hi ha %d números que son multiples de tres parells.\n", contpar);
	return 0;
}
