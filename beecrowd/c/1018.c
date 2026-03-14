/* Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis (cédulas) 
no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1. 
A seguir mostre o valor lido e a relação de notas necessárias.
*/

#include <stdio.h>
int main(){

	double valor, troco;
	int cem, cinquenta, vinte, dez, cinco, dois;
	double um, m50, m25, m10, m5, m1;

	scanf("%lf",&valor);

	troco = valor;

	while (reais/100){
		troco-= 100;
		cont_100++;
	}
	while (reais/50){
		reais -= 50;
		cont_50++;
	}
	while (reais/20){
		reais -= 20;
		cont_20++;
	}
	while (reais/10){
		reais -= 10;
		cont_10++;
	}
	while (reais/5){
		reais -= 5;
		cont_5++;
	}
	while (reais/2){
		reais -= 2;
		cont_2++;
	}
	if (reais){
		cont_1++;
	}

	// processamento da parte fracionária (centavos)
	while (centavos/50){
		centavos -= 50;
		cont_50_cent++; 
	}
	while (centavos/25){
		centavos -= 25;
		cont_25_cent++;
	}
	while (centavos/10){
		centavos -= 10;
		cont_10_cent++;
	}
	while (centavos/5){
		centavos -= 5;
		cont_5_cent++;
	}
	while (centavos){
		centavos--;
		cont_1_cent++;
	}
    
	printf("NOTAS:\n");
	printf("%lf nota(s) de R$ 100.00\n", cem);
	printf("%lf nota(s) de R$ 50.00\n", cinquenta);
	printf("%lf nota(s) de R$ 20.00\n", vinte);
	printf("%lf nota(s) de R$ 10.00\n", dez);
	printf("%lf nota(s) de R$ 5.00\n", cinco);
	printf("%lf nota(s) de R$ 2.00\n", dois);
	printf("MOEDAS:\n");
	printf("%lf moeda(s) de R$ 1.00\n", um);
	printf("%lf moeda(s) de R$ 0.50\n", m50);
	printf("%lf moeda(s) de R$ 0.25\n", m25);
	printf("%lf moeda(s) de R$ 0.10\n", m10);
	printf("%lf moeda(s) de R$ 0.05\n", m5);
	printf("%lf moeda(s) de R$ 0.01\n", troco);
	   
	return(0);
}
