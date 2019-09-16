#include <time.h>
#include <stdlib.h>
#include <stdio.h>


#define PROC 0
#define WRITE 1
#define READ 2



/**
	function to obtein the factorial of a number.
*/
double fact(double a){
	double tt=1;
	for(; a!=0; a--){
		tt*=a;
	}
	return tt;
}

/**
	function to obtein the power of a number.
*/
double powE(double a, double b){
	double resp=1;
	if(b==0){
		return 1;
	}
	for(int i=0; i<b; i++){
		resp*=a;
	}
	return resp;
}

/**
	function to obtein the bionomical probability, 
	given the next number, p(know probablity), x 
	( better known as the K), and the n, to know
	how much data is in the propsition.
*/
double genProb(double p, double x, double n){
	if(p>1 || p<0){
		return -1;//error
	}
	if(n<1){
		return -1;//error
	}
	if(x<0 || x>n){
		return -1; //error	
	}
	double rest=0;
	double comb=fact(n)/(fact(x)*fact(n-x)); //(n x) = n!/x!*(n-x)!
	double expPX=powE(p,x);//p^x
	double expPNX=powE(1-p,n-x);//(1-p)^(n-x)
	return (comb*expPX*expPNX); //(i=0)(x)E [ (n x)(p^x)((1-p)^(n-x)) ]
}

/**
	method to build all the instruction set that is
	going to be read and process by the cpu.
*/
int* armarInst(double p, double w, double r, double max_inst, double rot){
	int * inst=(int*) calloc(max_inst,sizeof(int));
	double ttP=0, ttW=0, ttR=0;
	double x=(double)(max_inst*rot);

	for(int i=0;x<max_inst;i++,max_inst--){
		//prob for process
		ttP=genProb(p,x,max_inst); // obtiene la probalidad de las instrucciones de procesos
		ttW=genProb(w,x,max_inst); // obtiene la probalidad de las instrucciones de escritura/write
		ttR=genProb(r,x,max_inst); // obtiene la probalidad de las instrucciones de lectura/read
		if(ttP>ttW && ttP>ttR){
			inst[i]=PROC;
		}
		else if(ttW>ttP && ttW>ttR){
			inst[i]=WRITE;
		}
		else if(ttR>ttP && ttR>ttW){
			inst[i]=READ;
		}
	}
	return inst;
}






