#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_no
{
    int32_t chave : 28;
    int32_t bal : 2;
    int32_t reservado : 2; /* sem uso */
    struct s_no *esq;
    struct s_no *dir;
} AVL;

void caso1(AVL **pt, bool *h)
{
    AVL *ptu = (*pt)->esq;

    if (ptu->bal == -1)
    {
        // Rotação simples à direita
        (*pt)->esq = ptu->dir;
        ptu->dir = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    }
    else
    {
        // Rotação dupla à direita
        AVL *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*pt)->esq = ptv->dir;
        ptv->dir = *pt;

        if (ptv->bal == -1)
        {
            (*pt)->bal = 1;
        }
        else
        {
            (*pt)->bal = 0;
        }

        if (ptv->bal == 1)
        {
            ptu->bal = -1;
        }
        else
        {
            ptu->bal = 0;
        }

        *pt = ptv;
    }

    (*pt)->bal = 0;
    *h = false;
}

void caso2(AVL **pt, bool *h)
{
    AVL *ptu = (*pt)->dir;
    if (ptu.bal == 1)
    {
        (*pt)->dir = ptu->esq;
        ptu->esq = pt;
        (*pt)->bal = 0;
        (*pt) = ptu;
    }
    else
    {
        AVL *ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = pt;
        if (ptv->bal == 1)
        {
            (*pt)->bal = -1
        }
        else
        {
            (*pt)->bal = 0;
        }
        if (ptv->bal == -1)
        {
            ptu->bal = 1;
        }
        else
        {
            ptu->bal = 0;
        }
        (*pt) = ptv;
    }
    (*pt)->bal = 0;
    h = 0;
}

void ins_AVL(int x, AVL **pt, bool *h)
{
    if (*pt == NULL)
    {
        // inicia novo nó
        *pt = (AVL *)malloc(sizeof(AVL));
        (*pt)->chave = x;
        (*pt)->bal = 0;
        (*pt)->esq = NULL;
        (*pt)->dir = NULL;
        *h = true;
    }
    else if (x == (*pt)->chave)
    {
        // chave já existe, não faz nada
        *h = false;
    }
    else if (x < (*pt)->chave)
    {
        ins_AVL(x, &(*pt)->esq, h);
        if (*h)
        {
            switch ((*pt)->bal)
            {
            case 1:
                (*pt)->bal = 0;
                *h = false;
                break;
            case 0:
                (*pt)->bal = -1;
                break;
            case -1:
                caso1(pt, h); // Rebalanceamento necessário
                break;
            }
        }
    }
    else
    {
        ins_AVL(x, &(*pt)->dir, h);
        if (*h)
        {
            switch ((*pt)->bal)
            {
            case -1:
                (*pt)->bal = 0;
                *h = false;
                break;
            case 0:
                (*pt)->bal = 1;
                break;
            case 1:
                caso2(pt, h); // Rebalanceamento necessário
                break;
            }
        }
    }
}