#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(void){ //argc es para saber la cantidad de palabras que recibe
	    //*argv[] es una matriz que contiene los argumento de entrada y salida
	int fd;
	char buf[] = "Estoy escribiendo";
				     //el primer parametro es donde le indico en donde esta el pipe
	mkfifo("/tmp/tubo", 0666); //el 666 es para que pueda ser escrito y leido para el usuario,el grupo,otros
	fd= open("/tmp/tubo",O_WRONLY);
	write(fd, buf, sizeof(buf));//estoy escribiendo en el pipe(1 parametro es para indicarle en donde comenzar a escribir)
				    //(2 parametro s para indicarle que voy a escribir)
				    //(3 parametro es para que sepa el tamanio de lo que voy a escribir)
	close(fd);
 
 return 0;
}
