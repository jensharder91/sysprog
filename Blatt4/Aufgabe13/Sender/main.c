#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd, err;
	struct sockaddr_in addrDest;
	char msg[64];
	int port;

	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0)
	{
		printf("Fehler bei der Socketerstellung!\n");
		return EXIT_FAILURE;
	}

	printf(">>Gebe den Port an: \n>>");
	scanf("%d", &port);

	addrDest.sin_family = AF_INET;
	addrDest.sin_port = htons(port);
	addrDest.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf(">>Nachricht: \n>>");
//	scanf("%s", msg);
	scanf("%*c%63[^\n]", msg);
	
	err = sendto(fd, msg, strlen(msg)+1, 0, (struct sockaddr*) &addrDest, sizeof(struct sockaddr_in));
	if(err < 0)
	{
		printf("senden fehlgeschlagen\n");
		return EXIT_FAILURE;
	}


	printf("nachricht gesendet!\n");
	printf("Portnummer: %d\n", ntohs(addrDest.sin_port));

	return EXIT_SUCCESS;
}
