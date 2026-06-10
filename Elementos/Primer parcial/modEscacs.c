#include <stdio.h>

int main(void){
	int num;
	int i = 0;
	int j = 0;

	
	scanf(" %d",&num);
	
	do{
	for(i = 1; i <= num; i++){
		for(j = 1; j <= num; j++){
			if (i%2 == 0){
				if(j%2 == 0){
					printf("#");
				}
				else{
					printf(" ");
				}
			}
			else {
				if(j%2 == 0){
					printf(" ");
				}
				else{
					printf("#");
				}
			}
		}
		printf("\n");
	}
	printf("\n");	
	scanf(" %d", &num);
	}while(num >= 0);

	return 0;
}
