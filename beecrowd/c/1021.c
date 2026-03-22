/* Leia um valor de ponto flutuante com duas casas decimais. Este valor
representa um valor monetário. A seguir, calcule o menor número de notas e
moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são
de 100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e
0.01. A seguir mostre a relação de notas necessárias.
*/

#include <stdio.h>

int main() {
  double valor;
  scanf("%lf", &valor);

  // Converte para centavos (inteiros) para evitar problemas com ponto flutuante
  int centavos = (int)(valor * 100 + 0.5);

  // Arrays com denominações em centavos e rótulos
  int denomin[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
  int quant[12] = {0};
  const char* labels[] = {"100.00", "50.00", "20.00", "10.00", "5.00", "2.00",
                          "1.00",   "0.50",  "0.25",  "0.10",  "0.05", "0.01"};

  // Calcula notas e moedas
  for (int i = 0; i < 12; i++) {
    quant[i] = centavos / denomin[i];
    centavos %= denomin[i];
  }

  printf("NOTAS:\n");
  for (int i = 0; i < 6; i++)
    printf("%d nota(s) de R$ %s\n", quant[i], labels[i]);

  printf("MOEDAS:\n");
  for (int i = 6; i < 12; i++)
    printf("%d moeda(s) de R$ %s\n", quant[i], labels[i]);

  return 0;
}
