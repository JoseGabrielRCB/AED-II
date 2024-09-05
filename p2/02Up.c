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

void preOrdem(Arvore *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->key); // Visita a raiz
        preOrdem(raiz->esq);      // Visita a subárvore esquerda
        preOrdem(raiz->dir);      // Visita a subárvore direita
    }
}

void TrocaSubArvore(Arvore *raiz, int x, int y)
{
    Arvore *pt_x = Busca_no(raiz, x);
    Arvore *pt_y = Busca_no(raiz, y);
    if (pt_x == NULL || pt_y == NULL)
        return;
    Arvore *pai_x = AchaPai(raiz, x);
    Arvore *pai_y = AchaPai(raiz, y);

    if (pai_x == NULL || pai_y == NULL) //  tenta trocar raiz ver como fazer ainda
        return;

    // refente a x
    if (pai_x->dir == pt_x)
    {
        pai_x->dir = pt_y;
    }
    else
    {
        if (pai_x->esq == pt_x)
            pai_x->esq = pt_y;
    }

    // referente a Y

    if (pai_y->dir == pt_y)
    {
        pai_y->dir = pt_x;
    }
    else
    {
        if (pai_y->esq == pt_y)
            pai_y->esq = pt_x;
    }
}
int main()
{
    Arvore *A = NULL;

    // Aloca A
    A = aloca_arvore(5);
    A->dir = aloca_arvore(6);
    A->dir->dir = aloca_arvore(7);
    A->esq = aloca_arvore(4);
    A->esq->esq = aloca_arvore(3);

    printf("Arvore A: ");
    preOrdem(A);
    printf("\nArvore A alterada: ");
    TrocaSubArvore(A, 4, 6);
    preOrdem(A);

    return 0;
}
