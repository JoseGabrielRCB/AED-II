
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gfx.h"

// structs
typedef struct ListSimp
{
    int num;
    struct ListSimp *prox;
} ListSimp;

typedef struct listCirc
{
    int num;
    struct listCirc *prox;
} listCirc;

typedef struct listaDouble
{
    int num;
    struct listaDouble *prox;
    struct listaDouble *ant;

} listaDouble;

typedef struct Head
{
    listaDouble *inicio;
    listaDouble *fim;
    int tamanho;
} Head;

typedef struct fila
{
    int num;
    struct fila *prox;
} filaStrc;

typedef struct PilhaStruc
{
    int num;
    struct PilhaStruc *prox;
} PilhaStruc;

// funcoes gfx

void Arrow(int x1, int y1, int x2, int y2)
{
    gfx_line(x1, y1, x2, y2);

    // Desenha a cabeça da seta
    gfx_line(x2, y2, x2 - 10, y2 + 5);
    gfx_line(x2, y2, x2 - 10, y2 - 5);
}

void ReverseArrow(int x1, int y1, int x2, int y2)
{
    gfx_line(x1, y1, x2, y2);

    // Desenha a cabeça da seta
    gfx_line(x2, y2, x2 + 10, y2 - 5);
    gfx_line(x2, y2, x2 + 10, y2 + 5);
}

void LimpaGfx()
{
    gfx_clear();
    gfx_paint();
}

void ImpressaoGfxSimp(int num, int cont)
{
    char texto[999];
    sprintf(texto, "%d", num);

    // Desenha um retângulo
    int x1 = 7 + cont * 130;
    int y1 = 7;
    int x2 = 100 + cont * 130;
    int y2 = 75;
    gfx_rectangle(x1, y1, x2, y2);

    // Desenha uma linha vertical dentro do retângulo
    int line = x1 + 68; // Ajustando a linha vertical para dentro do retângulo
    gfx_line(line, 10, line, 75);

    // Desenha o texto
    int numX = x1 + 13;
    int numY = 50;
    gfx_text(numX, numY, texto);

    // Se não for o último retângulo, desenha a seta para o próximo retângulo
    if (cont > 0)
    {
        int auxX2 = 100 + (cont - 1) * 130;
        int arrow_y = (y1 + y2) / 2;
        Arrow(auxX2, arrow_y, x1, arrow_y);
    }

    gfx_paint();
}

void ImpressaoGfxDouble(int num, int cont)
{
    char texto[999];
    sprintf(texto, "%d", num);

    // Desenha um retângulo
    int x1 = 7 + cont * 130;
    int y1 = 7;
    int x2 = 100 + cont * 130;
    int y2 = 75;
    gfx_rectangle(x1, y1, x2, y2);

    // Desenha uma linha vertical dentro do retângulo
    int line = x1 + 68; // Ajustando a linha vertical para dentro do retângulo
    gfx_line(line, 10, line, 75);

    // Desenha o texto
    int numX = x1 + 13;
    int numY = 50;
    gfx_text(numX, numY, texto);

    // Se não for o último retângulo, desenha a seta para o próximo retângulo
    if (cont > 0)
    {
        int auxX2 = 100 + (cont - 1) * 130;
        int arrow_y = (y1 + y2) / 2;
        Arrow(auxX2, arrow_y, x1, arrow_y);
        ReverseArrow(x1, arrow_y, auxX2, arrow_y);
        // gfx_line(x1,arrow_y/2,)
    }

    gfx_paint();
}

void ImpressaoGfxPilha(int num, int cont)
{
    char texto[999];
    sprintf(texto, "%d", num);

    // Desenha um retângulo
    int x1 = 7 + cont * 130;
    int y1 = 7;
    int x2 = 100 + cont * 130;
    int y2 = 75;
    gfx_rectangle(x1, y1, x2, y2);

    // Desenha uma linha vertical dentro do retângulo
    int line = x1 + 68; // Ajustando a linha vertical para dentro do retângulo
    gfx_line(line, 10, line, 75);

    // Desenha o texto
    int numX = x1 + 13;
    int numY = 50;
    gfx_text(numX, numY, texto);

    // Se não for o último retângulo, desenha a seta para o próximo retângulo
    if (cont > 1)
    {
        int auxX2 = 100 + (cont - 1) * 130;
        int arrow_y = (y1 + y2) / 2;
        Arrow(auxX2, arrow_y, x1, arrow_y);
    }

    gfx_paint();
}

