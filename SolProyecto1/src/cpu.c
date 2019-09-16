#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"
#include "main_memory.h"
#include "control.h"
#include "coherence.h"
#include "global_var.h"

void initCPUs()
{

    cpu_1 = (CPU) calloc(1, sizeof(struct cpu));
    cpu_1 -> id = 1;
    initCPU_1();

    cpu_2 = (CPU) calloc(1, sizeof(struct cpu));
    cpu_2 -> id = 2;
    initCPU_2();

    cpu_3 = (CPU) calloc(1, sizeof(struct cpu));
    cpu_3 -> id = 3;
    initCPU_3();

    cpu_4 = (CPU) calloc(1, sizeof(struct cpu));
    cpu_4 -> id = 4;
    initCPU_4();
}

void initCPU_1()
{
    // Inicializacion de memoria
    Bloque mem_cache_cpu_1 = (Bloque) calloc(8, sizeof(struct bloque));

    mem_cache_cpu_1[0].numero_bloque = 0;
    mem_cache_cpu_1[1].numero_bloque = 1;
    mem_cache_cpu_1[2].numero_bloque = 2;
    mem_cache_cpu_1[3].numero_bloque = 3;
    mem_cache_cpu_1[4].numero_bloque = 4;
    mem_cache_cpu_1[5].numero_bloque = 5;
    mem_cache_cpu_1[6].numero_bloque = 6;
    mem_cache_cpu_1[7].numero_bloque = 7;

    mem_cache_cpu_1[0].contenido = 0;
    mem_cache_cpu_1[1].contenido = 0;
    mem_cache_cpu_1[2].contenido = 0;
    mem_cache_cpu_1[3].contenido = 0;
    mem_cache_cpu_1[4].contenido = 0;
    mem_cache_cpu_1[5].contenido = 0;
    mem_cache_cpu_1[6].contenido = 0;
    mem_cache_cpu_1[7].contenido = 0;

    mem_cache_cpu_1[0].msi_state = 2;
    mem_cache_cpu_1[1].msi_state = 2;
    mem_cache_cpu_1[2].msi_state = 2;
    mem_cache_cpu_1[3].msi_state = 2;
    mem_cache_cpu_1[4].msi_state = 2;
    mem_cache_cpu_1[5].msi_state = 2;
    mem_cache_cpu_1[6].msi_state = 2;
    mem_cache_cpu_1[7].msi_state = 2;


    mem_cache_cpu_1[0].in_use = 0;
    mem_cache_cpu_1[1].in_use = 0;
    mem_cache_cpu_1[2].in_use = 0;
    mem_cache_cpu_1[3].in_use = 0;
    mem_cache_cpu_1[4].in_use = 0;
    mem_cache_cpu_1[5].in_use = 0;
    mem_cache_cpu_1[6].in_use = 0;
    mem_cache_cpu_1[7].in_use = 0;

    mem_cache_cpu_1[0].tag = -1;
    mem_cache_cpu_1[1].tag = -1;
    mem_cache_cpu_1[2].tag = -1;
    mem_cache_cpu_1[3].tag = -1;
    mem_cache_cpu_1[4].tag = -1;
    mem_cache_cpu_1[5].tag = -1;
    mem_cache_cpu_1[6].tag = -1;
    mem_cache_cpu_1[7].tag = -1;

    pthread_mutex_init(&mem_cache_cpu_1[0].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_1[1].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_1[2].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_1[3].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_1[4].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_1[5].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_1[6].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_1[7].lock, NULL);

    cpu_1 ->cache = mem_cache_cpu_1;
    pthread_t control;
    pthread_create(&control, NULL, control_program, (void *) cpu_1);
    cpu_1 -> instruction_control = control;


    pthread_t coherence_control;
    pthread_create(&coherence_control, NULL, coherence_program, (void *) cpu_1);
    cpu_1 -> coherence_control = coherence_control;
    

}


