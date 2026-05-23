#include "tp_pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

//PROTOTIPOS
char* convertirEnCadena(Pila p);
void eliminarClaveRecursiva(Pila auxiliar, Pila nuevaPila, int clave);

// EJERCICIO 2

bool p_ej2_existeclave(Pila p, int clave){
    TipoElemento te;
    Pila auxiliar = p_crear();
    bool resultado = false;

    while(!p_es_vacia(p) && !resultado){
        te = p_desapilar(p);
        p_apilar(auxiliar,te);
        if(te->clave == clave){
            resultado = true;
        }
    }
    while(!p_es_vacia(auxiliar)){
        te = p_desapilar(auxiliar);
        p_apilar(p,te);
    }
    return resultado;
}

Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    int contador = 1;
    TipoElemento te;
    Pila auxiliar = p_crear();
    while(!p_es_vacia(p)){
        te= p_desapilar(p);
        p_apilar(auxiliar,te);
        if(posicionordinal == contador){
            p_apilar(p,x);
            break;
        }
        contador++;
    }
    while(!p_es_vacia(auxiliar)){
        te = p_desapilar(auxiliar);
        p_apilar(p,te);
    }
    return p;
}

Pila p_ej2_eliminarclave(Pila p, int clave){
    TipoElemento te;
    Pila auxiliar = p_crear();
    while(!p_es_vacia(p)){
        te= p_desapilar(p);
        if(te->clave != clave){
            p_apilar(auxiliar,te);
        }
        else{
            free(te);
            break;
        }
    }
    while(!p_es_vacia(auxiliar)){
        te = p_desapilar(auxiliar);
        p_apilar(p,te);
    }
    return p;
}

Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    if(pos1 == pos2){
        return p;
    }
    int contador = 0;
    int contador2 = 0;
    TipoElemento te,tePos1,tePos2;
    Pila auxiliar = p_crear();

    while(!p_es_vacia(p)){
        contador++;
        te = p_desapilar(p);
        p_apilar(auxiliar,te);
        if(pos1 == contador){
            tePos1 = te;
        }
        if(pos2 == contador){
            tePos2 = te;
        }
    }
    contador2 = contador;
    while(!p_es_vacia(auxiliar)){
        te = p_desapilar(auxiliar);
        if(pos1 == contador2){
            p_apilar(p,tePos2);
        }
        else if(pos2 == contador2){
            p_apilar(p,tePos1);
        }
        else if((pos2 != contador2) && (pos2 != contador2)){
            p_apilar(p,te);
        }
        contador2--;
    }
    return p;
}

Pila p_ej2_duplicar(Pila p){
    TipoElemento te;
    Pila duplicada = p_crear();
    Pila auxiliar = p_crear();
    if(p_es_vacia(p)){
        return duplicada;
    }
    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(auxiliar,te);
    }
    while(!p_es_vacia(auxiliar)){
        te = p_desapilar(auxiliar);
        p_apilar(p,te);
        p_apilar(duplicada,te);
    }
    return duplicada;
}

int p_ej2_cantidadelementos(Pila p){
    int contador = 0;
    TipoElemento te;
    Pila auxiliar = p_crear();
    if(p_es_vacia(p)){
        return contador;
    }
    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        contador++;
        p_apilar(auxiliar,te);
    }
    while(!p_es_vacia(auxiliar)){
        te = p_desapilar(auxiliar);
        p_apilar(p,te);
    }
    return contador;
}

// EJERCICIO 3

bool p_ej3_iguales(Pila p1, Pila p2){
    int contador = 0;
    bool resultado = true;
    TipoElemento te,te2,te3;
    Pila auxiliar = p_crear();

    if(p_ej2_cantidadelementos(p1) != p_ej2_cantidadelementos(p2)){
        resultado = false;
    }

    while(contador < p_ej2_cantidadelementos(p1) && resultado == true){
        for(int i=-1; i < contador; i++){
            te = p_desapilar(p1);
            p_apilar(auxiliar,te);
        }
        while(!p_es_vacia(auxiliar)){
            te3 = p_desapilar(auxiliar);
            p_apilar(p1,te3);
        }
        for(int i=-1; i < contador; i++){
        te2 = p_desapilar(p2);
        p_apilar(auxiliar,te2);
        }
        while(!p_es_vacia(auxiliar)){
            te3 = p_desapilar(auxiliar);
            p_apilar(p2,te3);
        }
        if(te->clave != te2->clave){
            resultado = false;
        }
        contador++;
    }
    return resultado;
}

// EJERCICIO 4

char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){
    int cociente = 1;
    char* resultado;
    TipoElemento te;
    Pila p = p_crear();

    while(nrobasedecimal != 0){
        te = te_crear(nrobasedecimal % nrootrabase);
        p_apilar(p,te);
        nrobasedecimal = nrobasedecimal / nrootrabase;
    }
    resultado = convertirEnCadena(p);
    free(te);
    free(p);
    return resultado;
}

char* convertirEnCadena(Pila p){
    char* resultado = malloc(10 * sizeof(char));
    strcpy(resultado,"");
    char buffer[20];
    char letra[2];
    TipoElemento te;

    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        if(te->clave >= 10){
            letra[0] = te->clave + 55; // Calculo según el ASCII
            strcat(resultado,letra);
        }
        else{
            sprintf(buffer, "%i", te->clave);
            strcat(resultado,buffer);
        }
    }
    return resultado;
}

// EJERCICIO 5

Pila  p_ej5_invertir(Pila p){
    TipoElemento te;
    Pila invertida = p_crear();
    Pila auxiliar = p_crear();

    if(p_es_vacia(p)){
        return invertida;
    }
    
    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(auxiliar,te);
        p_apilar(invertida,te);
    }

    while(!p_es_vacia(auxiliar)){
        te = p_desapilar(auxiliar);
        p_apilar(p,te);
    }

    return invertida;
}

// EJERCICIO 6

Pila p_ej6_eliminarclave(Pila p, int clave){
    TipoElemento te;
    Pila auxiliar = p_crear();
    Pila nuevaPila = p_crear();

    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(auxiliar,te);
        p_apilar(nuevaPila,te);
    }
    while(!p_es_vacia(nuevaPila)){
        te = p_desapilar(nuevaPila);
        p_apilar(p,te);
    }

    eliminarClaveRecursiva(auxiliar,nuevaPila,clave);

    return nuevaPila;
}

void eliminarClaveRecursiva(Pila auxiliar, Pila nuevaPila, int clave){
    if(p_es_vacia(auxiliar)){
        return;
    }
    TipoElemento te = p_desapilar(auxiliar);
    if(te->clave != clave){
        p_apilar(nuevaPila,te);
    }
    eliminarClaveRecursiva(auxiliar,nuevaPila,clave);
}

