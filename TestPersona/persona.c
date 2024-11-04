#include "persona.h"

Persona* NuevaPersona(char *nombre, int estatura) {
    Persona *nueva;
    nueva = malloc(sizeof(Persona));

    strcpy(nueva->nombre, nombre);
    //nueva -> nombre = nombre;
    nueva -> estatura = estatura;
}

void ImprimirPersona(Persona p) {
    printf("%s mide %d cm\n", p.nombre, p.estatura);
}

void ImprimirPersona2(Persona *p) {
    printf("%s mide %d cm\n", p -> nombre, p -> estatura);
}

int CompararPersonas(Persona p, Persona q) {
    if (p.estatura > q.estatura) {
        return 1;
    } else if (p.estatura == q.estatura){
        return 0;
    } else {
        return -1;
    }
}

int CompararPersonas2(Persona *p, Persona *q) {
    if (p -> estatura > q -> estatura) {
        return 1;
    } else if (p -> estatura == q -> estatura){
        return 0;
    } else {
        return -1;
    }
}