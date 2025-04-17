# As coordenadas são em pixels e de ponta cabeça em relação as coordenadas cartesianas, ou seja,
# o eixo y cresce para baixo e o eixo x cresce para a direita.
# O sistema de cores é o RGB

import pygame
from pygame.locals import *
from sys import exit

pygame.init()

largura = 640
altura = 480
tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Desenho de objetos")

while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
    # Desenha um retâgulo vermelho na tela, com a posição (200, 300) -> [canto superior esquerdo], largura 40 e altura 50
    pygame.draw.rect(tela, (255, 0, 0), (200, 300, 40, 50))

    # Desenha um círculo azul na tela, com a posição (300, 260) -> [centro do círculo], raio 40
    pygame.draw.circle(tela, (0, 0, 255), (300, 260), 40)

    # Desenha uma linha amarela na tela, iniciando em (390, 0) e terminando em (390, 600), com espessura 5
    pygame.draw.line(tela, (255, 255, 0), (390, 0), (390, 600), 5)

    # Desenha um triângulo branco na tela, com os vértices em (400, altura/2), (450, altura/4) e (500, altura/2) e espessura 2
    pygame.draw.polygon(tela, (255, 255, 255), [(400, altura/2), (450, altura/4), (500, altura/2)], 2)
    pygame.display.update()
