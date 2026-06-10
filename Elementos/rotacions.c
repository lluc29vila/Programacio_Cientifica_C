#include <stdio.h>
#include <math.h>
void matriuRotacio(double rot[][3], double, int);

void matriuRotacio(double rot[][3], double alfa, int eix){

	if(eix == 1){
		rot[0][0] = 1;
		rot[0][1] = 0;
		rot[0][2] = 0;
		rot[1][0] = 0;
		rot[1][1] = cos(alfa);
		rot[1][2] = -sin(alfa);
		rot[2][0] = 0;
		rot[2][1] = sin(alfa);
		rot[2][2] = cos(alfa);
	}
	else if(eix == 2){
		rot[0][0] = cos(alfa);
		rot[0][1] = 0;
		rot[0][2] = sin(alfa);
		rot[1][0] = 0;
		rot[1][1] = 1;
		rot[1][2] = 0;
		rot[2][0] = -sin(alfa);
		rot[2][1] = 0;
		rot[2][2] = cos(alfa);
	}
	else{
		rot[0][0] = cos(alfa);
		rot[0][1] = -sin(alfa);
		rot[0][2] = 0;
		rot[1][0] = sin(alfa);
		rot[1][1] = cos(alfa);
		rot[1][2] = 0;
		rot[2][0] = 0;
		rot[2][1] = 0;
		rot[2][2] = 1;
	}

}

int main(void){
	int i = 0, j = 0, k = 0;
	double alfa, beta, gama;
	double rotX[3][3], rotY[3][3], rotZ[3][3], rot[3][3], rotFinal[3][3];

	printf("Escriu tres angles en radiants: ");
	scanf(" %lf %lf %lf", &alfa, &beta, &gama);

	matriuRotacio(rotX, alfa, 1);
	matriuRotacio(rotY, beta, 2);
	matriuRotacio(rotZ, gama, 3);

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			rot[i][j] = 0.;
			for(k = 0; k < 3; k++){
				rot[i][j] += rotZ[i][k] * rotY[k][j];
			}
		}
	}

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			rotFinal[i][j] = 0.;
			for(k = 0; k < 3; k++){
				rotFinal[i][j] += rot[i][k] * rotX[k][j];
			}
		}
	}

	printf("La matriu resultant es:\n");

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%lf ", rotFinal[i][j]);
		}
		printf("\n");
	}

	return 0;
}
