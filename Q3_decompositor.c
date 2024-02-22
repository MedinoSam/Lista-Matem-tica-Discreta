#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // Variaveis
    int n, primo, potencia;

    printf("Digite o numero para ser decomposto:\n");

    // Scanf do numero que vai ser decomposto
    scanf("%d", &n);

    printf ("%d = ", n);

    // for que avcansa os "primos" e defirica se o numero já
    // foi totalmente decomposto
    for ( primo = 2; n > 1;  primo ++ )
    {
        // Verifica o numero pode ser dividido pelo primo atual, veridica
        // a potencia do primo e divide o numero pelo primo quando necessario
        for ( potencia = 0; n % primo == 0; potencia++ )
        {
            n = n / primo;
        }
        // print da decomposicao
        if ( potencia != 0 )
        {
            if ( n == 1 )
            {
                printf("%d^%d\n", primo, potencia);    
            }
            else
            {
                printf("%d^%d x ", primo, potencia);
            }
        }
    }
    
    return 0;
}
