#include "lista.h"
#include <stdio.h>

int main(void){

    Tlistaen lista; // 

    criarlista(&lista); // criando uma lista vazia e verficando se ela está vazia logo em seguida

    if( voidlist(lista)) printf("Lista vazia!\n"); // está vazia?

    /* declarando variaveis de apoio que serão usadas para armazenar os dados que construirão a nossa lista */

    unsigned short int valor;   // guarda o valor que será guardado dentro da lista
    int pos1; pos1 = 1;         // declaro e dou os valores referentes as posições dentro da lista
    int pos2; pos2 = 2;
    int pos3; pos3 = 3;

    /* Aqui uso o scanf para pegar os valores que serão guardados dentro da lista e em seguido uso a funçao de inserção */
    printf("Digite um valor para a primeira posição:\n");
    scanf("%hu", &valor);
    inserir(&lista,pos1,valor);

    printf("Digite um valor para a segunda posição:\n");
    scanf("%hu", &valor);
    inserir(&lista,pos2,valor);

    printf("Digite um valor para a terceira posição:\n");
    scanf("%hu", &valor);
    inserir(&lista,pos3,valor);

    printf("\nA lista possui %d elementos na memória",listsize(lista)); /* imprime a qquantidade de elementos presentes na lista */
    imprimir(lista); /* imprime os valores que foram guardados dentro da lista */

    int val = 0; /* variavel de apoio que armazena o valor armazenado na posição 3 da lista */
    elementoNaPosicao(lista, 3, &val);
    printf("\nO elemento que ocupa a terceira posição da sua lista é: %d\n", val);
    

    return 0;

}