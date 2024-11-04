#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int cantidad = 0;

void compare(char a, char b)
{
    if (a == b)
        cantidad++;
}

void main(int argc, char *argv[]) {
    
    FILE *entrada;
    entrada = fopen(argv[1], "r");
    

    if (entrada == NULL) {
        fprintf(stderr, "ERROR DE APERTURA DE FICHERO");
        exit(-1);
    }

    char letra;

    while(fscanf(entrada, "%c", &letra) > 0) {
        char parametro = tolower(letra);
        //printf("%c", parametro);
        compare(parametro, *argv[2]);
    }

    printf("%c %d", *argv[2], cantidad);
}