#include<stdio.h>
#include <stdlib.h>
#include"tp_1_recursividad.h"

int* pedazos(int n, int b, int arreglo[], int* i);

int main(){
    int n;
    int b;
    printf("\nIngrese n: ");
    scanf("%i", &n);
    printf("\nIngrese b: ");
    scanf("%i", &b);
    if(b <= 1){
        printf("B no puede ser 0, 1 o un numero negativo");
    }
    else{
        int *arreglo = explosion(n, b);
        printf("\nLista con los pedazos: ");
        for(int i=1; i < arreglo[0]; i++){
            printf("%i ", arreglo[i]);
        }
    }
    return 0;
}

int* explosion (int n, int b){
    int *arreglo = malloc(sizeof(int));
    int i = 1;
    arreglo = pedazos(n, b, arreglo, &i);
    arreglo[0] = i; // Almaceno el indice para iterar en main() 
    return arreglo;
}

int* pedazos(int n, int b, int arreglo[], int* i){
    if(n <= b){
        (*i)++;
        arreglo = realloc(arreglo, (*i) * (sizeof(int)));
        arreglo[(*i)-1] = n;
        return arreglo;
    }
    if(n > b){
        pedazos(n/b, b, arreglo, i);
        pedazos(n-n/b, b, arreglo, i);
    }
}