#include <stdio.h>
#include <string.h>

#define MAX_GRAU 20

/* Funció per llegir un polinomi des d'un fitxer */
void llegir_polinomi(FILE *f, int *grau, double coef[]) {
    int i;
    fscanf(f, "%d", grau);
    for (i = 0; i <= *grau; i++) {
        fscanf(f, "%lf", &coef[i]);
    }
}

/* Funció per escriure un polinomi en un fitxer */
void escriure_polinomi(FILE *f, int grau, double coef[]) {
    int i;
    fprintf(f, "%d\n", grau);
    for (i = 0; i <= grau; i++) {
        fprintf(f, "%.6lf ", coef[i]);
    }
    fprintf(f, "\n");
}

/* Divisió de polinomis */
void dividir_polinomis(int gA, double A[], int gB, double B[],
                       int *gQ, double Q[], int *gR, double R[]) {
    int i, j, k;
    double coef;

    /* Inicialitzar residu amb A */
    *gR = gA;
    for (i = 0; i <= gA; i++) {
        R[i] = A[i];
    }

    /* Inicialitzar quocient */
    for (i = 0; i <= MAX_GRAU; i++) {
        Q[i] = 0.0;
    }

    if (gA < gB) {
        *gQ = 0;
        Q[0] = 0.0;
        return;
    }

    *gQ = gA - gB;

    while (*gR >= gB) {
        k = *gR - gB;
        coef = R[*gR] / B[gB];

        Q[k] = coef;

        for (j = 0; j <= gB; j++) {
            R[j + k] -= coef * B[j];
        }

        /* Actualitzar grau del residu */
        while (*gR > 0 && R[*gR] == 0.0) {
            (*gR)--;
        }
    }
}

int main() {
    char fitxer_dividend[11];
    char fitxer_divisor[11];
    char fitxer_quocient[11];
    char fitxer_resta[11];

    FILE *f1, *f2, *fq, *fr;

    int gA, gB, gQ, gR;
    double A[MAX_GRAU + 1], B[MAX_GRAU + 1];
    double Q[MAX_GRAU + 1], R[MAX_GRAU + 1];

    /* Demanar noms */
    printf("Nom fitxer dividend: ");
    scanf("%10s", fitxer_dividend);

    printf("Nom fitxer divisor: ");
    scanf("%10s", fitxer_divisor);

    printf("Nom fitxer quocient: ");
    scanf("%10s", fitxer_quocient);

    printf("Nom fitxer resta: ");
    scanf("%10s", fitxer_resta);

    /* Obrir fitxers */
    f1 = fopen(fitxer_dividend, "r");
    f2 = fopen(fitxer_divisor, "r");

    if (f1 == NULL || f2 == NULL) {
        printf("Error obrint fitxers d'entrada\n");
        return 1;
    }

    /* Llegir polinomis */
    llegir_polinomi(f1, &gA, A);
    llegir_polinomi(f2, &gB, B);

    fclose(f1);
    fclose(f2);

    /* Dividir */
    dividir_polinomis(gA, A, gB, B, &gQ, Q, &gR, R);

    /* Escriure resultats */
    fq = fopen(fitxer_quocient, "w");
    fr = fopen(fitxer_resta, "w");

    if (fq == NULL || fr == NULL) {
        printf("Error obrint fitxers de sortida\n");
        return 1;
    }

    escriure_polinomi(fq, gQ, Q);
    escriure_polinomi(fr, gR, R);

    fclose(fq);
    fclose(fr);

    printf("Divisio completada correctament.\n");

    return 0;
}
