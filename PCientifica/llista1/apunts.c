/*Apunts 10/03/2026 */

/*Punters a funció -trapezis a funció- per calcular inetegral de cada funcio que es crida.*/

double trapezis(int n, dobule a, double b, double (*f) (double)); /*Quart paramentre es un punter per a la funció de tipus doble que reven un doble i retornen un doble.
D'aquesta manera es poden calcular més d'una funció en el mateix fitxer*/

double f1(double x);
double f2(double *x);
int main (void){
	res1 = trapezis(15, 0, 1, f1); /*Funciona*/
	res2 = trapezis(12, 0, 1, f2); /*No funciona perque no es del mateix tipus*/


