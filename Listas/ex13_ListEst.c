#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *root;
node *curr;
node *aux;

int checkRamSpace()
{
    if( ( node * )malloc( sizeof( node ) ) == NULL )
        return 1;
    return 0;
}

void showList()
{
    int i = 0;
    while( curr != NULL )
    {
        printf( "Posicao [ %u ] | Valor = %u", i, curr->value );
        printf( "\n" );
        curr = curr->next;
        i++;
    }
}

void insertItemEndList()
{
    if( checkRamSpace() == 1 )
        printf( "Nao ha mais espaco para itens na lista.\n" );
    else
    {
        int i;
        aux = ( node * )malloc( sizeof( node ) );

        printf( "Digite o valor do item a ser inserido : " );
        scanf( "%u", &aux->value );
        printf( "\n" );

        while( curr->next != NULL )
            curr = curr->next;
        curr->next = aux;
        aux->next = NULL;
        curr = root;
    }
}

void insertItem()
{
    if( checkRamSpace() == 1 )
        printf( "\nNao ha mais espaco para itens na lista." );
    else
    {
        int i, position;
        aux = ( node * )malloc( sizeof( node ) );

        printf( "\nDigite o valor do item a ser inserido : " );
        scanf( "%u", &aux->value );
        printf( "\nDigite a posicao na qual quer inserir : " );
        scanf( "%u", &position );

        for( i = 0; i < position; i++ )
            curr = curr->next;
        printf( "ACHOU A POSICAO\n" );
        aux->next = curr->next;
        printf( "PEGOU O PROX\n" );
        curr->next = aux;
        printf( "ESTA SENDO APONTADO\n" );
        curr = root;
    }
}

void deleteItemValue()
{
    int val, i = 0;
    aux = ( node * )malloc( sizeof( node ) );

    printf( "Digite o valor a ser removido : " );
    scanf( "%u", &val );

    while( curr->next->value != val )
        curr = curr->next;
    aux = curr->next;
    curr->next = aux->next;
    free( aux );
    curr = root;
}

void deleteItemPosition()
{
    int pos, i;
    aux = ( node * )malloc( sizeof( node ) );

    printf( "Digite a posicao do item a ser removido : " );
    scanf( "%u", &pos );

    for( i = 0; i < pos-1; i++ )
        curr = curr->next;
    aux = curr->next;
    curr->next = aux->next;
    free( aux );
    curr = root;
}

int menu()
{
    int option;
    char flag = 'y';

    do
    {
        printf( "\n-- MENU --\n1 - INSERIR item no FIM da lista"
               "\n2 - INSERIR item em POSICAO especifica"
               "\n3 - REMOVER item por POSICAO"
               "\n4 - REMOVER item por VALOR"
               "\n5 - MOSTRAR lista"
               "\n6 - Encerrar o programa"
               "\n\nDigite a sua opcao : " );
        scanf( "%u", &option );
        switch( option )
        {
            case 1: insertItemEndList();    break;
            case 2: insertItem();           break;
            case 3: deleteItemPosition();   break;
            case 4: deleteItemValue();      break;
            case 5: showList();             break;
            case 6: flag = 'n';             break;
        }
    }
    while( flag == 'y' );

    return 0;
}

void initializer()
{
    root = ( node * )malloc( sizeof( node ) );
    root->value = 0;
    root->next = NULL;
    curr = root;
}

void firstLine()
{
    printf( "           # LISTA LINKADA ORDENADA #" );
}

int main()
{
    firstLine();
    initializer();
    return menu();
}
