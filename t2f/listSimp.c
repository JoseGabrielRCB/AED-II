#include <stdio.h>
#include <stdlib.h>

typedef struct ListSimp
{
    int num;
    struct ListSimp *prox;
} ListSimp;

int ExisteLista(ListSimp **list)
{
    if ((*list) == NULL)
        return 0;
    return 1;
}
void AddItem(ListSimp **list)
{
    int number = 0;
    printf("Qual o valor:\n");
    scanf("%d", &number);
    ListSimp *node = malloc(sizeof(ListSimp));
    node->num = number;
    node->prox = NULL;
    if ((*list) == NULL)
    {
        *list = node;
        return;
    }
    ListSimp *aux;
    aux = (*list);
    if (aux->num > number)
    {
        (*list) = node;
        node->prox = aux;
        return;
    }
    while (aux->prox != NULL)
    {
        if (aux->prox->num > number)
        {
            node->prox = aux->prox;
            aux->prox = node;
            return;
        }
        aux = aux->prox;
    }
    aux->prox = node;
}

void ImprimeList(ListSimp **list)
{

    ListSimp *it;
    it = (*list);
    if (ExisteLista(&it))
    {
        while (it != NULL)
        {
            printf("[%d]->", it->num);
            it = it->prox;
        }
        printf("\n");
        return;
    }
    printf("Sem lista\n");
}

void Busca(ListSimp **list)
{
    int number = 0;
    printf("Qual o valor de busca?\n");
    scanf("%d", &number);
    ListSimp *aux;
    aux = (*list);
    if (ExisteLista(&aux))
    {
        while (aux->prox != NULL)
        {
            if (aux->num == number)
            {
                printf("Existe\n");
                return;
            }
            aux = aux->prox;
        }
        if (aux->num == number)
        {
            printf("Existe\n");
            return;
        }

        printf("Nao existe\n");
        return;
    }
    printf("Nao exite lista");
    return;
}

void Remove(ListSimp **list)
{
    int number = 0;
    printf("Qual o valor a ser removido\n");
    scanf("%d", &number);
    ListSimp *aux;
    aux = (*list);
    if (ExisteLista(&aux))
    {
        if (aux->num == number)
        {
            (*list) = (*list)->prox;
            
            free(aux);
            printf("valor removido\n");
            return;
        }
        while (aux->prox != NULL)
        {
            if (aux->prox->num == number)
            {
                ListSimp *aux2;
                aux2 = aux->prox;
                aux->prox = aux->prox->prox;
                free(aux2);
                printf("valor removido\n");
                return;
            }
            aux = aux->prox;
        }
    }
    printf("Sem lista\n");
    return;
}

int main()
{
    int loop = 1;
    ListSimp *node = NULL;
    while (loop == 1)
    {
        int escolha = 0;
        printf("1-alocar\n2-buscar\n3-remover-\n4-visualizar\n");
        scanf("%d", &escolha);
        if (escolha == 1) // aloca ordenado
        {
            AddItem(&node);
            system("clear");
        }
        if (escolha == 2) // busca
            Busca(&node);
        if (escolha == 4) // visualisar
            ImprimeList(&node);
        if (escolha == 3)
            Remove(&node);
    }
    return 0;
}
