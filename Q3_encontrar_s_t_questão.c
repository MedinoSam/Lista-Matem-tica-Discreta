#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void falador_s_t ( int a, int b, int s_aux_1, int s_aux_2, int t_aux_1, int t_aux_2 )
{

    int quoci, resto, s_atual, t_atual;

    quoci = a / b;
    resto = a % b;

    s_atual = s_aux_1 - ( s_aux_2 * quoci );
    t_atual = t_aux_1 - ( t_aux_2 * quoci);

    if ( ( b % resto ) == 0 )
    {
        printf("s = %d e t = %d\n", s_atual, t_atual);
    }
    else
    {
        a = b;
        b = resto;

        s_aux_1 = s_aux_2;
        s_aux_2 = s_atual;

        t_aux_1 = t_aux_2;
        t_aux_2 = t_atual;

        falador_s_t ( a, b, s_aux_1, s_aux_2, t_aux_1, t_aux_2 );
    }

}


int main() 
{
    int a, b;

    printf("Digite o valor de a:\n");

    scanf("%d", &a);

    printf("Digite o valor de b:\n");

    scanf("%d", &b);

    falador_s_t ( a, b, 1, 0, 0, 1 );
    
    return 0;
}
