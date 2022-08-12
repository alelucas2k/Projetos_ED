// Definição da estrutura do nó da fila
typedef struct nofila {
	int dado;	// campo de informação
    struct nofila *prox; // ponteiro para o próximo nó
}no;

// Definição da estrutura "cabeça" da fila
typedef struct cabeca {
	no* inicio;	  // início da fila (nó frente)
    no* final; 	  // final da fila  (ultimo nó)
    int tamanho;  // guardará o tamanho atual da fila
}TFilaEncCab;


//############# A interface de uso do TAD Fila Encadeada Cabeça ##############//


/* Criar uma fila vazia */
void criarFila(TFilaEncCab *fila );

/* Verificar se a fila está vazia ou n�o */
int filaVazia(TFilaEncCab fila );

/* Verificar a quantidade de elementos da fila */
int tamanhoFila(TFilaEncCab fila);

/* Consultar o elemento que está na frente da fila (sem retirá-lo) */
int elementoFrente(TFilaEncCab fila, int *valor );

/* Enfileirar um elemento */
int enfileirar(TFilaEncCab *fila, int elemento );

/* Desenfileirar um elemento */
int desenfileirar(TFilaEncCab *fila, int *valor );

/* Exibir todos os elementos da fila */
void imprimir(TFilaEncCab fila);


/* PROTOTIPOS DAS FUNÇÕES DA AVALICAO: */


/* Função que recebe os dados do array e os infilera em uma nova fila */
int enfileirar_grupo( TFilaEncCab* fila, int* array_numeros);

/* Função que copia os itens da fila anterior para uma nova fila chamada clone */
TFilaEncCab* clonar( TFilaEncCab* origem );

/* Função auxiliar que retorna os dados que estão guardadas no vetor */
int* dadosEmVetor(TFilaEncCab fila);

/* Funcão que imprime os valores que foram guardados dentro do clone da primeira fila  */
void imprimir_clone( TFilaEncCab fila );


