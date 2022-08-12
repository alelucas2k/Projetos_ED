#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Tlistaen aloca();

/* Criando a lista encadeada vazia com um ponteiro para o começo da lista*/
void criarlista( Tlistaen *lista){
    *lista = NULL;}

/* Função que verifica se a lista está vazia */
int voidlist( Tlistaen lista){ 
    return lista == NULL;}

/* Função que retorna o tamanho da lista */
int listsize(Tlistaen lista){
    int tamanho = 0;

    while (lista != NULL)
    {
        lista = lista -> prox;
        tamanho ++;
    }return tamanho;
}

/* Função que insere um elemento na lista mediante um valor e uma posição */
int inserir( Tlistaen* lista, int posicao, int elemento){
    Tlistaen novo = NULL, aux = NULL;
    
    int contador = 1;

    if(voidlist(*lista)){ //inserindo na lista vazia
        if(posicao != 1) return 0;

        if((novo = aloca()) == NULL) return 0;  //alocando o "nó"

        novo -> dado = elemento;
        novo -> prox = *lista;

        *lista = novo;
        return 1;
    }

    aux = *lista;

    while((contador < posicao-1)&&(aux!=NULL)){
        aux = aux -> prox;
        contador++;

    }

    if(aux == NULL)return 0;

    if((novo = aloca())==NULL)return 0;

    novo -> dado =elemento;
    novo -> prox = aux -> prox;
    aux -> prox = novo;

    return 1;
}


/* Função quepega um valor da lista mediante sua posição */
int elementoNaPosicao( Tlistaen lista, int posicao, int* dado ){
	int posicaoAtual = 1;
    
    /*  se lista está vazia ou posição inválida */
    if ( voidlist( lista ) || posicao <= 0 ||
					posicao > listsize( lista ) ) return 0;

    while ( ( lista != NULL ) && ( posicaoAtual < posicao ) ){
    	lista = lista->prox;
        posicaoAtual++;
    }
    *dado = lista->dado;
   	return 1;
}


/* Função que printa na tela todos os valores guardados dentro da lista */
void imprimir ( Tlistaen lista ) {
	printf( "\nElementos da lista: ( ");

	for( ;!voidlist( lista ); lista = lista->prox )
	    printf("%d ", lista->dado );

	printf( ")" );
}

// alocar um novo nó na memória do computador
Tlistaen aloca(){ return (no*) malloc( sizeof( no ) ); }