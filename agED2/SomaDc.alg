
SomaDc(S,ini,fim)

    se ini = fim entao
        retorne S[ini]
    
    meio := (int +fim)/2   %fazer funcao piso%

    retorne SomaDc(S,ini,meio) + SomaDc(S,meio+1,fim)



%chamda externa%

SomaDc(S,1,n)