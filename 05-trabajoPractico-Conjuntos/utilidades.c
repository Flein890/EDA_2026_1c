#include "utilidades.h"
#include <stdlib.h>
#include <stdio.h>

Conjunto ingresarConjunto(){
    int num = 0;
    int clave = 0;
    TipoElemento te;
    Conjunto c = cto_crear();

    printf("\nIngrese un conjunto\n");
    while(true){
        printf("\nCuantos valores quiere ingresar en el conjunto? (maximo %i): ",TAMANIO_MAXIMO);
        scanf("%i",&num);
        if(validarMaximo(num, TAMANIO_MAXIMO)){
            printf("\nEl numero excede el maximo");
        }
        else{
            break;
        }
    }
    printf("\nIngrese elementos para el conjunto: ");
    for(int i = 0; i<num; i++){
        scanf("%i",&clave);
        te = te_crear(clave);
        cto_agregar(c,te);
    }
    return c;
}

Lista ingresarListaDeConjuntos(){
    int num = 0;
    TipoElemento te;
    Lista l = l_crear();

    while(true){
        printf("\nCuantos conjuntos quiere ingresar en la lista? (maximo %i): ",TAMANIO_MAXIMO);
        scanf("%i",&num);
        if(validarMaximo(num, TAMANIO_MAXIMO)){
            printf("\nEl numero excede el maximo");
        }
        else{
            break;
        }
    }
    printf("\nIngrese conjuntos para la lista: ");
    for(int i = 0; i<num; i++){
        te = te_crear_con_valor(0,ingresarConjunto());
        l_agregar(l,te);
    }
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