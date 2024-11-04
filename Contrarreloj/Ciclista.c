#include "Ciclista.h"

Ciclista* NuevoCiclista(char *nombre, int minutos, int segundos) {
    Ciclista *ciclista;
    ciclista = malloc(sizeof(Ciclista));

    strcpy(ciclista->nombre, nombre);
    ciclista -> minutos = minutos;
    ciclista -> segundos = segundos;
}

void ImprimirCiclista(Ciclista *p) {
    printf("Ciclista: %s, Tiempo: %d:%d\n", p -> nombre, p -> minutos, p -> segundos);
}

int CompararCiclista(Ciclista *p, Ciclista *q) {
    if (p -> minutos > q -> minutos) {
        return 1;
    } else if (p -> minutos < q -> minutos){
        return -1;
    } else if (p -> segundos > q -> segundos){
        return 1;
    } else if (p -> segundos < q -> segundos) {
        return -1;
    } else {
        return 0;
    }
}