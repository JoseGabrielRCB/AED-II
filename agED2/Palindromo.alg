
Palindromo(word,n,i)
    se( n<= 1)
        retorne 1
    
    se(Palindromo(word,n-1,i+1))
        se(word[n]== word[i+1])
            retorne 1
        senao
            retorne 0
        



Algoritimo
    escreval("Escreva uma palavra:")
    leia(word)
    Palindromo(word,n,0)

