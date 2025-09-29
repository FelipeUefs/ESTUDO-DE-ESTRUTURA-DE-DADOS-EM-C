/*Um ponteiro pode ser usado para dizer a uma função onde ela deve depositar o resultado de seus cálculos. 
Escreva uma função hm que converta minutos em horas-e-minutos. A função recebe um inteiro mnts e os endereços de duas variáveis inteiras, digamos h e m, e a
tribui valores a essas variáveis de modo que m seja menor que 60 e que 60*h + m seja igual a mnts.  
Escreva também uma função main que use a função hm.*/

#include <stdio.h>

int hm (int mnts, int *h, int *m)
{
   printf("Digite as horas e minutos para verificar (Nessa ordem): ");
   scanf("%d", h);
   scanf("%d", m);
   int converte = 60 * (*h) + (*m);
   if (converte == mnts) return 1;
      return 0;
}

int main(){
   int h, m;  //Variáveis normais (não ponteiros)
   int mnts;
   printf("Digite os minutos totais: ");
   scanf("%d", &mnts);
   int verifica = hm(mnts, &h, &m);  // Passa os ENDEREÇOS das variáveis
   printf("Valor valido - %d", verifica);
}