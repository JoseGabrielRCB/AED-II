
FindInGrup(v,quant,n)

    se quant < 0
            retorne 0
    se (FindInGrup (v,quant-1,n) = 0)

            se v[quant] == n
            retorne 1

            senao
            retorne 0 
    senao 
        retorne 1
    
