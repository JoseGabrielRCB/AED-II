

SomarConjunto(v,quant)

    se quant > 0 
        final = v[quant] + SomarConjunto(v,quant-1)
        retorne final
    se n<0
        retorne 0