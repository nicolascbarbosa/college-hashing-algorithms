#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

int arr[SIZE]={};
int count;
int totalCount=0;

int CalculateHash(int key)
{
    return key%SIZE;
}

void Insert(int element)
{
    if(count==SIZE){
        printf("Erro.\nA tabela esta cheia\n");
        exit(EXIT_FAILURE);
    }
    int probe=CalculateHash(element);
    while(arr[probe]!= '\0' && arr[probe]!=-1)
    {
        probe=(probe+1)%SIZE;
    }
    arr[probe]=element;
    count++;
}

int Search(int element)
{
    if(count==0){
        printf("Erro.\nA Tabela esta vazia\n");
        exit(EXIT_FAILURE);
    }
    int probe=CalculateHash(element);
    while(arr[probe]!=0)
    {
        if(arr[probe]==element){
        	return probe;
		}
        probe=(probe+1)%SIZE;
        totalCount++;
    }
    printf("\nElemento %d não encontrado.\n",element);
    return -1;
}

void PrintList()
{
    int i;
    for(i=0;i<SIZE;i++)
        printf("%d%c",arr[i],' ');
}

int main()
{
    int ch,item;
    printf("Digite os elementos a serenminseridos na tabela de hash :");
    printf("\nPara cancelar, Digite 0\n\n");
    do{
        scanf("%d",&item);
        Insert(item);
    }while(item!=0);

    PrintList();

    printf("\nDigite o elemento a ser procurado na tabela de hash :");
    printf("\nPara cancelar, Digite 0\n\n");
    do
    {
        scanf("%d",&item);
        if(item){
            int loc;
            loc=Search((item));
            if(loc!=-1)
                printf("\nElemento %d encontrado na localizacao %d",item,loc);
                printf("\nNumero de comparacoes: %d", totalCount);
        }
    }while(item);

    return 0;
}