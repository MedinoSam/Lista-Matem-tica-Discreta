#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mdc(int a, int b){
    if(a%b==0){
        return b;
    }else{
        return mdc(b,a%b);
    }
}

int inverso( int a, int b){
    int   i = 1;
    while ((a * i ) % b != 1) i++;
    return i;
}

int coprimos(int a, int b)
{
    if (mdc(a, b) == 1) // sao coprimos
    {
        return 1;
    }
    else
    {
        return 0; // nao sao coprimos
    }
}
//Pro teorema funcionar, todos os m precisam ser coprimos entre si
//utilizamos dois for para verificar se todos os indices no vetor sao primos entre si
int todosCoprimos(int mVetor[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++) // comparamos a posicao atual com o proximo, se sao primos entre si, blz
        {
            //como j=i+1, estamos comparando o valor da variavel no indice i, com o valor da variavel no indicie i+1, ou j, ou seja, o proximo valor do vetor
            if (coprimos(mVetor[i], mVetor[j]) == 0)
            {
                return 0; // pelo menos um nao eh coprimo
            }
        }
    }
    return 1; //sao todos coprimos
}
int loop(int vezes)
{
    int     restoVetor[100] = {};//armazena os restos
    int         mVetor[100] = {};//armazena os mod
    int    subEmeVetor[100] = {};//armazena os subM
    int   solucaoVetor[100] = {};//armazena as solucoes

    int superM = 1;
    int xZero  = 0;

    for (int i = 0; i<vezes; i++)
    {
        printf ("Temos um sistema do tipo x ≡ r1(mod m1), x ≡ r2(mod m2), x ≡ r3(mod m3)\n");
        printf ("Digite os valores de r1, m1, r2, m2, r3, m3, respectivamente\n");
        scanf ("%d %d", &restoVetor[i], &mVetor[i]);
        superM *= mVetor[i];
    }

    // verificamos se os valores recebidos dos modulos sao coprimos entre si

    if (todosCoprimos(mVetor, vezes) == 0)
    {
        printf ("ERRO! existem valores que  nao sao coprimos\n");
        return -5;
    }
    else
    {
        for (int i = 0; i<vezes; i++)
        {
            subEmeVetor[i] = superM/mVetor[i];
            solucaoVetor[i] = inverso(subEmeVetor[i], mVetor[i]);
            xZero+= subEmeVetor[i]*restoVetor[i]*solucaoVetor[i];
        }
        return xZero%superM;

    }

}

int main() {
    int vezes;
    scanf ("%d", &vezes);
    int resultado = loop(vezes);
    if (resultado == -5)
    {
        printf ("ERRO! verifique a entrada");
    }
    else
    {
        printf ("O resultado do sistema eh %d\n", resultado);
    }

	return 0;
}