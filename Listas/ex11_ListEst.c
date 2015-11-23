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
    int position = 0, i = 0;

    aux = ( node * )malloc( sizeof( node ) );
    node *temp = ( node * )malloc( sizeof( node ) );
    temp->data = 0;
    temp->next = 0;

    printf( "Digite a posicao do item da lista a ser removido : " );
    scanf( "%u", &position );

    curr = root;

	while( curr != NULL )
	{
		if( position-1 == i )
		{
			aux = temp->next;
			temp->next = aux->next;
			free( aux );
			break;
		}
		temp = curr;
		curr = curr->next;
		i++;
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

