#include <stdio.h>

int main()
{
	unsigned int ano = 0;
	
	printf( "Digite o ano a ser verificado : " );
	scanf( "%u", &ano );
	
	if( ano % 4 == 0 )
	{
		if( ano % 100 == 0 )
		{
			if( ano % 400 == 0 )
				printf( "Esse ano é bissexto." );
			else
				printf( "Esse ano não é bissexto." );
		}
		else
			printf( "Esse ano é bissexto." );
	}
	else
		printf( "Esse ano não é bissexto." );
	return 0;
}
