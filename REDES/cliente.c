#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORTA 12345

int main(){
    int socket_cliente = 0;
    struct sockaddr_in endereco_servidor;
    char mensagem[50];
    char buffer[1024] = {0};

    // 1. Cria socket do cliente
    if((socket_cliente = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Erro ao criar socket");
        return -1;
    }

    // Define informações do servidor
    endereco_servidor.sin_family = AF_INET;
    endereco_servidor.sin_port = htons(PORTA);

    // Converte o endereço IP de string binário
    // 127.0.0.1 é o endereço da própria máquina
    if(inet_pton(AF_INET, "127.0.0.1", &endereco_servidor.sin_addr) <= 0){
        perror("Endereço inválido ou não suportado");
        return -1;
    }

    if(connect(socket_cliente, (struct sockaddr *) &endereco_servidor, sizeof(endereco_servidor)) < 0){
        perror("Erro de conexão");
        return -1;;
    }
    puts("Conectado ao servidor!");

    while(1){
        strcpy(mensagem, "");
        // 2. Conectar ao servidor
        
        // 3. Enviar mensagem para o servidor
        fgets(mensagem, sizeof(mensagem), stdin);
        send(socket_cliente, mensagem, strlen(mensagem), 0);
        printf("Mensagem enviada: %s\n", mensagem);

        // 4. Ler resposta do servidor
        read(socket_cliente, buffer, 1024);
        printf("Resposta do servidor: %s\n", buffer);
    }

    // 5. Encerra o socket
    close(socket_cliente);

    return 0;
}