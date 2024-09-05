#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "gfx.h"

typedef struct s_arq_no
{
    int32_t chave : 30;
    uint32_t esq : 1;
    uint32_t dir : 1;
} bin_arvore;

typedef struct Arvore
{
    int key;
    struct Arvore *dir, *esq;
} Arvore;

Arvore *Busca_Arvore(int x, Arvore *pt, int *f)
{
    if (pt == NULL)
    {
        (*f) = 0; // O nó não foi encontrado.
        return NULL;
    }

    if (x == pt->key)
    {
        (*f) = 1;  // O nó foi encontrado.
        return pt; // Retorna o nó encontrado.
    }
    else if (x < pt->key)
    {
        if (pt->esq == NULL)
        {
            (*f) = 2;    // O nó é menor e a subárvore esquerda é nula.
            return NULL; // Retorna NULL pois o nó não foi encontrado.
        }
        else
        {
            // Chama recursivamente a subárvore esquerda.
            return Busca_Arvore(x, pt->esq, f);
        }
    }
    else // x > pt->key
    {
        if (pt->dir == NULL)
        {
            (*f) = 3;    // O nó é maior e a subárvore direita é nula.
            return NULL; // Retorna NULL pois o nó não foi encontrado.
        }
        else
        {
            // Chama recursivamente a subárvore direita.
            return Busca_Arvore(x, pt->dir, f);
        }
    }
}

Arvore *Aloca(int x)
{
    Arvore *novoNO = malloc(sizeof(Arvore));
    novoNO->dir = novoNO->esq = NULL;
    novoNO->key = x;
    return novoNO;
}

Arvore *Insere_Na_Arvore(Arvore **pt, int x)
{
    int f = 0;
    Arvore *aux = (*pt);
    Busca_Arvore(x, aux, &f);
    // printf("[%d]", f);
    if (f == 1)
        return aux; // Valor já existe na árvore
    else
    {
        Arvore *new = Aloca(x);
        if (f == 0)
            (*pt) = new;
        else
        {
            Arvore *it = *pt;
            while (1)
            {
                if (x < it->key)
                {
                    if (it->esq == NULL)
                    {
                        it->esq = new;
                        break;
                    }
                    it = it->esq;
                }
                else
                {
                    if (it->dir == NULL)
                    {
                        it->dir = new;
                        break;
                    }
                    it = it->dir;
                }
            }
        }
    }
    return *pt;
}

Arvore *aloca(int value)
{

    Arvore *pt = malloc(sizeof(Arvore));
    pt->dir = pt->esq = NULL;
    pt->key = value;
    return pt;
}

Arvore *Insere_bin(FILE *arq, Arvore *pt)
{
    bin_arvore leitura;
    if (fread(&leitura, sizeof(bin_arvore), 1, arq) != 1)
        return NULL;
    Arvore *no = aloca(leitura.chave);
    if (leitura.esq == 1)
    {
        no->esq = Insere_bin(arq, pt);
    }
    if (leitura.dir == 1)
    {
        no->dir = Insere_bin(arq, pt);
    }
    return no;
}

// Função para salvar a árvore binária em um arquivo binário
void Save_tree(FILE *arq, Arvore *pt)
{
    if (pt == NULL)
        return;

    bin_arvore save;
    save.chave = pt->key;
    // esq
    if (pt->esq != NULL)
        save.esq = 1;
    else
        save.esq = 0;
    // dir
    if (pt->dir != NULL)
        save.dir = 1;
    else
        save.dir = 0;

    if (fwrite(&save, sizeof(bin_arvore), 1, arq) != 1)
    {
        printf("ERRO ao salvar\n");
        return;
    }

    if (pt->esq != NULL)
        Save_tree(arq, pt->esq);

    if (pt->dir != NULL)
        Save_tree(arq, pt->dir);
}

void Inicia_gfx()
{
    gfx_init(1500, 800, "Arvore");
    gfx_set_color(255, 255, 255);
}

