#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int mainSocket = socket(AF_INET,SOCK_STREAM,0);	
	int err;
	int port;
	char ipAdress[16];
	struct sockaddr_in addrSock;


	if(mainSocket < 0)
	{
		printf("ERROR bei socket(..)"); 
		return EXIT_FAILURE;
	}


	printf(">>Gebe den Host an: \n>>");
	scanf("%s", ipAdress);
	printf(">>Gebe den Port an: \n>>");
	scanf("%d", &port);

	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(port);
	addrSock.sin_addr.s_addr = inet_addr(ipAdress);

	err = connect(mainSocket, (struct sockaddr *) &addrSock, sizeof(struct sockaddr_in));
	if(err < 0)
	{
		printf("ERROR, bei connect(..)");
	}

	printf("SUCCESSful connected");

	int opt = -1;
	int betrag = 0;
	char strSend[19];
	char strOption;
	int* kontoStand;
	while(1)
	{
		/**
			LESE den kontostand
		*/
		
		size_t readSize = sizeof(kontoStand);
		ssize_t errSizeRead = read(mainSocket, kontoStand, readSize);
		if(errSizeRead < 0)
		{
			printf("ERROR, in write(..)");
		}
		printf("Der Kontostand beträgt: %d\n", *kontoStand);

		/** 
			nutzerEINGABE und SENDEN
		*/
		printf("Wähle aus folgenden Optionen aus:\n1 = Kontogutschrift\n2 = Kontoausgabe\n");
		scanf("%d", &opt);

		if(opt == 1)
		{
			strOption = '+';
		}
		else if(opt == 2)
		{
			strOption = '-';
		}
		else
		{
			printf("Keine gültige Option ausgewählt!\n");
			continue;
		}

		printf("Gebe einen Betrag ein, der mit dem Konto verrechnet werden soll:\n");
		scanf("%d", &betrag);
		
		
		sprintf(strSend, "%c%d", strOption, betrag);

		size_t sendSize = sizeof(strSend);
		ssize_t errSizeWrite = write(mainSocket, strSend, sendSize);
		if(errSizeWrite < 0)
		{
			printf("ERROR, in write(..)");
		}
	}


	err = close(mainSocket);
	if(err < 0)
	{
		printf("ERROR, mainSocket kann nicht geschlossen werden");
	}


}
