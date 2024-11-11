#include "Competidor.h"
#define cantidad 5

void main() {
    Competidor *competidores[cantidad];

    for (int i = 0; i < cantidad; i++) {
        char nombre[30];
        int minutos;
        int segundos;

        printf("Nombre del competidor: ");
        scanf("%s", nombre);
        printf("Tiempo en mm:ss: ");
        scanf("%d:%d", &minutos, &segundos);

        competidores[i] = NuevoCompetidor(nombre, minutos, segundos);
    }

    int cambios = 1;
    while(cambios) {
        cambios = 0;
        for (int i = 0; i < cantidad-1; i++) {
            if (CompararTiempos(competidores[i], competidores[i+1]) > 0) {
                Competidor *temporal = competidores[i];
                competidores[i] = competidores[i+1];
                competidores[i+1] = temporal;
                cambios++;
            }
        }
    }

    for (int i = 0; i < cantidad; i++) {
        ImprimirCompetidor(competidores[i]);
    }
}