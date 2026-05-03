# Median of Two Sorted Arrays | Explicação da Solução

**Problema:** Median of Two Sorted Arrays
**Dificuldade:** Hard
**Tópicos:** Array, Binary Search, Divide and Conquer

## 1. Descrição do Problema

Dado dois arrays ordenados de inteiros, `nums1` e `nums2`, precisamos encontrar a **mediana** do conjunto formado pela união dos dois arrays.

- A mediana é o valor central (ou a média dos dois valores centrais) de um conjunto ordenado.
- O retorno deve ser um número decimal (double).

**Exemplo:**

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.0
```

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.5
```

## 2. Entendendo o Problema

- Os arrays são **ordenados**.
- Podem ter tamanhos diferentes.
- O total de elementos é sempre >= 1.
- Valores podem ser negativos.

### Casos de borda

- Um array vazio e outro com elementos.
- Arrays de tamanhos diferentes.
- Arrays com valores repetidos.

## 3. Intuição da Solução

A solução mais eficiente usa **busca binária** para encontrar a mediana sem precisar unir os arrays.

- Queremos dividir os dois arrays em duas partes, de modo que a metade esquerda tenha o mesmo número de elementos que a metade direita.
- A mediana estará entre os maiores valores da metade esquerda e os menores da metade direita.
- Usamos busca binária para encontrar o ponto de divisão ideal.

## 4. Solução Implementada

### Código (padrão para O(log(min(m,n))) em Java):

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.length;
        int n = nums2.length;
        int imin = 0, imax = m;
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = (m + n + 1) / 2 - i;
            int maxLeftA = (i == 0) ? Integer.MIN_VALUE : nums1[i - 1];
            int minRightA = (i == m) ? Integer.MAX_VALUE : nums1[i];
            int maxLeftB = (j == 0) ? Integer.MIN_VALUE : nums2[j - 1];
            int minRightB = (j == n) ? Integer.MAX_VALUE : nums2[j];
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (Math.max(maxLeftA, maxLeftB) + Math.min(minRightA, minRightB)) / 2.0;
                } else {
                    return Math.max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                imax = i - 1;
            } else {
                imin = i + 1;
            }
        }
        return 0.0;
    }
}
```

### Explicação passo a passo

1. Garantimos que `nums1` é o menor array.
2. Usamos busca binária para dividir ambos os arrays.
3. Calculamos os valores à esquerda e à direita das divisões.
4. Se as condições de mediana são satisfeitas, retornamos o valor.
5. Caso contrário, ajustamos a busca binária.

## 5. Complexidade

- **Tempo:** O(log(min(m, n)))
- **Espaço:** O(1) (não usamos espaço extra)

## 6. Solução com Merge (Alternativa Simples)

Uma abordagem mais simples (mas menos eficiente) é fazer o merge dos dois arrays em um único array ordenado, e depois encontrar a mediana.

### Código com Merge:

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] merged = new int[nums1.length + nums2.length];
        int i = 0, j = 0, k = 0;

        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] <= nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }

        while (i < nums1.length) {
            merged[k++] = nums1[i++];
        }

        while (j < nums2.length) {
            merged[k++] = nums2[j++];
        }

        int n = merged.length;
        if (n % 2 == 1) {
            return merged[n / 2];
        } else {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    }
}
```

### Passo a passo:

1. Criamos um novo array `merged` com o tamanho combinado.
2. Usamos dois ponteiros `i` e `j` para percorrer `nums1` e `nums2`.
3. Comparamos os elementos e adicionamos o menor ao array merged.
4. Depois de terminar o merge, encontramos a mediana:
   - Se o tamanho é ímpar, retornamos o elemento do meio.
   - Se for par, retornamos a média dos dois elementos do meio.

### Vantagens e Desvantagens:

| Aspecto      | Merge           | Busca Binária        |
| ------------ | --------------- | -------------------- |
| Simplicidade | ✅ Mais simples | ❌ Mais complexa     |
| Velocidade   | ❌ O(m + n)     | ✅ O(log(min(m,n)))  |
| Espaço       | ❌ O(m + n)     | ✅ O(1)              |
| Entendimento | ✅ Fácil        | ❌ Requer pensamento |

## 7. Alternativas de Solução

| Abordagem     | Tempo            | Espaço | Observação         |
| ------------- | ---------------- | ------ | ------------------ |
| Merge e busca | O(m + n)         | O(m+n) | Simples, mas lenta |
| Busca binária | O(log(min(m,n))) | O(1)   | Mais eficiente     |

- A abordagem de merge une os arrays e pega a mediana, mas não atende ao requisito de eficiência.

## 8. Justificativa da Escolha

- A busca binária é mais rápida e eficiente, especialmente para arrays grandes.
- Não usa espaço extra.
- É mais complexa, mas vale a pena para problemas de alta performance.

## 9. Conceitos Importantes

- Busca binária
- Divisão de arrays
- Mediana
- Complexidade de algoritmos

## 10. Dicas para Iniciantes

- Pratique busca binária em problemas simples.
- Entenda como dividir arrays e calcular medianas.
- Teste com arrays de tamanhos diferentes e casos de borda.

## 11. Possíveis Melhorias

- Para arrays pequenos, a abordagem de merge pode ser mais simples.
- Estude outras formas de dividir arrays para problemas semelhantes.
