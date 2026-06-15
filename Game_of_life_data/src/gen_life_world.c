#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int **M, i, j, rows, cols;
    double seed;
    FILE *out;

    if (argc != 4) {
        printf("Usage: %s rows cols seed\n", argv[0]);
        return 1;
    }

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);
    seed = atoi(argv[3]);

    srand(seed);

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

    out = fopen("data/inputs/life_input.txt", "w");
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