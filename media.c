#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    printf("Dígame el número\n");
    int num;

    FILE *entrada;
    entrada = fopen(argv[1], "r");

    if (entrada == NULL) {
        fprintf(stderr, "ERROR DE APERTURA DE FICHERO");
        exit(-1);
    }

    double media = 0;
    int loops = 0;

    while (fscanf(entrada, "%d", &num) > 0) {
        if (num!=0) {
            loops++;
            media += num;
        } else {
            break;
        }
    }

    if (loops > 0) {
        media /= loops;
    }

    printf("La media es: %.2f\n", media);
}