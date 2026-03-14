/*Paulinho tem em suas mãos um novo problema. Agora a sua professora
lhe pediu que construísse um programa para verificar, à partir de
dois valores muito grandes A e B, se B corresponde aos últimos dígitos de A.
*/

var input = require('fs').readFileSync('./dev/stdin', 'utf8');
var lines = input.split('\n');

let n = Number(lines.shift());
let valores = [];

for (let i = 0; i < n; i++) {
    let tamanhoA;
    let tamanhoB;
    let A;
    let B;

    valores.push((String(lines.shift())).split(' '));

    A = valores[i][0];
    B = valores[i][1].replace('\r', '');
    tamanhoA = A.length;
    tamanhoB = B.length;

    if (Number(A) > 0 && Number(B) > 0 && tamanhoB <= 1000 && tamanhoA <= 1000) {

        if (tamanhoB > tamanhoA) {
            console.log('nao encaixa');
        } else {
            /* A função substring é responsável por pegar exatamente a
             * quantidade de caracteres do final da string de A equivalente
             * ao tamanho de B, logo após faz a comparação dos valores, em
             * casos positivos imprime 'encaixa', senão, 'nao encaixa'.
            */
            A = A.substring(tamanhoA, (tamanhoA - tamanhoB));
            if (Number(A) === Number(B)) {
                console.log('encaixa');
            } else {
                console.log('nao encaixa');
            }
        }
    }
}