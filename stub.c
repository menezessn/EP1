/* Marcelo de Menezes Nascimento 13727078 */

/* O processador executa instruções a partir do endereço zero.
 * as instruções DDF e DFF não precisam ser codificadas.
 * as instruções de deslocamento preservam o sinal.
 * a instrução PAR termina o simulador. */
 
#include <stdio.h>
#include <stdlib.h>


#define MEMSIZE 100

int M[MEMSIZE];  // representa a memória do HIPO.


void loadM (char *imgFileName) {
	
	FILE *fp;
	fp= fopen(imgFileName, "r");
	int i=0;
	while (!feof(fp)) {
		printf ("\nlendo linha %d ", i);
		/* quem escrever o conteúdo da memória deve ter o cuidado de fazê-lo 
		 * conforme a especificação. Esta função não checa. */
		/* podem acontecer coisas inesperadas caso falte ou sobre \n no arquivo. 
		 * */
		fscanf (fp, "%d\n", &(M[i]));
		printf ("\nconteudo: %d ", M[i]);
		++i;
	}
	fclose(fp);

}

void dumpM () {
	int i;
	for (i=0;i<MEMSIZE;i++) {
		printf ("(%d,%d)\t", i, M[i]);
	}
}

int acumulator; //acumulador
int instructionPointer;  // apontador de instrução
int mbr; // talvez não seja necessário.
int num;

void executeInstruction(int instruction, int adress){

	switch (instruction){

	case 11:
		acumulator = M[adress];
		break;

	case 12:
		M[adress] = acumulator;
		break;
	case 21:
		acumulator = acumulator + M[adress];
		break;
	case 22:
		acumulator = M[adress] - acumulator;
		break;
	case 23:
		acumulator = acumulator * M[adress];
		break;
	case 24:
		acumulator = acumulator / M[adress];
		break;
	case 25:
		acumulator = acumulator%M[adress];
		break;
	case 31: ;
		scanf("%d", &num);
		M[adress] = num;
		//M[adress] = rand()%100;
		break;
	case 41:
		printf("%d\n", M[adress]);
		break;
	case 50:
		
		break;
	case 51:
		instructionPointer = adress;
		break;
	case 52:

		if (acumulator > 0){
			instructionPointer = adress;
		}
		
		break;
	case 53:
		
		if (acumulator >= 0){
			instructionPointer = adress;
		}

		break;
	case 54:
		if (acumulator < 0){
			instructionPointer = adress;
		}
		break;
	case 55:
		if (acumulator <= 0){
			instructionPointer = adress;
		}
		break;
	case 56:
		if (acumulator != 0){
			instructionPointer = adress;
		}
		break;
	case 57:
		if (acumulator == 0){
			instructionPointer = adress;
		}
		break;
	case 58:
		/* code */
		break;
	case 59:
		/* code */
		break;
	case 61:
		acumulator = acumulator*10;
		break;
	case 62:
		acumulator = acumulator/10;
		break;
	case 70:
		exit(0);
		break;
	
	
	default:
		break;
	}

}

int getParameters (int code, int* adress){

	int instruct = code/100;
	*adress = code%100;
	return instruct;

}

void executa () {
	puts("\nExecucao:");
	//printf("");
	int adress;
	instructionPointer = 0;
	int instruction= -1;
	
	while (instruction!=70){

		instruction = getParameters(M[instructionPointer], &adress);
		instructionPointer++;
		executeInstruction(instruction, adress);
		
	}

	
}

void main (int argc, char *argv[]) {

	puts ("Hello");
	//if (argc>1) {
		/* Um computador frequentemente tem um programa que carrega um 
		 * executável na memória. Esse programa é mais complicado que o tipo
		 * de programa que é suficiente para oferecer um entendimento básico
		 * dos conceitos que quero explorar na disciplina. Por isso, a carga de
		 * um programa na memória, neste simulador, é algo feito "por fora"
		 * da simulação.
		 * */
		//loadM("teste.hipo");

		int i;
		for (i = 0 ; i<MEMSIZE ; i++){
			M[i] = 0;
		}
		
		loadM(argv[1]);
		//printf(argv[1]);
		dumpM();
		executa();
	//}
}
