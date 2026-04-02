#include "../Headers/Headers.h"

int main (void){

   bool evelda = divisiblePor7(32291);
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