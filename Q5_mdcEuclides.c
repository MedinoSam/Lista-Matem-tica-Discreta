/* Escrever um programa para determinar o mdc de dois números com base no Al-
goritmo de Euclides. */

#include <stdio.h>

int mdc_euclides(int n1, int n2)
{
    int q = n1 / n2;
    int resto = n1 - (q * n2);
    printf("%d = %d - %d * %d\n", resto, n1, q, n2);
    if (resto == 0)
    {
        return n2;
    }
    else
    {
        return mdc_euclides(n2, resto);
    } 
}

int prox_euclides(int n1, int n2)
{
    int q = n1 / n2;
    int resto = n1 - (q * n2);
    if (resto == 0)
    {
        return 0;
    }
    else
    {
        /* code */
    }
    
    
}

int main()
{
    int n1, n2;

    printf("Digite dois números inteiros e te direi o MDC entre eles: ");
    scanf("%d%d", &n1, &n2);

    if (n2 > n1)
    {
        int aux = n1;
        n1 = n2;
        n2 = aux;
    }

    int mdc; 
    mdc = mdc_euclides(n1, n2);

    printf("O MDC entre %d e %d é %d\n", n1, n2, mdc);

}
