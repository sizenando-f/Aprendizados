#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORTA 12345

int main(){
    int socket_servidor, socket_cliente;
    struct sockaddr_in endereco_servidor, endereco_cliente;
    socklen_t tamanho_endereco_cliente;
    char buffer[1024] = {0};
    char *mensagem_resposta = "Mensagem recebida com sucesso!";

    // 1. Criando o socket do servidor e definindo família e porta do endereço-servidor

    // AF_INET diz que vai usar IPV4
    // SOCK_STREAM é o tipo de socket TCP
    // 0 é o protocolo padrão escolhido automaticamente
    if((socket_servidor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Define familia IPV4 no endereço do servidor
    endereco_servidor.sin_family = AF_INET;
    // Permite conexões de qualquer IP da máquina
    endereco_servidor.sin_addr.s_addr = INADDR_ANY;
    // Define a porta onde o servidor vai atuar
    // htons converte a porta para o formato correto, de rede
    endereco_servidor.sin_port = htons(PORTA);

    // 2. Vincula o socket criado no endereço do servidor configurado
    if(bind(socket_servidor, (struct sockaddr *) &endereco_servidor, sizeof(endereco_servidor)) < 0){
        perror("Erro de bind");
        exit(EXIT_FAILURE);
    }

    // 3. Coloca o socket em modo de escuta
    // 10 é o número máximo de conexões pendentes na fila
    if(listen(socket_servidor, 10) < 0){
        perror("Erro de listen");
        exit(EXIT_FAILURE);
    }
    printf("Servidor ouvindo na porta %d...\n", PORTA);

    // 4. Aceitar uma conexão cliente
    // A função é bloqueada até que um cliente consiga se conectar
    // Um socket é criado para o ciente para que haja o conexão entre o servidor e cliente
    tamanho_endereco_cliente = sizeof(endereco_cliente);
    while(1){
        if((socket_cliente = accept(socket_servidor, (struct sockaddr*) &endereco_cliente, &tamanho_endereco_cliente)) < 0){
            perror("Erro de accept");
            exit(EXIT_FAILURE);
        }
        puts("Cliente conectado!");

        // 5. Ler a mensagem do cliente
        strcpy(buffer, "");
        read(socket_cliente, buffer, 1024);
        printf("Mensagem do cliente: %s\n", buffer);

        // 6. Enviar uma resposta para o cliente
        send(socket_cliente, mensagem_resposta, strlen(mensagem_resposta), 0);
        puts("Mensagem de resposta enviada");

         // 7. Encerra os sockets
        close(socket_cliente);
    }
    

   
    close(socket_servidor);

    return 0;
}