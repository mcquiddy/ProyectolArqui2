#include "pthread.h"
#include "main_memory.h"
#include "cpu.h"
#include <stdint.h>
#include <inttypes.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


#define MAX_INST 100

//Probalidades de las instrucciones

#define PR 0.3
#define PW 0.5
#define PP 0.2
#define ROT 0.3

#ifndef GLOBAL_VAR_H_INCLUDED
#define GLOBAL_VAR_H_INCLUDED

Bloque memory;


CPU cpu_1;
CPU cpu_2;
CPU cpu_3;
CPU cpu_4;

FILE* outputCPU1;
FILE* outputCPU2;
FILE* outputCPU3;
FILE* outputCPU4;


pthread_t memory_output;


int randomNum(int lower, int upper);


#endif 
