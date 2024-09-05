#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */
#include <stdlib.h>
#include <math.h>

void inverte_valores(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int alterar_r(int x)
{
    return x / 2;
}

int altera_p1(int posicao, int raio)
{

    /* return posicao = posicao + (posicao * 33 / 100) * plus_dec; */

    return posicao = (raio * sqrt(2) / 2 + posicao);
}

int altera_p2(int raio, int p1, int p)
{
    int posicao = p1 + (p - p1) * 2;
    return posicao;
}

int recursao(int px, int py, int r, int recursao_quant)
{
    if (recursao_quant == 0)
    {
        return 1;
    }
    r = alterar_r(r);

    int px1 = altera_p1(px, r);
    int py1 = altera_p1(py, r);

    int px2 = altera_p2(r, px1, px);
    int py2 = altera_p2(r, py1, py);

    gfx_ellipse(px1, py2, r, r);
    gfx_ellipse(px1, py1, r, r);
    gfx_ellipse(px2, py1, r, r);
    gfx_ellipse(px2, py2, r, r);

    recursao(px1, py1, r, recursao_quant - 1);
    recursao(px1, py2, r, recursao_quant - 1);
    recursao(px2, py1, r, recursao_quant - 1);
    recursao(px2, py2, r, recursao_quant - 1);
    gfx_paint();
    return 0;
}
int elipise(int valor_recursao, int px, int py, int raio)
{

    gfx_set_color(255, 255, 255);
    //gfx_ellipse(,)
    

    recursao(px, py, raio, valor_recursao);

    sleep(30);

    gfx_quit();
    return 0;
}

int main()
{
    int a = 10;
    int py = 300;
    int px = 300;
    int rx = 280;

    printf("TESTE\n");
    gfx_init(600, 600, "elipise"); // inicia janela grafico
    elipise(a, px, py, rx);
}