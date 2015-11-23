#include <stdio.h>

int fatorial( int num )
{
	if( num == 1 )
		return num;
	else
		num = num * fatorial( num-1 );
	return num;
}

int main()
{
	unsigned int n = 6,
				 aux = 0;

	for( int i = 0; i < 7; i++ )
	{
        printf( "...rodando..." );
		aux = fatorial( n );
        printf( "...fatorial funfando..." );
		aux = aux / fatorial( i );
        printf( "...divisao de fatorial funfando..." );
		aux = aux * fatorial( n-i );
		printf( "%u\n", aux );
	}
    return 0;
}
