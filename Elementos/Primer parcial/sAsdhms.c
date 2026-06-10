#include <stdio.h>

int main (void){
	int tiempo, segundos, minutos, horas, dias, semanas;
	printf("¿Cuantos segundos quieres que calcule?\n");
	scanf("%d", &tiempo);
	segundos = tiempo%60;
	minutos = tiempo/60%60;
	horas = tiempo/3600%24;
	dias = tiempo/3600/24%7;
	semanas = tiempo/3600/24/7;
	printf("Son %d semanas, %d dias, %d horas, %d minutos, %d segundos.\n", semanas, dias, horas, minutos, segundos);
return 0;
}

