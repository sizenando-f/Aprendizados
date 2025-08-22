import pygame                           # Para o jogo
from pygame.locals import *             # Importando funcionalidades
from sys import exit                    # Para fechar o programa
import os                               # Para navegar pelas pastas
from random import randrange, choice    # Gera inteiros aleatorios

# Inicializa o pygame
pygame.init()
pygame.mixer.init()

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

# Som para quando dinossauro bater em obstáculo
SOM_COLISAO = pygame.mixer.Sound(os.path.join(DIRETORIO_SONS, "death_sound.wav"))
# Coloca volume no máximo
SOM_COLISAO.set_volume(1)
# Inicialmente não colidiu com nada
COLIDIU = False

# Escolha aleatória sobre qual obstáculo vai aparecer
ESCOLHA_OBSTACULO = choice([0, 1])

# Classes
# Dinossauro
class Dino(pygame.sprite.Sprite):
    # Construtor
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)

        # Define o som de pulo
        self.som_pulo = pygame.mixer.Sound(os.path.join(DIRETORIO_SONS, "jump_sound.wav"))
        # Seta o volumo, 0 - 1
        self.som_pulo.set_volume(1)

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

        # Máscara sobreposta em sprite para inserir colisão
        self.mask = pygame.mask.from_surface(self.image)
 
        # Sseta posição inicial y para ser usado na comparação se o dinossauro está no chão (96 é a altura do dinossaruo, //2 pega o centro)
        self.pos_y_inicial = ALTURA_TELA - 64 - 96//2
        # Inicialmente não está pulando
        self.pulo = False
    
    # Função para quando o dinossauro pular
    def pular(self):
        # Define que é pra pular
        self.pulo = True
        # Toca som de pulo
        self.som_pulo.play()

    def update(self):
            # Se for pra pular
            if self.pulo:
                # Se ele tiver alcançado a altura desejada
                if self.rect.y <= 250:
                    # Para de pular
                    self.pulo = False
                # Caso contrário continua subindo
                self.rect.y -= 12
            else:
                # Se não estiver pulando, verifica se a posição atual é menor que a posição inicial do y (altura do chão)
                if self.rect.y < self.pos_y_inicial:
                    # Se for move o dinossaruo para o chão, fazendo ele cair
                    self.rect.y += 12
                else:
                    # Se não for, quer dizer que ele está no chão, então precisa apenas deixar ele no chão
                    self.rect.y = self.pos_y_inicial

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

# Chão
class Chao(pygame.sprite.Sprite):
    # Construtor
    def __init__(self, pos_x):
        pygame.sprite.Sprite.__init__(self)
        # Pega a sprite na posição 6
        self.image = SPRITE_SHEEET.subsurface((6*32, 0), (32,32))
        # Aumenta o tamanho em 2
        self.image = pygame.transform.scale(self.image, (2*32, 2*32))

        # Pega o retângulo da imagem
        self.rect = self.image.get_rect()
        # Posiciona y na altura - 64
        self.rect.y = ALTURA_TELA - 64
        # Pega o índice recebido e posiciona em x multiplicado por 64 (tamanho da imagem) para dar impressão de preenchimento
        self.rect.x = pos_x * 64 
    
    def update(self):
        # Se passar da tela
        if self.rect.topright[0] < 0:
            # Reinicia
            self.rect.x = LARGURA_TELA
        
        # Velocidade o chão
        self.rect.x -= 6

# Cacto
class Cacto(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)

        # Pega a sprite da spritesheet
        self.image = SPRITE_SHEEET.subsurface((5*32, 0), (32, 32))
        # Aumenta seu tamanho
        self.image = pygame.transform.scale(self.image, (32*2, 32*2))
        # Pega o retângulo da imagem
        self.rect = self.image.get_rect()

        # Insere a máscara para colisão
        self.mask = pygame.mask.from_surface(self.image)

        # Randomiza valor que obstáculo vai receber para ser inserido
        self.escolha = ESCOLHA_OBSTACULO

        # Define posição da sprite pelo centro
        self.rect.center = (LARGURA_TELA, ALTURA_TELA - 64)
        # Define para iniciar fora da tela
        self.rect.x = LARGURA_TELA
    
    def update(self):
        # Vai aparecer apenas quando a escolha for zero
        if self.escolha == 0:
            # Se ele passar da tela, reinicia
            if self.rect.topright[0] < 0:
                self.rect.x = LARGURA_TELA
            # Faz o cacto "andar"
            self.rect.x -= 10

