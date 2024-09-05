#include <stdio.h>
#include <stdlib.h>

int FindeHightNum(int v[], int n, int aux)
{
    if (n < 0)
    {
        return aux;
    }
    else
    {
        if (aux < v[n])
        {
            printf("\n\n%d\n\n", n);
            aux = v[n];
        }

        return FindeHightNum(v, n - 1, aux);
    }
}

int main()
{
    int Conj[5] = {12, 2, 7, 10, 6};
    int quant = 0;

    printf("How many num=bers have in you conj?");
    scanf("%d", &quant);

    printf("\n\nHIGHT VALOR: %d", FindeHightNum(Conj, quant - 1, 1));
}