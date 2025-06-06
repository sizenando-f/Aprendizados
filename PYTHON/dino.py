import pygame                   # Para o jogo
from pygame.locals import *     # Importando funcionalidades
from sys import exit            # Para fechar o programa
import os                       # Para navegar pelas pastas

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

        # Define o retângulo da sprite e a posição que ela será colocada em pixel
        self.rect = self.image.get_rect()
        self.rect.center = (100,100)

    def update(self):
            # Se chegar ao final das sprites do dino
            if self.indice_lista > 2:
                # Reseta para o ínicio para reiniciar a animação
                self.indice_lista = 0

            # Incrementa em 0.25 para dar uma lentidão nas iterações
            self.indice_lista += 0.25

            # Atualiza a sprite que é mostrada, cast (int) porque índice não pode ser float
            self.image = self.imagens_dino[int(self.indice_lista)]
            
        

# Variável para agrupar todas as sprites do jogo
TODAS_AS_SPRITES = pygame.sprite.Group()

# Instãncia do dinossauro
DINO = Dino()

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
    
