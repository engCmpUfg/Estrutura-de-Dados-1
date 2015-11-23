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
	unsigned int num = 0;
	
	printf( "Digite um numero : " );
	scanf( "%u", &num );
	printf( "O fatorial desse numero é : %u", fatorial( num ) );
}
