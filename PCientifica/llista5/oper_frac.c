#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char sig;
	unsigned int num;
	unsigned int den;
}fraccio;

unsigned int mcd(unsigned int, unsigned int);
void reduir(fraccio *);
void suma(fraccio, fraccio, fraccio *);
fraccio resta(fraccio, fraccio);
fraccio producte(fraccio, fraccio);
unsigned int quocient(fraccio, fraccio, fraccio *);
void escriure(fraccio, char, fraccio, fraccio);


int main(void){
	unsigned int div;
	fraccio fraccio1;
	fraccio fraccio2;
	fraccio rsum;
	fraccio rresta;
	fraccio rprod;
	fraccio rquo;

	printf("operació i fraccions (format: signe numerador denominador signe numerador denominador):\n");
	scanf(" %c %u %u %c %u %u", &fraccio1.sig, &fraccio1.num, &fraccio1.den, &fraccio2.sig, &fraccio2.num, &fraccio2.den);
	if(fraccio1.den == 0 || fraccio2.den == 0){
		printf("Denominador = 0 no es posible\n");
		return 1;
	}

	suma(fraccio1, fraccio2, &rsum);
	rresta = resta(fraccio1, fraccio2);
	rprod = producte(fraccio1, fraccio2);
	div = quocient(fraccio1, fraccio2, &rquo);

	printf("\n( %c %u / %u ) + ( %c %u / %u ) = ( %c %u / %u )\n", fraccio1.sig, fraccio1.num, fraccio1.den, fraccio2.sig, fraccio2.num, fraccio2.den, rsum.sig, rsum.num, rsum.den);

	printf("( %c %u / %u ) - ( %c %u / %u ) = ( %c %u / %u )\n", fraccio1.sig, fraccio1.num, fraccio1.den, fraccio2.sig, fraccio2.num, fraccio2.den, rresta.sig, rresta.num, rresta.den);

	printf("( %c %u / %u ) * ( %c %u / %u ) = ( %c %u / %u )\n", fraccio1.sig, fraccio1.num, fraccio1.den, fraccio2.sig, fraccio2.num, fraccio2.den, rprod.sig, rprod.num, rprod.den);
	
	if(div == 0){
	printf("( %c %u / %u ) / ( %c %u / %u ) = ( %c %u / %u )\n", fraccio1.sig, fraccio1.num, fraccio1.den, fraccio2.sig, fraccio2.num, fraccio2.den, rquo.sig, rquo.num, rquo.den);
	}

	return 0;
}


unsigned int mcd(unsigned int a, unsigned int b){
	unsigned int temp;
	while(b != 0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}


void reduir(fraccio *f){

	unsigned int a = mcd(f->num, f->den);

	f->num = f->num/a;
	f->den = f->den/a;
}

void suma(fraccio a, fraccio b, fraccio *result){
	
	if((a.sig == '+' && b.sig == '+') || (a.sig == '-' && b.sig == '-')){
		result->num = (a.num*b.den) + (b.num*a.den);
		result->den = a.den*b.den;
		if(a.sig == '+'){
			result->sig = '+';
		}
		else result->sig = '-';
	}
	else if(a.sig == '-' && b.sig == '+'){
		if(a.num*b.den > b.num*a.den){
			result->num = (a.num*b.den) - (b.num*a.den);
			result->den = a.den*b.den;
			result->sig = '-';
		}
		else{
			result->num = (b.num*a.den) - (a.num*b.den);
			result->den = a.den*b.den;
			result->sig = '+';
		}
	}
	else{
		if(a.num*b.den > b.num*a.den){
			result->num = (a.num*b.den) - (b.num*a.den);
			result->den = a.den*b.den;
			result->sig = '+';
		}
		else{
			result->num = (b.num*a.den) - (a.num*b.den);
			result->den = a.den*b.den;
			result->sig = '-';
		}
	}

	reduir(result);
}


fraccio resta(fraccio a, fraccio b){
	
	fraccio result;


	if((a.sig == '+' && b.sig == '-') || (a.sig == '-' && b.sig == '+')){
		result.num = (a.num*b.den) + (b.num*a.den);
		result.den = a.den*b.den;
		if(a.sig == '+'){
			result.sig = '+';
		}
		else result.sig = '-';
	}
	else if(a.sig == '+' && b.sig == '+'){
		if(a.num*b.den > b.num*a.den){
			result.num = (a.num*b.den) - (b.num*a.den);
			result.den = a.den*b.den;
			result.sig = '+';
		}
		else{
			result.num = (b.num*a.den) - (a.num*b.den);
			result.den = a.den*b.den;
			result.sig = '-';
		}
	}
	else{
		if(a.num*b.den > b.num*a.den){
			result.num = (a.num*b.den) - (b.num*a.den);
			result.den = a.den*b.den;
			result.sig = '-';
		}
		else{
			result.num = (b.num*a.den) - (a.num*b.den);
			result.den = a.den*b.den;
			result.sig = '+';
		}
	}

	reduir(&result);

	return result;
}


fraccio producte(fraccio a, fraccio b){

	fraccio result;

	result.num = a.num*b.num;
	result.den = a.den*b.den;

	if((a.sig == '+' && b.sig == '+') || (a.sig == '-' && b.sig == '-')){
		result.sig = '+';
	}
	else result.sig = '-';

	reduir(&result);

	return result;
}

unsigned int quocient(fraccio a, fraccio b, fraccio *result){

	if(b.num == 0) return 1;

	result->num = a.num*b.den;
	result->den = a.den*b.num;

	if((a.sig == '+' && b.sig == '+') || (a.sig == '-' && b.sig == '-')){
		result->sig = '+';
	}
	else result->sig = '-';

	reduir(result);

	return 0;
}


