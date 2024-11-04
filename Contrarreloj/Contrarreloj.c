#include <stdio.h>
#include "Ciclista.h"

void main() {
    char nombreCiclista[10];
    int minutos;
    int segundos;
    
    int cantidad;
    printf("Dígame cuántos ciclistas han participado:\n");
    scanf("%d", &cantidad);

    Ciclista *ciclistas[cantidad];

    for (int i = 0; i < cantidad; i++) {
        printf("Dígame el nombre del ciclista:\n");
        scanf("%s", nombreCiclista);
        printf("Dígame el tiempo que ha hecho el ciclista:\n");
        scanf("%d:%d", &minutos, &segundos);
        if (minutos<0 || segundos<0 || segundos>60) {
            do {
                printf("Datos inválidos, introduzca de nuevos los datos\n");
                printf("Dígame el nombre del ciclista:\n");
                scanf("%s", nombreCiclista);
                printf("Dígame el tiempo que ha hecho el ciclista:\n");
                scanf("%d:%d", &minutos, &segundos);
            } while(minutos<0 || segundos<0 || segundos>60);
        }
        ciclistas[i] = NuevoCiclista(nombreCiclista, minutos, segundos);
    }

    Ciclista *temporal;

    int cambios = 1;
    while(cambios) {
        cambios = 0;
        for(int i = 0; i<cantidad-1; i++) {
            if (CompararCiclista(ciclistas[i], ciclistas[i+1]) > 0) {
                temporal = ciclistas[i];
                ciclistas[i] = ciclistas[i+1];
                ciclistas[i+1] = temporal;
                cambios++;
            }
        }
    }

    for (int i = 0; i < cantidad; i++) {
        printf("Puesto %d: ", i+1);
        ImprimirCiclista(ciclistas[i]);
    }
}