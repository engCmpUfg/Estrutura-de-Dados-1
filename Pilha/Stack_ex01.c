#include <stdio.h>
#include <string.h>

signed int top;
char stack[ 50 ];

void empilhar( char letter, int position )
{
    printf( "# %c\n", letter );
    stack[ position ] = letter;
    top = position;
    // Como essa é uma estrutura estática não é necessário criar o link
    //  entre os itens da pilha.
}

void desempilhar()
{
    if( top == -1  )
        printf( "Não há nada na pilha para desempilhar.\n" );
    else
    {
        if( top == 0 )
        {
            printf( "# %c\n", stack[ top ] );
            top = -1;
        }
        else
        {
            printf( "# %c\n", stack[ top ] );
            top -= 1;
        }
    }
}

int main( void )
{
	char word[ 50 ];

	printf( "Digite uma palavra : " );
	scanf( "%s", word );

    int i, j;

    printf( "Empilhando...\n" );
    for( i = strlen( word )-1, j = 0; i > -1; i-=1, j++ )
        empilhar( word[ i ], j );

    printf( "Desempilhando...\n" );
    for( i = 0; i < strlen( word ); i++ )
        desempilhar();
}
