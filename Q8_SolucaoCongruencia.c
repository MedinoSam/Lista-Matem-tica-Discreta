#include <stdio.h>

int mdc_euclides(int a, int m)
{
    int q = a / m;
    int resto = a - (q * m);
    if (resto == 0)
    {
        return m;
    }
    else
    {
        return mdc_euclides(m, resto);
    } 
}

int qtde_solucoes(int mdc, int b)
{
    if (b % mdc == 0)
    {
        return mdc;
    }
    else
    {
        return 0;
    }
}

//simplificar

int inverse(int a, int m){
    int   i = 1;
    while ((a * i) % m != 1) i++;
    return i;
}

//verificar se o x inicial ta dentro de 0 < x < m

void imprimir_solucoes(int x0, int m, int k, int mdc)
{
    while (k <= mdc - 1)
    {
        int x = x0 + m * k;
        printf("X%d = %d + %d * %d = %d\n", k+1, x0, m, k, x);
        k += 1;
    }
}

int main()
{
    int a, b, m;
    printf("Vamos calcular uma congruência linear!\nDigite os valores de a, b e m, respectivamente: ");
    scanf("%d%d%d", &a, &b, &m);

    int mdc_principal = mdc_euclides(a, m);

    int qtde = qtde_solucoes(mdc_principal, b);

    if (qtde == 0)
    {
        printf("ERRO!, não existem soluções.\n");
    }
    else if (qtde == 1)
    {
        int inverso = inverse(a, m);
        int solucao_principal = b * inverso;

        if (solucao_principal <= 0 || solucao_principal >= m)
        {
            solucao_principal = solucao_principal % m;
        }
        
        printf("O valor de x é %d.\n", solucao_principal);
    }
    else
    {
        //precisa simplificar pois mdc(a,m) eh maior que 1

        a = a / mdc_principal;
        b = b / mdc_principal;
        m = m / mdc_principal;

        int mdc_simplificada = mdc_euclides(a, m);

        int inverso = inverse(a, m);
        int solucao_principal = b * inverso;

        if (solucao_principal <= 0 || solucao_principal >= m)
        {
            solucao_principal = solucao_principal % m;
        }

        imprimir_solucoes(solucao_principal, m, 0, mdc_principal);
    }

    return 0;
}