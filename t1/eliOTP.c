#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */
#include <stdlib.h>
#include <math.h>

int elipise(int recursao, int px, int py, int r)
{
    

    if (recursao <= 0)
    {
        return 0;
    }
    r = r / 2;

    printf("%d\n",px);

    int px1 = r * sqrt(2) / 2 + px;
    int py1 = r * sqrt(2) / 2 + py;

    int px2 = px1 + (px - px1) * 2;
    int py2 = py1 + (py - py1) * 2;

    gfx_ellipse(px1, py1, r, r);
    gfx_ellipse(px1, py2, r, r);
    gfx_ellipse(px2, py1, r, r);
    gfx_ellipse(px2, py2, r, r);

    elipise(recursao - 1, px1, py1, r);

    elipise(recursao - 1, px1, py2, r);

    elipise(recursao - 1, px2, py1, r);

    elipise(recursao - 1, px2, py2, r);

    
    
    return 0;
}

int main()
{
    
    int a = 10 ;
    int py = 300;
    int px = 300;
    int r = 280;

    printf("TESTE\n");
    gfx_init(600, 600, "elipise");
    gfx_set_color(255, 255, 255);
    gfx_ellipse(px, py, r, r);
    elipise(a, px, py, r);
    gfx_paint();
    sleep(10);

    gfx_quit();

    return 0;
}