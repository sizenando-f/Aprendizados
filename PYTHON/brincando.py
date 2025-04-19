import pygame
from pygame.locals import *
from sys import exit

pygame.init()

largura = 600
altura = 600
x = largura / 2
y = altura / 2

tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Lembrando")
relogio = pygame.time.Clock()

while True:
    relogio.tick(60)
    tela.fill((255,255,255))
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
    
    pygame.draw.rect(tela, (0, 0, 0), (x, y, 50, 50), 0, 20)

    if pygame.key.get_pressed()[K_SPACE]:
        y -= 15
    if pygame.key.get_pressed()[K_a]:
        x -= 10
    if pygame.key.get_pressed()[K_d]:
        x += 10
    
    y += 5

    if y >= altura - 50:
        y = altura - 50
    if x >= largura - 50:
        x = largura - 50
    if y < 0:
        y = 0
    if x < 0:
        x = 0

    pygame.display.update()