#include <stdio.h>
#include <stdlib.h>

int Addtic(int n)
{
    if (n > 0)
    {
        int total = n + Addtic(n - 1);
        return total;
    }
    return 0;
}

int main()
{

    int n = 5;

    printf("\nSOMA: %d\n", Addtic(n));
    return 0;
}