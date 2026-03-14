/* Dois carros (X e Y) partem em uma mesma direção. O carro X sai com velocidade constante
de 60 Km/h e o carro Y sai com velocidade constante de 90 Km/h.
Em uma hora (60 minutos) o carro Y consegue se distanciar 30 quilômetros do carro X, 
ou seja, consegue se afastar um quilômetro a cada 2 minutos.
Leia a distância (em Km) e calcule quanto tempo leva (em minutos)
para o carro Y tomar essa distância do outro carro.
*/

#include <stdio.h>
int main(){
	int km, distanciax=0, distanciay=0, min=0;
	int x=1000, y=1500;
	
	scanf("%d", &km);
	km *= 1000;
	
	while (distanciay-distanciax < km){
		distanciax += x;
		distanciay += y;
		min++;
	}
	
	printf("%d minutos\n", min);
	
	return 0;
}
