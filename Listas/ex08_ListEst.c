#include <stdio.h>
#include <stdlib.h>

// Define os nós da lista
typedef struct
{
       int valor, prox;
} node;

// Aloca espaço para a lista e é usado para acessá-la
node *aux;

int checkListState()
{
	int i, full = 0;

	for( i = 0; i < 10; i++ )
		if( aux[ i ].valor != 0 )
			full++;

	if( full == 10 )
		printf( "Lista cheia!" );

	return full;
}

void insertItem()
{
	int i, position, value;

	if( checkListState() < 10 )
	{
		printf( "Digite a posicao para inserir um novo item : " );
		scanf( "%u", &position );
		printf( "Digite o valor a ser inserido : " );
		scanf( "%u", &value );

		aux[ position ].valor = value;

        for( i = position-1; i > -1; i=i-1 )
            if( aux[ i ].valor != 0 )
            {
                aux[ i ].prox = position;
                break;
            }

        for( i = position+1; i < 10; i++ )
            if( aux[ i ].valor != 0 )
            {
                aux[ position ].prox = i;
                break;
            }
	}
}

void deleteItem()
{
	int i, position;

	printf( "Digite a posicao do nó a ser removido : " );
	scanf( "%u", &position );

    for( i = 0; i < position; i++ )
        if( aux[ i ].prox == position )
            break;

    if( aux[ position ].prox != 0 )
    {
        aux[ i ].prox = aux[ position ].prox;
        aux[ position ].valor = 0;
        aux[ position ].prox = 0;
    }
    else
    {
        aux[ position ].valor = 0;
        aux[ position ].prox = 0;
    }
}

void showList()
{
	int i;

	for( i = 0; i < 10; i++ )
		printf( "Valor da posicao %u : %u | Proximo : %u\n", i, aux[ i ].valor, aux[ i ].prox );
	printf( "\n" );
}

void resetList()
{
    int i;

    for( i = 0; i < 10; i++ )
    {
         aux[ i ].valor = 0;
         if( i == 9 )
            aux[ i ].prox = 42;
         else
            aux[ i ].prox = 0;
    }
}

int menu()
{
	char flag = 'y';
	int option = 0;

	do
	{
		printf( "--> Menu <--\n\n1 - Inserir item na lista\n2 - Excluir"
			" item da lista\n3 - Resetar lista\n4 - Exibir Lista\n5 - "
			"Encerrar Operações\n\nDigite sua opção : " );
		scanf( "%u", &option );
		switch( option )
		{
                case 1: insertItem(); break;
                case 2: deleteItem(); break;
                case 3: resetList();  break;
                case 4: showList();	  break;
                case 5: flag = 'n';   break;
        }
	}
	while( flag == 'y' );

	return 0;
}

int main()
{
	aux = ( node * ) malloc( 10 * sizeof( node ) );

    resetList();
    return menu();
}

