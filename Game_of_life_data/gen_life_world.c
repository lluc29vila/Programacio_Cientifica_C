#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void){
    int **M, i, j, rows, cols;
    FILE *out;

    srand(time(NULL));

    scanf(" %d %d", &rows, &cols);

    M = (int**)malloc(rows*sizeof(int*));
    if(M == NULL){
        return 1;
    }
    for(i = 0; i < rows; i++){
        M[i] = (int*)malloc(cols*sizeof(int));
        if(M[i] == NULL){
            free(M);
            return 1;
        }
    }

    out = fopen("life_input.txt", "w");
    if(out == NULL) return 1;

    fprintf(out, "%d %d\n", rows, cols);

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            M[i][j] = rand()%2;
            fprintf(out, "%d ", M[i][j]);
        }
        fprintf(out, "\n");
    }

    for(i = 0; i < rows; i++) free(M[i]);
    free(M);

    fclose(out);

    return 0;
}