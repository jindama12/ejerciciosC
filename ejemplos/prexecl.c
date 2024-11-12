#include <stdio.h>
#include <unistd.h>

void main(){
	printf("Ejemplo de uso de exec():\n");
	printf("listado del directorio:");
   	execl("/bin/ls", "ls", "-l", (char *)NULL); //ejecuta este comando y no se ejecuta el resto del programa --> (char *)NULL envia los errores a la basura
	printf("\nFin del programa...\n");
}
