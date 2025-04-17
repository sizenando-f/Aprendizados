import pygame
from pygame.locals import *
from sys import exit

# Inicializa todas as funções e variáveis da biblioteca Pygame
pygame.init()

# Dimensões da tela
largura = 640
altura = 480

# Cria uma tela com as dimensões especificadas
tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Tela inicial")

# Loop onde ficará todo o script do jogo
while True:
    # For para saber se algum evento ocorreu
    for event in pygame.event.get():
        # Verifica se o evento foi o fechamento da tela
        if event.type == QUIT:
            pygame.quit()   # Fecha o Pygame
            exit()  #Fecha o programa
    # Atualiza a tela do jogo a cada iteração do loop, se não tiver, o jogo trava
    pygame.display.update()