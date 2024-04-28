#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista

struct No {
	
    int dado;
    struct No* prox;
};

// Definição da estrutura da lista com descritor

struct DescritorLista {
    struct No* inicio;
};

// Função para inicializar a lista com descritor

void inicializarLista(struct DescritorLista* lista) {
    lista->inicio = NULL;
}

// Função para criar um novo nó

struct No* criarNo(int dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = dado;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para inserir um nó na lista com descritor de forma ordenada

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

// Função para imprimir os elementos da lista com descritor

void imprimirLista(struct DescritorLista* lista) {
    struct No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para calcular o valor médio dos elementos da lista

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

// Função para remover o primeiro nó imediatamente superior ao valor médio

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


