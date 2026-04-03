#include "../Headers/Headers.h"

int producto(int,int);

int main (void){
    int num;
    int num2; 

    printf("Ingrese el numero a multiplicar: \n");
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

int producto(int a,int b){
    if(b == 1){
       return a; 
    }
    else if(b<0){
       return -producto(a, -b);
    }
    return a + producto(a,b-1);
}

