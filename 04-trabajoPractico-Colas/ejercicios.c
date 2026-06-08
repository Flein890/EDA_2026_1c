#include "tp_colas.h"
#include "../libs/pilas/headers/pilas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//------------------------------2-----------------------------

//  a.	Informar si un elemento dado se encuentra en la cola.
// Si la encuentra retorna true, caso contrario false
bool c_ej2_existeclave(Cola c, int clave){
    Cola aux = c_crear();
    bool state = false;
    while(!c_es_vacia(c)){
        TipoElemento e = c_desencolar(c);
        if(e->clave == clave){
            state = true;
        }
        c_encolar(aux,e);
    }

    while(!c_es_vacia(aux)){
        TipoElemento e = c_desencolar(aux);
        c_encolar(c,e);
    }

    return state;
};

//  b.	Agregar un nuevo elemento en una posición dada (colarse).
// Retorna la nueva cola con el elemento insertado, caso contrario la cola original recibida.
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento x){
    Cola aux = c_crear();
    bool agregado = false;
    int pos = 1;

    while(!c_es_vacia(c)){
        if(!agregado && pos == posicionordinal){ //validar rango? posicionordinal se puede exceder del limite / simplemente no lo agrega?
            c_encolar(aux,x);
            agregado = true;
        }
        TipoElemento e = c_desencolar(c);
        c_encolar(aux,e);
        pos++;
    }
    while(!c_es_vacia(aux)){
        TipoElemento e1 = c_desencolar(aux);
        c_encolar(c,e1);
    }
    
    return c;
};

//  c.	Dado un elemento sacarlo de la cola todas las veces que aparezca.
// Retorna la nueva cola sin el/los elemento/s, caso contrario la cola original recibida.
Cola c_ej2_sacarelemento(Cola c, int clave){
     Cola aux = c_crear();
 while(!c_es_vacia(c)){
     TipoElemento e = c_desencolar(c);
     if(clave != e->clave){
         c_encolar(aux,e);
     }
   
 }
 while(!c_es_vacia(aux)){
     TipoElemento e1 = c_desencolar(aux);
     c_encolar(c,e1);
 }

 return c;
};

//  d.	Contar los elementos de la cola.
// Retorna la cantidad de elementos de la cola, o 0 (cero) si esta vacia.
int c_ej2_contarelementos(Cola c){
    int cont = 0;
    Cola aux = c_crear();
    while(!c_es_vacia(c)){
        TipoElemento e = c_desencolar(c);
        c_encolar(aux,e);
        cont++;
    }

     while(!c_es_vacia(aux)){
     TipoElemento e1 = c_desencolar(aux);
     c_encolar(c,e1);
 }

 return cont;

};

//  e.	Realizar una función que realice una copia de una cola.
// Retorna la cola copia tal cual la original, no debe perserse la original.  Si es vacia retorna vacia.
Cola c_ej2_copiar(Cola c){
    Cola aux = c_crear();
    Cola copia = c_crear();

    while(!c_es_vacia(c)){
        TipoElemento e = c_desencolar(c);
        c_encolar(aux,e);
    }

     while(!c_es_vacia(aux)){
     TipoElemento e1 = c_desencolar(aux);
     c_encolar(c,e1);
     c_encolar(copia,e1);
 }
 return copia;
    
}

//  f.	Invertir el contenido de una cola sin destruir la cola original.
// Retorna la cola al reves (invertida), no debe perserse la original. Si es vacia retorna vacia.

/*Cola c_ej2_invertir(Cola c){
    Pila invertir = p_crear();
    Cola aux = c_crear();
    while(!c_es_vacia(c)){
        TipoElemento e = c_desencolar(c);
        p_apilar(invertir,e);
    }
    while(!p_es_vacia(invertir)){
        TipoElemento e = p_desapilar(invertir);
        c_encolar(c,e);
    }
    return c;
};*/

Cola c_ej2_invertir(Cola c)
{
    Cola aux = c_crear();
    Pila invertir = p_crear();
    Cola resultado = c_crear();

    while (!c_es_vacia(c))
    { 
        // vacio y reconstruyo la original
        TipoElemento te = c_desencolar(c);
        c_encolar(aux, te);
        TipoElemento te_copia = te_crear(te->clave);
        p_apilar(invertir, te_copia);
    }
    while (!c_es_vacia(aux))
    {
        TipoElemento te = c_desencolar(aux);
        c_encolar(c, te);
    }
    while (!p_es_vacia(invertir))
    {
        TipoElemento te = p_desapilar(invertir);
        c_encolar(resultado, te);
    }
    free(aux);
    free(invertir);
    return resultado;
}
//------------------------------3-----------------------------
//	Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos 
// (solo comparar por la clave),
// 	sin destruirlas. Utilizar para la resolución del problema una sola cola auxiliar.
//  */
// retorna true si son exactamente iguales, caso contrario retorna false.
bool c_ej3_iguales(Cola c1, Cola c2){
   
    int cantidadElementosC1 = c_ej2_contarelementos(c1);
    int cantidadElementosC2 = c_ej2_contarelementos(c2);
    int cant = 0;
    bool res = true;

    if(cantidadElementosC1 != cantidadElementosC2){
        res = false;
    }

    while(!c_es_vacia(c1) && cantidadElementosC1 == cantidadElementosC2 && cant < cantidadElementosC1){ 
        TipoElemento e1 = c_desencolar(c1);
        TipoElemento e2 = c_desencolar(c2);
        if(e1->clave != e2->clave){
            res = false;
        }
        c_encolar(c1,e1);
        c_encolar(c2,e2);
        cant++;
    }

return res;
};

