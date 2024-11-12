#include <stdio.h>
#include <stdlib.h>

void main(){
	printf("Ejemplo de uso de system():\n");
	printf("\t listado del directorio actual y envío a un fichero:");
	printf("%d",system("ls >salida.txt")); //system crea un hijo que ejecuta ese comandos (el programa sigue)
	printf("\n\tAbrimos el fichero con gedit...");
        printf("%d",system("gedit salida.txt"));
	printf("\n\tEste comando es erróneo: %d",system("gegedit"));
        printf("\nFin del programa...\n");
}
