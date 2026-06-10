#include <stdio.h>
#include <math.h>



int maximo_comun(int num1, int num2){
	int a, b;
	int rest;
	a = num1;
	b = num2;
	int mcd;
	if(num1<num2){
		num1 = b;
		num2 = a;
	}
	do{
		rest = num1%num2;
		num1 = num2;
		num2 = rest;
		mcd = num1;
	} while(rest != 0);
	return mcd;
}



int main(void){
	int a, b;
	int suma = 0;
	int i = 2;
	int mcd;
	scanf(" %d %d", &a, &b);
	while(a >= 0 && b >=  0){
		mcd = maximo_comun(a,b);
		if (mcd != 1){
			suma += mcd*((i%2 == 0) ? 1 : -1);
			i++;
		}
		scanf(" %d %d", &a, &b);

	}
	printf("= %d\n", suma);
	return 0;
}


