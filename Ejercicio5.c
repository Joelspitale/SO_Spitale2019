#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>



int main(){

	int pid, id_hijo; 
	

	pid = fork();

	if(pid==0){ 
	                   
		id_hijo = getpid();               
		printf("Soy el hijo y mi id es: %d\n", id_hijo );
		while(1);

	} else {
		printf("Padre\n" );				
	}
	
	return 0; 
}
