
    Max(a,b)
        se a > b
            retorna a
        retorna b

    Altura(PT)
        se pt == λ
            retorna 0
        retorna 1+ Max(Altura(pt->esq),Altura(pt->dir));

    Verifica_AVL(PT,->f)


        
