#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 1000
#define VECTOR_SIZE 20000

struct node
{
    int data;
    struct node *next;
};

struct node *head[TABLE_SIZE] = {NULL}, *c;

void Insert(int num)
{
    int i = num % TABLE_SIZE;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head[i] == NULL)
        head[i] = newnode;
    else
    {
        c = head[i];
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = newnode;
    }
}

void Search()
{
    int key, index, totalCount = 0;
    printf("\nDigite o numero que voce deseja procurar \n");
    scanf("%d", &key);
    index = key % TABLE_SIZE;
    if (head[index] == NULL)
        printf("\n Numero %d não encontrado\n", key);
    else
    {
        for (c = head[index]; c != NULL; c = c->next)
        {
            if (c->data == key)
            {
                printf("Numero %d encontrado\n", key);
                printf("Numero de comparacoes: %d", totalCount);
                break;
            }
            totalCount++;
        }
        if (c == NULL)
            printf("\n Numero %d não encontrado\n", key);
    }
}

void Display()
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("\nDados contidos na tabela no indicie %d\n", i);
        if (head[i] == NULL)
        {
            printf("A tabela não possui entradas");
            return;
        }
        else
        {
            for (c = head[i]; c != NULL; c = c->next)
                printf("%d->", c->data);
        }
    }
}

int main()
{
    int opt, key, i;
    int *vector;
    while (1)
    {
        printf("\nDigite:\n1. Para rodar o comando de inserir 20k de numeros aleatorios automaticamente\n2. Mostrar dados da tabela \n3. Procurar \n4.Sair \n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            for (i = 0; i < VECTOR_SIZE; i++)
                Insert(rand() % VECTOR_SIZE);
            break;
        case 2:
            Display();
            break;
        case 3:
            Search();
            break;
        default:
            exit(0);
        }
    }
}