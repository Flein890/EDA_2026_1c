#include "utilidades.h"
#include <stdlib.h>
#include <stdio.h>

Pila ingresarPila(){
    int num = 0;
    int clave = 0;
    TipoElemento te;
    Pila p = p_crear();

    printf("\nIngrese una pila\n");
    while(true){
        printf("\nCuantos valores quiere ingresar? (maximo 10): ");
        scanf("%i",&num);
        if(validarMaximo(num, TAMANIO_MAXIMO)){
            printf("\nEl numero excede el maximo: ");
        }
        else{
            break;
        }
    }
    for(int i = 0; i<num; i++){
        printf("\nIngrese clave para la pila: ");
        scanf("%i",&clave);
        te = te_crear(clave);
        p_apilar(p,te);
    }
    return p;
}

int ingresarEntero(){
    int num = 0;
    printf("\nIngrese un numero: ");
    scanf("%i",&num);
    return num;
}

bool validarMaximo(int num, int max){
    return num > max;
}