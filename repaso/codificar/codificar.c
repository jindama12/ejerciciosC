#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char *argv[]) {
    int fd[2];
    pid_t pid;
    FILE *archivo = NULL;

    pipe(fd);
    pid = fork();

    switch(pid) {
        case -1:
            printf("Error al hacer el fork\n");
            exit(-1);
        case 0:
            close(fd[0]);
            archivo = fopen(argv[1], "r");

            char matricula[8];

            if (archivo == NULL) {
                printf("Error al abrir el archivo\n");
                exit(-1);
            }

            while (fscanf(archivo, "%s", matricula) > 0) {
                write(fd[1], matricula, 8);
            }

            exit(0);
        default:
            close(fd[1]);
            char lectura[8];

            while(read(fd[0], lectura, 8) > 0) {
                for (int i = 0; i < 4; i++) {
                    if (lectura[i] >= '7') {
                        lectura[i] -= 7;
                    } else {
                        lectura[i] += 3;
                    }
                }

                printf("Matricula codificada %s\n", lectura);
            }

            exit(0);

    }
}