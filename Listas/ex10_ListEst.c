#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *root;
node *curr;
node *aux;
int n = 4;

void showList()
{
	int i = 1;

	curr = root;

    printf( "-- Lista atual --\n" );
    while( curr->next != NULL )
    {
        printf( "Posicao [ %u ] | Valor - %u", i, curr->data);
        printf( "\n" );
        curr = curr->next;
        i++;
    }
}

void removeItem()
{
    int value = 0;

    aux = ( node * )malloc( sizeof( node ) );

    printf( "Digite o valor do item da lista a ser removido : " );
    scanf( "%u", &value );

    curr = root;

	while( curr->next != NULL )
	{
		if( curr->data == value && curr == root )
		{
			root = root->next;
			free( curr );
			curr = root;
		}
		if( curr->data == value-1 )
		{
			aux = curr->next;
			curr->next = aux->next;
			free( aux );
		}
		curr = curr->next;
	}
	
	showList();
}

void createList()
{
    int i;

    root = ( node * )malloc( sizeof( node ) );
    curr = root;

    for( i = 0; i < n+1; i++ )
    {
        curr->data = i+1;
        aux = ( node * )malloc( sizeof( node ) );
        curr->next = aux;
        curr = aux;
    }

    showList();
}

int main()
{
    createList();
    removeItem();

    return 0;
}
