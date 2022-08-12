#include "listaenc.h"
#include <stdio.h>
#include <stdlib.h>


int main (void){
	// a "cabeça" da fila...
	TFilaEncCab fila;

    // coloca a fila num estado válido (e consistente)
    criarFila( &fila );


    if( filaVazia( fila ) ) printf( "Esta vazia!" );

    enfileirar( &fila, 10 );
    enfileirar( &fila, 20 );
    enfileirar( &fila, 30 );

    int frente; elementoFrente( fila, &frente );
    printf( "\nElemento frente: %d", frente  );

    imprimir( fila );
    printf( "\nTamanho da fila: %d", tamanhoFila( fila )  );

    desenfileirar( &fila, &frente ); //10
    printf( "\n\nElemento desenfileirado: %d", frente );

    imprimir( fila );
    printf( "\nTamanho da fila: %d", tamanhoFila( fila )  );

   	desenfileirar( &fila, &frente ); //20
    printf( "\n\nElemento desenfileirado: %d", frente );
   	desenfileirar( &fila, &frente ); //30
    printf( "\n\nElemento desenfileirado: %d", frente );

    // e se quem utiliza a biblioteca comete equívocos?
    printf( "\n%s", desenfileirar( &fila, &frente ) ? "Sucesso" : "Erro na retirada!" );

    imprimir( fila );
    printf( "\nTamanho da fila: %d\n", tamanhoFila( fila )  ); 

	/* IMPLEMENTANDO AS QUESTÕES DA AVALIAÇÃO: */

	printf("\nImplementando as funções passadas na avaliação:\n");

	/* declarando o array que será clonado */
	int vetor[5] = {1, 2, 3, 4, 5};

	/* enfileriando os dados do array dentro de uma fila, passando a fila como enderço final e o vetor como fonte dos dados*/
	enfileirar_grupo(&fila, vetor);
	/* imprimindo a fila*/
	imprimir(fila);

	/* alocando a memoria */
	TFilaEncCab* clone = malloc(sizeof(TFilaEncCab));
	/* passando a fila incial como fonte dos dados que serão clonados em uma nova fila */
	clone = clonar(&fila);
	/* condicionado para caso de a a funcção clonar n tenha funcionado ou caso a fila inicial esteja vazia */
	if(clone==NULL)printf("\n a fila está vazia");
	else{
		/* imprimindo a fila clone */
		imprimir_clone(*clone);
	}


	return 0;
}