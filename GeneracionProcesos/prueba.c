#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main() {
    pid_t pid, id_hijo;

    pid = fork();

    if (pid==-1) //error, no se ha creado el proceso hijo
	{
		printf("No se ha podido crear el proceso hijo...\n");
		exit(-1);
	}

    if (pid==0) // proceso hijo
	{
		printf("Soy el proceso hijo\n\t");
		sleep(1);
		printf("Mi PID es %d y el de mi padre es %d\n",getpid(),getppid());
		sleep(10);
		printf("Hasta que la grieta del invocador nos separe\n");
	} else // proceso padre 
	{
		printf("Soy el proceso padre\n\t");
		printf("mi PID es %d, el de mi padre es %d\n",getpid(),getppid());
		id_hijo=wait(NULL);
		printf("mi hijo  %d terminó\n",id_hijo);
	}

    exit(0);
}