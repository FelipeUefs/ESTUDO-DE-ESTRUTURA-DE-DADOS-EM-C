#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *ant;
    struct No *prox;
} No;

// Função para criar nó
No* cria_no(int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// Troca dois nós
void troca_nos(No **head, int x, int y) {
    if (x == y || *head == NULL) return;

    No *a = *head, *b = *head;

    // Busca nós
    while (a && a->valor != x) a = a->prox;
    while (b && b->valor != y) b = b->prox;

    if (!a || !b) return; // não achou algum

    // Troca anterior
    if (a->ant) a->ant->prox = b;
    else *head = b;

    if (b->ant) b->ant->prox = a;
    else *head = a;

    // Troca próximo
    if (a->prox) a->prox->ant = b;
    if (b->prox) b->prox->ant = a;

    // Troca os ponteiros dos nós
    No *tempAnt = a->ant;
    No *tempProx = a->prox;

    a->ant = b->ant;
    a->prox = b->prox;

    b->ant = tempAnt;
    b->prox = tempProx;
}

// Imprimir lista
void imprime_lista(No *head) {
    while (head) {
        printf("%d <-> ", head->valor);
        head = head->prox;
    }
    printf("NULL\n");
}

int main() {
    No *head = cria_no(1);
    head->prox = cria_no(2);
    head->prox->ant = head;
    head->prox->prox = cria_no(3);
    head->prox->prox->ant = head->prox;
    head->prox->prox->prox = cria_no(4);
    head->prox->prox->prox->ant = head->prox->prox;

    printf("Lista original:\n");
    imprime_lista(head);

    troca_nos(&head, 2, 4);

    printf("Lista apos trocar 2 e 4:\n");
    imprime_lista(head);

    return 0;
}
