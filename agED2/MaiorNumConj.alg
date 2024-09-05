

FindeHightNum(v,n,aux)

%The first aux valor, need to be 0%

    se n <0
     retorne aux
    se aux < v[n]
     aux := v[n]

retorne FindeHightNum(v,n-1,aux)



