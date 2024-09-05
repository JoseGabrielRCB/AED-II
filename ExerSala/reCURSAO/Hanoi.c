#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void situacao(int quant, int pinos[3][])
{
    system("cls");
    for (int i = 0; i < quant; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d", pinos[j][i]);
        
        }
    printf("\n");
    
    }
}

int comp(char val)
{
        val = tolower(val)
    if (val == 'a')
    {
                return 0;
           
    }
    if (val == "b")
    {
                return 1;
           
    }
    if (val == "c")
    {
    return 2;
           
    }
        return -1;
}

int cmpfunc(const void *a, const void *b)
{
        return (*(int *)a - *(int *)b);
}

void search(int quant, int pinos[3][], int op1, int op2)
{
        int disc1;
        int coord;
        for (int i = 0; i < quant; i++)
    {
                if (pinos[op1][i] != 0)
        {
                        disc1 = pinos[op1][i];
                        pinos[op1][i] = 0;
                        coord = i;
                        break;
                   
        }
           
    }
        for (int i = quant - 1; i >= 0; i--)
    {
                if (pinos[op2][i] == 0)
        {
                        if (pinos[op2][quant - 1] == 0 || pinos[op2][i + 1] < disc1)
            {
                                pinos[op2][i] = disc1;
                                qsort(pinos[op2], quant, sizepf(int), cmpfunc);
                           
            }
            else
            {
                                pinos[op1][coord] = disc1;
                                printf("Nao e possivel inserir um disco maior que outro menos na mesma columa/n!");
                                system("pause");
                           
            }
                        break;
                   
        }
           
    }
}

int main()
{
        int quant;
        printf("Digite a quantidade de discos que deseja operar: ");
    scanf("%d", &quant");
    int pinos[3][quant];
    for(int i = 0; i < 3; i++){
                if (i = 0)
        {
                        for (int j = 0; j < quant; j++)
            {
                                pinos[0] = j + 1;
                           
            }
                   
        }
        else
        {
                        for (int j = 0; j < quant; j++)
            {
                                pinos[i][j] = 0;
                           
            }
                   
        }
            }
    int fim = 0
    char opcao1, opcao2;
    int op1, op2;
    while(fim = 0){
                situacao(quant, pinos);
        printf("\n    A    B    C\n\n);
        printf("Escolha primeiro a coluna que deseja remover um disco: ");
        scanf("%c", &opcao1);
        op1 = comp(tolower(opcao1));
        if(op1 != -1){
                         printf("Agora escolha a coluna que deseja inserir o disco removido: ");
                         scanf("%c", &opcao2);
                         op2 = comp(tolower(opcao2));
                         if (op2 != -1)
            {
                                 if (op1 != op2)
                {
                                         search(quant, pinos, op1, op2);
                                    
                }
            
            }
            else
            {
                printf("Pino nao existente!");
                system("pause");
            }
         } else {
            printf("Pino nao existente!");
            system("pause"); } if(pinos[1][0] != 0 || pinos[2][0] != 0){
            system("cls");
            printf("Parabens, voce moveu a torre inteira para outra coluna!");
            fim++; }}
}