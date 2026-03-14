/**
 * Crie um programa para ordenar um conjunto de strings pelo seu tamanho.
 * Seu programa deve receber um conjunto de strings e retornar este mesmo
 * conjunto ordenado pelo tamanho das palavras, se o tamanho das strings for
 * igual, deve-se manter a ordem original do conjunto.
 */

var input = require('fs').readFileSync('./dev/stdin/file.txt', 'utf8');
var lines = input.split('\n');

let n = Number(lines.shift());
var frases = [];

function ordenar(a, b) {
   return b.length - a.length;
}

for (let i = 0; i < n; i++) {

   frases.push((String(lines.shift())).split(' '));

   /* O ultimo vetor lido do objeto recebe um
    * caracter de escape '\r', o replace remove-o 
    * para garantir que o código gere o resultado esperado.
   */
   frases[i][frases[i].length - 1] = frases[i][frases[i].length - 1].replace('\r', '');

   frases[i] = (frases[i].sort(ordenar));

   /*
    * Imprime o resultado subtituindo a ',' do que vem  
    * do formato do objeto por espaço ' ', que garante o
    * resultado esperado pelo problema.
   */
   console.log((frases[i]).toString().replace(/,/g, ' '));
}