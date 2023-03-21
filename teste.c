# include <stdlib.h>
#include <stdio.h>

void loadM (char *imgFileName) {
	FILE *fp;
    int line;
	fp=fopen (imgFileName, "r");
	int i=0;
	while (!feof(fp)) {
		printf ("lendo linha %d\n", i);
		/* quem escrever o conteúdo da memória deve ter o cuidado de fazê-lo 
		 * conforme a especificação. Esta função não checa. */
		/* podem acontecer coisas inesperadas caso falte ou sobre \n no arquivo. 
		 * */
		fscanf (fp, "%d\n", &(line));
		printf ("conteudo: %d\n ", line);
		++i;
	}
	fclose(fp);
}


void main( char arcv, char *argv[]){

    puts("Hello World");
    printf("%s", argv[1]);
    loadM(argv[1]);


}