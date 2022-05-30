#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main(int argc, char *argv[]) {
	int *a;
	int i, temp, n;
	time_t t, t1, t2;
	FILE *arq;
	n = (int)(atoi(argv[1]));
	a = (int *) malloc( n * sizeof(int) ); //alocando espa�o na mem�ria
	if(a == NULL) {
		printf("ERRO: nao ha memoria.\n");
	} else {
		arq = fopen("numeros.txt", "w"); //abrindo arquivo para escrever valores gerados
		(void) time(&t1); //registrando o tempo inicial
		srand((unsigned)time(&t)); //passando 't' para podermos gerar rand�micos
		/* Receber os valores */
		for (i=0; i<n; i++) {
			a[i] = (rand() % 500001); //gera n�meros de -250.000 a 250.000
			fprintf(arq, "%d\n", a[i]);
		}
		(void) time(&t2); //regstrando o tempo final
		printf("\n\nTempo gasto para gerar %d numeros: %d segundos\n\n", n, ((int)(t2-t1)));
		fprintf(arq, "\n"); //Imprimindo linha em branco no final do arquivo
		/* libertar a mem�ria e fechar arquivo*/
		free( a );
		fclose( arq );
	}
}
