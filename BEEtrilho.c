#include <stdio.h>

int verifica_permutacao(int N, int perm[]) {
    int pilha[N];
    int topo = -1;
    int atual = 1; // próximo vagão que chega
    for (int i = 0; i < N; i++) {
        int desejado = perm[i];

        // Empilha vagões até chegar no desejado
        while (topo == -1 || pilha[topo] != desejado) {
            if (atual > N) // acabou os vagões
                return 0;
            pilha[++topo] = atual++;
        }

        // Retira o vagão desejado da pilha
        topo--;
    }
    return 1;
}

void processa_bloco(int N) {
    while (1) {
        int perm[N];
        int fim_bloco = 0;

        // Lê permutação
        for (int i = 0; i < N; i++) {
            scanf("%d", &perm[i]);
            if (perm[i] == 0) {
                fim_bloco = 1;
                break;
            }
        }

        if (fim_bloco) break;

        // Verifica permutação
        if (verifica_permutacao(N, perm))
            printf("Yes\n");
        else
            printf("No\n");
    }

    printf("\n"); // linha em branco após cada bloco
}

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        processa_bloco(N);
    }

    return 0;
}
