#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "main_memory.h"
#include "global_var.h"

#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

void *control_program(void *cpu);
int* shouffle_array(int * array);

#endif // CONTROL_H_INCLUDED
