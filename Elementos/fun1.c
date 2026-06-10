#include <stdio.h>
#include <math.h>

double fun1(double x){

	return x*x*x - 10*sin(x);
}

double dfun1(double x){

	return 3*x*x - 10*cos(x);
}

