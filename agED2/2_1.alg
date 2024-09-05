
(2.1)

Procedimento Insere(Lista, n, x):
    aux := 0
    para i de 1 até n+1 faca:
        se x < Lista[i] e busca(x) = 0 então:
            aux := Lista[i]
            Lista[i] := x
            para j de (i+1) até (n+1) faça:
                aux2 := Lista[j]
                Lista[j] := aux
                aux := aux2
            busca := 1
    se busca = 0 então:
        Lista[n] := x
fim funcao


Procedimento Remove(Lista,n,x)
    para i de 1 ate n faca
        se x = Lista[i]
            para j de i ate n faca
                Lista[j] = Lista[j+1]
            fim para
            n := n-1
            i := i-1
fim funcao


(2.5)

Cmedia = p x Cpar + 2p x Cimpar

onde:
    Cpar é a complexidade media de busca por uma chave par
    Cimpar é a complexidade media por uma chave impar
    p é a probabilidade de achar uma chave par
    2p é a probabilidade de achar uma chave impar
fim onde


(2.6)
    //-insersao : o nó a ser inserido e a extremidade desejada

(A)    Insersao(x,extremidade,n,lista)
        aux :=0
        i:=1
        se extremidade = 1 então //para inicio
            aux := lista[i]
            lista[i]=x
            n :=n+1
            para i de 1  ate n+1 faca
                aux2 = lista[i+1]
                lista[i+1] = aux
                aux = aux2
        senao +
            aux := lista[n]
            lista[n] = x
            para i de n ate 1 passo i:=-1 faca
                aux2 = lista[i-1]
                lista[i-1] = aux
                aux = aux2
        fim se
fim procedimento 

(B)        Remove(extermidade,n,lista)
            se extremidade = 2 faca //final
                lista[n] := nulo
            senao
                lista[1] = nulo
                n:= n-1
                para i de 1 ate n faca
                   lista[i] = lista[i+1]
                fim para
            fim se
        fim procedimento


(2.9)

    //insersao lista encadeada circular
    // ↑
    // λ

    InsersaoListaCircular(x,lista)
        aux := 0
        Aloca(novoNo)
        novoNo↑.num := x
        se lista = nulo entao
            lista := novoNo
            lista↑.prox := lista
        senao
            aux := novoNo
            novoNo↑.prox := lista↑.prox
            lista↑.prox := aux
    fim procedimento

    RemoveListaCircular(x,lista,n)
        aux := 0
        

(IntercecSimplesEncadeada)

    ValorIguaisListas(lA,lB)
        Aloca(lD)
        copia_A = lA
        enquanto copia_A <> λ faca
            copia_B = lB
            enquanto copia_B  <> faca
                se copia_A↑.num = copia_B↑.num entao
                    aux = lD
                    cont := 0
                    enquanto aux <> λ
                        se aux↑.num = copia_B↑.num
                            cont :=1    
                        aux:= aux↑.prox
                    fim enquanto
                    se cont <> 1 entao
                        lD := copia_B↑.num
                        lD := lD↑.prox
                copia_B := copia_B↑.prox
            fim enquanto
            copia_A := copia_A↑.prox
        fim enquanto
        return lD









