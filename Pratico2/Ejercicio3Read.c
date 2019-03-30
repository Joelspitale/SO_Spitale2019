#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(void){ //argc es para saber la cantidad de palabras que recibe
	    //*argv[] es una matriz que contiene los argumento de entrada y salida
	int fd,n;
	char buf[1024];
	fd= open("/tmp/tubo",O_RDONLY);
	n = read(fd, buf, sizeof(buf));

	printf("Nr bytes rx: %d \n", n);
	printf("Mensaje: %s \n", buf);

	close(fd);
 
 return 0;
}
