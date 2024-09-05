#include <stdio.h>
#include <stdlib.h>

int Invert(int quant, int Sq[], int i)
{

    if(i < quant)
    {
        int aux = Sq[quant];
        Sq[quant] = Sq[i];
        Sq[i] = aux;

        return Invert(quant - 1, Sq, i + 1);
    }
}

int main()
{
    int Sq[5] = {1, 2, 3, 4, 5};
    int quant = 5;

    Invert(quant - 1, Sq, 0);
    for (int i = 0; i < quant; i++)
    {
        printf("%d",Sq[i]);
    }
    
}
