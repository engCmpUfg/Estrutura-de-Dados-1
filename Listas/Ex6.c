#include <stdio.h>

// IMPLEMENTAR RECURSÃO
int main()
{
	unsigned int num = 0,
				 fib = 1,
				 aux = 1,
				 aux1 = 1;
				 	
	printf( "Digite o numero de termos para a sequencia : " );
	scanf( "%u", &num );
	
	printf( " 1 | " );
	for( int i = 0; i < num; i++ )
	{
		printf( "%u | ", fib );
		fib = aux + aux1;
		aux = aux1;
		aux1 = fib;
	}
}
