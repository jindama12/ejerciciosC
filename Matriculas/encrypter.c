#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buffer[8];
    pid_t pid;
    FILE *archivo = NULL;

    pipe(fd);
    pid = fork();

    switch(pid) {
        case -1:
            printf("No se ha podido crear el fork\n");
            exit(-1);
        
        case 0:
            char matricula[8];
            close(fd[0]);
            
            archivo = fopen("matriculas.txt", "r");
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
            while (read(fd[0], buffer, 8) > 0) {
                printf("Sin codificar: %s\n", buffer);
                for (int i = 0; i<4; i++) {
                    if (buffer[i] >= 55) {
                        buffer[i] -= 7;
                    } else {
                        buffer[i] += 3;
                    }
                }

                printf("Codificada: %s\n", buffer);
            }

            exit(0);
    }
}