#include <stdio.h>
#include <stdlib.h>

int top;
int array[ 50 ];

void insertValues()
{
    int value;
    printf( "\nDigite o valor a ser inserido : " );
    scanf( "%u", &value );
    printf( "\n" );
    if( top == 9999 )
        top = 0;
    else
        top += 1;
    array[ top ] = value;
}

void stackDown()
{
    top -= 1;
}

void soma()
{
    array[ top-1 ] += array[ top ];
}

void subtracao()
{
    array[ top-1 ] -= array[ top ];
}

void multiplicacao()
{
    array[ top-1 ] = array[ top ] * array[ top ];
}

void divisao()
{
    array[ top-1 ] = array[ top ] / array[ top ];
}

void doOperations()
{
    int option = 0;
    char flag = 'y';

    if( top == 0 )
        printf( "Insira mais itens para efetuar operacoes\n" );
    else
        do
        {
            printf( "## MENU DE OPERACOES ##\n\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao"
                "\n4 - Divisao\n5 - Encerraro operacoes\n\nDigite sua opcao :" );
            scanf( "%u", &option );
            switch( option )
            {
                case 1: soma();             break;
                case 2: subtracao();        break;
                case 3: multiplicacao();    break;
                case 4: divisao();          break;
                case 5:
                    flag = 'n';
                    printf( "O resultado e = %u", array[ top ] );
                    printf( "\n" );
                    break;
            }
            stackDown();
        }
        while( flag == 'y' );
}

int menu()
{
    int option = 0;
    char flag = 'y';

    do
    {
        printf( "--> MENU <--\n\n1 - Inserir valores\n2 - Efetuar operacoes"
            "\n3 - Finalizar o programa\n\nDigite sua opcao : " );
        scanf( "%u", &option );
        switch( option )
        {
            case 1: insertValues(); break;
            case 2: doOperations(); break;
            case 3: flag = 'n';     break;
            system( "cls" );
        }
    }
    while( flag == 'y' );

    return 0;
}

int main()
{
    top = 9999;
    return menu();
}
