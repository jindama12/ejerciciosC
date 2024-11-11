#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    int numeroAleatorio;
    srand(getpid());
    numeroAleatorio = rand() % 10 + 1;

    int respuesta;
    printf("Dígame el número: ");
    scanf("%d", &respuesta);

    while(respuesta != numeroAleatorio)  {
        printf("Erróneo, dígame otro número: ");
        scanf("%d", &respuesta);
    }

    printf("Correcto, el número era %d\n", numeroAleatorio);
}