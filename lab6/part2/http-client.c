#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

static void die(const char *s) { perror(s); exit(1); }

int main(int argc, char **argv)
{
    if (argc != 4) {
        fprintf(stderr, "usage: %s <host> <server-port> <file-path>\n",
                argv[0]);
        exit(1);
    }

    struct hostent *he;
    char *serverName = argv[1];
    
	if ((he = gethostbyname(serverName)) == NULL) {
	    die("gethostbyname failed");
	}
    char *ip = inet_ntoa(*(struct in_addr *)he->h_addr);

    unsigned short port = atoi(argv[2]);

    // Create a socket for TCP connection

    int sock; // socket descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket failed");

    // Construct a server address structure

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr)); // must zero out the structure
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port        = htons(port); // must be in network byte order

    // Establish a TCP connection to the server

    if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        die("connect failed");


    char *host = argv[1];
    char *file = argv[3];
    const char *GET = "GET %s HTTP/1.0\r\nHost: %s:%u\r\n\r\n";
    char request[4096];
    // Send the GET request to web server

    snprintf(request, sizeof(request), GET, file, host, port);
    if (send(sock, request, strlen(request), 0) != strlen(request))
        die("send size failed");

   //loop to recieve web server response
   
   FILE *input = fdopen(sock, "r");
   char response[4096];
   

   char *filename = strrchr(argv[3], '/');
   FILE *fp = fopen(filename+1, "w");

   char buf[4096];
   unsigned int n;
   unsigned int OK = 0;
   
   // check if status = 200, break if not
   fgets(response,200, input);
   char *firstline = strstr(response,"HTTP/1.1 200 OK");
   if(firstline){OK++;}
   //if status is not = 200 print the first line
   if(!firstline){
   printf("%s", response);
   }


   while(fgets(response, sizeof(response), input)!=NULL && OK){
   
   //check if fgets passed the header files after the blank line
   char f[]="\r\n";
   if(*response==*f){ 
	   //download content from web server
        while ((n = fread(buf, 1, sizeof(buf), input)) > 0) {
              fwrite(buf, 1, n, fp);
        } 
	break; 
   }
   } 


    fclose(fp);
    fclose(input);
    close(sock);
  


}
