#include <stdio.h>

int main(void){
	int n;
	int i= 0, j = 0;
	
	scanf(" %d", &n);
	for(i = 1; i <= n; i++){

		for(j =1; j <= n; j++){
			printf(" %d", n);
		}

		j = 1;
		printf("\n");
		if(n == i){
			printf("\n");
			scanf(" %d", &n);
			i = 1;
		}
	}
	return 0;
}
