#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Escrever um programa para encontrar o inverso de a mod b.
int mdc(int a, int b){
    if(a%b==0){
        return b;
    }else{
        return mdc(b,a%b);
    }
}
/* int achaInversoModular(int classeX, int subM, int mOriginal)
{
     if((classeX*subM)%mOriginal ==1)
     {
         return classeX;
     }

     return achaInversoModular(classeX+1, subM, mOriginal);
} */

int inverse( int a, int b){
    int   i = 1;
    while ((a * i ) % b != 1) i++;
    return i;
}

int main() {
    int a, b;
    printf ("Temos uma congruencia do tipo a mod b\n");
    printf ("Queremos o valor de x tal que ax ≡ 1(mod b)\n");
    printf ("Digite os valores de a e b\n");
    scanf ("%d %d", &a, &b);
    if (mdc(a, b)!= 1)
    {
        printf ("ERRO!, eles precisam ser primos entre si\n");
    }
    else
    {
        int resultado = inverse(a, b);
        printf ("O inverso de %d mod %d eh %d\n", a, b, resultado);
    }



	return 0;
}