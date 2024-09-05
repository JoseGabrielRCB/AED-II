#include "gfx.h"
#include <stdio.h>
#include <unistd.h>

void flush_in()
{
    int ch;
    do
    {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void ERRO() // imprime erro caso alguma entreda seja errada
{
    system("clear");
    printf("ERRO VALOR INVALIDO ESCOLHA QUADRADO OU CIRCULO DE ATE 10 DE RECURSAO\n");
    printf("PRESSIONE ENTER PARA SAIR\n");
    flush_in(); // limpa buffer do teclado
    getchar();  // espera entrada do usurario para continuar
    system("clear");
}

void remove_centro(int x1, int y1, int x2, int y2) // impede que apareca "retangulos" dentro do centro
{

    gfx_set_color(0, 0, 0);
    gfx_filled_rectangle(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
}

int rec_quad(int x1, int y1, int x2, int y2, int n) // recurcao do qaudrado
{
    if (n == 0)
    {
        return 0; // finaliza recusao
    }
    // modularizacao criar acumulo erros

    //   quadrado esquerda
    int NX1E = x1 - (x2 - x1) / 2;
    int NY1E = y1 + (y2 - y1) / 4;
    int NX2E = x1;
    int NY2E = y2 - (y2 - y1) / 4;

    // quadrado cima
    int NX1C = x1 + (x2 - x1) / 4;
    int NY1C = y1 - (y2 - y1) / 2;
    int NX2C = x2 - (x2 - x1) / 4;
    int NY2C = y1;

    // quadrado baixo

    int NX1B = x1 + (x2 - x1) / 4;
    int NY1B = y2;
    int NX2B = x2 - (x2 - x1) / 4;
    int NY2B = y2 + (y2 - y1) / 2;

    // quadrado direita
    int NX1D = x2;
    int NY1D = y1 + (y2 - y1) / 4;
    int NX2D = x2 + (x2 - x1) / 2;
    int NY2D = y2 - (y2 - y1) / 4;

    rec_quad(NX1E, NY1E, NX2E, NY2E, n - 1);
    rec_quad(NX1C, NY1C, NX2C, NY2C, n - 1);
    rec_quad(NX1B, NY1B, NX2B, NY2B, n - 1);
    rec_quad(NX1D, NY1D, NX2D, NY2D, n - 1);

    gfx_set_color(255, 255, 255);
    gfx_rectangle(NX1D, NY1D, NX2D, NY2D);
    gfx_rectangle(NX1B, NY1B, NX2B, NY2B);
    gfx_rectangle(NX1E, NY1E, NX2E, NY2E);
    gfx_rectangle(NX1C, NY1C, NX2C, NY2C);
   // remove_centro(x1, y1, x2, y2);
    return 0;
}

int alt_px1(int r, int px)
{
    return r * sqrt(2) / 2 + px;
}

int alt_py1(int r, int py)
{
    return r * sqrt(2) / 2 + py;
}

int alt_px2(int px, int px1)
{
    return px1 + (px - px1) * 2;
}

int alt_py2(int py, int py1)
{
    return py1 + (py - py1) * 2;
}

int elipise(int recursao, int px, int py, int r)
{

    if (recursao <= 0)
    {
        return 0;
    }
    r = r / 2;

    int px1 = alt_px1(r, px);
    int py1 = alt_py1(r, py);

    int px2 = alt_px2(px, px1);
    int py2 = alt_py2(py, py1);

    elipise(recursao - 1, px1, py1, r);
    elipise(recursao - 1, px1, py2, r);
    elipise(recursao - 1, px2, py1, r);
    elipise(recursao - 1, px2, py2, r);

    gfx_ellipse(px1, py1, r, r);
    gfx_ellipse(px1, py2, r, r);
    gfx_ellipse(px2, py1, r, r);
    gfx_ellipse(px2, py2, r, r);

    return 0;
}

void menu()
{
    printf("TRABALHO 1:\n");
    int aux = 0;
    int recursao = 0;

    while (1)
    {
        printf("Qual forma deseja : (1-circulo // 2-quadrado)\n");
        scanf("%d", &aux);
        printf("Qual a quantidade de recursao?\n");
        scanf("%d", &recursao);
        if ((aux != 2 && aux != 1) || (recursao > 10) || (recursao < 0))
        {
            ERRO();
        }
        else
        {
            break;
        }
    }

    if (aux == 1) // escolha circulo
    {
        gfx_init(600, 600, "elipise");
        gfx_set_color(255, 255, 255);
        gfx_ellipse(300, 300, 280, 280);
        elipise(recursao, 300, 300, 280);
        gfx_paint();
        sleep(10);
        gfx_quit();
    }
    if (aux == 2) // quadrado
    {
        gfx_init(600, 600, "quadrado");
        gfx_rectangle(200, 200, 400, 400);
        rec_quad(200, 200, 400, 400, recursao);
        gfx_paint();
        sleep(10);
        gfx_quit();
    }
}

int main()
{
    menu();
    return 0;
}