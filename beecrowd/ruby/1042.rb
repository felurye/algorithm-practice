=begin
Leia 3 valores inteiros e ordene-os em ordem crescente. No final, mostre os valores em ordem crescente, 
uma linha em branco e em seguida, os valores na sequência como foram lidos.

Entrada
A entrada contem três números inteiros.

Saída
Imprima a saída conforme foi especificado.
=end

input = gets.chomp.split
n1, n2, n3 = input
sort = [n1.to_i, n2.to_i, n3.to_i]

(sort.length).times do |j|
    (sort.length-1).times do |i|
        if (sort[i] > sort[i+1])
        sort[i], sort[i+1] = sort[i+1], sort[i]
        swapped = true
        end
    end
end

(sort.length).times do |i|
    puts sort[i]
end

puts ""
puts input