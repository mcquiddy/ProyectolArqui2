#include "main_memory.h"
#include "global_var.h"

void initMem()
{

    // Inicializacion de memoria
    memory = (Bloque) calloc(16, sizeof(struct bloque));

    memory[0].numero_bloque = 0;
    memory[1].numero_bloque = 1;
    memory[2].numero_bloque = 2;
    memory[3].numero_bloque = 3;
    memory[4].numero_bloque = 4;
    memory[5].numero_bloque = 5;
    memory[6].numero_bloque = 6;
    memory[7].numero_bloque = 7;
    memory[8].numero_bloque = 8;
    memory[9].numero_bloque = 9;
    memory[10].numero_bloque = 10;
    memory[11].numero_bloque = 11;
    memory[12].numero_bloque = 12;
    memory[13].numero_bloque = 13;
    memory[14].numero_bloque = 14;
    memory[15].numero_bloque = 15;

    memory[0].contenido = 0;
    memory[1].contenido = 0;
    memory[2].contenido = 0;
    memory[3].contenido = 0;
    memory[4].contenido = 0;
    memory[5].contenido = 0;
    memory[6].contenido = 0;
    memory[7].contenido = 0;
    memory[8].contenido = 0;
    memory[9].contenido = 0;
    memory[10].contenido = 0;
    memory[11].contenido = 0;
    memory[12].contenido = 0;
    memory[13].contenido = 0;
    memory[14].contenido = 0;
    memory[15].contenido = 0;

    pthread_mutex_init(&memory[0].lock, NULL);
    pthread_mutex_init(&memory[1].lock, NULL);
    pthread_mutex_init(&memory[2].lock, NULL);
    pthread_mutex_init(&memory[3].lock, NULL);
    pthread_mutex_init(&memory[4].lock, NULL);
    pthread_mutex_init(&memory[5].lock, NULL);
    pthread_mutex_init(&memory[6].lock, NULL);
    pthread_mutex_init(&memory[7].lock, NULL);
    pthread_mutex_init(&memory[8].lock, NULL);
    pthread_mutex_init(&memory[9].lock, NULL);
    pthread_mutex_init(&memory[10].lock, NULL);
    pthread_mutex_init(&memory[11].lock, NULL);
    pthread_mutex_init(&memory[12].lock, NULL);
    pthread_mutex_init(&memory[13].lock, NULL);
    pthread_mutex_init(&memory[14].lock, NULL);
    pthread_mutex_init(&memory[15].lock, NULL);


}