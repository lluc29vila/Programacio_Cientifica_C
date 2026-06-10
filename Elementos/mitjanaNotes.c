#include <stdio.h>
#define DIM 50

int main(void){
	int n;
	float notes[DIM];
	float x;
	int i = 0;
	int cont = 0;

	scanf(" %d", &n);

	if(n > DIM){
		printf("masses notes\n");
	}
	else {
		for(i = 0; i < n; i++){
			scanf(" %f", &notes[i]);
		}
		for(i = 0; i < n; i++){

			x += notes[i];
		}
		x = x / n;

		for(i = 0; i < n; i++){

			if(notes[i] < x){
				cont++;
			}
		}
		printf("Hi ha %d notes per sobre de la mitjana %.2f. \n", cont, x);
	}
	return 0;
}

