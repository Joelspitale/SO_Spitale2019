#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
# define MAX 20
// argc= la cantidad de argumentos qu tiene el comando
//argc= una matriz que contiene [1] el archivo de in y [2] el archivo de out
int main(int argc,char *argv[]){	
	char infile[20], outfile[20];
	int f_in, f_out,count;
	char buff[MAX];

	strcpy( infile, argv[1]);//copia lo que hay en argv[1] a infile
	strcpy(outfile,argv[2]);//copia lo que hay en argv[1] a infile

	printf("Copiando %s a %s \n",infile,outfile );

	f_in= open(infile, O_RDONLY);//puntero a la ruta del fichero que queremos abrir(1 parametros)
								 //forma de apertura(parametro 2)
								 //Si tiene un 3 parametro es para indicar es para los permisos 	
	f_out= open(outfile, O_RDONLY | O_CREAT,S_IRUSR | S_IWUSR);

	while((count=read(f_in,buff,MAX))>0 ){
		write(f_out,buff,count);
	}
	close(f_in);
	close(f_out);
	return 0;
}
