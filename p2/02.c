#include <stdlib.h>
#include <stdio.h>

typedef struct Arvore
{
    int key;
    struct Arvore *esq, *dir;
} Arvore;

Arvore *Busca_no(Arvore *node, int val)
{
    if (node == NULL)
        return NULL;
    if (node->key < val)
        return Busca_no(node->dir, val); // Busca na subárvore direita
    if (node->key > val)
        return Busca_no(node->esq, val); // Busca na subárvore esquerda
    return node;                         // node->key == val
}

Arvore *aloca_arvore(int x)
{
    Arvore *node = malloc(sizeof(Arvore));
    node->dir = node->esq = NULL;
    node->key = x;
    return node;
}

Arvore *AchaPai(Arvore *pt, int filho)
{
    if (pt == NULL)
        return NULL;
    if ((pt->dir != NULL && pt->dir->key == filho) || (pt->esq != NULL && pt->esq->key == filho))
        return pt;
    if (filho > pt->key)
        return AchaPai(pt->dir, filho);
    else
        return AchaPai(pt->esq, filho);
    return NULL;
}

void TrocaSubArvores(Arvore *arvore_1, Arvore *arvore_2, int troca_1, int troca_2)
{
    Arvore *aux1 = Busca_no(arvore_1, troca_1);
    Arvore *aux2 = Busca_no(arvore_2, troca_2);
    if (aux1 == NULL || aux2 == NULL)
        return;

    Arvore *pai_1 = AchaPai(arvore_1, troca_1);
    Arvore *pai_2 = AchaPai(arvore_2, troca_2);

    if (pai_1 != NULL)
    {
        if (pai_1->dir != NULL && pai_1->dir->key == troca_1)
        {
            pai_1->dir = aux2;
        }
        else if (pai_1->esq != NULL && pai_1->esq->key == troca_1)
        {
            pai_1->esq = aux2;
        }
    }
    else
    { // Se pai_1 for NULL, então troca_1 é a raiz de arvore_1
        arvore_1 = aux2;
    }

    if (pai_2 != NULL)
    {
        if (pai_2->dir != NULL && pai_2->dir->key == troca_2)
        {
            pai_2->dir = aux1;
        }
        else if (pai_2->esq != NULL && pai_2->esq->key == troca_2)
        {
            pai_2->esq = aux1;
        }
    }
    else
    { // Se pai_2 for NULL, então troca_2 é a raiz de arvore_2
        arvore_2 = aux1;
    }
}

void preOrdem(Arvore *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->key); // Visita a raiz
        preOrdem(raiz->esq);      // Visita a subárvore esquerda
        preOrdem(raiz->dir);      // Visita a subárvore direita
    }
}

int main()
{
    Arvore *A, *B = NULL;

    // Aloca A
    A = aloca_arvore(5);
    A->dir = aloca_arvore(6);
    A->dir->dir = aloca_arvore(7);
    A->esq = aloca_arvore(4);
    A->esq->esq = aloca_arvore(3);

    // Aloca B
    B = aloca_arvore(20);
    B->dir = aloca_arvore(24);
    B->dir->dir = aloca_arvo    re(30);
    B->esq = aloca_arvore(19);
    B->esq->esq = aloca_arvore(18);

    printf("Arvore A (pre-ordem): ");
    preOrdem(A);
    printf("\n");

    printf("Arvore B (pre-ordem): ");
    preOrdem(B);
    printf("\n");

    printf("\nTrocando subárvores...\n\n");

    TrocaSubArvores(A, B, 4, 19);

    printf("Arvore A (pre-ordem): ");
    preOrdem(A);
    printf("\n");

    printf("Arvore B (pre-ordem): ");
    preOrdem(B);
    printf("\n");

    return 0;
}
