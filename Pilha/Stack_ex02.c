#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char letter;
    struct node *prev;
} node;

node *top;

void stackUp( char letter )
{
    node *item = ( node * )malloc( sizeof( node ) );
    item->letter = letter;
    if( top == NULL )
        item->prev = NULL;
    else
        item->prev = top;
    top = item;
}

void stackDown()
{
    if( top == NULL )
        printf( "Não há o que desempilhar.\n" );
    else
    {
        node *deadNode = ( node * )malloc( sizeof( node ) );
        deadNode = top;
        printf( "%c - ", top->letter );
        top = top->prev;
        free( deadNode );
    }
}

int main( void )
{
    top = NULL;
    char word[ 50 ];
    int i;

    printf( "Digite uma palavra : " );
    scanf( "%s", word );

    printf( "Empilhando..." );
    for( i = strlen( word ); i > -1; i-=1 )
        stackUp( word[ i ] );
    printf( "\nEmpilhado com sucesso!" );

    printf( "\nDesempilhando...\n# " );
    for( i = 0; i < strlen( word ); i++ )
        stackDown();
    printf( "Fim da pilha!\n" );

    return 0;
}
