#include <stdio.h>
#include <ctype.h>

#define N 100

int comptar_caracters(char linia[], int *vocal, int *consonant, int *espai, int *digit, int *altra);

int main(void){
	int consonants, vocals, espais, digits, altres, total;
	char linia[N+1];

	fgets(linia, N+1, stdin);

	total = comptar_caracters(linia, &vocals, &consonants, &espais, &digits, &altres);

	printf("\nResultats\n");
	printf("Vocals: %d\n", vocals);
	printf("Consontants: %d\n", consonants);
	printf("Espais en blanc: %d\n", espais);
	printf("Dígits: %d\n", digits);
	printf("Altres: %d\n", altres);
	printf("Totals: %d\n", total);

	return 0;
}

int comptar_caracters(char linia[], int *vocal, int *consonant, int *espai, int *digit, int *altra){

	int i = 0;

	*vocal = 0;
	*consonant = 0;
	*espai = 0;
	*digit = 0;
	*altra = 0;

	while( linia[i] != '\0' && linia[i] != '\n'){

		if(isalpha(linia[i])){
			linia[i] = tolower(linia[i]);
			if(linia[i] == 'a' || linia[i] == 'e' || linia[i] == 'i' || linia[i] == 'o' || linia[i] == 'u'){
				(*vocal)++;
			}
			else{
				(*consonant)++;
			}
		}
		else if(isdigit(linia[i])){
			(*digit)++;
		}
		else if(linia[i] == ' '){
			(*espai)++;
		}
		else{
			(*altra)++;
		}
	
	i++;
	}
	return i;
}



