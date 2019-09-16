DIRS=build output bin
OUTPUT= ./output/cpu1_output ./output/cpu2_output ./output/cpu3_output ./output/cpu4_output

all:	\
	src/main.c \
	src/coherence.c include/coherence.h \
	src/control.c include/control.h \
	src/cpu.c include/cpu.h \
	src/global_var.c include/global_var.h \
	src/main_memory.c include/main_memory.h \
	src/Binomial_Inst.c include/Binomial_Inst.h \
	src/simulador.c include/simulador.h 

	gcc -o build/global_var.o -c src/global_var.c -I./include/
	gcc -o build/coherence.o -c src/coherence.c -I./include/ 
	gcc -o build/main.o -c src/main.c -I./include/ 
	gcc -o build/cpu.o -c src/cpu.c -I./include/
	gcc -o build/main_memory.o -c src/main_memory.c -I./include/ 
	gcc -o build/control.o -c src/control.c -I./include/
	gcc -o build/Binomial_Inst.o -c src/Binomial_Inst.c -I./include/ 
	gcc -o build/simulador.o -c src/simulador.c -I./include/ 

	gcc -o ./bin/msi_cache build/main.o build/control.o \
		build/cpu.o \
		build/global_var.o \
		build/main_memory.o \
		build/coherence.o \
		build/Binomial_Inst.o \
		build/simulador.o -pthread -lm

		
$(shell mkdir -p $(DIRS))
$(shell touch $(OUTPUT))
