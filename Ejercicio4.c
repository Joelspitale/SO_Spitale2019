#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

	int pid;
	int STATUS;

	pid = fork();

	if(pid==0){                    //hijo
		printf("Hijo\n" );
	} else {
		printf("Padre\n" );				//padre
	
		wait(&STATUS);
			printf("Estoy esperando a que mi hijo termine\n" );

			if(WIFEXITED(STATUS)){
				printf("Termine normalmente\n" );
			} else {
				exit(1);

			}
		
	}
	
	return 0; 
}