void initCPU_2()
{
    // Inicializacion de memoria
    Bloque mem_cache_cpu_2 = (Bloque) calloc(8, sizeof(struct bloque));

    mem_cache_cpu_2[0].numero_bloque = 0;
    mem_cache_cpu_2[1].numero_bloque = 1;
    mem_cache_cpu_2[2].numero_bloque = 2;
    mem_cache_cpu_2[3].numero_bloque = 3;
    mem_cache_cpu_2[4].numero_bloque = 4;
    mem_cache_cpu_2[5].numero_bloque = 5;
    mem_cache_cpu_2[6].numero_bloque = 6;
    mem_cache_cpu_2[7].numero_bloque = 7;


    mem_cache_cpu_2[0].contenido = 0;
    mem_cache_cpu_2[1].contenido = 0;
    mem_cache_cpu_2[2].contenido = 0;
    mem_cache_cpu_2[3].contenido = 0;
    mem_cache_cpu_2[4].contenido = 0;
    mem_cache_cpu_2[5].contenido = 0;
    mem_cache_cpu_2[6].contenido = 0;
    mem_cache_cpu_2[7].contenido = 0;


    mem_cache_cpu_2[0].msi_state = 2;
    mem_cache_cpu_2[1].msi_state = 2;
    mem_cache_cpu_2[2].msi_state = 2;
    mem_cache_cpu_2[3].msi_state = 2;
    mem_cache_cpu_2[4].msi_state = 2;
    mem_cache_cpu_2[5].msi_state = 2;
    mem_cache_cpu_2[6].msi_state = 2;
    mem_cache_cpu_2[7].msi_state = 2;



    mem_cache_cpu_2[0].in_use = 0;
    mem_cache_cpu_2[1].in_use = 0;
    mem_cache_cpu_2[2].in_use = 0;
    mem_cache_cpu_2[3].in_use = 0;
    mem_cache_cpu_2[4].in_use = 0;
    mem_cache_cpu_2[5].in_use = 0;
    mem_cache_cpu_2[6].in_use = 0;
    mem_cache_cpu_2[7].in_use = 0;

    mem_cache_cpu_2[0].tag = -1;
    mem_cache_cpu_2[1].tag = -1;
    mem_cache_cpu_2[2].tag = -1;
    mem_cache_cpu_2[3].tag = -1;
    mem_cache_cpu_2[4].tag = -1;
    mem_cache_cpu_2[5].tag = -1;
    mem_cache_cpu_2[6].tag = -1;
    mem_cache_cpu_2[7].tag = -1;

    pthread_mutex_init(&mem_cache_cpu_2[0].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_2[1].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_2[2].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_2[3].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_2[4].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_2[5].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_2[6].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_2[7].lock, NULL);

    cpu_2 ->cache = mem_cache_cpu_2;
    pthread_t control;
    pthread_create(&control, NULL, control_program, (void *) cpu_2);
    cpu_2 -> instruction_control = control;


    pthread_t coherence_control;
    pthread_create(&coherence_control, NULL, coherence_program, (void *) cpu_2);
    cpu_2 -> coherence_control = coherence_control;
    

}


void initCPU_3()
{
    // Inicializacion de memoria
    Bloque mem_cache_cpu_3 = (Bloque) calloc(8, sizeof(struct bloque));

    mem_cache_cpu_3[0].numero_bloque = 0;
    mem_cache_cpu_3[1].numero_bloque = 1;
    mem_cache_cpu_3[2].numero_bloque = 2;
    mem_cache_cpu_3[3].numero_bloque = 3;
    mem_cache_cpu_3[4].numero_bloque = 4;
    mem_cache_cpu_3[5].numero_bloque = 5;
    mem_cache_cpu_3[6].numero_bloque = 6;
    mem_cache_cpu_3[7].numero_bloque = 7;

    mem_cache_cpu_3[0].contenido = 0;
    mem_cache_cpu_3[1].contenido = 0;
    mem_cache_cpu_3[2].contenido = 0;
    mem_cache_cpu_3[3].contenido = 0;
    mem_cache_cpu_3[4].contenido = 0;
    mem_cache_cpu_3[5].contenido = 0;
    mem_cache_cpu_3[6].contenido = 0;
    mem_cache_cpu_3[7].contenido = 0;

    mem_cache_cpu_3[0].msi_state = 2;
    mem_cache_cpu_3[1].msi_state = 2;
    mem_cache_cpu_3[2].msi_state = 2;
    mem_cache_cpu_3[3].msi_state = 2;
    mem_cache_cpu_3[4].msi_state = 2;
    mem_cache_cpu_3[5].msi_state = 2;
    mem_cache_cpu_3[6].msi_state = 2;
    mem_cache_cpu_3[7].msi_state = 2;

    mem_cache_cpu_3[0].in_use = 0;
    mem_cache_cpu_3[1].in_use = 0;
    mem_cache_cpu_3[2].in_use = 0;
    mem_cache_cpu_3[3].in_use = 0;
    mem_cache_cpu_3[4].in_use = 0;
    mem_cache_cpu_3[5].in_use = 0;
    mem_cache_cpu_3[6].in_use = 0;
    mem_cache_cpu_3[7].in_use = 0;

    mem_cache_cpu_3[0].tag = -1;
    mem_cache_cpu_3[1].tag = -1;
    mem_cache_cpu_3[2].tag = -1;
    mem_cache_cpu_3[3].tag = -1;
    mem_cache_cpu_3[4].tag = -1;
    mem_cache_cpu_3[5].tag = -1;
    mem_cache_cpu_3[6].tag = -1;
    mem_cache_cpu_3[7].tag = -1;

    pthread_mutex_init(&mem_cache_cpu_3[0].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_3[1].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_3[2].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_3[3].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_3[4].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_3[5].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_3[6].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_3[7].lock, NULL);

    cpu_3 ->cache = mem_cache_cpu_3;
    pthread_t control;
    pthread_create(&control, NULL, control_program, (void *) cpu_3);
    cpu_3 -> instruction_control = control;


    pthread_t coherence_control;
    pthread_create(&coherence_control, NULL, coherence_program, (void *) cpu_3);
    cpu_3 -> coherence_control = coherence_control;
    
}

