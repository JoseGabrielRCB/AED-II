#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

/*
int centerX = 1500 / 2 - 100;
    int startY = 50;
    int dx = 250; // Ajustar espaçamento horizontal
    int dy = 100; // Ajustar espaçamento vertical*/

#define centerX 650
#define startY 50
#define dx 250
#define dy 100

void ERRO()
{
    system("clear");
    getchar();
    printf("ERRO!\n");
    getchar();
    system("clear");
}

void Limpa_tela_gfx()
{
    gfx_set_color(0, 0, 0);
    gfx_filled_rectangle(0, 0, 1500, 800);
    gfx_paint();
    gfx_set_color(255, 255, 255);
}

void menu_1(char arq_name[])
{
    FILE *arq = fopen(arq_name, "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    Arvore *raiz = NULL;
    raiz = Insere_bin(arq, raiz);
    gfx_set_color(255, 255, 255);
    Desenha_Arvore(raiz, centerX, startY, dx, dy);
    int action = 0;
    while (1)
    {
        printf("1-adicionar\n2-remover\n3-Procurar Antecessor e Sucessor de um valor\n");
        printf("4- Encontrar maior e menor valor\n5-Procurar um valor\n0-voltar\n");
        scanf("%d", &action);
        system("clear");
        if (action == 0)
            break;
        if (action == 1) // adicionar
        {
            int val;
            printf("Insira o valor a ser adcionado:\n");
            scanf("%d", &val);
            Insere_Na_Arvore(&raiz, val);
            Limpa_tela_gfx();
            Desenha_Arvore(raiz, centerX, startY, dx, dy);
        }
        if (action == 2)
        {
            printf("valor a ser removido:\n");
            int valor = 0;
            scanf("%d", &valor);
            int f;
            Arvore *aux = Busca_Arvore(valor, raiz, &f);
            if (f == 1)
            {
                printf("%d", aux->key);
                del(&raiz, aux);
                Limpa_tela_gfx();
                Desenha_Arvore(raiz, centerX, startY, dx, dy);
            }
            system("clear");
        }
        if (action == 3)
        {
            getchar();
            printf("Insira o valor do predecessor e antecessor:\n");
            int val, f = 0;
            scanf("%d", &val);
            Busca_Arvore(val, raiz, &f);
            if (f == 1)
            {
                Arvore *aux = Antecessor(raiz, val);
                printf("Antecessor: %d\n", aux->key);
                aux = Sucessor(raiz, val);
                printf("Sucesor: %d\n", aux->key);
                if (val < 0)
                    printf("Obs: Numeros negaivos são lidos invertidamente\nEX: -2 < -1 < 0...\n");
            }
            else
            {
                system("clear");
                printf("Valor não encontrado!!\n");
                getchar();
                getchar();
                system("clear");
            }
        }
        if (action == 5)
        {
            getchar();
            printf("Insera o valor a ser pesquisado:\n");
            int val, f = 0;
            scanf("%d", &val);
            Busca_Arvore(val, raiz, &f);
            if (f == 1)
            {
                printf("Valor %d, encontrado!\n", val);
                getchar();
            }
            else
            {
                printf("Valor %d,não encontrado\n", val);
                getchar();
            }
        }
        if (action == 4)
        {
            getchar();
            Arvore *aux = Menor_val(raiz);
            printf("Valor menor: %d\n", aux->key);
            aux = Maior_val(raiz);
            printf("Valor maior: %d\n", aux->key);
        }
    }
    fclose(arq);
    arq = fopen(arq_name, "wb");
    if (arq == NULL)
    {
        printf("ERRO AO SALVAR ARQUIVO");
        getchar();
    }
    Save_tree(arq, raiz);
    fclose(arq);
    Limpa_tela_gfx();
}

int main()
{
    // Imprime_tela(raiz, 500, 100, 25, 25);
    printf("T3\n\n");
    Inicia_gfx();
    int menu_destiny = 1;

    while (menu_destiny != 0)
    {
        printf("1-abrir arquivo binario\n2-criar arquivo binario\n0-finalizar programa\n");
        scanf("%d", &menu_destiny);
        if (menu_destiny == 0)
            return 1;
        if (menu_destiny != 1 && menu_destiny != 2)
            ERRO();
        if (menu_destiny == 1)
        {
            char nome_bin[100];
            system("clear");
            printf("Insira o nome do arquivo\n");
            scanf("%s", nome_bin);
            menu_1(nome_bin);
        }
        if (menu_destiny == 2)
        {
            system("clear");
            printf("Insira o nome do arquivo a ser criado\n");
            char nome_bin[100];
            scanf("%s", nome_bin);
            FILE *arq = fopen(nome_bin, "wb");
            if (arq == NULL)
            {
                printf("ERRO ao criar arquivo novo\n");
                getchar();
            }
            else
            {
                fclose(arq);
                menu_1(nome_bin);
            }
        }
    }
    return 0;
}