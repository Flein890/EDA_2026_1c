#include "tp_4_colas.h"
#include "../libs/pilas/headers/pilas.h"


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
Cola c_ej2_colarelemento(Cola c, int posicionordinal){
    Cola aux = c_crear();
    bool agregado = false;
    int pos = 1;
    TipoElemento aAgregar = te_crear(777);

    while(!c_es_vacia(c)){
        if(!agregado && pos == posicionordinal){ //validar rango? posicionordinal se puede exceder del limite / simplemente no lo agrega?
            c_encolar(aux,aAgregar);
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
Cola c_ej2_invertir(Cola c){
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
};


//------------------------------3-----------------------------