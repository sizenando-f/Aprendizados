import pygame
from pygame.locals import *
from sys import exit
from random import randint

pygame.init()

# Definindo o volume da música de fundo, variando de 0.0 a 1.0
pygame.mixer.music.set_volume(0.5)

# Carregando o o som de fundo
musica_de_fundo = pygame.mixer.music.load("BoxCat Games - Tricks.mp3")
# Reproduzindo o som de fundo em loop (-1 significa loop infinito)
pygame.mixer.music.play(-1)

# Carregando o som de moeda, qualquer som diferente da música precisa ser .wav
som_moeda = pygame.mixer.Sound("smw_coin.wav")
som_moeda.set_volume(0.8)  # Definindo o volume do som de moeda, variando de 0.0 a 1.0

largura = 640
altura = 480

tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Sons")

relogio = pygame.time.Clock()

tam_vermelho = 40
altura_vermelho = 50

x_vermelho = randint(0, largura - tam_vermelho)
y_vermelho = randint(0, altura - altura_vermelho)

x_azul = largura / 2
y_azul = altura / 2
velocidade = 10

fonte = pygame.font.SysFont("Arial", 40, True, True)
pontos = 0

while True:
    relogio.tick(60)
    tela.fill((0,0,0))

    mensagem = f"Pontos: {pontos}"

    texto_formatado = fonte.render(mensagem, True, (255, 255, 255))

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
    
    ret_azul = pygame.draw.rect(tela, (0, 0, 255), (x_azul, y_azul, 40, 50))
    ret_vermelho = pygame.draw.rect(tela, (255, 0, 0), (x_vermelho, y_vermelho, tam_vermelho, altura_vermelho))

    if pygame.key.get_pressed()[K_UP] or pygame.key.get_pressed()[K_w]:
        y_azul -= velocidade
    if pygame.key.get_pressed()[K_DOWN] or pygame.key.get_pressed()[K_s]:
        y_azul += velocidade
    if pygame.key.get_pressed()[K_RIGHT] or pygame.key.get_pressed()[K_d]:
        x_azul += velocidade
    if pygame.key.get_pressed()[K_LEFT] or pygame.key.get_pressed()[K_a]:
        x_azul -= velocidade

    if ret_azul.colliderect(ret_vermelho):
        x_vermelho = randint(0, largura - tam_vermelho)
        y_vermelho = randint(0, altura - altura_vermelho)
        pontos += 1
        som_moeda.play()  # Reproduz o som de moeda quando o retângulo azul colide com o vermelho

    tela.blit(texto_formatado, (largura - 210, 20))
    
    pygame.display.update()