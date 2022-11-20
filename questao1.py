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
import matplotlib.pyplot as plt
dados = {'Algoritmos':algoritmos,'Tempos':tempos,'Entradas':entradas}
dados = pd.DataFrame(dados)

aleatorios_10 = dados.loc[dados['Entradas'] == "nA_10"]
aleatorios_50 = dados.loc[dados['Entradas'] == "nA_50"]
aleatorios_100 = dados.loc[dados['Entradas'] == "nA_100"]
crescentes_10 = dados.loc[dados['Entradas'] == "nC_10"]
crescentes_50 = dados.loc[dados['Entradas'] == "nC_50"]
crescentes_100 = dados.loc[dados['Entradas'] == "nC_100"]
decrescentes_10 = dados.loc[dados['Entradas'] == "nD_10"]
decrescentes_50 = dados.loc[dados['Entradas'] == "nD_50"]
decrescentes_100 = dados.loc[dados['Entradas'] == "nD_100"]

#plots de entradas aleatorias
yA10 = aleatorios_10['Tempos']
xA10 = aleatorios_10['Algoritmos']
yA50 = aleatorios_50['Tempos']
xA50 = aleatorios_50['Algoritmos']
yA100 = aleatorios_100['Tempos']
xA100 = aleatorios_100['Algoritmos']

plt.plot(xA10,yA10,label='Entrada aleatória de tamanho 10')
plt.plot(xA50,yA50,label='Entrada aleatória de tamanho 50')
plt.plot(xA100,yA100,label='Entrada aleatória de tamanho 100')
plt.legend()
plt.ylabel('Tempo em nanossegundos')
plt.xlabel('Algoritmos')
plt.show()

#plots de entradas em ordem crescente
yC10 = aleatorios_10['Tempos']
xC10 = aleatorios_10['Algoritmos']
yC50 = crescentes_50['Tempos']
xC50 = crescentes_50['Algoritmos']
yC100 = crescentes_100['Tempos']
xC100 = crescentes_100['Algoritmos']

plt.plot(xC10,yC10,label='Entrada em OC de tamanho 10')
plt.plot(xC50,yC50,label='Entrada em OC de tamanho 50')
plt.plot(xC100,yC100,label='Entrada em OC de tamanho 100')
plt.legend()
plt.ylabel('Tempo em nanossegundos')
plt.xlabel('Algoritmos')
plt.show()

#plots de entradas em ordem decrescente
yD10 = decrescentes_10['Tempos']
xD10 = decrescentes_10['Algoritmos']
yD50 = decrescentes_50['Tempos']
xD50 = decrescentes_50['Algoritmos']
yD100 = decrescentes_100['Tempos']
xD100 = decrescentes_100['Algoritmos']

plt.plot(xD10,yD10,label='Entrada em OD de tamanho 10')
plt.plot(xD50,yD50,label='Entrada em OD de tamanho 50')
plt.plot(xD100,yD100,label='Entrada em OD de tamanho 100')
plt.legend()
plt.ylabel('Tempo em nanossegundos')
plt.xlabel('Algoritmos')
plt.show()
