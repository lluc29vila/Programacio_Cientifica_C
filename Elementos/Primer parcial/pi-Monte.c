#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int n = 0;
	double x, y;
	int inside = 0;
	int i = 0;
	double aproxPI;


	srand((unsigned) time(0));
	
	scanf(" %d", &n);

	for(i = 0; i < n; i++){
		x = (double) rand()/RAND_MAX;
		y = (double) rand()/RAND_MAX;

		if (x*x + y*y <= 1){
			inside++;
		}
	}
	aproxPI = 4.0* ((double)inside/(double)n);

	printf("La aproximació a PI és: %lf \n", aproxPI);

	return 0;
}


