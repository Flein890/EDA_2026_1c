#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tp_conjunto.h"


//==============================EJERCICIO 4=================================



bool c_ej4_transitividad(Conjunto A, Conjunto B,Conjunto C){ //usar C
    if(cto_cantidad_elementos(A) > cto_cantidad_elementos(B)){
        return false;
    }

    Conjunto X = cto_diferencia(A, B);
    Conjunto Y = cto_diferencia(B, A);

    if(!cto_es_vacio(X)) return false;
    else if(cto_es_vacio(Y)) return false;

    free(X);
    free(Y);
    return true;
}


//==============================EJERCICIO 5=================================

Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){
    Conjunto X, Y, Z;

    X = cto_diferencia(A,B);
    Y = cto_diferencia(B,A);
    Z = cto_union(X, Y);

    free(X);
    free(Y);
    return Z;
}

//==============================EJERCICIO 6=================================
bool  c_ej6_subconjuntopropio (Conjunto A, Conjunto B){
    if(cto_cantidad_elementos(A) > cto_cantidad_elementos(B)){
        return false;
    }

    Conjunto X = cto_diferencia(A, B);
    Conjunto Y = cto_diferencia(B, A);

    if(!cto_es_vacio(X)) return false;
    else if(cto_es_vacio(Y)) return false;

    free(X);
    free(Y);
    return true;
}

//==============================EJERCICIO 7=================================




//==============================EJERCICIO 8=================================

bool c_ej8_soniguales(Conjunto A, Conjunto B){
    bool iguales = true;
    if(cto_cantidad_elementos(A) != cto_cantidad_elementos(B)){
        iguales = false;
    }

    Conjunto X = cto_diferencia(A, B);
    Conjunto Y = cto_diferencia(B, A);

    if(cto_cantidad_elementos(X) != 0 || cto_cantidad_elementos(Y) != 0){
        iguales = false;
    }

    free(X);
    free(Y);
    return iguales;
}

