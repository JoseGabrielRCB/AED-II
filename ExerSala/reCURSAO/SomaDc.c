#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int SomaDc(int S[], int ini, int fim)
{

    if (ini == fim)
    {
        return(S[ini]);
        
    }
    int meio = floor((ini+fim)/2);

    return SomaDc(S,ini,meio) + SomaDc(S,meio+1,fim);

}

int main()
{

    int vetor[4] = {1, 7, 6, 2};

    int soma = SomaDc(vetor,0,3);
    system("cls");
    printf("\n\nSOMA:%d\n\n",soma);
}