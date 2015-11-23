#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *prev;
} node;

node *top;
node *root;
node *curr;

void insertValues()
{
    curr = ( node * )malloc( sizeof( node ) );
    printf( "\nDigite o valor a ser inserido : " );
    scanf( "%u", &curr->value );
    printf( "\n" );
    curr->prev = top;
    printf( "\nV/Atual ~~ %d", curr->value );
    printf( "\nV/Topo ~~ %d", top->value );
    top = curr;
    printf( "\nV/Atual ~~ %d", curr->value );
    printf( "\nV/Topo ~~ %d", top->value );
}

void soma()
{
    printf( "Primeiro ~~ %d", top->prev->value );
    printf( "\nSegundo ~~ %d", top->value );
    top->prev->value = top->prev->value + top->value;
    printf( "\nResultado = %d", top->prev->value );
}

void subtracao()
{
    printf( "Primeiro ~~ %d", top->prev->value );
    printf( "\nSegundo ~~ %d", top->value );
    top->prev->value -= top->value;
    printf( "\nResultado = %d", top->prev->value );
}

void multiplicacao()
{
    printf( "Primeiro ~~ %d", top->prev->value );
    printf( "\nSegundo ~~ %d", top->value );
    top->prev->value = top->prev->value * top->value;
    printf( "\nResultado = %d", top->prev->value );
}

void divisao()
{
    printf( "Primeiro ~~ %d", top->prev->value );
    printf( "\nSegundo ~~ %d", top->value );
    top->prev->value = top->prev->value / top->value;
    printf( "\nResultado = %d", top->prev->value );
}

void doOperations()
{
    int option = 0;
    char flag = 'y';

    if( top == root )
        printf( "Insira mais itens para efetuar operacoes\n" );
    else
        do
        {
            printf( "\n## MENU DE OPERACOES ##\n\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao"
                "\n4 - Divisao\n5 - Encerraro operacoes\n\nDigite sua opcao : " );
            scanf( "%d", &option );
            switch( option )
            {
                case 1: soma();             break;
                case 2: subtracao();        break;
                case 3: multiplicacao();    break;
                case 4: divisao();          break;
                case 5:
                    flag = 'n';
                    printf( "O resultado e = %d", top->value );
                    break;
            }
            printf( "\n" );
            top = top->prev;
        }
        while( flag == 'y' );
}

int menu()
{
    int option = 0;
    char flag = 'y';

    do
    {
        printf( "\n--> MENU <--\n\n1 - Inserir valores\n2 - Efetuar operacoes"
            "\n3 - Finalizar o programa\n\nDigite sua opcao : " );
        scanf( "%u", &option );
        switch( option )
        {
            case 1: insertValues(); break;
            case 2: doOperations(); break;
            case 3: flag = 'n';     break;
        }
    }
    while( flag == 'y' );

    return 0;
}

int main()
{
    root = ( node * )malloc( sizeof( node ) );
    root->prev = NULL;
    top = root;
    return menu();
}
