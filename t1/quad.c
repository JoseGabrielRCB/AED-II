#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */

void remove_centro(int x1, int y1, int x2, int y2)
{

    gfx_set_color(0, 0, 0);
    gfx_filled_rectangle(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
}

int fun_reduz_2(int a, int b)
{
	return a - (b - a) / 2;
}

int fun_aumenta(int a, int b)
{
	return a + (b - a) / 4;
}

int fun_inverte(int b)
{
	return b;
}

int fun_reduz_4(int a, int b)
{
	return a - (b - a) / 4;
}

int rec_quad(int x1, int y1, int x2, int y2, int n) // recurcao do qaudrado
{
	if (n == 0)
	{
		return 0; // finaliza recusao
	}

	//  quadrado esquerda
	int NX1E = fun_reduz_2(x1, x2);
	int NY1E = fun_aumenta(y1,y2);
	int NX2E = fun_inverte(x1);
	int NY2E = fun_reduz_4(y1,y2);
/* 
    int NX1E = x1 - (x2 - x1) / 2;
	int NY1E = y1 + (y2 - y1) / 4;
	int NX2E = x1;
	int NY2E = y2 - (y2 - y1) / 4; */

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
	remove_centro(x1, y1, x2, y2);
	return 0;
}
int main()
{
    gfx_init(600, 600, "quadrado");
    gfx_rectangle(200, 200, 400, 400);
    rec_quad(200, 200, 400, 400, 3);
    gfx_paint();
    sleep(10);
    gfx_quit();
    return 0;
}