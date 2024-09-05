#include <stdio.h>
#include <stdlib.h>

typedef struct listCirc
{
    int num;
    struct listCirc *prox;
} listCirc;

int ExistCirc(listCirc **list)
{
    if ((*list) == NULL)
        return 0;
    else
        return 1;
}

void PrintList(listCirc **list)
{
    if ((*list) == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }
    listCirc *aux = (*list);
    do
    {
        printf("[%d]--> ", aux->num);
        aux = aux->prox;
    } while (aux != (*list));
    printf("\n");
}

void AddCirc(listCirc **list, listCirc **stop)
{
    int number;
    printf("Valor a ser inserido:\n");
    scanf("%d", &number);

    listCirc *node = malloc(sizeof(listCirc));
    if (node == NULL)
    {
        perror("Erro ao alocar memória");
        exit(1);
    }
    node->num = number;

    if (*list == NULL)
    {
        // Lista está vazia, inicializar
        *list = node;
        *stop = node;
        node->prox = node; // Lista circular aponta para si mesma
        return;
    }

    listCirc *aux = *list;

    if (aux->num > number)
    {
        // Inserir no início e atualizar stop->prox
        node->prox = aux;
        *list = node;
        (*stop)->prox = node;
        return;
    }

    while (aux->prox != (*list))
    {
        if (aux->prox->num > number)
        {
            node->prox = aux->prox;
            aux->prox = node;
            return;
        }
        aux = aux->prox;
    }

    // Inserir no final e atualizar stop
    aux->prox = node;
    node->prox = *list;
    *stop = node;
}

int SearchCirc(listCirc **list)
{
    if (ExistCirc(&*list))
    {
        int number = 0;
        printf("Qual o valor de busca:\n");
        scanf("%d", &number);
        listCirc *aux = (*list);
        do
        {
            if (aux->num == number)
                return 1;
            aux = aux->prox;
        } while (aux != (*list));
        return 0;
    }
    printf("Nao contem lista\n");
    return -1;
}

void RemoveCirc(listCirc **list)
{
    if (!ExistCirc(list))
    {
        printf("Lista vazia\n");
        return;
    }
    int number;
    printf("Qual o valor a ser removido:\n");
    scanf("%d", &number);
    listCirc *it = *list;
    if (it->num == number)
    {
        if ((*list)->prox == *list)
        {
            free(*list);
            *list = NULL;
        }
        else
        {
            listCirc *aux = *list;
            while (it->prox != *list)
            {
                it = it->prox;
            }
            *list = (*list)->prox;
            it->prox = *list;
            free(aux);
        }
        printf("valor removido\n");
        return;
    }
    do
    {
        if (it->prox->num == number)
        {
            listCirc *aux2 = it->prox;
            it->prox = it->prox->prox;
            free(aux2);
            printf("valor removido\n");
            return;
        }
        it = it->prox;
    } while (it != *list);
    printf("Valor nao encontrado na lista\n");
}

int main()
{
    int loop = 1;
    listCirc *node = NULL;
    listCirc *stop = node;
    while (loop == 1)
    {
        int escolha = 0;
        printf("1-alocar\n2-buscar\n3-remover\n4-visualizar\n");
        scanf("%d", &escolha);
        if (escolha == 1)
        {
            AddCirc(&node, &stop);
            system("clear");
        }
        if (escolha == 4)
            PrintList(&node);
        if (escolha == 2)
        {
            int busca = SearchCirc(&node);
            if (busca == 1)
                printf("Valor encontrado\n");
            else if (busca == 0)
                printf("Valor nao encontrado\n");
        }
        if (escolha == 3)
            RemoveCirc(&node);
    }
}