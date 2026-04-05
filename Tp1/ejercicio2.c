#include "tp_1_recursividad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
    int num;
    int num2; 

    printf("\nIngrese el numero a multiplicar: \n");
    int num1Valido = scanf("%d",&num);
    while(num1Valido == 0){
        printf("Numero invalido, ingrese el numero a multiplicar: \n");
        while(getchar() == '\n');
        num1Valido = scanf("%d",&num);
    }

    printf("Ingrese por cuanto se quiere multiplicar: \n");
    int num2Valido = scanf("%d",&num2);
    while(num2Valido == 0){
        printf("Numero invalido, ingrese el numero a multiplicar: \n");
        while(getchar() == '\n');
        num2Valido = scanf("%d",&num2);
    }

    int res = producto(num,num2);
    printf("resultado: %d",res);
}

int producto(int m,int n){
    if(n == 1){
       return m; 
    }
    else if(n<0){
       return -producto(m, -n);
    }
    return m + producto(m,n-1);
}
