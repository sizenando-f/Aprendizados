import pygame
from pygame.locals import *
from sys import exit
from random import randint

pygame.init()

largura = 640
altura = 480

tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Jogo da Cobra")

relogio = pygame.time.Clock()

larg_maca = 20
altu_maca = 20

x_maca = randint(0, largura - larg_maca)
y_maca = randint(0, altura - altu_maca)

x_cobra = largura / 2
y_cobra = altura / 2
velocidade = 5

x_controle = 1  # Variável de controle x (0 = não muda, 1 = vai para direta, -1 = vai para esquerda)
y_controle = 0  # Variável de controle y (0 = não muda, 1 = vai para baixo, -1 = vai para cima)

fonte = pygame.font.SysFont("Arial", 20, True, True)
pontos = 0

lista_corpo = [] # Lista para armazenar as posições do corpo da cobra

# Função para desenhar o corpo da cobra
def desenha_corpo(lista_corpo):
    for XeY in lista_corpo:
        pygame.draw.rect(tela, (0, 255, 0), (XeY[0], XeY[1], 20, 20))

while True:
    relogio.tick(60)
    tela.fill((255,255,255))

    mensagem = f"Pontos: {pontos}"

    texto_formatado = fonte.render(mensagem, True, (0, 0, 0))

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
        
        if event.type == KEYDOWN:
            if event.key == K_LEFT: # Se clicar seta esquerda, para de se mover verticalmente e muda para mover para esquerda
                if x_controle != 1: # Verificação para não comer a própria cauda
                    y_controle = 0
                    x_controle = -1
            if event.key == K_RIGHT: # Se clicar seta direita, para de se mover verticalmente e muda para mover para direita
                if x_controle != -1: # Verificação para não comer a própria cauda
                    y_controle = 0
                    x_controle = 1
            if event.key == K_UP:   # Se clicar seta cima, para de se mover horizontalemnte e muda para mover para cima
                if y_controle != 1: # Verificação para não comer a própria cauda
                    y_controle = -1
                    x_controle = 0
            if event.key == K_DOWN: # Se clicar seta baixo, para de se mover horizontalmente e muda para mover para baixo
                if y_controle != -1: # Verificação para não comer a própria cauda
                    y_controle = 1
                    x_controle = 0
    
    cobra = pygame.draw.rect(tela, (0, 255, 0), (x_cobra, y_cobra, 20, 20))
    maca = pygame.draw.rect(tela, (255, 0, 0), (x_maca, y_maca, larg_maca, altu_maca))

    x_cobra += velocidade * x_controle  # Aplica velocidade na cobra multiplicado pela direção de x, se 0 então não muda horizontalmente
    y_cobra += velocidade * y_controle  # Aplica velocidade na cobra multiplicado pela direção de y, se 0 então não muda verticalmente

    # Comparações para ver se a cobra saiu da tela
    if y_cobra < 0:
        y_cobra = altura
    if y_cobra > altura:
        y_cobra = 0
    if x_cobra > largura:
        x_cobra = 0
    if x_cobra < 0:
        x_cobra = largura

    if cobra.colliderect(maca):
        x_maca = randint(0, largura - larg_maca)
        y_maca = randint(0, altura - altu_maca)
        pontos += 3

    lista_cabeca = [x_cobra, y_cobra]   # Posição da cabeça da cobra

    # Para saber a cabeca colidiu com alguma parte do corpo
    if lista_cabeca in lista_corpo:
        print("Acabou")
        lista_corpo.clear()
        pontos = 0
    
    lista_corpo.append(lista_cabeca)  # Adiciona a cabeça à lista do corpo da cobra
    if len(lista_corpo) > pontos:
        del lista_corpo[0]
    desenha_corpo(lista_corpo)  # Desenha o corpo da cobra

    
    tela.blit(texto_formatado, (largura - 120, 20))
    
    pygame.display.update()