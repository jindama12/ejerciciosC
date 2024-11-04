#include <stdio.h>
#include <stdlib.h>
#define elementos 5
void main() {
    char *tunombre[elementos];
    int estatura[elementos];

    for (int i = 0; i<elementos; i++) {
        tunombre[i]=malloc(10*sizeof(char));
        printf("Escribe tu nombre: ");
        scanf("%s", tunombre[i]);
        printf("Escribe tu estatura en cm: ");
        scanf("%d", &estatura[i]);
    }

    //ordenar
    int cambios = 1;
    while(cambios) {
        //printf("Hola\n");
        cambios = 0;
        for(int i = 0; i<elementos-1; i++) {
            int res;
            char *temporal;
            if (estatura[i] > estatura[i+1]) {
                temporal = tunombre[i+1];
                tunombre[i+1] = tunombre[i];
                tunombre[i] = temporal;

                res = estatura[i+1];
                estatura[i+1] = estatura[i];
                estatura[i] = res;
                cambios++;
            }
        }
    }

    for (int i = 0; i<elementos; i++) {
        printf("Nombre: %s, mide %d cm\n", tunombre[i], estatura[i]);
        //printf("Estatura %d: %d cm\n", i , estatura[i]);
    }
}