void Ant_Suce(Arvore *pt, int value)
{
    if (pt == NULL)
        return;
    if (pt->key == value)
    {
        if (pt->esq != NULL)
        {
            printf("Sucessor esquerda: %d\n", pt->esq->key);
        }
        else
        {
            printf("Sem sucessor a esquerda\n");
        }
        if (pt->dir != NULL)
        {
            printf("Sucessor direita: %d\n", pt->dir->key);
        }
        else
        {
            printf("Sem sucessor a direita\n");
        }
        return;
    }

    Arvore *it = pt;
    if (it->esq != NULL)
    {
        if (it->esq->key == value)
        {
            printf("Ant: %d\n", it->key);
            if (it->esq->esq != NULL)
            {
                printf("Secessor Esquerda: %d\n", it->esq->esq->key);
            }
            else
            {
                printf("Sem sucessor Esquerda\n");
            }
            if (it->esq->dir != NULL)
            {
                printf("Sucessor direira: %d\n", it->esq->dir->key);
            }
            else
            {
                printf("Sem sucessor a direita\n");
            }
            return;
        }
        it = it->esq;
        Ant_Suce(it, value);
    }
    it = pt;
    if (it->dir != NULL)
    {
        if (it->dir->key == value)
        {
            printf("Ant: %d\n", it->key);
            if (it->dir->esq != NULL)
            {
                printf("Secessor Esquerda: %d\n", it->dir->esq->key);
            }
            else
            {
                printf("Sem sucessor Esquerda\n");
            }
            if (it->dir->dir != NULL)
            {
                printf("Secessor direita: %d\n", it->dir->dir->key);
            }
            else
            {
                printf("Sem sucessor a esqueda\n");
            }

            return;
        }
        it = it->dir;
        Ant_Suce(it, value);
    }
}

void Desenha_Arvore(Arvore *pt, int x, int y, int dx, int dy)
{
    if (pt == NULL)
        return;

    // Desenhar o retângulo para o nó atual
    int reta_comp = 50;
    int resta_altura = 30;
    gfx_rectangle(x, y, x + reta_comp, y + resta_altura);

    // Desenhar o texto do nó
    char buffer[10];
    sprintf(buffer, "%d", pt->key);
    gfx_text(x + reta_comp / 2 - 10, y + resta_altura / 2 - 10, buffer);

    // Desenhar as conexões e os nós filhos
    if (pt->esq != NULL)
    {
        gfx_line(x + reta_comp / 2, y + resta_altura, x - dx + reta_comp / 2, y + dy);
        Desenha_Arvore(pt->esq, x - dx, y + dy, dx / 2, dy);
    }
    if (pt->dir != NULL)
    {
        gfx_line(x + reta_comp / 2, y + resta_altura, x + dx + reta_comp / 2, y + dy);
        Desenha_Arvore(pt->dir, x + dx, y + dy, dx / 2, dy);
    }

    gfx_paint();
}

Arvore *Menor_val(Arvore *pt)
{
    while (pt->esq != NULL)
        pt = pt->esq;
    return pt;
}

Arvore *Maior_val(Arvore *pt)
{
    while (pt->dir != NULL)
        pt = pt->dir;
    return pt;
}

Arvore *Sucessor(Arvore *pt, int val)
{
    if (pt == NULL)
    {
        return NULL;
    }

    Arvore *maior = NULL;
    while (pt != NULL)
    {
        if (val < pt->key)
        {
            maior = pt;
            pt = pt->esq;
        }
        else
            pt = pt->dir;
    }

    return maior;
}

Arvore *Antecessor(Arvore *pt, int val)
{
    if (pt == NULL)
    {
        return NULL;
    }

    Arvore *menor = NULL;
    while (pt != NULL)
    {
        if (val > pt->key)
        {
            menor = pt;
            pt = pt->dir;
        }
        else
            pt = pt->esq;
    }

    return menor;
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

void transplant(Arvore **raiz, Arvore *a, Arvore *d)
{
    Arvore *daddy = AchaPai(*raiz, a->key);
    if (daddy == NULL)
    {
        *raiz = d;
    }
    else if (a == daddy->esq)
    {
        daddy->esq = d;
    }
    else
    {
        daddy->dir = d;
    }
}

// *Funcao de deletar

void del(Arvore **T, Arvore *a)
{
    if (a->esq == NULL)
    {
        transplant(T, a, a->dir);
    }
    else if (a->dir == NULL)
    {
        transplant(T, a, a->esq);
    }
    else
    {
        Arvore *x = Menor_val(a->dir);
        if (x->dir != NULL)
        {
            transplant(T, x, x->dir);
            x->dir = a->dir;
        }
        Arvore *yp = AchaPai(*T, x->key);
        if (yp != a)
        {
            yp->esq = x->dir;
            x->dir = a->dir;
        }
        transplant(T, a, x);
        x->esq = a->esq;
    }
}

// Funcao que acha o sucessor e antecessor de um no