#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do n� da lista

struct No {
	
    int dado;
    struct No* prox;
};

// Defini��o da estrutura da lista com descritor

struct DescritorLista {
    struct No* inicio;
};

// Fun��o para inicializar a lista com descritor

void inicializarLista(struct DescritorLista* lista) {
    lista->inicio = NULL;
}

// Fun��o para criar um novo n�

struct No* criarNo(int dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = dado;
    novoNo->prox = NULL;
    return novoNo;
}

// Fun��o para inserir um n� na lista com descritor de forma ordenada

void inserirOrdenado(struct DescritorLista* lista, int dado) {
    struct No* novoNo = criarNo(dado);
    struct No* atual = lista->inicio;
    struct No* anterior = NULL;

    while (atual != NULL && atual->dado < dado) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novoNo->prox = lista->inicio;
        lista->inicio = novoNo;
    } else {
        anterior->prox = novoNo;
        novoNo->prox = atual;
    }
}

// Fun��o para imprimir os elementos da lista com descritor

void imprimirLista(struct DescritorLista* lista) {
    struct No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Fun��o para calcular o valor m�dio dos elementos da lista

float calcularMedia(struct DescritorLista* lista) {
    float soma = 0;
    int quantidade = 0;
    struct No* atual = lista->inicio;
    while (atual != NULL) {
        soma += atual->dado;
        quantidade++;
        atual = atual->prox;
    }
    return soma / quantidade;
}

// Fun��o para remover o primeiro n� imediatamente superior ao valor m�dio

void removerPrimeiroNoAcimaDaMedia(struct DescritorLista* lista, float media) {
    struct No* atual = lista->inicio;
    struct No* anterior = NULL;

    while (atual != NULL && atual->dado <= media) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            lista->inicio = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
    }
}

int main() {
    struct DescritorLista lista;
    inicializarLista(&lista);

    int numNos;
    printf("Quantos nos voce deseja inserir na lista? ");
    scanf("%d", &numNos);

    int i;
    for (i = 0; i < numNos; i++) {
        int dado;
        printf("Insira o valor do no %d: ", i + 1);
        scanf("%d", &dado);
        inserirOrdenado(&lista, dado);
    }

    printf("Lista criada:\n");
    imprimirLista(&lista);

    float media = calcularMedia(&lista);
    printf("O valor medio dos elementos da lista e: %.2f\n", media);

    removerPrimeiroNoAcimaDaMedia(&lista, media);
    printf("Lista apos remover o primeiro no imediatamente superior a media:\n");
    imprimirLista(&lista);

    return 0;
}


