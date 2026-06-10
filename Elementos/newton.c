#include <stdio.h>
#include <math.h>
double fun1(double);
double dfun1(double);
double fun2(double);
double dfun2(double);

double newton(double (*fun)(double), double (*dfun)(double), double x0, double tol, int iterMax) {
    double x = x0;
    double fx = fun(x);
    double dfx = dfun(x);
    int iter = 0;

    while (fabs(fx) > tol && fabs(x - (x - fx / dfx)) > tol && iter < iterMax) {
        x = x - fx / dfx; 
        fx = fun(x);
        dfx = dfun(x);
        iter++;
    }

    if (iter >= iterMax) {
        printf("No convergió después de %d iteraciones.\n", iterMax);
    } else {
        printf("Convergió en %d iteraciones.\n", iter);
    }

    return x;
}

int main() {
    double x0, tol;
    int iterMax;

    printf("Introduce el valor inicial x0: ");
    scanf("%lf", &x0);
    printf("Introduce la tolerancia tol: ");
    scanf("%lf", &tol);
    printf("Introduce el número máximo de iteraciones iterMax: ");
    scanf("%d", &iterMax);

    double root1 = newton(fun1, dfun1, x0, tol, iterMax);
    printf("Raíz de f1(x) = x^3 - 10 * sin(x): %lf\n", root1);

    double root2 = newton(fun2, dfun2, x0, tol, iterMax);
    printf("Raíz de f2(x) = x^6 - x - 1: %lf\n", root2);

    return 0;
}
