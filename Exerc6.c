/*Escreva um programa que leia números reais e armazene-os em uma matriz A, alocada dinamicamente (usando malloc) e realize as
seguintes tarefas. Você deve fazer uma função para cada item:
a) Ache e "retorne" o maior e o menor elemento
da matriz; ok
b) Some cada elemento das linhas pares com o
maior valor, alterando a matriz; 
c) Some cada elemento das linhas ímpares com o
maior valor, alterando a matriz.*/
#include <stdlib.h>
#include <stdio.h>

float **criar (int c, int l){
    float **matriz;
    matriz = (float**) malloc(c * sizeof(float*));
    for(int i = 0; i < c; i++){
        matriz[i] = malloc (l * sizeof(float));
    }
    return matriz;
}

void alimentar(float **matriz, int c, int l){
    printf("Alimente a matriz: ");
    for (int i = 0; i < c; i++){
        for(int j = 0; j < l; j++){
            scanf("%f", &matriz[i][j]);
        }
    }
}

void max_min (float **matriz, int c, int l, float *max, float *min)
{   
    *max = matriz[0][0];
    *min = matriz[0][0];
    for (int i = 0; i < c; i++){
        for (int j = 0; j < l; j++){
            if (matriz[i][j] > *max) *max = matriz[i][j];
            if (matriz[i][j] < *min) *min = matriz[i][j];
        }
    }
    printf("Maior numero: %.2f\nMenor numero: %.2f", *max, *min);
}

void soma_pares(float **matriz, int c, int l, float max){
    for (int i = 0; i < c; i++)
    {  
        if ( i % 2 == 0)
        { 
            for (int j = 0; j < l; j++)
            {
                matriz[i][j] += max;
            }
        }
    }
}

void soma_impares (float **matriz,int c, int l, float min)
{
    for (int i = 0; i < c; i++)
    {  
        if ( i % 2 == 1)
        { 
            for (int j = 0; j < l; j++)
            {
                matriz[i][j] += min;
            }
        }
    }
}

int main(){
    float max, min;
    int c, l;
    printf("Digite o tamanho da sua matriz: ");
    scanf("%d %d", &c, &l);
    float **matriz = criar(c, l);
    alimentar(matriz, c, l);
    max_min(matriz, c, l, &max, &min);
    soma_pares(matriz, c, l, max);
    soma_impares(matriz, c, l, min);

    printf("\nMatriz resultante (valores ajustados):\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < l; j++) {
            printf("%10.3f", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < c; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}


