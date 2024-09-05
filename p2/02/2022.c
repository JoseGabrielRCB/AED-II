#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct No
{
    int bal;
    int val;
    struct No *esq;
    struct No *dir;
} No;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int altura(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
        return 1 + max(altura(raiz->esq), altura(raiz->dir));
}

int bal(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        raiz->bal = dir - esq;
    }
    return raiz->bal;
}
int VerificaAvl(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int verifica = bal(raiz);
        if (verifica > 1 || verifica < -1)
            return 0;
        else
            return 1;
    }
}

No *inserir(No *raiz, int val)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->val = val;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->bal = 0;
        return novo;
    }

    if (val < raiz->val)
    {
        raiz->esq = inserir(raiz->esq, val);
    }
    else if (val > raiz->val)
    {
        raiz->dir = inserir(raiz->dir, val);
    }
    bal(raiz);
    return raiz;
}

void imprimirArvore(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirArvore(raiz->esq);
        printf("Valor: %d, balanceamento: %d\n", raiz->val, raiz->bal);
        imprimirArvore(raiz->dir);
    }
}
int main()
{
    No *raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 22);

    // Imprimindo a árvore com os balanceamentos
    imprimirArvore(raiz);

    printf("arvore e avl: %d\n", VerificaAvl(raiz));

    return 0;
}

typedef struct No
{
    int bal;
    int val;
    struct No *esq;
    struct No *dir;
} No;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int altura(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
        return 1 + max(altura(raiz->esq), altura(raiz->dir));
}

int bal(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        raiz->bal = dir - esq;
    }
    return raiz->bal;
}
int VerificaAvl(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int verifica = bal(raiz);
        if (verifica > 1 || verifica < -1)
            return 0;
        else
            return 1;
    }
}

No *inserir(No *raiz, int val)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->val = val;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->bal = 0;
        return novo;
    }

    if (val < raiz->val)
    {
        raiz->esq = inserir(raiz->esq, val);
    }
    else if (val > raiz->val)
    {
        raiz->dir = inserir(raiz->dir, val);
    }
    bal(raiz);
    return raiz;
}

void imprimirArvore(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirArvore(raiz->esq);
        printf("Valor: %d, balanceamento: %d\n", raiz->val, raiz->bal);
        imprimirArvore(raiz->dir);
    }
}
int main()
{
    No *raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 22);

    // Imprimindo a árvore com os balanceamentos
    imprimirArvore(raiz);

    printf("arvore e avl: %d\n", VerificaAvl(raiz));

    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct No
{
    int bal;
    int val;
    struct No *esq;
    struct No *dir;
} No;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int altura(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
        return 1 + max(altura(raiz->esq), altura(raiz->dir));
}

int bal(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        raiz->bal = dir - esq;
    }
    return raiz->bal;
}
int VerificaAvl(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int verifica = bal(raiz);
        if (verifica > 1 || verifica < -1)
            return 0;
        else
            return 1;
    }
}

No *inserir(No *raiz, int val)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->val = val;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->bal = 0;
        return novo;
    }

    if (val < raiz->val)
    {
        raiz->esq = inserir(raiz->esq, val);
    }
    else if (val > raiz->val)
    {
        raiz->dir = inserir(raiz->dir, val);
    }
    bal(raiz);
    return raiz;
}

void imprimirArvore(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirArvore(raiz->esq);
        printf("Valor: %d, balanceamento: %d\n", raiz->val, raiz->bal);
        imprimirArvore(raiz->dir);
    }
}
int main()
{
    No *raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 22);

    // Imprimindo a árvore com os balanceamentos
    imprimirArvore(raiz);

    printf("arvore e avl: %d\n", VerificaAvl(raiz));

    return 0;
}

typedef struct No
{
    int bal;
    int val;
    struct No *esq;
    struct No *dir;
} No;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int altura(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
        return 1 + max(altura(raiz->esq), altura(raiz->dir));
}

int bal(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        raiz->bal = dir - esq;
    }
    return raiz->bal;
}
int VerificaAvl(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int verifica = bal(raiz);
        if (verifica > 1 || verifica < -1)
            return 0;
        else
            return 1;
    }
}

No *inserir(No *raiz, int val)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->val = val;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->bal = 0;
        return novo;
    }

    if (val < raiz->val)
    {
        raiz->esq = inserir(raiz->esq, val);
    }
    else if (val > raiz->val)
    {
        raiz->dir = inserir(raiz->dir, val);
    }
    bal(raiz);
    return raiz;
}

void imprimirArvore(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirArvore(raiz->esq);
        printf("Valor: %d, balanceamento: %d\n", raiz->val, raiz->bal);
        imprimirArvore(raiz->dir);
    }
}
int main()
{
    No *raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 22);

    // Imprimindo a árvore com os balanceamentos
    imprimirArvore(raiz);

    printf("arvore e avl: %d\n", VerificaAvl(raiz));

    return 0;
}