void LinhaCircGfx(int x2, int y2) //linha do incio ao fim dos nos
{
    gfx_line(35, 100, x2, y2 + 100);
    gfx_paint();
}

void ImpressaoGfxCirc(int num, int cont)
{
    char texto[999];
    sprintf(texto, "%d", num);

    // Desenha um retângulo
    int x1 = 7 + cont * 130;
    int y1 = 7;
    int x2 = 100 + cont * 130;
    int y2 = 75;
    gfx_rectangle(x1, y1, x2, y2);

    // Desenha uma linha vertical dentro do retângulo
    int line = x1 + 68; // Ajustando a linha vertical para dentro do retângulo
    gfx_line(line, 10, line, 75);

    // Desenha o texto
    int numX = x1 + 13;
    int numY = 50;
    gfx_text(numX, numY, texto);

    // Se não for o último retângulo, desenha a seta para o próximo retângulo
    if (cont > 0)
    {
        int auxX2 = 100 + (cont - 1) * 130;
        int arrow_y = (y1 + y2) / 2;
        Arrow(auxX2, arrow_y, x1, arrow_y);
    }
    gfx_paint();
}

// funcoes pilha
int ExistPilha(PilhaStruc **pilha) //verifica se tem pilha
{
    if ((*pilha) == NULL)
        return 0;
    return 1;
}

void ImprimeTudoPilha(PilhaStruc **pilha)
{
    int cont = 1;
    PilhaStruc *aux = (*pilha);
    if (ExistPilha(&aux) == 1)
    {

        ImpressaoGfxPilha(aux->num, cont); //imprime o prmimeiro no
        cont++;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
            ImpressaoGfxSimp(aux->num, cont); //impre os nos
            cont++;
        }
        system("clear");
    }
}

void VerTopoPilha(PilhaStruc **pilha) //ve o topo da pilha
{
    PilhaStruc *aux = (*pilha);
    if (ExistPilha(&aux))
    {
        printf("top->[%d]\n", (*pilha)->num);
        return;
    }
    printf("Nao exist lista\n");
}

void AddPilha(PilhaStruc **pilha) // adiona na pilha
{
    int num = 0;
    PilhaStruc *NewPilha = malloc(sizeof(PilhaStruc)); //aloca novo no
    printf("Qual o valor a ser adicionado?\n");
    scanf("%d", &num);
    NewPilha->num = num;
    NewPilha->prox = NULL; 
    if ((*pilha) == NULL)
    {
        (*pilha) = NewPilha; //caso seja o primeiro no
        return;
    }
    NewPilha->prox = (*pilha); //adiciona nos proximos nos
    (*pilha) = NewPilha;
    printf("Valor %d adiconado\n", num);
}

void RemovePilha(PilhaStruc **pilha)
{
    if ((*pilha) != NULL)
    {
        PilhaStruc *aux = (*pilha); 
        (*pilha) = (*pilha)->prox;
        free(aux); //rmeove valor da pilha
        return;
    }
    return;
}
// funcoes de fila

void RemoverFila(filaStrc **fila)
{
    if (*fila == NULL)
    {
        printf("Fila vazia\n");
        return;
    }
    filaStrc *aux = *fila;
    (*fila) = (*fila)->prox;
    free(aux); //rmeove valor da fila
}

int isEmptyfila(filaStrc **fila) //verifica fila vazia ou nao
{
    if ((*fila) == NULL)
        return 0;
    return 1;
}

void printfila(filaStrc **fila) //impime a fila
{
    filaStrc *aux = (*fila);
    if (isEmptyfila(&aux))
    {
        printf("[%d]\n", aux->num);
        return;
    }
    printf("Sem fila\n");
}

void ImprimeTudofila(filaStrc **fila) //imprime todos os valores da fila
{
    int cont = 0;
    filaStrc *aux = (*fila);
    ImpressaoGfxSimp(aux->num, cont);
    cont++;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
        ImpressaoGfxSimp(aux->num, cont);
        printf("\n[%d]", aux->num);
        cont++;
    }
    printf("\n");
}

