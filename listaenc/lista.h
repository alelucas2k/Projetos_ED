/* criando a estrututra usada para formar a lista encadeada */
typedef struct nolist{
    int dado;      
    struct nolist *prox;
}no;

/* ponteiro que chama o no da lista  */
typedef no* Tlistaen;

/* Função que cria uma lista encadeada e vazia */
int voidlist(Tlistaen lista);

/* Função que verifica se a lista encadeada está vazia */
void criarlista(Tlistaen *lista);

/* Função que retorna o tamanho da lista encadeada */
int listsize(Tlistaen lista);

/* Função responsável por inserir os valores dentro da lista */
int inserir( Tlistaen* lista, int posicao, int elemento);

/* Função que imprime na tela os valores dentro da lista */
void imprimir ( Tlistaen lista );

/* Função que fornece o dado guardado em um determinado local da lista */
int elementoNaPosicao( Tlistaen lista, int posicao, int* dado );