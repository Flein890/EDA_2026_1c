#include "tp_1_recursividad.h"
#include <stdio.h>
#include <stdlib.h>


int fibo(int);

int main (void){

    int num;

    printf("Ingrese un numero fibo(n): \n");
    int esValido = scanf("%d",&num);

    while(!esValido){
        printf("INCORRECTO. Ingrese un numero fibo(n): \n");
        while(getchar() == '\n');
        esValido = scanf("%d",&num);
    }

    int fiboo = fibo(num);
    printf("%d",fiboo);
    return false;
}

int fibo(int a){
    if(a <=1){ //caso base, para que no calcule fibo(-1) + fibo(-2), etc.
        return a;
    }else
    {
    return fibo(a-1) + fibo(a-2); //caso recursivo por definicion matematica de fibonacci. Fn = Fn-1 + Fn-2
    }
};