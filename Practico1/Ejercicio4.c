#include<stdio.h>
int main(){
	pid_t id_padre;	/* PID del proceso padre */
    pid_t id_hijo;	/* PID del proceso hijo */
    int   estado;	/* Estado de salida */

    id_padre = getpid ();
    printf ("Inicio proceso padre. PID=%d\n",id_padre);
    id_hijo=fork();

    if(id_hijo==0){
    	  
    }
    else{
    	while (waitpid (id_hijo, &estado, 0) != id_hijo);
    }
return 0;
}