#include <stdio.h>

int main() {
    char linha[51]; 

    while (fgets(linha, sizeof(linha), stdin)) {
        int italico = 0; 
        int negrito = 0; 

        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '_') {
                if (!italico) {
                    printf("<i>");
                    italico = 1;
                } else {
                    printf("</i>");
                    italico = 0;
                }
            } else if (linha[i] == '*') {
                if (!negrito) {
                    printf("<b>");
                    negrito = 1;
                } else {
                    printf("</b>");
                    negrito = 0;
                }
            } else {
                putchar(linha[i]); 
            }
        }
    }

    return 0;
}
