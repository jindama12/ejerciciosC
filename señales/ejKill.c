#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int cont = 0;

void manejador (int segnal)
{
	printf("Tu puntuación es %d\n", cont);
    exit(0);
}

void main(){
	int pid_hijo,pid_padre;

	pid_padre=getpid();
	pid_hijo=fork();
	switch(pid_hijo){
		case -1:
			printf("error al crear el proceso\n");
			exit(-1);
		case 0: //hijo
            signal(SIGUSR1, manejador);
            srand (getpid());
            int n1;
            int n2;
            int respuesta;
			while(1){
				n1 = rand() % 10 + 1;
                n2 = rand() % 10 + 1;
                printf("Cuánto es %d + %d\n", n1, n2);
                scanf("%d",&respuesta);
                if (respuesta == (n1+n2)) {
                    printf("Correcto\n");
                    cont += 3;
                } else {
                    printf("Incorrecto\n");
                    cont -= 1;
                }
			};
			break;
		default: //padre
			sleep(60);
			kill(pid_hijo,SIGUSR1);
            exit(0);
	}
}