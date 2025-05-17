class Cachorro:
    # Construtor
    def __init__(self, nome, cor, idade, tamanho):
        # Definição dos atributos
        self.nome = nome
        self.cor = cor
        self.idade = idade
        self.tamanho = tamanho
    
    # Método para latir
    def latir(self):
        print("Au Au")
    def correr(self):
        print(f"{self.nome} está correndo")

cachorro_1 = Cachorro("Faceiro", "Caramelo", 10, "Grande")

print(cachorro_1.nome)
print(cachorro_1.idade)
cachorro_1.idade = 9
print(cachorro_1.idade)
cachorro_1.latir()
cachorro_1.correr()