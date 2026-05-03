# Longest Common Prefix | Explicação da Solução

**Problema:** Longest Common Prefix
**Dificuldade:** Easy
**Tópicos:** String, Trie

## 1. Descrição do Problema

- O problema pede para encontrar o **maior prefixo comum** entre um array de strings.
- Se não existir nenhum prefixo comum entre todas as strings, deve ser retornada uma string vazia.
- O prefixo comum é a sequência de caracteres que aparece no **início de todas as strings** do array.

**Exemplo:**

```
Input: strs = ["flower", "flow", "flight"]
Output: "fl"
```

```
Input: strs = ["dog", "racecar", "car"]
Output: ""
```

## 2. Entendendo o Problema

Antes de pensar em código, precisamos entender o que está sendo pedido.

- O array pode ter **1 a 200 strings**
- Cada string pode ter tamanho de **0 a 200 caracteres**
- Os caracteres são apenas **letras minúsculas do inglês** (a-z)
- O prefixo deve estar presente em **todas** as strings, sem exceção

### Casos de borda (Edge Cases)

- **Array vazio**: `[]` → deve retornar `""`
- **Apenas uma string**: `["alone"]` → deve retornar `"alone"`
- **Strings idênticas**: `["test", "test", "test"]` → deve retornar `"test"`
- **Nenhum prefixo em comum**: `["abc", "def", "ghi"]` → deve retornar `""`
- **Prefixo é a string inteira**: `["a", "a", "a"]` → deve retornar `"a"`

## 3. Intuição da Solução

A ideia principal é usar o **primeiro elemento como referência** e ir verificando se ele é prefixo dos demais.

Funciona assim:

1. Pegamos a primeira string como prefixo inicial
2. Para cada string seguinte, verificamos se o prefixo atual está no início dela
3. Se não estiver, **reduzimos o prefixo** removendo o último caractere
4. Repetimos até encontrar um prefixo válido ou o prefixo ficar vazio

Esse método é conhecido como **Horizontal Scanning** (varredura horizontal).

## 4. Solução Implementada

### Código

```java
class Solution {

    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        String prefix = strs[0];
        for (int i = 1; i < strs.length; i++) {
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) {
                    return "";
                }
            }
        }
        return prefix;
    }
}
```

### Explicação passo a passo

1. **Verificação de array vazio**: Se o array não tem elementos, retornamos `""` imediatamente.

2. **Inicialização**: Pegamos a primeira string (`strs[0]`) como prefixo inicial.

3. **Loop principal**: Iteramos por todas as strings a partir do índice 1.

4. **Verificação**: Usamos `indexOf(prefix) != 0` para saber se o prefixo está no início da string.
   - `indexOf` retorna o índice da primeira ocorrência ou -1 se não encontrar
   - Se não estiver no início (índice diferente de 0), o prefixo não é comum

5. **Redução do prefixo**: Enquanto o prefixo não for encontrado no início da string, vamos removendo o último caractere usando `substring`.

6. **Early return**: Se o prefixo se tornar vazio, já sabemos que não existe prefixo comum e retornamos `""`.

7. **Retorno**: Após verificar todas as strings, retornamos o prefixo encontrado.

**Trace do algoritmo com o exemplo `["flower", "flow", "flight"]`:**

```
Início: prefix = "flower"

i = 1: strs[1] = "flow"
  - "flow".indexOf("flower") = -1 (não encontrado)
  - prefix = "flowe"
  - "flow".indexOf("flowe") = -1
  - prefix = "flow"
  - "flow".indexOf("flow") = 0 ✓

i = 2: strs[2] = "flight"
  - "flight".indexOf("flow") = -1
  - prefix = "flo"
  - "flight".indexOf("flo") = -1
  - prefix = "fl"
  - "flight".indexOf("fl") = 0 ✓

Retorno: "fl"
```

## 5. Complexidade

### Complexidade de Tempo

```
O(S), onde S é a soma de todos os caracteres em todas as strings
```

No pior caso (ex: `["a", "a", "a", ...]`), verificamos cada caractere de cada string. Na prática, o algoritmo pode parar cedo quando encontra diferença.

### Complexidade de Espaço

```
O(1)
```

Estamos usando apenas uma variável `prefix` para armazenar a referência da primeira string (não consideramos o espaço da própria string de entrada como espaço extra).

## 6. Alternativas de Solução

| Abordagem           | Tempo      | Espaço | Observação                          |
| ------------------- | ---------- | ------ | ----------------------------------- |
| Horizontal Scanning | O(S)       | O(1)   | Simples e eficiente                 |
| Vertical Scanning   | O(S)       | O(1)   | Compara caractere por posição       |
| Sort and Compare    | O(n log n) | O(1)   | Ordena e compara apenas 2 strings   |
| Trie                | O(S)       | O(S)   | Excessivo para apenas buscar prefix |

**Vertical Scanning**: Percorre os caracteres verticalmente, comparando o primeiro caractere de todas as strings, depois o segundo, etc.

```
f l o w e r
f l o w     → f, l, o, w são comuns
f l i g h t → f, l são comuns
```

## 7. Justificativa da Escolha

A solução por **Horizontal Scanning** foi escolhida porque:

- É **simples e legível**: o código é direto e fácil de entender
- É **eficiente**: O(S) no pior caso, que é ótimo para este problema
- Usa **espaço constante**: não precisa de estruturas auxiliares
- Funciona bem para **todos os casos de borda**: vazio, único elemento, etc

## 8. Conceitos Importantes

- **String manipulation**: uso de `indexOf()` e `substring()` para manipulação de strings
- **Complexidade de algoritmos**: análise de tempo e espaço
- **Prefix**: conceito de prefixo em strings
- **Horizontal scanning**: padrão de iterar horizontalmente sobre os dados

## 9. Dicas para Iniciantes

Destaque aprendizados importantes:

- **Como identificar o problema**: quando ver "prefixo comum", pense em comparar strings caractere por caractere
- **Quando usar `indexOf()`**: é útil para verificar se uma substring existe no início de uma string (basta verificar se retorna 0)
- **Erro comum**: não esquecer do caso de array vazio
- **`substring(0, n)`**: remove os últimos caracteres, mantendo apenas os primeiros n

**Problemas semelhantes para praticar:**

- 28. Find the Index of the First Occurrence in a String
- 179. Largest Number
- 441. Arranging Coins

## 10. Possíveis Melhorias

Perguntas para refletir:

- **Pode ser mais simples?** A solução atual já é bastante direta
- **Pode usar menos memória?** Já é O(1)
- **Abordagem mais elegante?** O Vertical Scanning pode ser mais intuitivo em alguns casos

**Vertical Scanning melhorado:**

```java
for (int i = 0; i < strs[0].length(); i++) {
    char c = strs[0].charAt(i);
    for (int j = 1; j < strs.length; j++) {
        if (i >= strs[j].length() || strs[j].charAt(i) != c) {
            return strs[0].substring(0, i);
        }
    }
}
return strs[0];
```
