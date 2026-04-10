#include "tp_1_recursividad.h"
#include <stdio.h>


int main (void){

    int num;
    int resultado;
    printf("Ingrese un NUMERO para saber si es divisible por 7: ");
    resultado = scanf("%d",&num);
    while(resultado == 0){
        printf("INVALIDO\n");
        printf("Ingrese un NUMERO para saber si es divisible por 7: ");
        while (getchar() != '\n'); // limpiar buffer
        resultado = scanf("%d",&num);
    }
    
    bool evelda = divisiblePor7(num);
    printf("\n\n");
   printf("%s",evelda ? "true" : "false"); //uso el operador ternario, ya que bool en c toma valores de 0 y 1.
    return 0;
}

bool divisiblePor7(int n){
    if(n < 70){
        if(n%7 == 0){
            return true;
        }
        else{
            return false;
        }
    }

    //del numero, agarrar el ultimo digito y separarlo, multiplicarlo por dos y restarlo a lo que quedo del numero

    int numAux = n%10;//como es el resto me da el ultimo digito
    numAux = numAux * 2;

    n = n/10; //le saco el ultimo digito

    int aux = n - numAux; 

    //printf("n-> %d\n",n);
    //printf(" aux -> %d",numAux);

return divisiblePor7(aux);
};
