#include <stdio.h>

int main(void){
	unsigned int n;
	int phi = 0;
	int i = 0;
	int k, num, r;

	int mu = 1;
	int cont = 0;

	int M = 0;
	int j = 0;

	scanf(" %u", &n);

	/*Phi*/
	
	for(i = 1; i < n; i++){
		k = i;
		num = n;
		do{
			r = num%k;
			num = k;
			k = r;
		}while(r != 0);

		if(num == 1){
			phi++;
		}
	}
	printf(" %d \n", phi);


	/*mu*/
	
	if(
			
	/*M*/





	return 0;
}
