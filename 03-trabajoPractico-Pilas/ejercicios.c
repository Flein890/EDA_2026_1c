#include "tp_pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


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

    if (nrootrabase < 2 || nrootrabase > 16)
    {
        resultado = calloc(20, sizeof(char)); 
        sprintf(resultado, "%i", nrobasedecimal); 
        free(p); 
        return resultado; 
    }

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

/*Pila p_ej6_eliminarclave(Pila p, int clave){                  // No termina siendo ni iterativo al 100%
    TipoElemento te;                                            // Ni recursivo al 100%
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
}*/

// [!]: Iterativo: Complejidad Lineal.

Pila p_ej6_eliminarclave(Pila p, int clave)
{
    Pila paux = p_crear(),
         prest = p_crear();

    while (!p_es_vacia(p))
    {   
        p_apilar(paux, p_desapilar(p));
    }
    while(!p_es_vacia(paux))
    {
        TipoElemento x = p_desapilar(paux);
        p_apilar(p, x);
        if(x->clave != clave) {
            p_apilar(prest, x);
        }
    }

    return prest; 
}


// [!]: Recursivo - Lineal
Pila p_ej6_eliminarclave_r(Pila p, int clave)
{
    if (p_es_vacia(p)) return p_crear();  // Base

    TipoElemento x = p_desapilar(p); 

    Pila nuevaPila = p_ej6_eliminarclave_r(p, clave); 
    
    p_apilar(p, x); // rearma la pila original
    if (x->clave != clave) p_apilar(nuevaPila, x); 
    return nuevaPila; 
}

// EJERCICIO 7
 void rellenar_pila(Pila p1, Pila aux){
        while(!p_es_vacia(aux)){
            TipoElemento e1 = p_desapilar(aux);
            p_apilar(p1,e1);
        }
    }

Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    Pila pAux = p_crear();
    Pila pAux2 = p_crear();
    Pila coincidencias = p_crear();
    // pararme el primer elemento de p1, comparar con todos los de p2, si alguno es igual
    // sumarlo a otra pila llamada coincidencias, caso contrario no se hace nada, repito proceso
    // con hasta terminar p1. usando apilar y desapilar


    while(!p_es_vacia(p1)){
        TipoElemento e1;
        e1 = p_desapilar(p1);

        while(!p_es_vacia(p2)){
            TipoElemento e2;
            e2 = p_desapilar(p2);
            if(e1->clave == e2->clave){
                p_apilar(coincidencias,e2);
            }
            p_apilar(pAux2,e2);
        }

        rellenar_pila(p2,pAux2); //sin la coincidencia anterior
        p_apilar(pAux,e1);
    }
    rellenar_pila(p1,pAux);

    return coincidencias;
};


// EJERCICIO 8

Pila valRep(Pila P);

Pila p_ej8_sacarrepetidos(Pila P){
    // Pila P = p_crear();
    Pila PR = p_crear();
    Pila paux= p_crear();
    TipoElemento Y;
    int clave;
    int c = 0; // Contador de elementos
    bool b;

    // do{
    //     b = ingresoEntero(&clave, &c);
    //     if(b) p_apilar(P,te_crear(clave));

    // }while(b);

    p_mostrar(P);

    PR = valRep(P); //PR contiene los elementos resultantes

    return PR; //repetidos
}


Pila copia_p(Pila pila) {
    TipoElemento X;
    Pila pAux = p_crear();
    Pila pCopia = p_crear();
    while(!p_es_vacia(pila))
    {
        X = p_desapilar(pila);
        p_apilar(pAux, X);
    }

    while(!p_es_vacia(pAux))
    {
        X = p_desapilar(pAux);
        p_apilar(pila, X);
        p_apilar(pCopia, X);
    }
    return pCopia;
}

TipoElemento contarClave(Pila pila, int c) {
    TipoElemento Y, J;
    int*cont =(int*)malloc(sizeof(int));  //Reservo memoria al contador
    *cont=0;
    Pila pAux=p_crear();

    while(!p_es_vacia(pila))
    {
        Y = p_desapilar(pila);
        if (c == Y->clave){
            (*cont)++;
        }
        p_apilar(pAux, Y);
    }
    J = te_crear_con_valor(c, cont);

    while(!p_es_vacia(pAux))
    {
        p_apilar(pila, p_desapilar(pAux));
    }

    return J;
}

bool buscarClave(Pila pila, TipoElemento Y)
{
	Pila pAux = p_crear();
	TipoElemento X;
	bool b = false;

	while (!p_es_vacia(pila))
	{
		X = p_desapilar(pila);
		if (X->clave == Y->clave){ //Si la clave esta en la pila, b es true .. en caso de no entrar al if, b es false
			b = true;
		}
		p_apilar(pAux, X);
	}
	while (!p_es_vacia(pAux))
	{
		p_apilar(pila,p_desapilar(pAux));
	}

	return b;
}


Pila valRep(Pila P) {
    Pila pCopia = copia_p(P);
    Pila pCopia2 = copia_p(P);
    Pila pAux= p_crear();
    TipoElemento X;
    Pila PR = p_crear();
    TipoElemento J;

    while(!p_es_vacia(pCopia))                      // N
    {
        X = p_desapilar(pCopia);                    

        J = contarClave(pCopia2, X->clave);     // N * (N)

        if(!buscarClave(pAux,X))                // N * (N + N) = 2N"2 = O(N"2)
        {
           p_apilar(PR, J);
        }

        p_apilar(pAux,X);
    }

    return PR;
}
