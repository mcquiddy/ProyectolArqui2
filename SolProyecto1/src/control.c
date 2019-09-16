#include "control.h"
#include "Binomial_Inst.h"

int* shouffle_array(int * array){
    for(int k=MAX_INST-1;k>1;k--){
        int az = randomNum(0,k);
        int tmp = array[az];
        array[az] = array[k];
        array[k] = tmp;
    }
    return array;
}
void *control_program(void *cpu)
{   
    CPU this_cpu = (CPU) cpu;
    Bloque cache = this_cpu->cache;

    char states[3][11];
    strcpy(states[0], "Modified");
    strcpy(states[1], "Shared");
    strcpy(states[2], "Invalid");
    int* instruccion = armarInst(PP, PW, PR, MAX_INST, ROT);
    instruccion = shouffle_array(instruccion);

    
    for(int count_Inst=0;count_Inst<MAX_INST;count_Inst++)
    {
        
        int Bloque_mem = randomNum(0,15);
        int Bloque_cache = Bloque_mem%8;
        int tagtmp = Bloque_mem >> 3;

        if(instruccion[count_Inst] == 0){                 // instruccion de procesamiento              
                  

            if(this_cpu->id == 1){                        

                outputCPU1 = fopen("output/cpu1_output", "a");
                fprintf(outputCPU1, "Procesando el Bloque %d \n", Bloque_cache);
                fclose(outputCPU1);

            } else if(this_cpu->id == 2){                  

                outputCPU2 = fopen("output/cpu2_output", "a");
                fprintf(outputCPU2, "Procesando el Bloque %d \n", Bloque_cache);
                fclose(outputCPU2);
            
            } else if(this_cpu->id == 3){                 

                outputCPU3 = fopen("output/cpu3_output", "a");
                fprintf(outputCPU3, "Procesando el Bloque %d \n", Bloque_cache);
                fclose(outputCPU3);
            
            } else {                                       

                outputCPU4 = fopen("output/cpu4_output", "a");
                fprintf(outputCPU4, "Procesando el Bloque %d \n", Bloque_cache);
                fclose(outputCPU4);
            
            }

        } else if(instruccion[count_Inst] == 1){       // instruccion de escritura
            
            int state_tmp=0;
            pthread_mutex_lock(&memory[Bloque_mem].lock);                          
            memory[Bloque_mem].contenido = this_cpu -> id;                          
            memory[Bloque_mem].CPUs_in_use[(this_cpu -> id) - 1] = this_cpu->id;   
            

            pthread_mutex_lock(&cache[Bloque_cache].lock);                   
            cache[Bloque_cache].contenido = this_cpu -> id;
            state_tmp = cache[Bloque_cache].msi_state;                 
            cache[Bloque_cache].msi_state = 0;                                   
            cache[Bloque_cache].in_use = 1;
            cache[Bloque_cache].tag = tagtmp;                                     
            
            pthread_mutex_unlock(&cache[Bloque_cache].lock);                
            pthread_mutex_unlock(&memory[Bloque_mem].lock);                         


            if(this_cpu->id == 1){

                outputCPU1 = fopen("output/cpu1_output", "a");
                fprintf(outputCPU1, ANSI_COLOR_CYAN "Escritura, con tag %d \n",cache[Bloque_cache].tag );
                fprintf(outputCPU1,ANSI_COLOR_BLUE  "Bloque %d State %s-Modified\n" ANSI_COLOR_RESET, Bloque_cache,states[state_tmp]);
                fclose(outputCPU1);

            } else if(this_cpu->id == 2){
                
                outputCPU2 = fopen("output/cpu2_output", "a");
                fprintf(outputCPU2, ANSI_COLOR_CYAN "Escritura, con tag %d \n",cache[Bloque_cache].tag );
                fprintf(outputCPU2, ANSI_COLOR_GREEN "Bloque %d State %s-Modified\n" ANSI_COLOR_RESET, Bloque_cache,states[state_tmp]);
                fclose(outputCPU2);

            } else if(this_cpu->id == 3){

                outputCPU3 = fopen("output/cpu3_output", "a");
                fprintf(outputCPU3, ANSI_COLOR_CYAN "Escritura, con tag %d \n",cache[Bloque_cache].tag );
                fprintf(outputCPU3, ANSI_COLOR_YELLOW "Bloque %d State %s-Modified\n" ANSI_COLOR_RESET, Bloque_cache,states[state_tmp]);
                fclose(outputCPU3);
                
            } else {

                outputCPU4 = fopen("output/cpu4_output", "a");
                fprintf(outputCPU4, ANSI_COLOR_CYAN "Escritura, con tag %d \n",cache[Bloque_cache].tag );
                fprintf(outputCPU4, ANSI_COLOR_MAGENTA "Bloque %d State %s-Modified\n" ANSI_COLOR_RESET, Bloque_cache,states[state_tmp]);
                fclose(outputCPU4);

            }


        } else {    // instruccion es de lectura
            
            
            char mensaje[6];
            int flag_HM=0;
            int state_tmp=0;
            if(cache[Bloque_cache].msi_state == 2 || cache[Bloque_cache].contenido == 0){
               
                strcpy(mensaje, "Miss");
         

            } else if (cache[Bloque_cache].tag != tagtmp){
                strcpy(mensaje, "Miss");
            }
            else {                
                   
                strcpy(mensaje, "Hit");
                flag_HM=1;

            }
            state_tmp = cache[Bloque_cache].msi_state;  
            cache[Bloque_cache].in_use = 1;         

            if(this_cpu->id == 1){

                outputCPU1 = fopen("output/cpu1_output", "a");
                fprintf(outputCPU1, ANSI_COLOR_RED "Lectura %s, con tag %d \n", mensaje,cache[Bloque_cache].tag );
                if(flag_HM==0){
                    if(memory[Bloque_mem].contenido==0){
                        fprintf(outputCPU1, ANSI_COLOR_BLUE "Bloque %d State %s \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    
                    }
                    else{
                        pthread_mutex_lock(&memory[Bloque_mem].lock);                          
                        memory[Bloque_mem].CPUs_in_use[(this_cpu -> id) - 1] = this_cpu->id;                           

                        pthread_mutex_lock(&cache[Bloque_cache].lock);                   
                        cache[Bloque_cache].contenido = memory[Bloque_mem].contenido;           
                        cache[Bloque_cache].msi_state = 1;                                    
                        cache[Bloque_cache].tag = tagtmp;

                        pthread_mutex_unlock(&cache[Bloque_cache].lock);                
                        pthread_mutex_unlock(&memory[Bloque_mem].lock);   

                        fprintf(outputCPU1, ANSI_COLOR_BLUE "Bloque %d State %s-Shared \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    }
                    fprintf(outputCPU1, ANSI_COLOR_BLUE "Contenido desde la memoria: %d\n" ANSI_COLOR_RESET, memory[Bloque_mem].contenido); 
                }
                else{
                    fprintf(outputCPU1, ANSI_COLOR_BLUE "Bloque %d State %s \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    fprintf(outputCPU1, ANSI_COLOR_BLUE "Contenido desde la caché: %d\n" ANSI_COLOR_RESET, cache[Bloque_cache].contenido); 
                }
                fclose(outputCPU1);

            } else if(this_cpu->id == 2){

                outputCPU2 = fopen("output/cpu2_output", "a");
                fprintf(outputCPU2, ANSI_COLOR_RED "Lectura %s, con tag %d \n", mensaje,cache[Bloque_cache].tag );
                if(flag_HM==0){
                    if(memory[Bloque_mem].contenido==0){
                        fprintf(outputCPU2, ANSI_COLOR_GREEN "Bloque %d State %s \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    
                    }
                    else{
                        pthread_mutex_lock(&memory[Bloque_mem].lock);                          
                        memory[Bloque_mem].CPUs_in_use[(this_cpu -> id) - 1] = this_cpu->id;                           

                        pthread_mutex_lock(&cache[Bloque_cache].lock);                   
                        cache[Bloque_cache].contenido = memory[Bloque_mem].contenido;           
                        cache[Bloque_cache].msi_state = 1;                                    
                        cache[Bloque_cache].tag = tagtmp;

                        pthread_mutex_unlock(&cache[Bloque_cache].lock);                
                        pthread_mutex_unlock(&memory[Bloque_mem].lock);  

                        fprintf(outputCPU2, ANSI_COLOR_GREEN "Bloque %d State %s-Shared \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    }
                    fprintf(outputCPU2, ANSI_COLOR_GREEN "Contenido desde la memoria: %d\n" ANSI_COLOR_RESET, memory[Bloque_mem].contenido); 
                }
                else{
                    fprintf(outputCPU2, ANSI_COLOR_GREEN "Bloque %d State %s \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    fprintf(outputCPU2, ANSI_COLOR_GREEN "Contenido desde la caché: %d\n" ANSI_COLOR_RESET, cache[Bloque_cache].contenido); 
                }
                fclose(outputCPU2);

            } else if(this_cpu->id == 3){

                outputCPU3 = fopen("output/cpu3_output", "a");
                fprintf(outputCPU3, ANSI_COLOR_RED "Lectura %s, con tag %d \n", mensaje,cache[Bloque_cache].tag );
                if(flag_HM==0){
                    if(memory[Bloque_mem].contenido==0){
                        fprintf(outputCPU3, ANSI_COLOR_YELLOW "Bloque %d State %s \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    
                    }
                    else{
                        pthread_mutex_lock(&memory[Bloque_mem].lock);                          
                        memory[Bloque_mem].CPUs_in_use[(this_cpu -> id) - 1] = this_cpu->id;                           

                        pthread_mutex_lock(&cache[Bloque_cache].lock);                   
                        cache[Bloque_cache].contenido = memory[Bloque_mem].contenido;           
                        cache[Bloque_cache].msi_state = 1;                                    
                        cache[Bloque_cache].tag = tagtmp;

                        pthread_mutex_unlock(&cache[Bloque_cache].lock);                
                        pthread_mutex_unlock(&memory[Bloque_mem].lock);  

                        fprintf(outputCPU3, ANSI_COLOR_YELLOW "Bloque %d State %s-Shared \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    }
                    fprintf(outputCPU3, ANSI_COLOR_YELLOW "Contenido desde la memoria: %d\n" ANSI_COLOR_RESET, memory[Bloque_mem].contenido); 
                }
                else{

                    fprintf(outputCPU3, ANSI_COLOR_YELLOW "Bloque %d State %s \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    fprintf(outputCPU3, ANSI_COLOR_YELLOW "Contenido desde la caché: %d\n" ANSI_COLOR_RESET, cache[Bloque_cache].contenido); 
                }
                fclose(outputCPU3);

            } else {

                outputCPU4 = fopen("output/cpu4_output", "a");
                fprintf(outputCPU4, ANSI_COLOR_RED "Lectura %s, con tag %d \n", mensaje,cache[Bloque_cache].tag );
                if(flag_HM==0){
                    if(memory[Bloque_mem].contenido==0){
                        fprintf(outputCPU4, ANSI_COLOR_MAGENTA "Bloque %d State %s \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    
                    }
                    else{
                        pthread_mutex_lock(&memory[Bloque_mem].lock);                          
                        memory[Bloque_mem].CPUs_in_use[(this_cpu -> id) - 1] = this_cpu->id;                           

                        pthread_mutex_lock(&cache[Bloque_cache].lock);                   
                        cache[Bloque_cache].contenido = memory[Bloque_mem].contenido;           
                        cache[Bloque_cache].msi_state = 1;                                    
                        cache[Bloque_cache].tag = tagtmp;

                        pthread_mutex_unlock(&cache[Bloque_cache].lock);                
                        pthread_mutex_unlock(&memory[Bloque_mem].lock);  

                        fprintf(outputCPU4, ANSI_COLOR_MAGENTA "Bloque %d State %s-Shared \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    }                    
                    fprintf(outputCPU4, ANSI_COLOR_MAGENTA "Contenido desde la memoria: %d\n" ANSI_COLOR_RESET, memory[Bloque_mem].contenido); 
                }
                else{

                    fprintf(outputCPU4, ANSI_COLOR_MAGENTA "Bloque %d State %s \n" ANSI_COLOR_RESET, Bloque_cache, states[state_tmp]);
                    fprintf(outputCPU4, ANSI_COLOR_MAGENTA "Contenido desde la caché: %d\n" ANSI_COLOR_RESET, cache[Bloque_cache].contenido); 
                }
                fclose(outputCPU4);

            }

        }

        sleep(2);

    }

    return NULL;
}
