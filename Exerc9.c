#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int valor;
    struct no *prox;
} celula;

//Inserir em Lista
void inserir (celula **LE, int x){
    celula*nova = malloc(sizeof(celula));
    nova->valor = x;
    if(!*LE){
        nova->prox = NULL;
        *LE = nova;
    }
    celula*tail = *LE;
    while(tail->prox != NULL){
        tail = tail->prox;
    }
    tail->prox = nova;
}
//remover de Lista
void remover (celula **LE){
    celula *head = *LE;
    *LE = head->prox;
    free(head);
}

void inserir_stack(celula**hat, int x){
    celula*nova = malloc(sizeof(celula));
    nova->valor = x;
    if (!*hat){
        nova->prox = NULL;
        *hat = nova;
    }
    else{
        nova->prox = *hat;
        *hat = nova;
    }
}
void remover_stack(celula **LE){
    celula *remover = *LE;
    *LE = remover->prox;
    free(remover);
}

  