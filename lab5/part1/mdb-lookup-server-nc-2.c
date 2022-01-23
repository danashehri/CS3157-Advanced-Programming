
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

sig_atomic_t volatile running = 1;
void signalhandler(int s){
  if(s == SIGINT){
  running = 0;
  }
}

static void die(const char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char **argv){

	//to exit on ctrl-c	
	signal(SIGINT, &signalhandler);
        pid_t pid;

	while(running){
	
	printf("port number: ");
	char port[7];
	port[sizeof(port)-1]='\0';
	fgets(port, sizeof(port), stdin);
        if(port[0]=='\n'){
	continue;

	}
	pid = fork();
        if (pid < 0) {
        die("fork failed");
        } 
	else if (pid == 0) {
        // child process
        fprintf(stderr, "[pid=%d] ", (int)getpid());
        fprintf(stderr, "mdb-lookup-server started on port %s\n", port);
	execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh",
                port, (char *)0);
        die("execl failed");
        }

	// parent process
        while(waitpid((pid_t) -1, NULL, WNOHANG) > 0){
        //child process stopped
        fprintf(stderr, "[pid=%d] ", (int)pid);
        fprintf(stderr, "mdb-lookup-server terminated\n");
        }
	
	}


return 0;
}
