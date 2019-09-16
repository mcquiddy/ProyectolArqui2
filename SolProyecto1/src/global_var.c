#include "global_var.h"

// Genera un numero aleatorio dentro de un rango
int randomNum(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

