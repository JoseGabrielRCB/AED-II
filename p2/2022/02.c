#include <stdio.h>
#include <stdio.h>

typedef struct AVL
{
    struct AVL *dir,*esq;
    int key,bal;
}AVL;




int Verifica_AVL(AVL *pt_AVL){
    if (pt_AVL == NULL)
        return 1;
    
    if (pt_AVL->bal < 2 && pt_AVL->bal > -2)
    {
        if (pt_AVL->esq != NULL)
            Verifica_AVL(pt_AVL->esq);
        if (pt_AVL->dir != NULL)
            Verifica_AVL(pt_AVL->dir);
    }
    return 0;s
}




int main(){

}