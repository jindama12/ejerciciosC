#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void manejador (int segnal)
{
	printf("Se ha recibido la señal %d\n",segnal);
}

int main(){
    signal(SIGUSR1,manejador);
    printf("Esperando señal, soy el proceso %d\n", getpid());
	while(1){
        pause();
    };
}