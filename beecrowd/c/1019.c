/* Leia um valor inteiro, que é o tempo de duração em segundos de um determinado evento em uma fábrica,
e informe-o expresso no formato horas:minutos:segundos.
*/

#include <stdio.h>
int main(){
	int hora, min, seg;
	
	scanf("%d", &seg);
	
	hora = seg/3600;
	min = (seg-(hora*3600))/60;
	seg = seg -(hora*3600)-(min*60);

	printf("%d:%d:%d\n", hora, min, seg);
	
	return 0;
}
