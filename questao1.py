import re
t = open('resultados.txt', 'r')

content = t.readlines()
linhas = []
tempos = []
algoritmos = []
entradas = []

for linha in content:
    if len(re.findall(r'-------', linha)) == 2:
        linhas.append(linha)

for linha in linhas:
    algoritmos.append((linha.split())[-2])

#-----------------------
linhas = []
for line in content:
    if re.findall(r' ns\n',line) == [' ns\n']:
        linhas.append(line)

for linha in linhas:
    tempos.append(int((linha.split())[-2]))

#--------------------------
linhas = []
for line in content:
    if re.findall(r'_',line) == ['_']:
        entradas.append(line.split("\n")[0])
for i in range(len(entradas)):
    entradas[i] = [entradas[i]]*4
entradas = [item for sub_l in entradas for item in sub_l]

#--------------------------
import pandas as pd
dados = {'Algoritmos':algoritmos,'Tempos':tempos,'Entradas':entradas}
dados = pd.DataFrame(dados)

print(dados)

