
% IMplemente uma função recursiva soma(n), que calcule a somatoria dos n primeiros numeros inteiros%

Soma(n)
{
    se  n > 0 ent
    {
        int total := n + soma(n-1)
        retone total
    }

    se n<=0
    {
        retorne 0
    }

}