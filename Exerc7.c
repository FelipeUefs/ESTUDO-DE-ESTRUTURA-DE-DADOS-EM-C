
/*Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.*/
#include <stdio.h>

typedef struct node{
    int valor;
    struct node *prox;
}celula;

int crescente (celula *LE)
{
    celula *aux = LE;
    while (aux->prox != NULL)
    {
        if(aux->valor > aux->prox->valor)
        {
            return 0;
        }
    aux = aux->prox;
    }
    return 1;
}