import pygame
from pygame.locals import *
from sys import exit

pygame.init()

largura = 640
altura = 480

tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Controlando objetos")
relogio = pygame.time.Clock()

x = largura / 2
y = altura / 2

while True:
    relogio.tick(60)
    tela.fill((0, 0, 0))

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
        # Para caso seja um evento unico, como pressionar uma tecla ou clicar com o mouse
        # if event.type == KEYDOWN:
        #     if event.key == K_UP or event.key == K_w:
        #         y -= 1
        #     if event.key == K_DOWN or event.key == K_s:
        #         y += 1
        #     if event.key == K_LEFT or event.key == K_a:
        #         x -= 1
        #     if event.key == K_RIGHT or event.key == K_d:
        #         x += 1
    
    # Definindo a velocidade do objeto, o valor pode ser alterado para aumentar ou diminuir a velocidade
    velocidade = 10
    # Para caso seja um evento continuo, como pressionar e segurar uma tecla ou mover o mouse
    if pygame.key.get_pressed()[K_UP] or pygame.key.get_pressed()[K_w]:
        y -= velocidade
    if pygame.key.get_pressed()[K_DOWN] or pygame.key.get_pressed()[K_s]:
        y += velocidade
    if pygame.key.get_pressed()[K_RIGHT] or pygame.key.get_pressed()[K_d]:
        x += velocidade
    if pygame.key.get_pressed()[K_LEFT] or pygame.key.get_pressed()[K_a]:
        x -= velocidade

    pygame.draw.rect(tela, (255, 0, 0), (x, y, 40, 50))
    pygame.display.update()