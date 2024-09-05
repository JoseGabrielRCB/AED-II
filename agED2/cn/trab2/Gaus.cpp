#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

void Imprime_Matrix(int tam, float **matrix)
{
    for (int i = 0; i < tam; i++)
    {
        for (int a = 0; a < tam; a++)
            cout << matrix[i][a] << " ";
        cout << endl;
    }
}

int main()
{
    int var = 0;
    while (1)
    {
        cout << "Quantas variaveis:\n";
        cin >> var;
        if (var <= 0)
        {
            system("clear");
            cout << "Valor Invalido\n";
            getchar();
        }
        else
            break;
    }
    float **Matrix = new float *[var];
    for (int i = 0; i < var; i++)
    {
        Matrix[i] = new float [var];
    }

    //float *Matrix = new float[var * var];
    cout << "Preencha as linhas da matrix\n";
    for (int i = 0; i < var; i++)
    {
        cout << "Linha " << i + 1 << endl;
        for (int a = 0; a < var; a++)
        {
            int num;
            cin >> num;
            Matrix[i][a] = num;
        }
        cout << endl;
    }

   Imprime_Matrix(var, Matrix);
    delete[] Matrix;
    return 0;
}
