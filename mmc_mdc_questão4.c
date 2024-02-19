#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


// função para potencias com expontes naturais.
int elevar ( int base, int potencia )
{
    if ( potencia == 0 )
    {
        return 1;
    }
    else if ( potencia == 1 )
    {
        return base;
    }
    else
    {
        return base * elevar ( base, potencia -1 );
    }
}

int main()
{
    //  Variaveis
    int n1, n2, primo, potencia, produto_fator_n1, produto_fator_n2;
    int mmc_local, mdc_local;
    int mmc = 1;
    int mdc = 1;
    int soma_resto;

    // Scanf do 2 numeros
    scanf("%d%d", &n1, &n2);

    // Soma dos dois para a condicao de parara do for principal
    soma_resto = n1 + n2;

    // for principal que avanca os numeros "primos" 
    // e verifica se os numeros foram totalmente decompostos 
    for ( primo = 2; soma_resto > 2; primo ++ )
    {
        // Verifica se o numetro n1 pode ser decomposto pelo "primo"
        // atual, divide o n1 pelo primo quando necessario, verifica o 
        // expoente do numero primo, e salva o avalor final do primo atual
        // elevado a seu expoente
        potencia = 0;
        for ( potencia = 0; n1 % primo == 0; potencia++ )
        {
            n1 = n1 / primo;
        }
        produto_fator_n1 = elevar( primo, potencia );
        
        // Mesma coisa do passo anterior mas agora com o n2.
        potencia = 0;
        for ( potencia = 0; n2 % primo == 0; potencia++ )
        {
            n2 = n2 / primo;
        }
        produto_fator_n2 = elevar ( primo, potencia );

        // Definicao de qual valor vai ser usado no mdc para a base atual
        if ( produto_fator_n1 < produto_fator_n2 )
        {
            mdc_local = produto_fator_n1;
        }
        else
        {
            mdc_local = produto_fator_n2;
        }

        // Definicao de qual valor vai ser usado no mmc para a base atual
        if ( produto_fator_n1 > produto_fator_n2 )
        {
            mmc_local = produto_fator_n1;
        }
        else
        {
            mmc_local = produto_fator_n2;
        }

        // Atribuindo os valores escolhidos no calculo final do mmc e mdc
        mdc = mdc * mdc_local;
        mmc = mmc * mmc_local;

        // calculando novamene a soma de n1 e n2 apos as suas divisoes pelo
        // primo atual
        soma_resto = n1 + n2;


    }

    //print mmc e mdc
    printf ("mmc: %d\n", mmc);

    printf ("mdc: %d\n", mdc);
    
    return 0;
}