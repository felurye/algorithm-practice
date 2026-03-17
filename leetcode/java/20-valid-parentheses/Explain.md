# Valid Parentheses | Explicação da Solução

**Problema:** Valid Parentheses  
**Dificuldade:** Easy  
**Tópicos:** Stack, String, Hash Map

## 1. Descrição do Problema

Dada uma string `s` contendo apenas os caracteres `'('`, `')'`, `'{'`, `'}'`, `'['`, `']'`, precisamos verificar se a sequência de parênteses é **válida**.

Uma sequência é considerada válida se:

- Todo parêntese de abertura tiver **um parêntese de fechamento correspondente** do mesmo tipo.
- Os parênteses forem **fechados na ordem correta** (estrutura bem aninhada).

O retorno deve ser um `boolean`:

- `true` se a string for válida.
- `false` caso contrário.

**Exemplo:**

```
Input: s = "()[]{}"
Output: true
```

```
Input: s = "(]"
Output: false
```

## 2. Entendendo o Problema

- A string pode estar vazia ou ter vários caracteres.
- Só existem 3 tipos de parênteses: `()`, `{}`, `[]`.
- A ordem importa: `"([)]"` não é válido, mesmo tendo o mesmo número de aberturas e fechamentos.

### Casos de borda (Edge Cases)

- String vazia (`""`) → geralmente considerada válida.
- Strings com tamanho ímpar → nunca podem ser válidas (sempre sobra algo sem par).
- Um único caractere → sempre inválido.
- Sequência com fechamento sem abertura anterior → inválida, ex: `")("` ou `")"`.
- Aberturas corretas mas ordem errada → `"([)]"`.

## 3. Intuição da Solução

Esse é um problema **clássico de uso de pilha (Stack)**.

Ideia principal:

- Quando encontramos um **parêntese de abertura** (`(`, `[`, `{`), empilhamos esse caractere.
- Quando encontramos um **parêntese de fechamento** (`)`, `]`, `}`):
  - Verificamos se existe algum elemento na pilha.
  - Desempilhamos o último parêntese de abertura.
  - Checamos se ele corresponde ao tipo correto de fechamento.
- No final, se a pilha estiver vazia, todos os parênteses foram bem pareados.

Padrão utilizado:

- **Stack (LIFO – Last In, First Out)**: o último parêntese aberto deve ser o primeiro a ser fechado.

## 4. Solução Implementada

### Código

```java
class Solution {

    public boolean isValid(String s) {
        if (s == null || s.length() % 2 != 0) {
            return false;
        }

        java.util.Deque<Character> stack = new java.util.ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char open = stack.pop();
                if (!isMatchingPair(open, c)) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }

    private boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')')
                || (open == '[' && close == ']')
                || (open == '{' && close == '}');
    }
}
```

### Explicação passo a passo

1. **Verificação inicial**: se a string é `null` ou tem tamanho ímpar, já retornamos `false`, pois não é possível formar pares perfeitos.
2. **Criação da pilha**: usamos um `ArrayDeque<Character>` como pilha para armazenar os parênteses de abertura.
3. **Iteração pela string**:
   - Se o caractere atual é um **parêntese de abertura**, fazemos `push` na pilha.
   - Se é um **parêntese de fechamento**:
     - Se a pilha está vazia, não há abertura correspondente → retornamos `false`.
     - Caso contrário, fazemos `pop` e verificamos se o par aberto/fechado é do mesmo tipo usando `isMatchingPair`.
4. **Após o loop**:
   - Se a pilha está vazia, todos os parênteses foram fechados corretamente → retornamos `true`.
   - Se ainda há elementos na pilha, existem aberturas sem fechamento → retornamos `false`.

## 5. Complexidade

### Complexidade de Tempo

- Percorremos a string uma única vez.
- Cada caractere é empilhado ou desempilhado no máximo uma vez.

Logo, a complexidade de tempo é:

```
O(n)
```

onde `n` é o tamanho da string `s`.

### Complexidade de Espaço

- No pior caso, todos os caracteres são de abertura (por exemplo, `"(((([[[{{{"`), então todos são empilhados.

Complexidade de espaço:

```
O(n)
```

## 6. Alternativas de Solução

1. **Usar um `HashMap` para mapear fechamentos para aberturas**
   - Ex.: `')' -> '(', ']' -> '[', '}' -> '{'`.
   - Deixa o código mais flexível e evita `if` encadeados.

2. **Usar uma string de substituição repetida**
   - Enquanto a string contém `"()"`, `"[]"` ou `"{}"`, substituir por `""`.
   - No final, verificar se a string ficou vazia.
   - Porém, essa abordagem é menos eficiente (pode chegar a O(n²)).

| Abordagem                     | Tempo | Espaço | Observação                      |
| ----------------------------- | ----- | ------ | ------------------------------- |
| Pilha com comparações diretas | O(n)  | O(n)   | Simples e eficiente             |
| Pilha + HashMap               | O(n)  | O(n)   | Código mais organizado/flexível |
| Substituição de strings       | O(n²) | O(1)   | Fácil de entender, mas lenta    |

## 7. Justificativa da Escolha

- A abordagem com **pilha** é a mais natural para esse tipo de problema.
- A complexidade de tempo é **O(n)**, ótima para entradas grandes.
- A implementação é simples, direta e fácil de testar.

## 8. Conceitos Importantes

- Estrutura de dados **Stack (Pilha)**.
- Comportamento **LIFO (Last In, First Out)**.
- Validação de estruturas aninhadas.

## 9. Dicas

- Sempre que você tiver que validar algo que **abre e fecha em ordem**, pense em pilha (ex.: HTML tags, expressões matemáticas, etc.).
- Treine identificar padrões:
  - parênteses balanceados → pilha
  - janela deslizante → sliding window
  - prefixos/sufixos → arrays auxiliares, prefix sum
- Teste sempre:
  - sequência vazia,
  - apenas aberturas,
  - apenas fechamentos,
  - ordens trocadas como `"([)]"`.
