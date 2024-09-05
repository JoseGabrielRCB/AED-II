#include <stdlib.h>
#include <stdio.h>

typedef struct Arvore
{
    int key;
    struct Arvore *dir, *esq;
} Arvore;

typedef struct node
{
    Arvore *key;
    struct node *next;
} node;

Arvore *aloca_arvore(int x)
{
    Arvore *node = malloc(sizeof(Arvore));
    node->dir = node->esq = NULL;
    node->key = x;
    return node;
}

node *aloca_fila(Arvore *pt)
{
    node *aux = malloc(sizeof(node));
   // aloca(aux)
   // aux->prox := lambida 
    aux->key = pt;
    aux->next = NULL;
    return aux;
}

void Inlevel(node *fila, node **tail)
{
    if (fila->key->dir != NULL)
    {
        (*tail)->next = aloca_fila(fila->key->dir);
        (*tail) = (*tail)->next;
    }

    if (fila->key->esq != NULL)
    {
        (*tail)->next = aloca_fila(fila->key->esq);
        (*tail) = (*tail)->next;
    }

    if (fila->next != NULL)
    {
        Inlevel(fila->next, tail);
    }
}

void Remove(node **fila)
{
    node *aux = (*fila);
    (*fila) = (*fila)->next;
    free(aux);
}

void ImprimeFila(node *fila)
{
    while (fila != NULL)
    {
        printf("[%d]->", fila->key->key);
        fila = fila->next;
    }
    printf("\n");
}

int main()
{
    Arvore *raiz = aloca_arvore(1);
    Arvore *aux = aloca_arvore(2);
    raiz->dir = aux;
    aux = aloca_arvore(3);
    raiz->esq = aux;
    aux = aloca_arvore(4);
    raiz->dir->dir = aux;
    aux = aloca_arvore(5);
    raiz->esq->esq = aux;

    node *fila, *tail = NULL;
    fila = tail = aloca_fila(raiz);
    Inlevel(fila, &tail);
    ImprimeFila(fila);

    while (fila != NULL)
    {
        node *tmp = fila;
        fila = fila->next;
        free(tmp);
    }
    return 0;
}

// Primeira questão da prova do fabricio
