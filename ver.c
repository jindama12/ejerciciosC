#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/wait.h>
//#include <fcntl.h>

int main(int argc,char *argv[]){
 	
	FILE *fd;
	pid_t pid;

	//fd=fopen(argv[1],"r"); --> lo muestra solo uno
	pid = fork();
	fd=fopen(argv[1],"r"); // lo muestran ambos

	if (pid == 0) { //hijo
		if (fd == NULL){
			printf("ERROR DE APERTURA DEL FICHERO ....\n");
			exit(-1);
		}	
		printf("Contenido del fichero:\n");
		char letra;
		while(fscanf(fd,"%c",&letra)>0)
		{
			printf("%c",letra);
		}
		fclose(fd);
	} else { //padre
		//wait(NULL); --> espera a que el hijo termine
		if (fd == NULL){
			printf("ERROR DE APERTURA DEL FICHERO ....\n");
			exit(-1);
		}
		printf("Contenido del fichero:\n");
		char letra;
		while(fscanf(fd,"%c",&letra)>0)
		{
			printf("%c",letra);
		}
		fclose(fd);
	}
}