void initCPU_4()
{
    // Inicializacion de memoria
    Bloque mem_cache_cpu_4 = (Bloque) calloc(8, sizeof(struct bloque));

    mem_cache_cpu_4[0].numero_bloque = 0;
    mem_cache_cpu_4[1].numero_bloque = 1;
    mem_cache_cpu_4[2].numero_bloque = 2;
    mem_cache_cpu_4[3].numero_bloque = 3;
    mem_cache_cpu_4[4].numero_bloque = 4;
    mem_cache_cpu_4[5].numero_bloque = 5;
    mem_cache_cpu_4[6].numero_bloque = 6;
    mem_cache_cpu_4[7].numero_bloque = 7;

    mem_cache_cpu_4[0].contenido = 0;
    mem_cache_cpu_4[1].contenido = 0;
    mem_cache_cpu_4[2].contenido = 0;
    mem_cache_cpu_4[3].contenido = 0;
    mem_cache_cpu_4[4].contenido = 0;
    mem_cache_cpu_4[5].contenido = 0;
    mem_cache_cpu_4[6].contenido = 0;
    mem_cache_cpu_4[7].contenido = 0;

    mem_cache_cpu_4[0].msi_state = 2;
    mem_cache_cpu_4[1].msi_state = 2;
    mem_cache_cpu_4[2].msi_state = 2;
    mem_cache_cpu_4[3].msi_state = 2;
    mem_cache_cpu_4[4].msi_state = 2;
    mem_cache_cpu_4[5].msi_state = 2;
    mem_cache_cpu_4[6].msi_state = 2;
    mem_cache_cpu_4[7].msi_state = 2;



    mem_cache_cpu_4[0].in_use = 0;
    mem_cache_cpu_4[1].in_use = 0;
    mem_cache_cpu_4[2].in_use = 0;
    mem_cache_cpu_4[3].in_use = 0;
    mem_cache_cpu_4[4].in_use = 0;
    mem_cache_cpu_4[5].in_use = 0;
    mem_cache_cpu_4[6].in_use = 0;
    mem_cache_cpu_4[7].in_use = 0;

    mem_cache_cpu_4[0].tag = -1;
    mem_cache_cpu_4[1].tag = -1;
    mem_cache_cpu_4[2].tag = -1;
    mem_cache_cpu_4[3].tag = -1;
    mem_cache_cpu_4[4].tag = -1;
    mem_cache_cpu_4[5].tag = -1;
    mem_cache_cpu_4[6].tag = -1;
    mem_cache_cpu_4[7].tag = -1;

    pthread_mutex_init(&mem_cache_cpu_4[0].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_4[1].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_4[2].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_4[3].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_4[4].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_4[5].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_4[6].lock, NULL);
    pthread_mutex_init(&mem_cache_cpu_4[7].lock, NULL);

    cpu_4 -> cache = mem_cache_cpu_4;
    pthread_t control;
    pthread_create(&control, NULL, control_program, (void *) cpu_4);
    cpu_4 -> instruction_control = control;


    pthread_t coherence_control;
    pthread_create(&coherence_control, NULL, coherence_program, (void *) cpu_4);
    cpu_4 -> coherence_control = coherence_control;
    
}


