/*Faça um programa que leia um vetor X[10]. Substitua a seguir, 
todos os valores nulos e negativos do vetor X por 1. Em seguida mostre o vetor X.
*/

var input = require('fs').readFileSync('./dev/stdin', 'utf8');
var lines = input.split('\n');

for (let i = 0; i < 10; i++) {
    let n = Number(lines.shift());
    n > 0 ? console.log('X[' + i + '] = ' + n) : console.log('X[' + i + '] = 1');
}
