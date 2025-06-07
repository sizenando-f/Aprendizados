import pygame                   # Para o jogo
from pygame.locals import *     # Importando funcionalidades
from sys import exit            # Para fechar o programa
import os                       # Para navegar pelas pastas
from random import randrange    # Gera inteiros aleatorios

# Inicializa o pygame
pygame.init()

# Variáveis globais
# Armazena caminho absoluto do script atual
DIRETORIO_PRINCIPAL = os.path.dirname(__file__)

# Diretório com as sprites
DIRETORIO_IMAGENS = os.path.join(DIRETORIO_PRINCIPAL, "dino_sprites")

# Diretório com os sons
DIRETORIO_SONS = os.path.join(DIRETORIO_PRINCIPAL, "dino_sons")

# Dimensões da tela do jogo
ALTURA_TELA = 480
LARGURA_TELA = 640

# Cores em RGB
COR_BRANCA = (255,255,255)

# Relógio para definir o fps
RELOGIO = pygame.time.Clock()

# Inicializa tela passando o tamanho e o nome da janela
TELA = pygame.display.set_mode((LARGURA_TELA, ALTURA_TELA))
pygame.display.set_caption("Dino Game")

# Importa sprites convertendo para alpha (mantendo transparência)
SPRITE_SHEEET = pygame.image.load(os.path.join(DIRETORIO_IMAGENS, "dinoSpritesheet.png")).convert_alpha()

# Classes
# Dinossauro
class Dino(pygame.sprite.Sprite):
    # Construtor
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        # Vetor com as sprites do dinossauro
        self.imagens_dino = []

        # Laço pra inserir cada sprite no vetor
        for i in range(3):
            # SPRITE_SHEET é a imagem carregada, subsurface recorta pequenos pedaços a partir da 
            # primeira tupla como coordenada e o tamanho do recorte é a segunda tupla em pixel
            img = SPRITE_SHEEET.subsurface((i*32,0),(32,32))
            img = pygame.transform.scale(img, (32*3, 32*3))
            self.imagens_dino.append(img)

        # Define o índice de iteração da lista e a primeira imagem a ser mostrada
        self.indice_lista = 0
        self.image = self.imagens_dino[self.indice_lista]

        # Define o retângulo da sprite para conseguir controlar a posição, e a posição que ela será colocada em pixel
        self.rect = self.image.get_rect()
        self.rect.center = (100,ALTURA_TELA - 64)

    def update(self):
            # Se chegar ao final das sprites do dino
            if self.indice_lista > 2:
                # Reseta para o ínicio para reiniciar a animação
                self.indice_lista = 0

            # Incrementa em 0.25 para dar uma lentidão nas iterações
            self.indice_lista += 0.25

            # Atualiza a sprite que é mostrada, cast (int) porque índice não pode ser float
            self.image = self.imagens_dino[int(self.indice_lista)]

#Nuvem
class Nuvem(pygame.sprite.Sprite):
    # Construtor
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        # Pega a imagem recortada em 32x32 na posição 7
        self.image = SPRITE_SHEEET.subsurface((7*32,0), (32,32))
        # Aumenta o tamanho x 3
        self.image = pygame.transform.scale(self.image, (3*32, 3*32))

        # Define o retângulo para controlar posição
        self.rect = self.image.get_rect()
        # Define uma posição inicial aleatório do y da nuvem, entre 0 e 200 pixel, variando de 50 em 50
        self.rect.y = randrange(0, 200, 50)
        # Define a posição x inicial da nuvem, entre 30 e 300 menos a largura da tela para ficar dentro da tela
        self.rect.x = LARGURA_TELA - randrange(30, 300, 90)
    
    def update(self):
        # Se passar o x [0] da posição do canto superior direito do retângulo para pela borda esquerda da tela
        if self.rect.topright[0] < 0:
            # Atualiza y gerando outra posição
            self.rect.y = randrange(0, 200, 50)
            # Atualiza x para voltar ao início da tela
            self.rect.x = LARGURA_TELA

        # Velocidade que a nuvem se move para esquerda
        self.rect.x -= 4

class Chao(pygame.sprite.Sprite):
    def __init__(self, pos_x):
        pygame.sprite.Sprite.__init__(self)
        self.image = SPRITE_SHEEET.subsurface((6*32, 0), (32,32))
        self.image = pygame.transform.scale(self.image, (2*32, 2*32))

        self.rect = self.image.get_rect()
        self.rect.y = ALTURA_TELA - 64
        self.rect.x = pos_x * 64
    
    def update(self):
        if self.rect.topright[0] < 0:
            self.rect.x = LARGURA_TELA
        
        self.rect.x -= 6


# Variável para agrupar todas as sprites do jogo
TODAS_AS_SPRITES = pygame.sprite.Group()

# Instãncias
DINO = Dino()

# Para gerar 4 nuvens
for i in range(4):
    NUVEM = Nuvem()
    TODAS_AS_SPRITES.add(NUVEM)

for i in range(ALTURA_TELA*2//64):
    CHAO = Chao(i)
    TODAS_AS_SPRITES.add(CHAO)

# Acrescentando no grupo de sprites
TODAS_AS_SPRITES.add(DINO)

while True:
    # Define o jogo com 60FPS
    RELOGIO.tick(60)

    # Pinta a tela de branco
    TELA.fill(COR_BRANCA)

    # Laço principal de eventos
    for event in pygame.event.get():
        # Se a pessoa sair do jogo, fecha janela e sai
        if event.type == QUIT:
            pygame.quit()
            exit()

    # Desenha todas as sprites na tela e atualiza
    TODAS_AS_SPRITES.draw(TELA)
    TODAS_AS_SPRITES.update()

    # Limpa a tela
    pygame.display.flip()
    
