#include "listaenc.h"
#include <stdlib.h>
#include <stdio.h>

//--------------------------------------------------------------------------

// funções auxiliares que fatoram código comum às sub-rotinas...
no* aloca();

//--------------------------------------------------------------------------


//************ Implementação do TAD Fila Encadeada c/ Cabeça. **************//


/* Criar uma fila vazia
 * Parâmetros: o nó "cabeça" da fila (a struct será passada por referência )
 */
void criarFila( TFilaEncCab * fila ){
	fila->inicio = fila->final = NULL; // condição para fila vazia
    fila->tamanho = 0;
}

/* Verificar se a fila está vazia ou não
 * Parâmetros: o nó "cabeça" da fila (agora, passado por valor)
 */
int filaVazia( TFilaEncCab fila ){ 
	return ( fila.inicio == NULL && fila.final == NULL );
}

/* Verificar a quantidade de elementos da fila
 * Parâmetros: o nó "cabeça" da fila (agora, passado por valor)
 */
int tamanhoFila( TFilaEncCab fila ){ return fila.tamanho; }

/* Consultar o elemento que está na frente da fila (sem retirá-lo)
 * Parâmetros: o nó "cabeça" da fila (agora, passado por valor)
 *			   e outro ponteiro "de retorno"
 *			   que deverá armazenar uma cópia do elem. frente retornado
 * Retorno: 0 em caso de fracasso ou 1 em caso de sucesso
 */
int elementoFrente( TFilaEncCab fila, int *valor ){
	// se fila está vazia
    if ( filaVazia( fila ) ) return 0;
    *valor = (fila.inicio)->dado;
    return 1;
}

/* Enfileirar um novo elemento no final da fila
 * Parâmetros: o nó "cabeça" da fila (a struct será passada por referência )
 *			   e o elemento desejado.
 * Retorno: 0 em caso de fracasso ou 1 em caso de sucesso
 */
int enfileirar( TFilaEncCab *fila, int elemento ){
    no* novo;
	if ( (novo = aloca()) == NULL ) return 0;

    novo->dado = elemento;
    novo->prox = NULL;

    if( filaVazia(*fila) ) fila->inicio = novo;
    else (fila->final)->prox = novo; // atualiza final para apontar p/ novo nó

    fila->final = novo;
    (fila->tamanho)++;
 	return 1;
}

/* Desenfileirar o elemento que está na frente da fila
 * Parâmetros: o nó "cabeça" da fila (a struct será passada por referência )
 *			   e outro ponteiro "de retorno" para uma variável inteira
 *			   que deverá armazenar uma cópia do elemento retirado
 * Retorno: 0 em caso de fracasso ou 1 em caso de sucesso
 */
int desenfileirar ( TFilaEncCab *fila, int *valor ){
	// se fila está vazia...
    if ( filaVazia(*fila) ) return 0;

    // jogar uma copia do elemento a ser retirado "para fora" da função
    *valor = (fila->inicio)->dado;

    // testar para ver se fila possui apenas um elemento: caso especial
    if( fila->inicio == fila->final ) fila->final = NULL;

    // guardar o nó a ser removido
    no* aux = fila->inicio;
    // atualizar o início da fila
    fila->inicio = (fila->inicio)->prox;
    // liberar a memória
    free(aux);
    // atualizar o campo tamanho da fila
    (fila->tamanho)--;
    return 1;
}

/* Exibir todos os elementos da fila
 * Parâmetros: o nó "cabeça" da fila (agora, passado por valor)
 */
void imprimir( TFilaEncCab fila ){
	printf("\nFila=[ ");
   	// varrendo todos os elementos
   	for (  ; fila.inicio != NULL; fila.inicio = (fila.inicio)->prox )
		printf( "%d, ", (fila.inicio)->dado );
   	printf("]");
}


// alocar um novo nó na memória do computador
// função usada para fatorar código comum
no* aloca( void ){ return ( (no*) malloc( sizeof(no) ) ); }


/* CODIGO DAS FUNÇÕES DA AVALIAÇÃO */


/* Função auxiliar que retorna os dados que estão guardadas no vetor */
/* recebe uma fila qualquer como parametor e retorna os itens que a compoem */
int* dadosEmVetor(TFilaEncCab fila)
{
    int* vetor = calloc(tamanhoFila(fila),sizeof(int));
    int i = 0;
    for (  ; fila.inicio != NULL; fila.inicio = (fila.inicio)->prox )
    {
        vetor[i] = (fila.inicio)->dado;
        i++;
    }
    return vetor;
}


/* Função que recebe os dados do array e os infilera em uma nova fila */
/* receb como parametro a fila que irá armazenar os dados e um array que fornecerá esses dados */
int enfileirar_grupo( TFilaEncCab* fila, int* array_numeros)
{
    for (int i = 0; i < 5; i++){enfileirar(fila, array_numeros[i]);}

    if (tamanhoFila(*fila)==5){return 0;}
    else{ return 1;}
}


/* Função que copia os itens da fila anterior para uma nova fila chamada clone */
/* Recebe como parametro a fila que possui os dados a serem clonados */
TFilaEncCab* clonar( TFilaEncCab* origem )
{	
	/* alocando a memóeria */
    TFilaEncCab* clone = malloc(sizeof(TFilaEncCab));

    if (clone == NULL)
    {
        return NULL;
    }
    

    criarFila(clone);
	/* guarda os valores da fila de orifem dentro da nova fila clone */
    enfileirar_grupo(clone,dadosEmVetor(*origem));

    return clone;
    
}


/* Funcão que imprime os valores que foram guardados dentro do clone da primeira fila  */
/* recebe a fila clone como parametro */
void imprimir_clone( TFilaEncCab fila ){
	printf("\nClone=[ ");
   	// varrendo todos os elementos
   	for (  ; fila.inicio != NULL; fila.inicio = (fila.inicio)->prox )
		printf( " %d,", (fila.inicio)->dado );
   	printf("]");
}





