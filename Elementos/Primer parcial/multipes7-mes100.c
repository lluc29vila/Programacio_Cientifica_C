#include <stdio.h>

int main(void){
	int num;
	int a = 100;

	printf("Donam un número major que 100.\n");
	scanf(" %d", &num);

	printf("Els multipes de 7 entre 100 i %d són: ", num);
	while(a < num){
		a++;
		if(a%7 == 0){
			printf("%d, ", a);
		}
	}
	return 0;
}
