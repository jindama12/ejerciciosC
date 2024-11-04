/*
    proceso 1 --> Leer matrículas de coche 9999aaa
                  Cada matrícula la envía por un pipe a otro proceso
    
    proceso 2 --> Leer matrículas del pipe
                  Codifica matrículas: n + 3
                  Muestra por pantall
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[8];
    pid_t pid;
    FILE *ff = NULL;

    pipe(fd);
    pid=fork();

    switch(pid){
        case -1: //error
            printf("no se ha podido hacer el fork\n");
            exit(-1);
            break;
        case 0: //hijo
            close(fd[0]);
            ff = fopen("matriculas.txt", "r");

            if(fd == NULL) {
                printf("Error");
                exit(-1);
            }

            while(fscanf(ff, "%s", matricula) > 0) {
                write(fd[1], matricula, 8);
                printf("%s", matricula);
            }
        default://padre
            close(fd[1]);
            read(fd[1], codificado, 8);
            for (int i = 0; i<4; i++) {
                if ((codificado[i]+3) > 9) {
                    codificado[i]-=7;
                } else {
                    codificado[i] = codificado[i] + 3;
                }
            }
            printf("%s\n", codificado);
    }
}