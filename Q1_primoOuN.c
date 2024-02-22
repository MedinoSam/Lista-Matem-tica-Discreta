/*Escrever um programa que determina se um dado número inteiro é primo ou não. */


#include <stdio.h>
#include <math.h>

int main(){
    int numero, resto, divisor = 0;
    scanf("%d", &numero);
    int i;

    for(i = numero; i >= 1; i--){
        resto = numero % i;
        if(resto == 0){
            divisor++;
        }
    }

    if(divisor > 2){
        printf("o numero %d nao eh primo\n", numero);
    }else{
        printf("o numero %d eh primo\n", numero);
    }

    return 0;
}
