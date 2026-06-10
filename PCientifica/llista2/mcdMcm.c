#include <stdio.h>

void mcdMcm(int*, int*);

int main(void){
	int a, b;

	scanf(" %d %d", &a, &b);

	if(a > 0 && b > 0){

		mcdMcm(&a, &b);

		printf("El MCD: %d i el MCM: %d\n", a, b);
	}
	else{
		return 1;
	}

	return 0;
}

void mcdMcm(int *a, int *b){
	int r, x, y;
	int mcd, mcm;

	x = *a;
	y = *b;

	while(y != 0){
		r = y;
		y = x%y;
		x = r;
	}
	mcd = x;
	mcm = (*a * *b)/mcd;

	*a = mcd;
	*b = mcm;

}
		


