
//aluno 
PalindromoEncadeado(Lista)
    aux := lista↑.anterior
    aux2 := lista
    enquanto aux2 <> aux e 
        se aux↑.char <> aux2↑.char
            return 0
        aux := aux↑.anterior
        aux2 := aux2↑.prox



//Professor

PalindromoEncadeadoInterativo(Lista)
    se Lista = Lambida
        return True
    inicio := Lista
    fim := Lista↑.anterior
    enquanto inicio↑.ant <> fim e ini <> faca
        se inicio↑.chave <> fim↑.chave entao
            return False
        inicio := inicio↑.prox
        fim := fim↑.prox
    return True
fim procedimento

PalindromoEncadeadoRecursivo(ini,fim)
    se ini = Lambida entao  
        return True
    se ini↑.chave <> fim↑.chave entao
        return False
    se ini↑.ant = fim ou ini = fim entao
        return True
    PalindromoEncadeadoRecursivo(ini↑.prox,fim↑.ant)
