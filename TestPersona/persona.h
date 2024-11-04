#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char nombre[10];
    int estatura;
} Persona;

Persona* NuevaPersona(char *nombre, int estatura);
void ImprimirPersona(Persona p);
void ImprimirPersona2(Persona *p);
int CompararPersonas(Persona p, Persona q);
int CompararPersonas2(Persona *p, Persona *q);