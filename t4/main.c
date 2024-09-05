#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "gfx.h"

#define centerX 650
#define startY 50
#define distx 250
#define disty 100
#define false 0;
#define true 1;

typedef struct s_no
{
    int32_t chave : 28;
    int32_t bal : 2;
    int32_t reservado : 2; /* sem uso */
    struct s_no *esq;
    struct s_no *dir;

} AVL;

typedef struct s_arq_no
{
    int32_t chave : 28;
    int32_t bal : 2;
    uint32_t esq : 1;
    uint32_t dir : 1;

} AVL_bin;

// Funcoes de Arvore

void aloca(AVL_bin leitura, AVL **aux)
{
    (*aux) = malloc(sizeof(AVL));
    (*aux)->chave = leitura.chave;
    (*aux)->bal = leitura.bal;
    (*aux)->dir = (*aux)->esq = NULL;
}

AVL *Insere_AVL_bin(FILE *arq)
{
    AVL_bin leitura;
    if (fread(&leitura, sizeof(AVL_bin), 1, arq) != 1)
        return NULL;
    AVL *no;
    aloca(leitura, &no);
    if (leitura.esq == 1)
        no->esq = Insere_AVL_bin(arq);
    if (leitura.dir == 1)
        no->dir = Insere_AVL_bin(arq);
    return no;
}

void Salva_AVL(FILE *arq, AVL *pt)
{
    if (pt == NULL)
        return;
    AVL_bin save;
    save.chave = pt->chave;
    save.bal = pt->bal;
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
    if (fwrite(&save, sizeof(AVL_bin), 1, arq) != 1)
    {
        printf("ERRO AO SALVAR");
        return;
    }
    if (pt->esq != NULL)
        Salva_AVL(arq, pt->esq);

    if (pt->dir != NULL)
        Salva_AVL(arq, pt->dir);
}

void caso1(AVL **pt, int *h)
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
    *h = 0; // Altura reduzida, então h é 0 (Falso)
}

