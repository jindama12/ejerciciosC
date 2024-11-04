#include "persona.h"
//#define elementos 5

void main() {
    Persona *p;
    char tunombre[10];
    int estatura;
    printf("Nombre: ");
    scanf("%s", tunombre);
    printf("Estatura: ");
    scanf("%d", &estatura);

    p = NuevaPersona(tunombre, estatura);

    Persona *q;
    printf("Nombre: ");
    scanf("%s", tunombre);
    printf("Estatura: ");
    scanf("%d", &estatura);

    q = NuevaPersona(tunombre, estatura);

    //ImprimirPersona(*p);
    //ImprimirPersona2(p); //mejor así

    int comparacion = CompararPersonas(*p, *q);

    if (comparacion == 1) {
        printf("La primera persona es más alta\n");
    } else if (comparacion == 0) {
        printf("Ambas personas son igual de altas\n");
    } else {
        printf("La segunda persona es más alta\n");
    }
}