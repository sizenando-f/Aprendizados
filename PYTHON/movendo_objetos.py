import pygame
from pygame.locals import *
from sys import exit

pygame.init()

largura = 640
altura = 480

# Variáveis para controlar o movimento do retângulo, o valor será alterado em cada iteração do loop, dará uma sensação de movimento
x = largura/2
y = 0


tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Movendo objetos")

# Cria um objeto relógio para controlar a taxa de atualização da tela
relogio = pygame.time.Clock()

while True:
    # Define a taxa de atualização da tela para 200 quadros por segundo
    # Isso significa que a tela será atualizada 200 vezes por segundo
    relogio.tick(200)

    # Limpa a tela com a cor preta, necessário para não deixar rastros dos objetos que foram desenhados anteriormente, criando uma impressão de movimento
    tela.fill((0, 0, 0))

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
    
    pygame.draw.rect(tela, (255, 0, 0), (x, y, 40, 50))

    # Incrementa o valor de y, fazendo com que o retângulo se mova para baixo
    y += 1
    # Se o retângulo passar do limite inferior da tela, ele volta para o topo
    if y > altura:
        y = 0
    
    pygame.display.update()