# Dinossauro Voador
class DinoVoador(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)

        # Define o vetor de sprites
        self.imagens_dino = []

        # Pega as sprites dentro do intervalo
        for i in range (3, 5):
            # Recorta as sprites
            img = SPRITE_SHEEET.subsurface((i*32, 0), (32, 32))
            # Aumenta seu tamanho
            img = pygame.transform.scale(img, (3*32, 3*32))
            # Insere no vetor de sprites
            self.imagens_dino.append(img)
        
        # Define o indice da lista para ser incrementado para mostrar movimento
        self.indice_lista = 0
        # Define a imagem inicial
        self.image = self.imagens_dino[self.indice_lista]
        # Define máscara para colisão
        self.mask = pygame.mask.from_surface(self.image)

        # Randomiza escolha inicial para aparição
        self.escolha = ESCOLHA_OBSTACULO

        # Pega o retângulo da imagem
        self.rect = self.image.get_rect()
        # Define posição pelo centro
        self.rect.center = (LARGURA_TELA, 300)
        # Coloca inicialmente no fim da tela
        self.rect.x = LARGURA_TELA

    
    def update(self):
        # Só vai aparecer quando a escolha for 1
        if self.escolha == 1:
            # Se tiver passado da tela, reinicia
            if self.rect.topright[0] < 0:
                # Define para aparecer no final da tela
                self.rect.x = LARGURA_TELA
            # Faz o dino voar
            self.rect.x -= 10

            # Se tiver ultrapassado o numero de sprites no vetor
            if self.indice_lista > 1:
                # Reinicia animação
                self.indice_lista = 0
            # Incrementa 1/10 da animação para parecer mais suave
            self.indice_lista += 0.10
            # Define imagem atual com o novo índice calculado (converte pra int por indice precisa ser inteiro)
            self.image = self.imagens_dino[int(self.indice_lista)]

# Variável para agrupar todas as sprites do jogo
TODAS_AS_SPRITES = pygame.sprite.Group()
GRUPO_OBSTACULOS = pygame.sprite.Group()

# Instãncias
DINO = Dino()
CACTO = Cacto()
DINOVOADOR = DinoVoador()

# Para gerar 4 nuvens
for i in range(4):
    NUVEM = Nuvem()
    TODAS_AS_SPRITES.add(NUVEM)

# Para preencher com chão, largura da tela * 2 para preencher buracos (gambiarra)
for i in range(LARGURA_TELA*2//64):
    CHAO = Chao(i)
    TODAS_AS_SPRITES.add(CHAO)

# Acrescentando no grupo de sprites
TODAS_AS_SPRITES.add(DINO)
TODAS_AS_SPRITES.add(CACTO)
TODAS_AS_SPRITES.add(DINOVOADOR)

# Acrescentando ao grupo de obstáculos
GRUPO_OBSTACULOS.add(CACTO)
GRUPO_OBSTACULOS.add(DINOVOADOR)

# Loop principal
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
        if event.type == KEYDOWN:
            if event.key == K_SPACE:
                if DINO.rect.y != DINO.pos_y_inicial:
                    pass
                else:
                    DINO.pular()

    # Verifica se houve colisão entre o objeto principal (DINO) e algum objeto do grupo de obstáculo (GRUPO_OBSTACULOS),
    # 0 para indicar que o obstáculo não deve sumir na colisão e collide_mask pois é o método de colisão de pixel
    colisoes = pygame.sprite.spritecollide(DINO, GRUPO_OBSTACULOS, 0, pygame.sprite.collide_mask)

    # Desenha todas as sprites na tela e atualiza
    TODAS_AS_SPRITES.draw(TELA)

    # Se o cacto ou o dinossauro saírem da tela
    if CACTO.rect.topright[0] <= 0 or DINOVOADOR.rect.topright[0] <= 0:
        # O novo obstáculo é escolhido
        ESCOLHA_OBSTACULO = choice([0, 1])
        # Cacto e dinovolta para fora da tela
        CACTO.rect.x = LARGURA_TELA
        DINOVOADOR.rect.x = LARGURA_TELA
        # Randomiza novamente qual obstáculo surgirá
        CACTO.escolha = ESCOLHA_OBSTACULO
        DINOVOADOR.escolha = ESCOLHA_OBSTACULO

    # Se DINO colidiu com algo e não estiver houvendo outras colisões
    if colisoes and COLIDIU == False:
        # Som de colisão toca
        SOM_COLISAO.play()
        # Colidiu passa para true (assim o som não fica tocando infinitamente na colisão)
        COLIDIU = True

    # Se colidiu, o jogo trava
    if COLIDIU:
        pass
    else:
        # Caso contrário as imagens continuam atualizando
        TODAS_AS_SPRITES.update()

    # Limpa a tela
    pygame.display.flip()
    
