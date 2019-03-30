#include<stdio.h>
int main(){
	int pid,id_actual,id_padre;
	pid= fork();
	
	if( pid!=0){
		printf("padre\n");
		printf("id padre es PID=%d, PPID=%d\n",getpid (), getppid ());
	}
	else{
		printf("hijo\n");
		printf ("Inicio proceso hijo. PID=%d, PPID=%d\n",getpid (), getppid ());
	}
return 0;
}
