=begin

Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas de um ponto em um plano. 
A seguir, determine qual o quadrante ao qual pertence o ponto, ou se está sobre um dos eixos cartesianos 
ou na origem (x = y = 0).

Se o ponto estiver na origem, escreva a mensagem “Origem”.

Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou “Eixo Y”, conforme for a situação.

Entrada
A entrada contem as coordenadas de um ponto.

Saída
A saída deve apresentar o quadrante em que o ponto se encontra.
=end

coordenadas = gets.chomp.split
x = coordenadas[0].to_f
y = coordenadas[1].to_f

puts "Origem" if x == 0 && y == 00
puts "Eixo Y" if x == 0 && y != 00
puts "Eixo X" if x != 0 && y == 00
puts "Q1" if x > 0 && y > 0
puts "Q2" if x < 0 && y > 0
puts "Q3" if x < 0 && y < 0
puts "Q4" if x > 0 && y < 0