void caso2(AVL **pt, int *h)
{
    AVL *ptu = (*pt)->dir;

    if (ptu->bal == 1)
    {
        // Rotação simples à esquerda
        (*pt)->dir = ptu->esq;
        ptu->esq = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    }
    else
    {
        // Rotação dupla à esquerda
        AVL *ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = *pt;

        if (ptv->bal == 1)
        {
            (*pt)->bal = -1;
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

        *pt = ptv;
    }

    (*pt)->bal = 0;
    *h = 0; // Altura reduzida, então h é 0 (Falso)
}

void ins_AVL(int x, AVL **pt, int *h)
{
    if (*pt == NULL)
    {
        // Inicia novo nó
        *pt = (AVL *)malloc(sizeof(AVL));
        if (*pt == NULL)
        {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
        (*pt)->chave = x;
        (*pt)->bal = 0;
        (*pt)->esq = NULL;
        (*pt)->dir = NULL;
        *h = 1; // Altura aumentada
    }
    else if (x == (*pt)->chave)
    {
        // Chave já existe, não faz nada
        *h = 0;
        return;
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
                *h = 0;
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
                *h = 0;
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

void imprime_in_ordem(AVL *pt)
{
    if (pt == NULL)
    {
        return;
    }

    // Primeiro, visita o nó esquerdo
    imprime_in_ordem(pt->esq);

    // Em seguida, imprime o nó atual
    printf("%d ", pt->chave);

    // Por último, visita o nó direito
    imprime_in_ordem(pt->dir);
}

void Busca_AVL(AVL *pt, int val, int *exist)
{
    if (pt == NULL)
        return;
    if (val == pt->chave)
        *exist = 1;
    if (val < pt->chave)
        Busca_AVL(pt->esq, val, exist);
    if (val > pt->chave)
        Busca_AVL(pt->dir, val, exist);
    return;
}

AVL *buscaMin(AVL *pt)
{
    while (pt->esq != NULL)
    {
        pt = pt->esq;
    }
    return pt;
}

int remove_AVL(int x, AVL **pt, int *h)
{
    if (*pt == NULL)
    {
        return 0; // Elemento não encontrado
    }

    if (x < (*pt)->chave)
    {
        if (remove_AVL(x, &(*pt)->esq, h))
        {
            if (*h)
            {
                switch ((*pt)->bal)
                {
                case -1:
                    (*pt)->bal = 0;
                    *h = 1;
                    break;
                case 0:
                    (*pt)->bal = 1;
                    *h = 0;
                    break;
                case 1:
                    caso2(pt, h); // Rotação à esquerda para balancear
                    if ((*pt)->bal == 0)
                    {
                        *h = 1; // Se a altura não mudou após rotação
                    }
                    else
                    {
                        *h = 0;
                    }
                    break;
                }
            }
        }
    }
    else if (x > (*pt)->chave)
    {
        if (remove_AVL(x, &(*pt)->dir, h))
        {
            if (*h)
            {
                switch ((*pt)->bal)
                {
                case 1:
                    (*pt)->bal = 0;
                    *h = 1;
                    break;
                case 0:
                    (*pt)->bal = -1;
                    *h = 0;
                    break;
                case -1:
                    caso1(pt, h); // Rotação à direita para balancear
                    if ((*pt)->bal == 0)
                    {
                        *h = 1; // Se a altura não mudou após rotação
                    }
                    else
                    {
                        *h = 0;
                    }
                    break;
                }
            }
        }
    }
    else
    { // Encontrou o nó a ser removido
        AVL *aux = *pt;

        if ((*pt)->esq == NULL)
        {
            *pt = (*pt)->dir;
            *h = 1;
        }
        else if ((*pt)->dir == NULL)
        {
            *pt = (*pt)->esq;
            *h = 1;
        }
        else
        {
            AVL *minDir = buscaMin((*pt)->dir);
            (*pt)->chave = minDir->chave;
            if (remove_AVL(minDir->chave, &(*pt)->dir, h))
            {
                if (*h)
                {
                    switch ((*pt)->bal)
                    {
                    case 1:
                        (*pt)->bal = 0;
                        *h = 1;
                        break;
                    case 0:
                        (*pt)->bal = -1;
                        *h = 0;
                        break;
                    case -1:
                        caso1(pt, h); // Rotação à direita para balancear
                        if ((*pt)->bal == 0)
                        {
                            *h = 1; // Se a altura não mudou após rotação
                        }
                        else
                        {
                            *h = 0;
                        }
                        break;
                    }
                }
            }
        }
        free(aux);
        return 1; // Elemento encontrado e removido
    }
    return 0; // Elemento não encontrado
}

// funcoes de GFX

void Desenha_Arvore(AVL *pt, int x, int y, int dx, int dy)
{
    if (pt == NULL)
        return;

    // Desenhar o retângulo para o nó atual
    int reta_comp = 50;
    int resta_altura = 30;
    gfx_rectangle(x, y, x + reta_comp, y + resta_altura);

    // Desenhar o texto do nó
    char buffer[10];
    char ball[10];
    sprintf(buffer, "%d", pt->chave);
    sprintf(ball, "%d", pt->bal);
    gfx_text(x + reta_comp / 2 - 10, y + resta_altura / 2 - 10, buffer);
    gfx_text((x + reta_comp / 2 - 10) + 40, y + resta_altura / 2 - 10, ball);

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

void Limpa_tela()
{
    gfx_set_color(0, 0, 0);
    gfx_filled_rectangle(0, 0, 1920, 1080);
    gfx_paint();
    gfx_set_color(255, 255, 255);
}
// Funcoes de Menu

void ERRO()
{
    system("clear");
    printf("Valor de entrada Invalida!\n");
    getchar();
}

AVL *Menu_AVL(AVL *raiz)
{
    while (1)
    {
        getchar();
        Limpa_tela();
        Desenha_Arvore(raiz, centerX, startY, distx, disty);
        printf("1-Inserir valor\n");  // implementado
        printf("2-Busca de valor\n"); // implemnetado
        printf("3-Remoção de valor\n");
        printf("0-Retornar\n");
        // imprime_in_ordem(raiz);
        int option = 0, num = 0, exist = 0, h = 0;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("clear");
            printf("Digite o valor:\n");
            // int num = 0, h = 0;
            scanf("%d", &num);
            ins_AVL(num, &raiz, &h);
            break;
        case 2:
            system("clear");
            printf("Digite o valor:\n");
            scanf("%d", &num);
            Busca_AVL(raiz, num, &exist);
            if (exist == 1)
                printf("Valor encontrado\n\n\n");
            else
                printf("Valor nao encontrado\n\n\n");
            break;

        case 3:
            printf("Digite o valor:\n");
            scanf("%d", &num);
            remove_AVL(num, &raiz, &h);
            break;

        case 0:
            system("clear");
            printf("Retornando...\n");
            break;
        default:
            ERRO();
            break;
        }
        if (!option)
            break;
    }
    getchar();
    return raiz;
}

void Menu_bin()
{
    system("clear");
    printf("Qual o nome do arquivo?(adcione o .bin)\n");
    char arquivo[100];
    scanf("%s", arquivo);
    FILE *arq = NULL;
    arq = fopen(arquivo, "rb");
    if (arq == NULL)
    {
        printf("Falha ao abrir arquivo!\n");
        return;
    }
    AVL *raiz;
    raiz = Insere_AVL_bin(arq);
    fclose(arq);
    raiz = Menu_AVL(raiz);
    arq = fopen(arquivo, "wr");
    if (arq == NULL)
    {
        printf("Erro ao salvar arquivo!");
        return;
    }
    Salva_AVL(arq, raiz);
    fclose(arq);
}

int menu()
{
    system("clear");
    printf("1-Criar arvore\n2-Abrir arquivo de Arvore\n0-Encerra\n");
    int option = 0;
    AVL *raiz = NULL;
    char name[100];
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        system("cls");
        printf("Qual o nome do arquivo?\n");
        scanf("%s", name);
        raiz = Menu_AVL(raiz);
        FILE *arq = NULL;
        arq = fopen(name, "wb");
        if (arq == NULL)
            printf("Erro ao criar arquivo!");
        else
            Salva_AVL(arq, raiz);
        fclose(arq);
        break;
    case 2:
        getchar();
        Menu_bin();
        break;
    case 0:
        printf("Finalizando...\n");
        break;
    default:
        ERRO();
        break;
    }

    return option;
}

int main()
{
    gfx_init(1920, 1080, "t4");
    while (1)
    {
        int loop = menu();
        if (loop == 0)
            break;
    }
}
