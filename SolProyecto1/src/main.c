#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "main_memory.h"
#include "global_var.h"
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "simulador.h"
#include <termios.h>

#define clear() printf("\e[3J")
#define resize() printf("\e[8;50;70t")

//https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
int mygetch ( void ) 
{
  int ch;
  struct termios oldt, newt;

  tcgetattr ( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );

  return ch;
}
void *memory_output_function(void *thread){
  
    resize();

    char states[4][11];
    strcpy(states[0], " Modified ");
    strcpy(states[1], "  Shared  ");
    strcpy(states[2], " Invalid  ");
    strcpy(states[3], "          ");

    while(1){

        printf("______________________Contenido de la Memoria ____________________\n");

        printf("__________________________________________________________________\n");
        printf("| Bloque | Contenido |  CPU 1   |  CPU 2   |  CPU 3   |  CPU 4   |\n");
        printf("|________________________________________________________________|\n");
        printf("|   0    |     %d     |%s|%s|%s|%s|\n", memory[0].contenido,
                 cpu_1->cache[0].tag == 0 ? states[cpu_1->cache[0].msi_state] : states[3],
                 cpu_2->cache[0].tag == 0 ? states[cpu_2->cache[0].msi_state] : states[3],
                 cpu_3->cache[0].tag == 0 ? states[cpu_3->cache[0].msi_state] : states[3],
                 cpu_4->cache[0].tag == 0 ? states[cpu_4->cache[0].msi_state] : states[3]);

        printf("|________________________________________________________________|\n");
        printf("|   1    |     %d     |%s|%s|%s|%s|\n", memory[1].contenido,
                 cpu_1->cache[1].tag == 0 ? states[cpu_1->cache[1].msi_state] : states[3],
                 cpu_2->cache[1].tag == 0 ? states[cpu_2->cache[1].msi_state] : states[3],
                 cpu_3->cache[1].tag == 0 ? states[cpu_3->cache[1].msi_state] : states[3],
                 cpu_4->cache[1].tag == 0 ? states[cpu_4->cache[1].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   2    |     %d     |%s|%s|%s|%s|\n", memory[2].contenido,
                 cpu_1->cache[2].tag == 0 ? states[cpu_1->cache[2].msi_state] : states[3],
                 cpu_2->cache[2].tag == 0 ? states[cpu_2->cache[2].msi_state] : states[3],
                 cpu_3->cache[2].tag == 0 ? states[cpu_3->cache[2].msi_state] : states[3],
                 cpu_4->cache[2].tag == 0 ? states[cpu_4->cache[2].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   3    |     %d     |%s|%s|%s|%s|\n", memory[3].contenido,
                 cpu_1->cache[3].tag == 0? states[cpu_1->cache[3].msi_state] : states[3],
                 cpu_2->cache[3].tag == 0 ? states[cpu_2->cache[3].msi_state] : states[3],
                 cpu_3->cache[3].tag == 0 ? states[cpu_3->cache[3].msi_state] : states[3],
                 cpu_4->cache[3].tag == 0 ? states[cpu_4->cache[3].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   4    |     %d     |%s|%s|%s|%s|\n", memory[4].contenido,
                 cpu_1->cache[4].tag == 0 ? states[cpu_1->cache[4].msi_state] : states[3],
                 cpu_2->cache[4].tag == 0 ? states[cpu_2->cache[4].msi_state] : states[3],
                 cpu_3->cache[4].tag == 0 ? states[cpu_3->cache[4].msi_state] : states[3],
                 cpu_4->cache[4].tag == 0 ? states[cpu_4->cache[4].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   5    |     %d     |%s|%s|%s|%s|\n", memory[5].contenido,
                 cpu_1->cache[5].tag == 0 ? states[cpu_1->cache[5].msi_state] : states[3],
                 cpu_2->cache[5].tag == 0 ? states[cpu_2->cache[5].msi_state] : states[3],
                 cpu_3->cache[5].tag == 0 ? states[cpu_3->cache[5].msi_state] : states[3],
                 cpu_4->cache[5].tag == 0 ? states[cpu_4->cache[5].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   6    |     %d     |%s|%s|%s|%s|\n", memory[6].contenido,
                 cpu_1->cache[6].tag == 0 ? states[cpu_1->cache[6].msi_state] : states[3],
                 cpu_2->cache[6].tag == 0 ? states[cpu_2->cache[6].msi_state] : states[3],
                 cpu_3->cache[6].tag == 0 ? states[cpu_3->cache[6].msi_state] : states[3],
                 cpu_4->cache[6].tag == 0 ? states[cpu_4->cache[6].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   7    |     %d     |%s|%s|%s|%s|\n", memory[7].contenido,
                 cpu_1->cache[7].tag == 0 ? states[cpu_1->cache[7].msi_state] : states[3],
                 cpu_2->cache[7].tag == 0 ? states[cpu_2->cache[7].msi_state] : states[3],
                 cpu_3->cache[7].tag == 0 ? states[cpu_3->cache[7].msi_state] : states[3],
                 cpu_4->cache[7].tag == 0 ? states[cpu_4->cache[7].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   8    |     %d     |%s|%s|%s|%s|\n", memory[8].contenido,
                 cpu_1->cache[0].tag == 1 ? states[cpu_1->cache[0].msi_state] : states[3],
                 cpu_2->cache[0].tag == 1 ? states[cpu_2->cache[0].msi_state] : states[3],
                 cpu_3->cache[0].tag == 1 ? states[cpu_3->cache[0].msi_state] : states[3],
                 cpu_4->cache[0].tag == 1 ? states[cpu_4->cache[0].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   9    |     %d     |%s|%s|%s|%s|\n", memory[9].contenido,
                 cpu_1->cache[1].tag == 1 ? states[cpu_1->cache[1].msi_state] : states[3],
                 cpu_2->cache[1].tag == 1 ? states[cpu_2->cache[1].msi_state] : states[3],
                 cpu_3->cache[1].tag == 1 ? states[cpu_3->cache[1].msi_state] : states[3],
                 cpu_4->cache[1].tag == 1 ? states[cpu_4->cache[1].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   10   |     %d     |%s|%s|%s|%s|\n", memory[10].contenido,
                 cpu_1->cache[2].tag == 1 ? states[cpu_1->cache[2].msi_state] : states[3],
                 cpu_2->cache[2].tag == 1 ? states[cpu_2->cache[2].msi_state] : states[3],
                 cpu_3->cache[2].tag == 1 ? states[cpu_3->cache[2].msi_state] : states[3],
                 cpu_4->cache[2].tag == 1 ? states[cpu_4->cache[2].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   11   |     %d     |%s|%s|%s|%s|\n", memory[11].contenido,
                 cpu_1->cache[3].tag == 1 ? states[cpu_1->cache[3].msi_state] : states[3],
                 cpu_2->cache[3].tag == 1 ? states[cpu_2->cache[3].msi_state] : states[3],
                 cpu_3->cache[3].tag == 1 ? states[cpu_3->cache[3].msi_state] : states[3],
                 cpu_4->cache[3].tag == 1 ? states[cpu_4->cache[3].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   12   |     %d     |%s|%s|%s|%s|\n", memory[12].contenido,
                 cpu_1->cache[4].tag == 1 ? states[cpu_1->cache[4].msi_state] : states[3],
                 cpu_2->cache[4].tag == 1 ? states[cpu_2->cache[4].msi_state] : states[3],
                 cpu_3->cache[4].tag == 1 ? states[cpu_3->cache[4].msi_state] : states[3],
                 cpu_4->cache[4].tag == 1 ? states[cpu_4->cache[4].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   13   |     %d     |%s|%s|%s|%s|\n", memory[13].contenido,
                 cpu_1->cache[5].tag == 1 ? states[cpu_1->cache[5].msi_state] : states[3],
                 cpu_2->cache[5].tag == 1 ? states[cpu_2->cache[5].msi_state] : states[3],
                 cpu_3->cache[5].tag == 1 ? states[cpu_3->cache[5].msi_state] : states[3],
                 cpu_4->cache[5].tag == 1 ? states[cpu_4->cache[5].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   14   |     %d     |%s|%s|%s|%s|\n", memory[14].contenido,
                 cpu_1->cache[6].tag == 1 ? states[cpu_1->cache[6].msi_state] : states[3],
                 cpu_2->cache[6].tag == 1 ? states[cpu_2->cache[6].msi_state] : states[3],
                 cpu_3->cache[6].tag == 1 ? states[cpu_3->cache[6].msi_state] : states[3],
                 cpu_4->cache[6].tag == 1 ? states[cpu_4->cache[6].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");
        printf("|   15   |     %d     |%s|%s|%s|%s|\n", memory[15].contenido,
                 cpu_1->cache[7].tag == 1 ? states[cpu_1->cache[7].msi_state] : states[3],
                 cpu_2->cache[7].tag == 1 ? states[cpu_2->cache[7].msi_state] : states[3],
                 cpu_3->cache[7].tag == 1 ? states[cpu_3->cache[7].msi_state] : states[3],
                 cpu_4->cache[7].tag == 1 ? states[cpu_4->cache[7].msi_state] : states[3]);
        printf("|________________________________________________________________|\n");

    
       
        sleep(1);
        clear();

    }
    
    return NULL;
}



int main()
{

    time_t t;

    printf(ANSI_COLOR_MAGENTA "Inicializando Simulador\n" ANSI_COLOR_RESET);
    initSimulador();

    printf("Presiones cualquier tecla para comenzar la ejecucion\n");
    mygetch();

    printf(ANSI_COLOR_MAGENTA "Inicializando memoria\n" ANSI_COLOR_RESET);
    initMem();

    printf(ANSI_COLOR_MAGENTA "Inicializando semilla para random\n" ANSI_COLOR_RESET);
    srand((unsigned) time(&t));

    printf(ANSI_COLOR_MAGENTA "Inicializando CPUs\n" ANSI_COLOR_RESET);
    printf("\n");
    usleep(10000);

    initCPUs();


    pthread_create(&memory_output, NULL, memory_output_function, (void *) NULL);

    pthread_join(cpu_1->instruction_control, NULL);
    pthread_join(cpu_2->instruction_control, NULL);
    pthread_join(cpu_3->instruction_control, NULL);
    pthread_join(cpu_4->instruction_control, NULL);

    pthread_join(cpu_1->coherence_control, NULL);
    pthread_join(cpu_2->coherence_control, NULL);
    pthread_join(cpu_3->coherence_control, NULL);
    pthread_join(cpu_4->coherence_control, NULL);
    
    pthread_join(memory_output, NULL);

    printf(ANSI_COLOR_RED "Liberando espacio asignado a cerrojos\n" ANSI_COLOR_RESET);
    int i = 0;
    while(i < 16){
        pthread_mutex_destroy(&memory[i].lock);
        i ++;
    }

    return 0;
}
