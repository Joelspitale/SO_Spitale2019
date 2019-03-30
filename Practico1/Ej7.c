#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void manejador(int signum); 
void manejador2(int signum); 

int pid_hijo; 
int main(){
	pid_hijo = fork();
	if(pid_hijo ==0)
	{
		signal(SIGINT, manejador2);	
		signal(SIGTSTP, manejador2);
		while(1);	
	}
	else
	{
		signal(SIGINT, manejador);	
		signal(SIGTSTP, manejador);
		while(1);	
	}
	return 0; 		
}
void manejador(int signum)
{
	signal(signum, manejador);
	kill(pid_hijo,signum);	
}
void manejador2(int signum)
{
	signal(signum, manejador2);
	if(signum == SIGTERM){
		printf("Proceso interrumpido\n");
		fflush(stdout);
	}
	if (signum == SIGTSTP){
		exit(0);
	}
}
