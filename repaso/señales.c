#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

static int contador = 0;

void manejador(int segnal) {
    printf("Puntuación total: %d\n", contador);
}

void main() {
    srand(getpid());
    pid_t pid, pid_hijo;

    pid = fork();

    switch(pid) {
        case -1:
            printf("Error al crear el fork\n");
            exit(-1);
        case 0:
            signal(SIGUSR1, manejador);

            int primerNumero;
            int segundoNumero;

            while(1) {
                primerNumero = rand()%21;
                segundoNumero = rand()%21;

                printf("%d + %d\n", primerNumero, segundoNumero);

                int respuesta;
                scanf("%d", &respuesta);

                if ((primerNumero+segundoNumero) == respuesta) {
                    printf("Correcto\n");
                    contador += 3;
                } else {
                    printf("Incorrecto\n");
                    contador -= 1;
                }
            }

            exit(0);
        default:
            sleep(60);
            kill(pid, SIGUSR1);
            exit(0);
    }
}