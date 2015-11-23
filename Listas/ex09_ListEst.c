#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *root;
node *curr;

void insertItem()
{
    int i, size;

    root = ( node * )malloc( sizeof( node ) );
    curr = root;
    node *aux;

    printf( "Digite a quantidade de termos que será inserida : " );
    scanf( "%u", &size );

    for( i = 0; i < size; i++ )
    {
        printf( "Digite um item a ser inserido : " );
        scanf( "%u", &curr->data );
        aux = ( node * )malloc( sizeof( node ) );
        curr->next = aux;
        curr = aux;
    }

    curr = root;

    for( i = 0; i < size; i++ )
    {
        printf( "Valor [ %u ]", curr->data );
        printf( "\n" );
        curr = curr->next;
    }
}

int main()
{
    insertItem();

    return 0;
}
