/*Escreva uma função mm que receba um vetor inteiro v[0..n-1] e os endereços de duas variáveis inteiras, digamos min e max, 
e deposite nessas variáveis o valor de um elemento mínimo e o valor de um elemento máximo do vetor.  
Escreva também uma função main que use a função mm.*/

#include <stdio.h>
#include <stdlib.h>

void max_min (int *Vetor,int n, int *min, int *max)
{
    int i;
    *min = Vetor[0];
    *max = Vetor[0];
   for (i = 0; i< n; i++)
    {
        if (Vetor[i] < *min) *min = Vetor[i];
        if (Vetor[i] > *max) *max = Vetor[i];
    }
}

int main()
{
    int min, max;
    int *Vetor;
    int i, n;
    printf("Digite a quatidade de numeros: ");
    scanf("%d", &n);
    Vetor = (int*) malloc(n * sizeof(int));
    printf("Digite os números");
    for (i = 0; i < n; i++)
    {   
        printf("\nNumero %d: ", i + 1);
        scanf("%d", &Vetor[i]);
    }
    max_min(Vetor, n, &min, &max);
    printf("O min: %d Max: %d", min, max);
    free(Vetor);
}