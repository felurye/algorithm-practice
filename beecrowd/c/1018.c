/* Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis
(cédulas) no qual o valor pode ser decomposto. As notas consideradas são de 100,
50, 20, 10, 5, 2 e 1. A seguir mostre o valor lido e a relação de notas
necessárias.
*/

#include <stdio.h>

int main() {
  int valor;
  scanf("%d", &valor);
  int original_valor = valor;

  int denomin[] = {100, 50, 20, 10, 5, 2, 1};
  int quant[7] = {0};
  const char* labels[] = {"100,00", "50,00", "20,00", "10,00",
                          "5,00",   "2,00",  "1,00"};

  // Processa notas (reais)
  for (int i = 0; i < 7; i++) {
    quant[i] = valor / denomin[i];
    valor %= denomin[i];
  }

  printf("%d\n", original_valor);
  for (int i = 0; i < 7; i++)
    printf("%d nota(s) de R$ %s\n", quant[i], labels[i]);

  return 0;
}