//------------------------------4-----------------------------
Cola  c_ej4_colanorepetidos(Cola c){
    int ocurrencias = 0;
    TipoElemento te,te2;
    Iterador ite,ite2;
    Lista l = l_crear();
    Cola aux = c_crear();

    if(c_es_vacia(c)){
        return aux;
    }
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        c_encolar(aux,te);
        l_agregar(l,te);
    }
    while(!c_es_vacia(aux)){
        te = c_desencolar(aux);
        c_encolar(c,te);
    }
    ite = iterador(l);
    ite2 = iterador(l);
    while(hay_siguiente(ite)){
        te = siguiente(ite);
        while(hay_siguiente(ite2)){
            te2 = siguiente(ite2);
            if(te->clave == te2->clave){
                ocurrencias++;
                if(ocurrencias > 1){
                    break;
                }
            }
        }
        if(ocurrencias < 2){
            c_encolar(aux,te);
        }
        ocurrencias = 0;
        ite2 = iterador(l);
    }
    printf("\nCola original: \n");
    c_mostrar(c);
    printf("Cola resultado: \n");
    c_mostrar(aux);
    printf("Complejidad: Cuadratica\n");
    return aux;
}

//------------------------------5-----------------------------


//------------------------------6-----------------------------

Lista c_ej6_comunesapilaycola(Pila p, Cola c)
{
    Lista listaComunes = l_crear();
    Pila pilaAux = p_crear();

    TipoElemento elemento;
    TipoElemento elemento2;
    TipoElemento elementoPos;

    int posP = 1;

    while(!p_es_vacia(p))
    {
        elemento = p_desapilar(p);
        
        p_apilar(pilaAux, elemento); 

        bool comunes = false;
        int posC = 1;

        Cola colaAux = c_ej2_copiar(c); 

        while(!c_es_vacia(colaAux) && !comunes)
        {
            elemento2 = c_desencolar(colaAux);
            if(elemento->clave == elemento2->clave) {
                comunes = true;
            } else {
                posC++;
            }
        }

        // sinoserepite
        if(comunes && l_buscar(listaComunes, elemento->clave) == NULL)
        {
            char buffer[20];
            sprintf(buffer, "%d:%d", posP, posC);

            char *valor = malloc(strlen(buffer) + 1); 
            strcpy(valor, buffer);

            elementoPos = te_crear_con_valor(elemento->clave, valor);
            l_agregar(listaComunes, elementoPos);
        }

        while(!c_es_vacia(colaAux)) {
            c_desencolar(colaAux);
        }
        free(colaAux);

        posP++;
    }

    while(!p_es_vacia(pilaAux))
    {
        elemento = p_desapilar(pilaAux);
        p_apilar(p, elemento);
    }

    free(pilaAux);

    return listaComunes;
}

//------------------------------7-----------------------------


bool atender_cliente(Cola c1, int Q) {

    TipoElemento x = c_recuperar(c1);

    x->clave -= Q;

    if (x->clave <= 0) {
        c_desencolar(c1);
        return true;
    }

    return false;
}


Cola c_ej7_atenderclientes(Cola cola1, Cola cola2, Cola cola3, int Q) {
    Cola resultado = c_crear();

    if (c_es_vacia(cola1) &&
        c_es_vacia(cola2) &&
        c_es_vacia(cola3)) {
        return resultado;
    }

    int pos1 = 1;
    int pos2 = 1;
    int pos3 = 1;

    while (!c_es_vacia(cola1) || !c_es_vacia(cola2) || !c_es_vacia(cola3)) {

       if (!c_es_vacia(cola1)) {

        if (atender_cliente(cola1, Q)) {

            char *texto = malloc(50);
            sprintf(texto, "Cliente %d Cola 1", pos1);

            TipoElemento nuevo = te_crear_con_valor(1, texto);

            c_encolar(resultado, nuevo);

            pos1++;
    }
}

    if (!c_es_vacia(cola2)) {

        if (atender_cliente(cola2, Q)) {

            char *texto = malloc(50);
            sprintf(texto, "Cliente %d Cola 2", pos2);

            TipoElemento nuevo = te_crear_con_valor(2, texto);

            c_encolar(resultado, nuevo);

            pos2++;
    }
}

        if (!c_es_vacia(cola3)) {

     if (atender_cliente(cola3, Q)) {

        char *texto = malloc(50);
        sprintf(texto, "Cliente %d Cola 3", pos3);

        TipoElemento nuevo =te_crear_con_valor(3, texto);

        c_encolar(resultado, nuevo);

        pos3++;
    }
}
    }

    return resultado;
}