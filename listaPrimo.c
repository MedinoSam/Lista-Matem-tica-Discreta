/* Escrever um programa para listar números primos sequencialmente. Você deve
otimizar o programa para que ele liste o maior número possível de primos em 60
segundos. */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int ehprimo(int n, int i, int divisor){
    int resto = n % i;
    if(i > n){
        if(divisor == 2 || divisor == 1) printf("%d\n", n);
        else{}
    }
    else{
        if(resto == 0){
            return ehprimo(n, i+1, divisor+1);
        }else{
            return ehprimo(n, i+1, divisor);
        }
    }
}

int main(){
    int numero = 1;
    int resto, i, divisor, n;
    bool vdd = true;
    
    while(vdd == true){
        n = ehprimo(numero, 1, 0);
        numero = numero + 1;
        n = 0;
    }

    return 0;
}
