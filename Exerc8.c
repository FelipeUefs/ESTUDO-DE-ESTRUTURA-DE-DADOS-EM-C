/*Escreva uma função que faça uma busca em uma lista encadeada crescente. Faça versões recursiva e iterativa*/

#include <stdio.h>

typedef struct node{
    int valor;
    struct node *prox;
}celula;

int busca (celula *LE, int x){
    if (!LE)
    {
        return 0;
    }
    while(LE->valor < x ){
        LE = LE->prox;
    }
    if (LE->valor == x) 
    {
        return 1;
    }
    return 0;
}

