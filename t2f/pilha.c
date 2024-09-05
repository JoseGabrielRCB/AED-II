#include <stdlib.h>
#include <stdio.h>

typedef struct Pilha
{
    int num;
    struct Pilha *prox;
} PilhaStrc;

int isEmpty(PilhaStrc **pilha)
{
    if ((*pilha) == NULL)
        return 0;
    return 1;
}

void printPilha(PilhaStrc **pilha)
{
    PilhaStrc *aux = (*pilha);
    if (isEmpty(&aux))
    {
        printf("[%d]\n", aux->num);
        return;
    }
    printf("Sem pilha\n");
}

void ImprimeTudo(PilhaStrc **pilha)
{
    PilhaStrc *aux = (*pilha);
    while (aux->prox != NULL)
    {
        printf("\n[%d]", aux->num);
        aux = aux->prox;
    }
    printf("\n");
}
void InserePilha(PilhaStrc **pilha)
{
    int num = 0;
    PilhaStrc *NewPilha = malloc(sizeof(PilhaStrc));
    if (NewPilha == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Qual o valor a ser inserido?\n");
    scanf("%d", &num);
    NewPilha->num = num;
    NewPilha->prox = *pilha; // Point to the current top of the stack
    *pilha = NewPilha;       // Update the top of the stack to the new node
}

void RemovePilha(PilhaStrc **pilha)
{
    PilhaStrc *aux = (*pilha);
    if (isEmpty(pilha))
    {
        (*pilha) = (*pilha)->prox;
        free(aux);
        return;
    }
    printf("Nao existe pilha");
}

int main()
{
    PilhaStrc *first = NULL;
    while (1)
    {
        int escolha = 0;
        printf("1-insersa\n");
        printf("2-busca\n");
        printf("3-remove\n");
        printf("4-ver\n");
        scanf("%d", &escolha);
        if (escolha == 1)
            InserePilha(&first);
        if (escolha == 4)
            printPilha(&first);
        if (escolha == 22)
            ImprimeTudo(&first);
    }
}