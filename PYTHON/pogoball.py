import pygame
from pygame.locals import *
from sys import exit

# Inicializando o pygame
pygame.init()

'''
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
'''

# Definindo a proporção da tela
largura = 700
altura = 700

# Definindo dimensões do retângulo
rect_largura = 80
rect_altura = 25

# Definindo posição inicial do retângulo
player_x = (largura / 2) - rect_largura / 2
player_y = altura - rect_altura

# Definindo a posição da máquina
maquina_x = (largura / 2) - rect_largura / 2
maquina_y = 0

# Definindo a posição da bola
bola_x = largura / 2
bola_y = altura / 2

# Definindo a direção da bola
direcao_y = 5
direcao_x = 0

# Definindo a velocidade do player
velocidade = 10

# Definindo a fonte do texto, os parâmetros são: nome da fonte, tamanho, negrito e itálico
fonte = pygame.font.SysFont("Arial", 20, True, False)
pontos = 0

# Inicializando a tela
tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Pogo")
relogio = pygame.time.Clock()

while True:
    # Definindo a taxa de atualização da tela
    relogio.tick(60)

    # Preenchendo a tela com a cor preta
    tela.fill((0, 0, 0))

    # Gerando a mensagem a ser exibida na tela
    mensagem = f"Pontos: {pontos}"

    # Renderizando o texto na tela, os parâmetros são: texto, anti-aliasing (normal = True, pixelado = False), cor do texto
    texto_formatado = fonte.render(mensagem, True, (255, 255, 255))

    # Desenhando o retângulo na tela, os parâmetros são: tela, cor, posição (x, y), largura e altura
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()

    # Desenhando o retângulo na tela, os parâmetros são: tela, cor, posição (x, y), largura e altura
    player = pygame.draw.rect(tela, (255, 255, 255), (player_x, player_y, rect_largura, rect_altura))
    bola = pygame.draw.rect(tela, (255, 255, 255), (bola_x, bola_y, 20, 20), 0, 20)
    maquina = pygame.draw.rect(tela, (255, 255, 255), (maquina_x, maquina_y, rect_largura, rect_altura))

    # Definindo o movimento do retângulo
    if pygame.key.get_pressed()[K_LEFT]:
        if player_x <= 0:
            player_x = 0
        else:
            player_x -= velocidade
    if pygame.key.get_pressed()[K_RIGHT]:
        if player_x >= largura - rect_largura:
            player_x = largura - rect_largura
        else:
            player_x += velocidade

    # Movendo a máquina
    if direcao_y < 0:
        if maquina_x < bola_x:
            maquina_x += velocidade * 0.8
        if maquina_x > bola_x:
            maquina_x -= velocidade * 0.8
    

    # Verifica se a máquina saiu da tela
    if maquina_x >= largura - rect_largura:
        maquina_x = largura - rect_largura
    
    # Movendo a bola
    bola_y += direcao_y
    bola_x += direcao_x

    # Verifica se a bola colidiu com o player
    if player.colliderect(bola):
        direcao_y *= -1
        bola_y = player_y - 20

        # Verifica para qual direção a bola irá
        if player_x + 30 < bola_x:
            direcao_x += 1
        else:
            direcao_x -= 1
    
    # Verifica se a bola colidiu com a máquina
    if maquina.colliderect(bola):
        direcao_y *= -1
        bola_y = maquina_y + 40

        # Verifica para qual direção a bola irá
        if maquina_x + 30 < bola_x:
            direcao_x += 1
        else:
            direcao_x -= 1

    # Verifica se a bola colidiu com as bordas
    if bola_x >= largura - 20 or bola_x <= 0:
        direcao_x *= -1
    

    # Verifica se a bola saiu da tela
    if bola_y <= 0:
        bola_y = altura/2
        bola_x = largura/2
        pontos += 1
        direcao_y = 5
        direcao_x = 0
    elif bola_y > altura:
        bola_y = altura/2
        bola_x = largura/2
        pontos -= 1
        direcao_y = 5
        direcao_x = 0

     # Desenha o texto na tela, os parâmetros são: texto, posição (x, y)
    tela.blit(texto_formatado, (largura - 100, 20))
    
    pygame.display.update()