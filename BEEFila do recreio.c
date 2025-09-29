#include <stdio.h>
#include <stdlib.h>

void ordena (int *notas, int M){
    for (int i = 0; i < M -1; i++){
        int max = i;
        for (int j = i + 1; j < M; j++){
            if (notas[j] > notas[max]) max = j;
        }
        int temp = notas[i];
        notas[i] = notas[max];
        notas[max] = temp;
    }
}

int comparacao (int *notas, int *original, int M){
    int contador = 0;
    for ( int i = 0; i < M; i++)
    {
        if (original[i] == notas[i])
            contador++;
    }
    return contador;
}

int main(){
int n;
int contador;
scanf("%d", &n);
for (int i = 0; i < n; i++)
    {
        int M;
        scanf("%d", &M);
        int *notas, *original;
        notas = (int *) malloc(M* sizeof(int));
        original = (int *) malloc(M* sizeof(int));
        
        for(int i = 0; i < M; i++){
            scanf("%d", &notas[i]);
            original[i] = notas[i];
        }
        ordena(notas, M);
        contador = comparacao(notas, original, M);
        printf("%d\n", contador);
        free(notas);
        free(original);
    }
}



