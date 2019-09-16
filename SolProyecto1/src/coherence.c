#include "coherence.h"
#include <time.h>

void *coherence_program(void *cpu)
{
    CPU this_cpu = (CPU) cpu;
    Bloque cache;
    int i;              
    int CPUs[4];
    while(1)
    {
        cache = this_cpu -> cache;
        i = 0;
        while(i < 16){
            int i_cash = i%8;
            int tagtmp = i >> 3;

            if(cache[i_cash].in_use == 1 && cache[i_cash].tag == tagtmp){        
                
                if(cache[i_cash].msi_state == 1 && cache[i_cash].contenido != memory[i].contenido) {          
                    cache[i_cash].msi_state = 2;   

                    if(this_cpu->id == 1){                        

                        outputCPU1 = fopen("output/cpu1_output", "a");
                        fprintf(outputCPU1,ANSI_COLOR_BLUE "Bloque %d State Shared-Invalid\n" ANSI_COLOR_RESET, i_cash);
                        fclose(outputCPU1);

                    } else if(this_cpu->id == 2){        

                        outputCPU2 = fopen("output/cpu2_output", "a");
                        fprintf(outputCPU2, ANSI_COLOR_GREEN "Bloque %d State Shared-Invalid\n" ANSI_COLOR_RESET, i_cash);
                        fclose(outputCPU2);
                    
                    } else if(this_cpu->id == 3){                

                        outputCPU3 = fopen("output/cpu3_output", "a");
                        fprintf(outputCPU3, ANSI_COLOR_YELLOW "Bloque %d State Shared-Invalid\n" ANSI_COLOR_RESET, i_cash);
                        fclose(outputCPU3);
                    
                    } else {                            

                        outputCPU4 = fopen("output/cpu4_output", "a");
                        fprintf(outputCPU4, ANSI_COLOR_MAGENTA "Bloque %d State Shared-Invalid\n" ANSI_COLOR_RESET, i_cash);
                        fclose(outputCPU4);
                    
                    }
                    // En caso de que esta en modified y el dato es diferente del cache a la memoria
                    //verficia si esta siendo usado por otro cpu, entonces cambia el estado a shared
                } else if(cache[i_cash].msi_state == 0 && cache[i_cash].contenido != memory[i].contenido) {    
                    
                    memcpy(CPUs, memory[i].CPUs_in_use, sizeof(CPUs));
                    
                    if( (CPUs[0] != 0 || CPUs[0] != this_cpu->id) ||
                        (CPUs[1] != 0 || CPUs[1] != this_cpu->id) ||
                        (CPUs[2] != 0 || CPUs[2] != this_cpu->id) ||
                        (CPUs[3] != 0 || CPUs[3] != this_cpu->id)){
                        cache[i_cash].msi_state = 1;  

                        if(this_cpu->id == 1){                        

                            outputCPU1 = fopen("output/cpu1_output", "a");
                            fprintf(outputCPU1,ANSI_COLOR_BLUE "Bloque %d State Modified-Shared\n" ANSI_COLOR_RESET, i_cash);
                            fclose(outputCPU1);

                        } else if(this_cpu->id == 2){        

                            outputCPU2 = fopen("output/cpu2_output", "a");
                            fprintf(outputCPU2, ANSI_COLOR_GREEN "Bloque %d State Modified-Shared\n" ANSI_COLOR_RESET, i_cash);
                            fclose(outputCPU2);
                        
                        } else if(this_cpu->id == 3){                

                            outputCPU3 = fopen("output/cpu3_output", "a");
                            fprintf(outputCPU3, ANSI_COLOR_YELLOW "Bloque %d State Modified-Shared\n" ANSI_COLOR_RESET, i_cash);
                            fclose(outputCPU3);
                        
                        } else {                            

                            outputCPU4 = fopen("output/cpu4_output", "a");
                            fprintf(outputCPU4, ANSI_COLOR_MAGENTA "Bloque %d State Modified-Shared\n" ANSI_COLOR_RESET, i_cash);
                            fclose(outputCPU4);
                        
                        }


                    }
                }

            }
            i ++;

            

        }
       usleep(10000);            
    }
    return NULL;
}