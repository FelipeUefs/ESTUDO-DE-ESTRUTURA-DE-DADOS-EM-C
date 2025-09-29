#include <stdio.h>
#include <stdlib.h>

/*Matriz dinamica com alimentação automatica */
int main(){
    int **matriz;
    int c, L;
    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &c, &L);

    matriz = (int**) malloc(c * sizeof(int*));

    for (int i = 0; i < c; i++)
        {
            matriz[i] = malloc (L * sizeof(int));
        }
    
    // Alimenta a matriz automatica
    int valor = 0;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < L; j++){
            matriz[i][j] = valor++;  
        }
    }
    
    for(int i= 0; i < c; i++){
        for(int j = 0; j < L; j++){
            printf("%2d ", matriz[i][j]);  
        }
        printf("\n");
    }
    for (int i = 0; i < c; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    
}