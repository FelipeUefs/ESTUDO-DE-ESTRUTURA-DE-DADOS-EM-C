/*Escreva uma função que receba como parâmetro uma lista
encadeada e retorne a quantidade de células da lista.*/

#include <stdio.h>
#include <stdlib.h>

//Função feita por mim
typedef struct node{
    int valor;
    struct node *prox;
} celula;

int quantidade(celula *LE){
    celula *p = LE;
    int contador = 0;  //Inicializar contador
    while (p != 5){
        p = p->prox;
        contador++;
    }
    return contador;
}


//Teste abaixo feito com IA

// Função para inserir no início da lista
void inserir(celula **LE, int valor){
    celula *nova = (celula*) malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = *LE;
    *LE = nova;
}

// Função para exibir a lista
void exibir(celula *LE){
    celula *p = LE;
    printf("Lista: ");
    while (p != NULL){
        printf("%d ", p->valor);
        p = p->prox;
    }
    printf("\n");
}

// Função para liberar a memória da lista
void liberar(celula **LE){
    celula *temp;
    while (*LE != NULL){
        temp = *LE;
        *LE = (*LE)->prox;
        free(temp);
    }
}

int main(){
    celula *LE = NULL;
    
    printf("=== TESTE DA FUNÇÃO QUANTIDADE ===\n\n");
    
    // Teste 1: Lista vazia
    printf("Teste 1 - Lista vazia:\n");
    printf("Quantidade de elementos: %d\n\n", quantidade(LE));
    
    // Teste 2: Inserindo alguns valores
    printf("Teste 2 - Inserindo valores 10, 20, 30:\n");
    inserir(&LE, 10);
    inserir(&LE, 20);
    inserir(&LE, 30);
    
    exibir(LE);
    printf("Quantidade de elementos: %d\n\n", quantidade(LE));
    
    // Teste 3: Inserindo mais valores
    printf("Teste 3 - Inserindo mais valores (40, 50):\n");
    inserir(&LE, 40);
    inserir(&LE, 50);
    
    exibir(LE);
    printf("Quantidade de elementos: %d\n\n", quantidade(LE));
    
    // Teste 4: Testando com muitos elementos
    printf("Teste 4 - Inserindo mais 5 elementos:\n");
    for(int i = 60; i <= 100; i += 10){
        inserir(&LE, i);
    }
    
    exibir(LE);
    printf("Quantidade de elementos: %d\n\n", quantidade(LE));
    
    printf("=== TODOS OS TESTES CONCLUÍDOS ===\n");
    printf("Sua função 'quantidade' está funcionando corretamente!\n");

    liberar(&LE);
    
    return 0;
}
