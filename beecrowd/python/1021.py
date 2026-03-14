# -*- coding: utf-8 -*-
"""
Leia um valor de ponto flutuante com duas casas decimais. 
Este valor representa um valor monetário. A seguir, 
calcule o menor número de notas e moedas possíveis no qual 
o valor pode ser decomposto. As notas consideradas são de 100, 
50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 
0.05 e 0.01. A seguir mostre a relação de notas necessárias.
"""
valor = eval(input())
resto = valor

cem = cinq = vinte = dez = cinco = dois = 0

um = cinq_cent = vinte_cinco = dez_cent = cinco_cent = um_cent = 0

if (valor / 100 >= 1):
	cem = valor / 100
	resto = valor % 100
	resto = float("%.2f" % resto)

if (resto / 50 >= 1):
	cinq = resto / 50
	resto = resto % 50
	resto = float("%.2f" % resto)

if (resto / 20 >= 1):
	vinte = resto / 20
	resto = resto % 20	
	resto = float("%.2f" % resto)

if (resto / 10 >= 1):
	dez = resto / 10
	resto = resto % 10
	resto = float("%.2f" % resto)

if (resto / 5 >= 1):
	cinco = resto / 5
	resto = resto % 5
	resto = float("%.2f" % resto)

if (resto / 2 >= 1):
	dois = resto / 2
	resto = resto % 2
	resto = float("%.2f" % resto)

if (resto / 1.0 >= 1):
	um = resto / 1.0
	resto = resto % 1.0
	resto = float("%.2f" % resto)

if (resto / 0.5 >= 1):
	cinq_cent = resto / 0.5
	resto = resto % 0.5
	resto = float("%.2f" % resto)

if (resto / 0.25 >= 1):
	vinte_cinco = resto / 0.25
	resto = resto % 0.25
	resto = float("%.2f" % resto)

if (resto / 0.10 >= 1):
	dez_cent = resto / 0.10
	resto = resto % 0.10
	resto = float("%.2f" % resto)

if (resto / 0.05 >= 1):
	cinco_cent = resto / 0.05
	resto = resto % 0.05
	resto = float("%.2f" % resto)

if (resto / 0.01 >= 1):
	um_cent = resto / 0.01
	resto = resto % 0.01
	resto = float("%.2f" % resto)

print("NOTAS:")
print (int(cem), "nota(s) de R$ 100.00")
print (int(cinq), "nota(s) de R$ 50.00")
print (int(vinte), "nota(s) de R$ 20.00")
print (int(dez), "nota(s) de R$ 10.00")
print (int(cinco), "nota(s) de R$ 5.00")
print (int(dois), "nota(s) de R$ 2.00")

print("MOEDAS:")
print (int(um), "moeda(s) de R$ 1.00")
print (int(cinq_cent), "moeda(s) de R$ 0.50")
print (int(vinte_cinco), "moeda(s) de R$ 0.25")
print (int(dez_cent), "moeda(s) de R$ 0.10")
print (int(cinco_cent), "moeda(s) de R$ 0.05")
print (int(um_cent), "moeda(s) de R$ 0.01")