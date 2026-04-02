#include "../Headers/Headers.h"

int fibo(int);

int main (void){

    int res = fibo(3);
    printf("%d",res);

    system("pause");
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