void Inserefila(filaStrc **fila) 
{
    int num = 0;
    filaStrc *Newfila = malloc(sizeof(filaStrc)); //aloca no
    printf("Qual o valor a ser inserido?\n");
    scanf("%d", &num);
    Newfila->num = num;
    Newfila->prox = NULL;
    filaStrc *aux = (*fila);
    if ((*fila) == NULL)
    {
        (*fila) = Newfila; //caso seja o primero
        return;
    }
    while (aux->prox != NULL) //anda as casa  para alocar
        aux = aux->prox;
    aux->prox = Newfila;
}

// funcoes Listsimp

int ExisteListaSimp(ListSimp **list) //lista vazia ou nao
{
    if ((*list) == NULL)
        return 0;
    return 1;
}

void AddItemSimp(ListSimp **list) //Add item na Lista simples
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

void ImprimeListSimp(ListSimp **list) //imprime lista simples
{
    int cont = 0;
    ListSimp *it;
    it = (*list);
    if (ExisteListaSimp(&it))
    {
        while (it != NULL)
        {
            ImpressaoGfxSimp(it->num, cont);
            cont++;
            printf("[%d]->", it->num);
            it = it->prox;
        }
        printf("\n");
        return;
    }
    LimpaGfx();
    gfx_text(400, 300, "Nao tem lista");
    gfx_paint();
    printf("Sem lista\n");
}

void BuscaSimp(ListSimp **list) //bausca o valor na lista simples
{
    int number = 0;
    printf("Qual o valor de busca?\n");
    scanf("%d", &number);
    ListSimp *aux;
    aux = (*list);
    if (ExisteListaSimp(&aux))
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
    LimpaGfx();
    gfx_text(400, 300, "Nao tem lista");
    gfx_paint();
    printf("Nao exite lista");
    return;
}

void RemoveSimp(ListSimp **list) //Remove o valor da lista simples
{
    int number = 0;
    printf("Qual o valor a ser removido\n");
    scanf("%d", &number);
    ListSimp *aux;
    aux = (*list);
    if (ExisteListaSimp(&aux))
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
    gfx_text(400, 300, "Nao tem lista");
    gfx_paint();
    printf("Sem lista\n");
    return;
}

// funcoes ListCirc
int ExistCirc(listCirc **list) //exite lista circular ou nao
{
    if ((*list) == NULL)
        return 0;
    else
        return 1;
}

void PrintListCirc(listCirc **list) // imprime toda a lista Circ
{

    if ((*list) == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }
    listCirc *aux = (*list);
    int cont = 0;
    do
    {
        ImpressaoGfxCirc(aux->num, cont);
        cont++;
        aux = aux->prox;
    } while (aux != (*list));
    if (cont > 1)
    {
        int y1 = 7;//cria a ultima linha 
        int auxX2 = 100 + (cont - 1) * 130;
        gfx_line(35, y1 + 100, auxX2, y1 + 100);
        gfx_line(35, y1 + 100, 35, 75);
        gfx_line(auxX2, y1 + 100, auxX2, 75);
        gfx_line(35, 75, 45, 80);
        gfx_line(35, 75, 25, 80);
        gfx_paint();
    }

    printf("\n");
}

void AddCirc(listCirc **list, listCirc **stop) //Adiciona na lista circular
{
    int number;
    printf("Valor a ser inserido:\n");
    scanf("%d", &number);
    listCirc *node = malloc(sizeof(listCirc));
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

int SearchCirc(listCirc **list) //procula valor na lista circular
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
            {
                printf("Existe\n");
                return 1;
            }
            aux = aux->prox;
        } while (aux != (*list));
        printf("Nao existe na lista\n");
        return 0;
    }
    printf("Nao contem lista\n");
    return -1;
}

void RemoveCirc(listCirc **list) //remove valor d alista circular
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

