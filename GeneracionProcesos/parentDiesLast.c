#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main() {
    pid_t pid, id_hijo;

    for (int i = 0; i<5; i++) {
        pid = fork();

        if (pid==-1) {
            exit(-1);
        }

        if (pid==0) {
            printf("Soy el proceso hijo\n\t");
		    sleep(1);
		    printf("Mi PID es %d y el de mi padre es %d\n",getpid(),getppid());
            int espera ;
            srand (getpid());
            espera = rand() % 11;
            sleep(espera);
            printf("Ya he acabado\n");
            exit(0);
        }
    }    

    for (int i = 0; i<5; i++) {
        id_hijo=wait(NULL);
		printf("mi hijo  %d terminó\n",id_hijo);
    }

    exit(0);
}