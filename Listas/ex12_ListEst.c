#include <stdio.h>
#include <stdlib.h>

// Define os NOS da lista
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
    printf( "TENTATIVA DE CRIACAO DE NO\n" );
    if( ( node * )malloc( sizeof( node ) ) == NULL )
        return 1;
    return 0;
}

void showList()
{
    int i = 0;

    while( curr != NULL )
    {
        printf( "POS : %u | VAL : %u", i, curr->value );
        printf( "\n" );
        curr = curr->next;
        i++;
    }
    curr = root;
}

void insertItemEndList()
{
    if( checkRamSpace() == 1 )
        printf( "Nao ha espaco para novos NOS!" );
    else
    {
        int val;

        while( curr->next != NULL )
            curr = curr->next;

        aux = ( node * )malloc( sizeof( node ) );
        curr->next = aux;

        printf( "Digite o valor a ser inserido no ultimo NO : " );
        scanf( "%u", &val );
        aux->value = val;
        aux->next = NULL;
        curr = root;
    }
}

void deleteItem()
{
}


int menu()
{
	char flag = 'y';
	int option = 0;

	do
	{
		printf( " ---- MENU ----\n\n1 - Inserir NO no final da Lista"
			"\n2 - Inserir NO em posicao especifica da Lista"
			"\n3 - Remover um NO no final da Lista"
			"\n4 - Remover NO de uma posicao especifica da Lista"
			"\n5 - Remover no com valor especifico"
			"\n6 - Mostrar Lista"
			"\n7 - Encerrar Operacoes\n\nDigite sua opcao : " );
		scanf( "%u", &option );
		switch( option )
		{
            case 1: insertItemEndList(); break;
            case 6: showList(); break;
            case 7: flag = 'n'; break;
        }
	}
	while( flag == 'y' );

	return 0;
}

int main()
{
    node *temp = ( node * )malloc( sizeof( node ) );

    root = ( node * )malloc( sizeof( node ) );
    root->value = 0;
    root->next = temp;
    temp->value = 1;
    temp->next = NULL;
    curr = root;

    return menu();
}


