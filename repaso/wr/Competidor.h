#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30];
    int minutos;
    int segundos;
} Competidor;

Competidor* NuevoCompetidor(char *nombre, int minutos, int segundos);

void ImprimirCompetidor(Competidor *c);

int CompararTiempos(Competidor *c, Competidor *c1);