#include <stdio.h>
#include <stdlib.h>


#ifndef MAIN_MEMORY_H_INCLUDED
#define MAIN_MEMORY_H_INCLUDED

typedef struct bloque
{
    int numero_bloque;
    int contenido;
    int in_use;
    int CPUs_in_use [4];         
    int msi_state;
    int tag; 
    pthread_mutex_t lock;  
} *Bloque;

void initMem();

#endif 
