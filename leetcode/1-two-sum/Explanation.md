# Two Sum | Explicação da Solução

**Problema:** Two Sum
**Dificuldade:** Easy
**Tópicos:** Array, Hash Table

## 1. Descrição do Problema

Dado um array de inteiros `nums` e um número inteiro `target`, precisamos encontrar **dois índices diferentes** do array cujos valores somados sejam iguais ao `target`.

O retorno deve ser **os índices desses dois elementos**.

Regras importantes do problema:

- Existe **exatamente uma solução válida**.
- **Não podemos usar o mesmo elemento duas vezes**.
- A ordem dos índices retornados **não importa**.

### Exemplo

Entrada:

```
nums = [2,7,11,15]
target = 9
```

Saída:

```
[0,1]
```

Explicação:

```
nums[0] + nums[1] = 2 + 7 = 9
```

## 2. Entendendo o Problema

Antes de pensar na solução, precisamos interpretar corretamente o problema.

### Entrada

- Um array de inteiros
- Um valor alvo (`target`)

### Saída

- Um array contendo **dois índices**

### Restrições importantes

- O array pode conter **valores negativos**
- Pode conter **números repetidos**
- Sempre existe **uma única solução**

### Casos de borda (Edge Cases)

Alguns cenários que devemos considerar:

| Caso                               | Exemplo       |
| ---------------------------------- | ------------- |
| números negativos                  | `[-3,4,3,90]` |
| números repetidos                  | `[3,3]`       |
| solução usando dois valores iguais | `target = 6`  |

Exemplo:

```
nums = [3,3]
target = 6
```

Resultado:

```
[0,1]
```

Mesmo com valores iguais, os **índices são diferentes**, então a solução é válida.

## 3. Intuição da Solução

Se temos:

```
a + b = target
```

podemos reescrever como:

```
b = target - a
```

Ou seja, para cada número `a`, podemos calcular **qual número precisamos encontrar** para atingir o `target`.

Esse número é chamado de **complemento**.

### Exemplo

```
nums = [2,7,11,15]
target = 9
```

Para cada número calculamos:

| número | complemento |
| ------ | ----------- |
| 2      | 7           |
| 7      | 2           |
| 11     | -2          |
| 15     | -6          |

Quando encontramos um número cujo **complemento já apareceu no array**, encontramos a solução.

Para tornar essa verificação rápida usamos um **HashMap**.

### Por que usar HashMap?

Um `HashMap` permite:

- inserir valores rapidamente
- verificar existência de elementos em **tempo constante O(1)**

No nosso caso armazenamos:

```
numero -> índice
```

Exemplo:

```
2 -> 0
7 -> 1
11 -> 2
```

Assim podemos verificar instantaneamente se o complemento já apareceu.

## 4. Solução Implementada (Ideal)

### Código

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }

        return new int[] {};
    }
}
```

## 5. Explicação Passo a Passo

### 1. Criamos o HashMap

```java
Map<Integer, Integer> map = new HashMap<>();
```

Esse mapa armazenará:

```
valor -> índice
```

Exemplo:

```
2 -> 0
7 -> 1
```

### 2. Percorremos o array apenas uma vez

```
for (int i = 0; i < nums.length; i++)
```

Essa solução faz **apenas uma passagem pelo array**.

### 3. Calculamos o complemento

```
int complement = target - nums[i];
```

Exemplo:

```
target = 9
nums[i] = 2
```

Então:

```
complement = 7
```

### 4. Verificamos se o complemento já apareceu

```
map.containsKey(complement)
```

Se o complemento já estiver no mapa, encontramos a solução.

Exemplo:

```
nums = [2,7,11,15]
```

Iteração:

| índice | valor | complemento | mapa  |
| ------ | ----- | ----------- | ----- |
| 0      | 2     | 7           | {}    |
| 1      | 7     | 2           | {2:0} |

Quando chegamos no `7`, o complemento é `2`.

E `2` já está no mapa.

### 5. Retornamos os índices

```
return new int[] { map.get(complement), i };
```

Resultado:

```
[0,1]
```

### 6. Se não encontrou, armazenamos o número

```
map.put(nums[i], i);
```

Isso permite que números futuros encontrem esse valor como complemento.

## 6. Complexidade

### Complexidade de Tempo

Percorremos o array **uma única vez**.

```
O(n)
```

As operações do HashMap (`put` e `containsKey`) são:

```
O(1)
```

### Complexidade de Espaço

Precisamos armazenar até `n` elementos no HashMap.

```
O(n)
```

## 7. Alternativas de Solução

### Solução Brute Force (Força Bruta)

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    return new int[] { i, j };
                }
            }
        }
        return new int[] {};
    }
}
```

### Como funciona

Essa solução compara **todos os pares possíveis**.

Exemplo:

```
[2,7,11,15]
```

Comparações:

```
2 + 7
2 + 11
2 + 15
7 + 11
7 + 15
...
```

### Complexidade

Tempo:

```
O(n²)
```

Espaço:

```
O(1)
```

### Comparação

| Abordagem          | Tempo | Espaço | Observação |
| ------------------ | ----- | ------ | ---------- |
| Brute Force        | O(n²) | O(1)   | simples    |
| HashMap (two-pass) | O(n)  | O(n)   | melhor     |
| HashMap (one-pass) | O(n)  | O(n)   | **ideal**  |

## 8. Justificativa da Escolha

A solução **One-pass HashMap** é considerada ideal porque:

- percorre o array **apenas uma vez**
- mantém complexidade **O(n)**
- encontra o complemento imediatamente
- evita trabalho desnecessário

Essa abordagem é frequentemente esperada em **entrevistas técnicas**.

## 9. Conceitos Importantes

Esse problema envolve vários conceitos fundamentais.

### Hash Tables

Estrutura que permite:

- inserção rápida
- busca rápida
- acesso em **tempo constante O(1)**

### Complement Pattern

Um padrão muito comum em problemas de algoritmos:

```
target - valor_atual
```

Esse padrão aparece em diversos problemas de array.

### Trade-off Tempo vs Espaço

Usamos **memória extra** (HashMap) para ganhar **velocidade**.

Esse tipo de decisão é muito comum no design de algoritmos.

## 10. Dicas para Iniciantes

Algumas lições importantes desse problema:

### 1. Sempre procure padrões matemáticos

Transformar:

```
a + b = target
```

em

```
b = target - a
```

simplifica o raciocínio.

### 2. Escolha a estrutura de dados correta

Usar `HashMap` reduz drasticamente a complexidade.

### 3. Evite loops aninhados quando possível

Loops aninhados geralmente indicam:

```
O(n²)
```

Muitas vezes existe uma solução **O(n)**.
