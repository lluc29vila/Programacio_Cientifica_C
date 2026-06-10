#include <stdio.h>
#define N 10000

int main(void){
	int n;
	int v[N];
	int i = 0;
	int j = 0;

	scanf(" %d", &n);

	if(n > N || n < 0){
		printf("massa gran");
	}
	else{
		for(i = 0; i < n-1; i++){
			v[i] = 2 + i;
		}
		for(i = 0; i < n-1; i++){
			
			if(v[i] != 0){
				for(j = i+1; j < n-1; j++){
				
					if(v[j] != 0 && v[j]%v[i] == 0){
						v[j] = 0;
					}
				}
				
			}
			printf(" %d", v[i]);
		}
		printf("\n");
	}
	return 0;
}