// funcoes ListDouble
Head *inicializaListaDouble() //incializa cabeca da lista dupla
{
    Head *lista = malloc(sizeof(Head));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

int listaExisteDouble(Head *lista) //existe ou nao lista double
{
    return lista->tamanho != 0;
}

void imprimeListaDouble(Head *list) //imprime toda lista double
{
    Head *aux = list;
    if (listaExisteDouble(aux))
    {
        int cont = 0;
        listaDouble *atual = list->inicio;
        while (atual != NULL)
        {
            ImpressaoGfxDouble(atual->num, cont);
            cont++;
            printf("[%d]--> ", atual->num);
            atual = atual->prox;
        }
        printf("\n");
        return;
    }
    printf("Sem lista");
}

listaDouble *criaNoDouble(int num) //aloca novo no double
{
    listaDouble *novoNo = malloc(sizeof(listaDouble));
    novoNo->num = num;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    return novoNo;
}

void insereNoFinalDouble(Head *lista, int num) // add valor na lista double
{
    listaDouble *novoNo = criaNoDouble(num);
    if (lista->fim == NULL)
    { // Lista vazia
        lista->inicio = novoNo;
        lista->fim = novoNo;
    }
    else
    {
        lista->fim->prox = novoNo;
        novoNo->ant = lista->fim;
        lista->fim = novoNo;
    }
    lista->tamanho++;
}

listaDouble *busca(Head *lista, int num)
{
    if (listaExisteDouble(lista))
    {
        listaDouble *atual = lista->inicio;
        while (atual != NULL)
        {
            if (atual->num == num)
                return atual;
            atual = atual->prox;
        }
        return NULL;
    }
    printf("Nao existe lista\n");
    return NULL;
}

void removeNoDouble(Head *lista, listaDouble *no)
{
    if (no == NULL)
        return;

    if (no->ant != NULL)
        no->ant->prox = no->prox;
    else
        lista->inicio = no->prox;

    if (no->prox != NULL)
        no->prox->ant = no->ant;
    else
        lista->fim = no->ant;

    free(no);
    lista->tamanho--;
}

// funcoes Menu
void PauseMenu()
{
    printf("clique ENTER pra continuar");
    getchar();
    getchar();
}

void ERRO()
{
    getchar();
    system("clear");
    printf("ERRO VALOR INVALIDO\n");
    getchar();
    system("clear");
}

int Escolha(char comando[], int quantOpcoes, int opcoes[])
{
    int escolha = 0;
    while (1)
    {
        printf("%s\n", comando);
        scanf("%d", &escolha);
        for (int i = 0; i < quantOpcoes; i++)
            if (escolha == opcoes[i])
                return escolha;
        ERRO();
    }
    return 0;
}

// MENUS
ListSimp *MenuSimp(ListSimp *list)
{
    gfx_set_color(255, 255, 255);
    if (list == NULL)
    {
        gfx_text(400, 300, "Nao tem lista");
        gfx_paint();
    }
    else
        ImprimeListSimp(&list);
    int aux = 1;
    while (aux != 0)
    {
        system("clear");
        int condicoes[5] = {1, 2, 3, 4, 5};
        printf("Lista simplismente encadeada\n");
        switch (Escolha("1-insersao\n2-busca\n3-remocao\n4-Ver lista\n5-voltar", 5, condicoes))
        {
        case 1:
            printf("Insersao:\n");
            AddItemSimp(&list);
            LimpaGfx();
            ImprimeListSimp(&list);
            break;
        case 2:
            printf("Busca:\n");
            BuscaSimp(&list);
            PauseMenu();
            break;
        case 3:
            printf("Remocao:\n");
            RemoveSimp(&list);
            LimpaGfx();
            ImprimeListSimp(&list);

            break;
        case 4:
            printf("Ver lista\n");
            ImprimeListSimp(&list);
            PauseMenu();
            break;
        case 5:
            aux = 0;
            break;
        default:
            break;
        }
    }
    return list;
}

listCirc *MenuCirc(listCirc *list, listCirc **stop)
{
    int loop = 1;
    while (loop != 0)
    {
        listCirc *aux = (*stop);
        int escolhas[4] = {1, 2, 3, 4};
        switch (Escolha("1-insersao\n2-busca\n3-remocao\n4-voltar", 4, escolhas))
        {
        case 1:
            printf("Inserir:\n");
            AddCirc(&list, &aux);
            LimpaGfx();
            PrintListCirc(&list);
            (*stop) = aux;
            break;
        case 2:
            printf("Buscas:\n");
            LimpaGfx();
            PrintListCirc(&list);
            SearchCirc(&list);
            break;
        case 3:
            printf("Remover:\n");
            RemoveCirc(&list);
            LimpaGfx();
            PrintListCirc(&list);
            break;
        case 4:
            loop = 0;
            break;
        default:
            break;
        }
    }
    return list;
}

Head *MenuDoubleList(Head *cabeca)
{
    Head *list = cabeca;
    int loop = 1;
    while (loop != 0)
    {
        LimpaGfx();
        imprimeListaDouble(cabeca);
        int comando[4] = {1, 2, 3, 4}, valor = 0;
        switch (Escolha("1-Aloca\n2-busca\n3-remocao\n4-voltar", 4, comando))
        {
        case 1:
            printf("\nAloca:");
            printf("Digite um valor para inserir: ");
            scanf("%d", &valor);
            insereNoFinalDouble(list, valor);
            break;
        case 2:
            printf("Digite um valor para buscar: ");
            scanf("%d", &valor);
            listaDouble *no = busca(list, valor);
            if (no != NULL)
                printf("Valor encontrado.\n");
            else
                printf("Valor não encontrado.\n");
            break;
        case 3:
            printf("Digite um valor para remover: ");
            scanf("%d", &valor);
            listaDouble *remove = busca(list, valor);
            if (remove != NULL)
            {
                removeNoDouble(list, remove);
                printf("Valor removido.\n");
            }
            else
                printf("Valor não encontrado.\n");
            break;
        case 4:
            loop = 0;
            break;
        default:
            break;
        }
    }
    LimpaGfx();
    return list;
}

filaStrc *MenuFila(filaStrc *fila)
{
    int loop = 1;
    if (fila == NULL)
    {
        gfx_text(400, 300, "Nao tem fila");
        gfx_paint();
    }
    while (loop != 0)
    {
        int comando[4] = {1, 2, 3, 4};
        switch (Escolha("1-Aloca\n2-remocao\n3-ver\n4-voltar", 4, comando))
        {
        case 1:
            Inserefila(&fila);
            LimpaGfx();
            ImprimeTudofila(&fila);
            break;
        case 2:
            RemoverFila(&fila);
            if (isEmptyfila(&fila) == 1)
            {
                LimpaGfx();
                ImprimeTudofila(&fila);
            }
            else
            {
                LimpaGfx();
                gfx_text(400, 300, "Nao tem fila");
                gfx_paint();
            }
            break;
        case 3:
            ImprimeTudofila(&fila);
            break;
        case 4:
            LimpaGfx();
            loop = 0;
            break;
        default:
            break;
        }
    }
    return fila;
}

PilhaStruc *MenuPIlha(PilhaStruc *pilha)
{
    if (pilha == NULL)
    {
        gfx_text(400, 300, "Nao tem fila");
        gfx_paint();
    }
    else
        ImprimeTudoPilha(&pilha);
    int loop = 1;
    while (loop != 0)
    {
        int comandos[4] = {1, 2, 3, 4};
        switch (Escolha("1-aloca\n2-remover\n3-ver\n4-voltar", 4, comandos))
        {
        case 1:
            AddPilha(&pilha);
            LimpaGfx();
            ImprimeTudoPilha(&pilha);
            break;
        case 2:
            LimpaGfx();
            if (ExistPilha(&pilha) == 1)
            {
                RemovePilha(&pilha);
                ImprimeTudoPilha(&pilha);
            }
            else
            {
                gfx_text(400, 300, "Nao tem fila");
                gfx_paint();
            }
            break;
        case 3:
            ImprimeTudoPilha(&pilha);
            break;
        case 4:
            loop = 0;
            break;
        default:
            break;
        }
    }
    LimpaGfx();
    return pilha;
}

void menu()
{ // iniciar listas
    ListSimp *listSimples = NULL;
    listCirc *CicularList = NULL;
    filaStrc *fila = NULL;
    PilhaStruc *pilha = NULL;
    listCirc *stop = NULL;
    Head *cabeca = inicializaListaDouble();
    gfx_init(1200, 900, "T2");
    /// menu
    int loop = 1;
    while (loop == 1)
    {
        LimpaGfx();
        printf("MENU DE LISTAS\n");

        // menu de usuario
        int condicoes[6] = {1, 2, 3, 4, 5, 6}, escolha = 0;
        escolha = Escolha("1-lista Simplismente encadeada\n2-Lista Circular Simplismente encadeada\n3- LIsta duplamente encadeada com no cabeca\n4-Pilha\n5-Fila\n6-voltar", 6, condicoes);
        switch (escolha)
        {
        case 1:
            listSimples = MenuSimp(listSimples);
            break;
        case 2:
            CicularList = MenuCirc(CicularList, &stop);
            break;
        case 3:
            cabeca = MenuDoubleList(cabeca);
            break;
        case 5:
            fila = MenuFila(fila);
            break;
        case 4:
            pilha = MenuPIlha(pilha);
            break;
        case 6:
            loop = 0;
            gfx_quit();
            break;
        default:
            break;
        }
    }
}

int main()
{
    menu();
}
// clear