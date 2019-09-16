#include <pthread.h>
#include "main_memory.h"


#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED


typedef struct cpu
{
    int id;             
    Bloque cache;
    pthread_t instruction_control;
    pthread_t coherence_control;
} *CPU;

void initCPUs();
void initCPU_1();
void initCPU_2();
void initCPU_3();
void initCPU_4();

#endif 
