#include "simulador.h"

void initSimulador(){
    
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
    } else {
       perror("getcwd() error");
       exit(1);
    }

    initSimuladorCPU1();
    initSimuladorCPU2();
    initSimuladorCPU3();
    initSimuladorCPU4();
    
}

void initSimuladorCPU1(){

    char buffer [1000];        
    snprintf(buffer, 1000, "gnome-terminal -x %s/scripts/cpu1_output_script.sh", cwd); 
    puts (buffer);              

    fclose(fopen("output/cpu1_output", "w"));    
    system(buffer);     
    
}

void initSimuladorCPU2(){

    char buffer [1000];         
    snprintf(buffer, 1000, "gnome-terminal -x %s/scripts/cpu2_output_script.sh", cwd); 
    puts (buffer);              

    fclose(fopen("output/cpu2_output", "w"));    
    system(buffer);     
    
}

void initSimuladorCPU3(){

    char buffer [1000];         
    snprintf(buffer, 1000, "gnome-terminal -x %s/scripts/cpu3_output_script.sh", cwd); 
    puts (buffer);              

    fclose(fopen("output/cpu3_output", "w"));    
    system(buffer);      
    
}

void initSimuladorCPU4(){

    char buffer [1000];        
    snprintf(buffer, 1000, "gnome-terminal -x %s/scripts/cpu4_output_script.sh", cwd); 
    puts (buffer);           

    fclose(fopen("output/cpu4_output", "w"));    
    system(buffer);    
    
}

