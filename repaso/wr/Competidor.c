#include "Competidor.h"

Competidor* NuevoCompetidor(char *nombre, int minutos, int segundos) {
    Competidor* competidor;
    competidor = malloc(sizeof(Competidor));

    strcpy(competidor -> nombre, nombre);
    competidor -> minutos = minutos;
    competidor -> segundos = segundos;
}

void ImprimirCompetidor(Competidor *c) {
    printf("El competidor %s, tiene un tiempo de %02d:%02d\n", c->nombre, c->minutos, c->segundos);
}

int CompararTiempos(Competidor *c, Competidor *c1) {
    if (c->minutos > c1->minutos) {
        return 1;
    } else if (c->minutos < c1->minutos) {
        return -1;
    } else if (c->segundos > c1->segundos) {
        return 1;
    } else if (c->segundos < c1->segundos) {
        return -1;
    } else {
        return 0;
    }
}