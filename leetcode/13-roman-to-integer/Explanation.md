# Roman to Integer | Explicação da Solução

**Problema:** Roman to Integer
**Dificuldade:** Easy
**Tópicos:** Hash Map, String, Math

## 1. Descrição do Problema

Dado uma string `s` contendo um numeral romano, precisamos converter para seu equivalente em inteiro.

Os numerais romanos são compostos por 7 símbolos e suas correspondências são:

| Símbolo | Valor |
| ------- | ----- |
| I       | 1     |
| V       | 5     |
| X       | 10    |
| L       | 50    |
| C       | 100   |
| D       | 500   |
| M       | 1000  |

**Regra especial de subtração:**

Quando um número menor aparece **antes** de um número maior, ele deve ser **subtraído**:

| Combinação | Valor |
| ---------- | ----- |
| IV         | 4     |
| IX         | 9     |
| XL         | 40    |
| XC         | 90    |
| CD         | 400   |
| CM         | 900   |

### Exemplos

```
Input: s = "III"
Output: 3
```

```
Input: s = "LVIII"
Output: 58
```

Explicação:

```
L = 50
V = 5
III = 3
Total: 50 + 5 + 3 = 58
```

```
Input: s = "MCMXCIV"
Output: 1994
```

Explicação:

```
M = 1000
CM = 900 (C menor que M, então subtrai)
XC = 90 (X menor que C, então subtrai)
IV = 4 (I menor que V, então subtrai)
Total: 1000 + 900 + 90 + 4 = 1994
```

## 2. Entendendo o Problema

- A string contém **apenas** caracteres romanos válidos.
- O valor retornado está entre **1 e 3999**.
- A subtração ocorre **sempre que um número menor precede imediatamente um número maior**.

### Casos de borda (Edge Cases)

| Caso                  | Exemplo     | Resultado |
| --------------------- | ----------- | --------- |
| Numeral simples       | "I"         | 1         |
| Subtração simples     | "IV"        | 4         |
| Subtração múltipla    | "MCMXCIV"   | 1994      |
| Valor máximo          | "MMMCMXCIX" | 3999      |
| Repetições permitidas | "III"       | 3         |

## 3. Intuição da Solução

A chave para resolver este problema está em **detectar a regra de subtração**.

Estratégia:

1. Mapear cada caractere romano para seu valor inteiro.
2. Percorrer a string da esquerda para direita.
3. Para cada caractere:
   - **Se o próximo caractere tem um valor maior**, o caractere atual deve ser **subtraído**.
   - **Caso contrário**, o caractere atual deve ser **adicionado**.

### Exemplo: "MCMXCIV"

```
M → valor = 1000, próximo = C (100) → 100 < 1000? Não, adiciona: +1000 = 1000
C → valor = 100, próximo = M (1000) → 100 < 1000? Sim, subtrai: -100 = 900
M → valor = 1000, próximo = X (10) → 10 < 1000? Não, adiciona: +1000 = 1900
X → valor = 10, próximo = C (100) → 10 < 100? Sim, subtrai: -10 = 1890
C → valor = 100, próximo = I (1) → 1 < 100? Não, adiciona: +100 = 1990
I → valor = 1, próximo = V (5) → 1 < 5? Sim, subtrai: -1 = 1989
V → valor = 5, sem próximo → adiciona: +5 = 1994
```

## 4. Solução Implementada

### Código

```java
class Solution {

    public int romanToInt(String s) {
        Map<Character, Integer> romanValues = new HashMap<>();
        romanValues.put('I', 1);
        romanValues.put('V', 5);
        romanValues.put('X', 10);
        romanValues.put('L', 50);
        romanValues.put('C', 100);
        romanValues.put('D', 500);
        romanValues.put('M', 1000);

        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            int currentValue = romanValues.get(s.charAt(i));

            if (i + 1 < s.length() && currentValue < romanValues.get(s.charAt(i + 1))) {
                result -= currentValue;
            } else {
                result += currentValue;
            }
        }

        return result;
    }
}
```

### Explicação da Lógica

1. **Criar Map:** Todos os 7 caracteres romanos são mapeados para seus valores correspondentes.

2. **Iterar pela string:** Percorremos cada caractere da esquerda para direita.

3. **Verificar subtração:** Para cada caractere:
   - Obtemos seu valor atual do Map.
   - Verificamos se existe um próximo caractere.
   - Se existe e seu valor é **maior** que o atual, aplicamos a **subtração**.
   - Caso contrário, aplicamos a **adição**.

4. **Retornar resultado:** Ao final, temos o valor inteiro correspondente ao numeral romano.

## 5. Análise de Complexidade

**Tempo:** O(n)

- Precisamos percorrer cada caractere da string uma única vez.
- Cada operação do HashMap (get) tem complexidade O(1).

**Espaço:** O(1)

- O HashMap tem tamanho constante (sempre 7 caracteres), independentemente da entrada.
- Portanto, a complexidade espacial é O(1).

## 6. Casos de Teste

| Entrada   | Saída | Explicação                 |
| --------- | ----- | -------------------------- |
| "III"     | 3     | 1 + 1 + 1 = 3              |
| "IV"      | 4     | 5 - 1 = 4                  |
| "IX"      | 9     | 10 - 1 = 9                 |
| "LVIII"   | 58    | 50 + 5 + 1 + 1 + 1 = 58    |
| "MCMXCIV" | 1994  | 1000 + 900 + 90 + 4 = 1994 |
