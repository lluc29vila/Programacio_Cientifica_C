#include <stdio.h>
#include <math.h>

double fun2(double x){
	return pow(x,6) - x - 1;
}

double dfun2(double x){
	return 6*pow(x,5) - 1;
}


