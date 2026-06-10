#include <stdio.h>

int main(void){
	int mcd, mcm;
	int num1, num2;
	int rest;

	printf("Inserte dos números.\n");
	scanf(" %d %d", &num1, &num2);
	
	int a, b;
	a = num1;
	b = num2;

	if(num1<num2){
		num1 = b;
		num2 = a;
	}
	do{
		rest =  num1%num2;
		num1 =  num2;
		num2 = rest;
		mcd = num1;

	} while(rest !=0);

	mcm = (a*b)/mcd;
	printf("mcd(%d,%d)= %d. mcm(%d,%d)= %d.\n", a, b, mcd, a, b, mcm);



	return 0;
}
	
