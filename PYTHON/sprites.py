import pygame
from pygame import *
from sys import exit

pygame.init()

largura = 640
altura = 480

tela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Sprites")

PRETO = (0,0,0)
BRANCO = (255, 255, 255)

class Sapo(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self) # Inicializa a sprite

        self.sprites = [] # Vetor para armazenar as sprites

        for i in range(1, 11):  # Armazenando todas as imagens no vetor
            self.sprites.append(pygame.image.load(f"sprites/attack_{i}.png"))
        
        self.atual = 0  # Índice da sprite atual
        self.image = self.sprites[self.atual]   # Sprite que aparecerá primeiro na tela

        self.rect = self.image.get_rect()   # Pega as dimensões imagem como um retângulo
        self.rect.topleft = 100, 270   # Escolhe o topo esquerdo da imagem como ponto de referência e coloca em 100 e 100

        self.image = pygame.transform.scale(self.image, (128*3, 64*3))  # Defini o tamanho da sprite no ínicio

        self.animar = False # Flag para saber se deve animar no início
    
    # Função para ativar a animaçõa
    def atacar(self):
        self.animar = True

    def update(self):
        # Se animação estiver ativada
        if self.animar:
            self.atual += 0.2   # Incrementa nas sprites na velocidade escolhida
            # Se estiver acabado as sprites
            if self.atual >= len(self.sprites):
                self.atual = 0  # Volta ao ínicio
                self.animar = False # Diz que a animação acabou

            self.image = self.sprites[int(self.atual)]  # Atualiza a sprite atual
            self.image = pygame.transform.scale(self.image, (128*3, 64*3))  # Mantém a dimensão da sprite


todas_sprites = pygame.sprite.Group()   # Para agrupar todas as sprites do jogo, assim ela executa para todas sprites automaticamente
sapo = Sapo()   # Instanciação do sapo
todas_sprites.add(sapo) # Adição do sapo no grupo de sprites

imagem_fundo = pygame.image.load("cidade_fundo.jpg").convert()    # Carrega imagem de fundo
imagem_fundo = pygame.transform.scale(imagem_fundo, (largura+3, altura))  # Corrije dimensão para tamanho da tela

relogio = pygame.time.Clock()

while True:
    relogio.tick(60)
    tela.fill(BRANCO)
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
        
        if event.type == KEYDOWN:
            sapo.atacar()
    
    tela.blit(imagem_fundo, (0,0))  # Blit pega uma imagem e coloca numa posição determinada (canto superior esquerdo)
    todas_sprites.draw(tela)
    todas_sprites.update()
    
    pygame.display.flip()
