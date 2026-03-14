# -*- coding: utf-8 -*-
'''
Com base na tabela abaixo, escreva um programa que leia o código de um item e a quantidade deste item. 
A seguir, calcule e mostre o valor da conta a pagar.
'''

cod, qtd = input().split(" ")
cod = int (cod)
qtd = int (qtd)

if (cod == 1):
	valor = 4 * qtd
elif (cod == 2):
	valor = 4.5 * qtd
elif (cod == 3):
	valor = 5 * qtd
elif (cod == 4):
	valor = 2 * qtd
elif (cod == 5):
	valor = 1.5 * qtd

print("Total: R$ %.2f" % valor)