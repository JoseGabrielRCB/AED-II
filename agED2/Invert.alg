


 %The parametrer i, need to be started with 0%

Invert(quant,v[],i)

    se i<quant
        aux = v[quant]
        v[quant] = v[i]
        v[i] = aux

        retorne Invert(quant-1,v,i+1)