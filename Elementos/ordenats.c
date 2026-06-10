#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 29

void imprimir_vector(int v[], int n) {
    int i = 0;
	printf("[");
    for(i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void) {
    srand(time(0));

    int n;
    int new;
    int v[N];
    int j = 0, k = 0, i = 0;

    printf("Dame un n entre 1 y 30: ");
    scanf("%d", &n);

    if (n < 1 || n > 30) {
        printf("Número no válido\n");
        return 1;
    }

    /* Vector inicial: primera mitad con valores aleatorios */
    v[0] = rand() % 10 - 5;
    printf("Vector inicial: ");
    imprimir_vector(v, 1); 

    for (i = 1; i < n / 2; i++) {
        v[i] = v[i - 1] + rand() % 10;
    }
    imprimir_vector(v, n / 2); 

    /* Llenar la segunda mitad del vector */
    k = n / 2;
    for (i = k; i < n; i++) {
        new = rand() % 100;
        printf("Número nuevo: %d\n", new);

       
        j = i - 1;
        while (j >= 0 && v[j] > new) {
            v[j + 1] = v[j];  
            j--;
        }
        v[j + 1] = new;  

        printf("Vector actualizado: ");
        imprimir_vector(v, i + 1);
    }

    return 0;
}



