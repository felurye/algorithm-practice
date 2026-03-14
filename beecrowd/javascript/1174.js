/*Faça um programa que leia um vetor A[100]. No final, 
mostre todas as posições do vetor que armazenam um valor
menor ou igual a 10 e o valor armazenado em cada uma das posições.
*/

var input = require('fs').readFileSync('./dev/stdin', 'utf8');
var lines = input.split('\n');

for (let i = 0; i < 100; i++) {
    let n = Number(lines.shift());
    if (n <= 10) {
        console.log('A[' + i + '] = ' + n.toFixed(1));
    }
}