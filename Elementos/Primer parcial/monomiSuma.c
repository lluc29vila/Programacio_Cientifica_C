#include <stdio.h>

int main(void) {
    int n;
    int x;
    int i, j;
    int iMax = 0, jMax = 0;
    double c, coefMax = 0;
    int grauMax = -1;

    scanf("%d", &n);

    for (x = 0; x < n; x++) {
        scanf("%d %d %lf", &i, &j, &c);

        int grau = i + j;

        if (grau > grauMax || (grau == grauMax && (i > iMax || (i == iMax && j > jMax)))) {
            grauMax = grau;
            iMax = i;
            jMax = j;
            coefMax = c;
        } else if (grau == grauMax && i == iMax && j == jMax) {
            coefMax += c;
        }
    }

    printf("Monomi maxim : %d %d %e\n", iMax, jMax, coefMax);

    return 0;
}
			
			
