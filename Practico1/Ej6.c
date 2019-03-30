#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void manejador(int signum); 

int main(){

	 
	signal(SIGINT, manejador);	
	signal(SIGTSTP, manejador);	
	while(1);

	return 0; 		
}

void manejador(int signum)
{
	signal(signum, manejador);
	fflush(stdout);

	if(signum == SIGINT)
	{
		printf("Proceso interrumpido\n");
	}
	
	if (signum == SIGTSTP)
	{
		exit(0);
	}
}