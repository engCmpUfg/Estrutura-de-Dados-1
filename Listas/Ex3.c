#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificacao( int num )
{
	for( int i = 2; i < num; i++ )
		if( num % i == 0 )
			return false;
	return true;
}

// Tentar fazer funcionar por RECURSIVIDADE
bool verificar( int num, int n )
{
	printf( "%u - ", num );
	printf( "%u\n\n", n );
	if( n > 1 )
	{
		if( num % n == 0 )
			return false;
		else
			verificar( num, n-1 );
	}
	return true;
}

int main()
{
	int num = 0;
	
	printf( "Digite o numero a ser verificado : " );
	scanf( "%u", &num );
	if( verificacao( num ) )
		printf( "Esse numero e primo.\n" );
	else
		printf( "Esse numero nao e primo.\n" );
}
