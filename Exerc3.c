/*Implemente um programa em C que utiliza a estrutura
apresentada para implementar uma lista. O programa
deve mostrar ao usuario duas opc¸ ´ oes. Se o usu ˜ ario ´
escolher 1, a lista deve ser impressa; se escolher 2, ele
deve entrar com o valor do conteudo do novo elemento da ´
lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} celula;

void inserir (celula **hat, int x){
    celula *nova = (celula*) malloc (sizeof(celula));
    nova ->valor = x;
    if (!*hat)
    {
        nova->prox = NULL;
        *hat = nova;
    }
        nova->prox = *hat;
        *hat= nova;
}

void exibir (celula *LE){
    celula *i;
    for (i= LE; i != NULL; i = i->prox)
    {
        printf(" %d", i->valor);
    }
    printf("\n");
}

int main(){
    celula *Vetor = NULL;
    int n = -1;
    while(n != 3)
    {
        printf("1 - Inserir\n2-Exibir\n3- Finalizar\n");
        scanf("%d", &n);
        if (n == 1)
        {
            int x;
            printf("Digite o numero que ira inserir");
            scanf("%d", &x);
            inserir(&Vetor, x);
        }
        else if (n == 2) exibir(Vetor);
        else if (n == 3)  printf("Finalizando Programa");
        else printf("Digite um valor valido!");
    }
   return 0;
}
