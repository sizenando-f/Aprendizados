import pygame
from pygame.locals import *
from sys import exit
from random import randint

pygame.init()

largura = 640
altura = 480

tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Gerando textos")
relogio = pygame.time.Clock()

x_vermelho = largura / 2
y_vermelho = altura / 2

x_azul = randint(0, largura - 40)
y_azul = randint(0, altura - 50)

velocidade = 10

# Fonte para o texto, os parâmetros são: nome da fonte, tamanho, negrito e itálico
fonte = pygame.font.SysFont("Arial", 40, True, True)
pontos = 0 # Variável para armazenar os pontos

while True:
    relogio.tick(60)
    tela.fill((0,0,0))

    mensagem = f"Pontos: {pontos}" # Texto a ser exibido na tela

    # Renderizando o texto na tela, os parãmetros são: texto, anti-aliasing (normal = True, pixelado = False), cor do texto
    texto_formatado = fonte.render(mensagem, True, (255, 255, 255)) 

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()

    ret_vermelho = pygame.draw.rect(tela, (255, 0, 0), (x_vermelho, y_vermelho, 40, 50))
    ret_azul = pygame.draw.rect(tela, (0, 0, 255), (x_azul, y_azul, 40, 50))

    if pygame.key.get_pressed()[K_UP] or pygame.key.get_pressed()[K_w]:
        y_vermelho -= velocidade
    if pygame.key.get_pressed()[K_DOWN] or pygame.key.get_pressed()[K_s]:
        y_vermelho += velocidade
    if pygame.key.get_pressed()[K_RIGHT] or pygame.key.get_pressed()[K_d]:
        x_vermelho += velocidade
    if pygame.key.get_pressed()[K_LEFT] or pygame.key.get_pressed()[K_a]:
        x_vermelho -= velocidade
    
    if ret_vermelho.colliderect(ret_azul):
        x_azul = randint(0, largura - 40)
        y_azul = randint(0, altura - 50)
        pontos += 1 # Adiciona 1 ponto a cada vez que o retângulo vermelho colide com o azul
    
    # Desenha o texto na tela, os parâmetros são: texto, posição (x, y)
    tela.blit(texto_formatado, (largura - 210, 20))

    pygame.display.update()