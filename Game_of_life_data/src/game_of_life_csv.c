/*Game_of_life where we can see a comparation of three versions of the game: closed, periodic and mobius*/


#include <stdio.h>
#include <stdlib.h>

typedef int(*Counter)(int**, int, int, int, int);
int** read_grid(const char* filename, int* rows, int* cols);
/*void print_grid(int** grid, int rows, int cols);*/
void print_comp(int **g0, int **g1, int **g2, int rows, int cols);
int count_neighbors(int** grid, int rows, int cols, int i, int j);
int count_neighbors_periodic(int **grid, int rows, int cols, int i, int j);
int count_neighbors_mobius(int **grid, int rows, int cols, int i, int j);
void update_grid(int** current, int** next, int rows, int cols, Counter count);
void free_grid(int** grid, int rows);
void save_generation(FILE *out, int **grid, int rows, int cols, int generation, const char *topology);


int main(void){

	FILE *out;
	char nameE[80];

	int i, j, rows, cols, pas;
	int generations = 100;
	int **current, **next, **aux, **cur_period, **next_period, **cur_mobius, **next_mobius;

	printf("What is de name of the input document? ");
	scanf(" %s", nameE);
	current = read_grid(nameE, &rows, &cols);

	next = (int**)malloc(rows*sizeof(int*));
	if(next == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	for(i = 0; i < rows; i++){
		next[i] = (int*)malloc(cols*sizeof(int));
		if(next[i] == NULL){
			printf("Error de memoria\n");
			return 1;
		}
	}

/*Reserva memoria periodic*/

	cur_period = (int**)malloc(rows*sizeof(int*));
	if(cur_period == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	/*Inicializo y copio matrices periodic*/
	for(i = 0; i < rows; i++){
		cur_period[i] = (int*)malloc(cols*sizeof(int));
		if(cur_period[i] == NULL){
			printf("Error de memoria\n");
			return 1;
		}
		for(j = 0; j < cols; j++){
			cur_period[i][j] = current[i][j];
		}
	}
	next_period = (int**)malloc(rows*sizeof(int*));
	if(next_period == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	for(i = 0; i < rows; i++){
		next_period[i] = (int*)malloc(cols*sizeof(int));
		if(next_period[i] == NULL){
			printf("Error de memoria\n");
			return 1;
		}
	}

/*Reserva memoria Mobius*/

	cur_mobius = (int**)malloc(rows*sizeof(int*));
	if(cur_mobius == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	/*Inicializo y copio matrices periodic*/
	for(i = 0; i < rows; i++){
		cur_mobius[i] = (int*)malloc(cols*sizeof(int));
		if(cur_mobius[i] == NULL){
			printf("Error de memoria\n");
			return 1;
		}
		for(j = 0; j < cols; j++){
			cur_mobius[i][j] = current[i][j];
		}
	}
	next_mobius = (int**)malloc(rows*sizeof(int*));
	if(next_mobius == NULL){
		printf("Error de memoria\n");
		return 1;
	}
	for(i = 0; i < rows; i++){
		next_mobius[i] = (int*)malloc(cols*sizeof(int));
		if(next_mobius[i] == NULL){
			printf("Error de memoria\n");
			return 1;
		}
	}
	
	/*Obro fitxer on es guarden les dades*/
	out = fopen("life.csv", "w");
	if(out == NULL){
		printf("Error al abrir fitxero\n");
		return 1;
	}

	/*Cabecera*/
	fprintf(out, "generation,row_num,col_num,state,topology\n");
	/*Imprimeixo el mon inicial*/
	printf("\n------------Initial World--------------\n");
	print_comp(current, cur_period, cur_mobius, rows, cols);

	save_generation(out, current, rows, cols, 0, "closed");
	save_generation(out, cur_period, rows, cols, 0, "periodic");
	save_generation(out, cur_mobius, rows, cols, 0, "mobius");

	
	if(generations <= 10) printf("Generating %d generations\n", generations);

	for(pas = 1; pas <= generations; pas++){

		if(generations <= 10) printf("Generation %d\n", pas);

		/*Update tancada*/
	
		update_grid(current, next, rows, cols, count_neighbors);
		
		aux = current;
		current = next;
		next = aux;

		/*Update periodic*/

		update_grid(cur_period, next_period, rows, cols, count_neighbors_periodic);

		aux = cur_period;
		cur_period = next_period;
		next_period = aux;

		/*Update Mobius*/
		
		update_grid(cur_mobius, next_mobius, rows, cols, count_neighbors_mobius);

		aux = cur_mobius;
		cur_mobius = next_mobius;
		next_mobius = aux;

		if(generations <= 10) print_comp(current, cur_period, cur_mobius, rows, cols);

		save_generation(out, current, rows, cols, pas, "closed");
		save_generation(out, cur_period, rows, cols, pas, "periodic");
		save_generation(out, cur_mobius, rows, cols, pas, "mobius");

	}

	fclose(out);

	free_grid(current, rows);
	free_grid(next, rows);
	free_grid(cur_period, rows);
	free_grid(next_period, rows);
	free_grid(cur_mobius, rows);
	free_grid(next_mobius, rows);

	return 0;
}


void free_grid(int** grid, int rows){
	int i;

	for(i= 0; i < rows; i++) free(grid[i]);
	free(grid);
}


void update_grid(int** current, int** next, int rows, int cols, Counter count){
	int i, j, cont = 0;

	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){

			/*Eleccio del tipo de contador segons tipus fronteres*/
			cont = count(current, rows, cols, i, j);

			if(current[i][j] == 1){
				if(cont == 2 || cont == 3) next[i][j] = 1;
				else next[i][j] = 0;
			}
			else if(current[i][j] == 0 && cont == 3) next[i][j] = 1;
			else next[i][j] = 0;
		}
	}
}



int count_neighbors(int** grid, int rows, int cols, int i, int j){
	int cont = 0, di, dj, ni, nj;
	
	for(di = -1; di <= 1; di++) {
		for(dj = -1; dj <= 1; dj++) {
			if(di == 0 && dj == 0) continue;
			ni = i + di;
			nj = j + dj;
			if(ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
				cont += grid[ni][nj];
			}
		}
	}
	return cont;
}

int count_neighbors_periodic(int **grid, int rows, int cols, int i, int j){

	int cont = 0, di, dj, ni, nj;
	for(di = -1; di <= 1; di++) {
		for(dj = -1; dj <= 1; dj++) {
			if(di == 0 && dj == 0) continue;
			ni = ((i + di)%rows + rows)%rows;
			nj = ((j + dj)%cols + cols)%cols;
			cont += grid[ni][nj];
		}
	}
	return cont;
}

int count_neighbors_mobius(int **grid, int rows, int cols, int i, int j){

	int cont = 0, di, dj, ni, nj;
	for(di = -1; di <= 1; di++) {
		for(dj = -1; dj <= 1; dj++) {
			if(di == 0 && dj == 0) continue;
			ni = i + di;
			nj = j + dj;

			if(ni < 0 || ni >= rows) continue;

			if(nj < 0){
				nj = cols - 1;
				ni = rows - 1 - i;
			}
			else if(nj >= cols){
				nj = 0;
				ni = rows - 1 - i;
			}

			if(ni < 0 || ni >= rows) continue;

			cont += grid[ni][nj];
		}
	}
	return cont;
}



/*
void print_grid(int** grid, int rows, int cols){
	int i, j;

	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			if(grid[i][j] == 1) printf("0 ");
			else printf(". ");
		}
		printf("\n");
	}
	printf("\n");
}
*/

void print_comp(int **g0, int **g1, int **g2, int rows, int cols){
	int i, j;

	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			if(g0[i][j] == 1) printf("0 ");
			else printf(". ");
		}
		printf("     ");
		for(j = 0; j < cols; j++){
			if(g1[i][j] == 1) printf("0 ");
			else printf(". ");
		}
		printf("     ");
		for(j = 0; j < cols; j++){
			if(g2[i][j] == 1) printf("0 ");
			else printf(". ");
		}
		printf("\n");
	}
	printf("\n");
}



int** read_grid(const char* filename, int* rows, int* cols){
	FILE *inp;
	int **M;
	int i, j;

	inp = fopen(filename, "r");
	if(inp == NULL){
		printf("Error al obrir fitxer de entrada\n");
		exit(1);
	}

	fscanf(inp, " %d %d", rows, cols);

	M = (int**)malloc(*rows*sizeof(int*));
	if(M == NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i = 0; i < *rows; i++){
		M[i] = (int*)malloc(*cols*sizeof(int));
		if(M[i] == NULL){
			printf("Error de memoria\n");
			exit(1);
		}
		for(j = 0; j < *cols; j++){
			fscanf(inp, " %d", &M[i][j]);
		}

	}

	fclose(inp);
	return M;
}

void save_generation(FILE *out, int **grid, int rows, int cols, int generation, const char *topology){
	int i, j;

	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			fprintf(out, "%d,%d,%d,%d,%s\n", generation, i, j, grid[i][j], topology);
		}
	}
}