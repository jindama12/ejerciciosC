#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#define elementos 5

void main() {
    Persona *vector[elementos];

    char tunombre[10];
    int estatura;

    for (int i = 0; i<elementos; i++) {
        printf("Escribe tu nombre: ");
        scanf("%s", tunombre);
        printf("Escribe tu estatura en cm: ");
        scanf("%d", &estatura);
        vector[i]=NuevaPersona(tunombre,estatura);
    }

    //ordenar

    Persona *temp;

    int cambios = 1;
    while(cambios) {
        cambios = 0;
        for(int i = 0; i<elementos-1; i++) {
            if (CompararPersonas2(vector[i], vector[i+1]) > 0) {
                temp = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = temp;
                cambios++;
            }
        }
    }

    for (int i = 0; i<elementos; i++) {
        ImprimirPersona2(vector[i]);
    }
}