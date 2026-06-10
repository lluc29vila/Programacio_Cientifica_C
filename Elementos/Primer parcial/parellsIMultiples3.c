#include <stdio.h>

int main(void){
	int num = 0;
	int contpar = 0;
	int conttres = 0;

	while(num > -1){
		scanf(" %d", &num);
		if(num%3 == 0){
			contpar++;
		}
		if(num%2 == 0){
			conttres++;
		}
	}
	printf("Hi ha %d parells i %d multiples de tres.\n", contpar, conttres);
	return 0;
}
