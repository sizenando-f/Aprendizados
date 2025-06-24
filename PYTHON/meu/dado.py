import random

inimigos = ["Rede", "Pescador", "Arpão", "Projétil", "Predador"]

probabilidade = [100, 100, 100, 100, 100]

MAX = 99999999 # Valor razoavelmente bom para intervalo de exibição nesse teste
tempo = 0
tempo_para_mostrar = MAX
quantos_inimigos_mostrar_max = 5

while True:
    if tempo == tempo_para_mostrar:
        k = random.randint(1, quantos_inimigos_mostrar_max)
        print(random.choices(inimigos, probabilidade, k = k))

        tempo = 0
        tempo_para_mostrar = random.randint(1, MAX)
        probabilidade = [random.randint(0, 100), random.randint(0, 100), random.randint(0, 100), random.randint(0, 100), random.randint(0, 100)]
        print(probabilidade)

    tempo += 1
