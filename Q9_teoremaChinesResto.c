#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// encontrar a solucao de um sistema de congruencia linear usando o teorema chines do resto.
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
    int r1, m1, r2, m2, r3, m3, superM, subM1, subM2, subM3;
    printf ("Temos um sistema do tipo x ≡ r1(mod m1), x ≡ r2(mod m2), x ≡ r3(mod m3)\n");
    printf ("Digite os valores de r1, m1, r2, m2, r3, m3, respectivamente\n");
    scanf ("%d %d", &r1, &m1);
    scanf ("%d %d", &r2, &m2);
    scanf ("%d %d", &r3, &m3);
    superM = m1*m2*m3;
    subM1 = superM/m1;
    subM2 = superM/m2;
    subM3 = superM/m3;
    if (mdc(subM1, m1) == 1)
    {

    }
    else
    {
        printf ("ERRO! %d e %d nao sao comprimos\n", subM1, m1);
        return 0;
    }
    if (mdc(subM2, m2) == 1)
    {

    }
    else
    {
        printf ("ERRO! %d e %d nao sao comprimos\n", subM2, m2);
        return 0;
    }
    if (mdc(subM3, m3) == 1)
    {

    }
    else
    {
        printf ("ERRO! %d e %d nao sao comprimos\n", subM3, m3);
        return 0;
    }

    /* int s1 = achaInversoModular(1, subM1, m1);
    int s2 = achaInversoModular(1, subM2, m2);
    int s3 = achaInversoModular(1, subM3, m3); */

    int s1 = inverse(subM1, m1);
    int s2 = inverse(subM2, m2);
    int s3 = inverse(subM3, m3);

    int xZero = (subM1*r1*s1) + (subM2*r2*s2) + (subM3*r3*s3);
    int resultado = xZero%superM;
    printf ("O resultado do sistema eh: %d\n", resultado);

	return 0;
}
