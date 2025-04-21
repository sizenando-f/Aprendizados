import pygame
from pygame.locals import *
from sys import exit
from random import randint # Para gerar números aleatórios, usado para mudar a posição do retângulo azul

pygame.init()

largura = 640
altura = 480

x_vermelho = largura / 2
y_vermelho = altura / 2
velocidade = 10

x_azul = randint(0, largura - 40) # Gera um número aleatório entre 0 e largura - 40 (largura do retângulo azul) para ser a posição inicial
y_azul = randint(0, altura - 50) # Gera um número aleatório entre 0 e altura - 50 (altura do retângulo azul) para ser a posição inicial

pontos = 0

tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Colidindo objetos")
relogio = pygame.time.Clock()

while True:
    relogio.tick(60)
    tela.fill((0,0,0))

   

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()

    # É possivel guardar o objeto (retângulo) criado em uma variável
    ret_vermelho = pygame.draw.rect(tela, (255, 0, 0), (x_vermelho, y_vermelho, 40, 50))
    ret_azul = pygame.draw.rect(tela, (0, 0, 255), (x_azul, y_azul, 40, 50))

    # O retângulo azul muda de posição quando o retângulo vermelho colide com ele
    if ret_vermelho.colliderect(ret_azul):
        x_azul = randint(0, largura - 40)
        y_azul = randint(0, altura - 50)
        pontos += 1
        print("Pontos: ", pontos)

    if pygame.key.get_pressed()[K_UP] or pygame.key.get_pressed()[K_w]:
        y_vermelho -= velocidade
    if pygame.key.get_pressed()[K_DOWN] or pygame.key.get_pressed()[K_s]:
        y_vermelho += velocidade
    if pygame.key.get_pressed()[K_RIGHT] or pygame.key.get_pressed()[K_d]:
        x_vermelho += velocidade
    if pygame.key.get_pressed()[K_LEFT] or pygame.key.get_pressed()[K_a]:
        x_vermelho -= velocidade

    pygame.display.update()