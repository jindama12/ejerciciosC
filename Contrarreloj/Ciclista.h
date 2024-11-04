#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char nombre[10];
    int minutos;
    int segundos;
} Ciclista;

Ciclista* NuevoCiclista(char *nombre, int minutos, int segundos);

void ImprimirCiclista(Ciclista *p);
int CompararCiclista(Ciclista *p, Ciclista *q);