#include "tp_2_listas.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
    Modificado por ultima vez 28/04 - Franco
*/ 

// Punto 2

Lista verElementosRepetidos(Lista l1, Lista l2)
{
    Lista rest = l_crear();
    Iterador i_l1 = iterador(l1);

    while (hay_siguiente(i_l1)) 
    {
        TipoElemento te = siguiente(i_l1);
        if(l_buscar(l2, te->clave) != NULL)
        {
            l_agregar(rest, te);
        }
    }
    free(i_l1);
    return rest;
}

Lista verElementosQueNoSeRepiten(Lista l1, Lista l2)
{
    Lista rest = l_crear();
    Iterador i_l1 = iterador(l1);

    while (hay_siguiente(i_l1)) 
    {
        TipoElemento te = siguiente(i_l1);
        if(l_buscar(l2, te->clave) == NULL)
        {
            l_agregar(rest, te);
        }
    }
    free(i_l1);
    return rest;
}

float promedio(Lista l1)
{
    Iterador i_l1 = iterador(l1);
    int acum = 0;
    int max = l_longitud(l1);
    while(hay_siguiente(i_l1))
    {
        TipoElemento te = siguiente(i_l1);
        acum += te->clave;
    }
    float rest = (float)acum/max;
    free(i_l1);
    return rest;
}

ResultadoValorMinimo valorMinimo(Lista l1, Lista l2)
{
    Iterador i_l1 = iterador(l1);
    Iterador i_l2 = iterador(l2);
    ResultadoValorMinimo rest;
    int pos = 1;

    if(!l_es_vacia(l1)){rest.valor = l_recuperar(l1,1)->clave; rest.pos = 1;}
    if(!l_es_vacia(l2)){rest.valor_2 = l_recuperar(l2, 1)->clave; rest.pos_2 = 1;}

    while(hay_siguiente(i_l1))
    {   
        TipoElemento te = siguiente(i_l1);
        if((te->clave) < rest.valor)
        {
            rest.valor = te->clave;
            rest.pos = pos;
        }
        pos++;
    }

    pos = 1;
    while(hay_siguiente(i_l2))
    {   
        TipoElemento te = siguiente(i_l2);
        if((te->clave) < rest.valor)
        {
            rest.valor_2 = te->clave;
            rest.pos_2 = pos;
        }
        pos++;
    }
    free(i_l1);
    free(i_l2);
    return rest;
}


int CompararListas(Lista l1, Lista L2)
{
    int mayorl1 = 0, 
    iguales = 0, 
    mayorl2 = 0;
    Iterador i_l1 = iterador(l1);
    Iterador i_l2 = iterador(L2);
    while(hay_siguiente(i_l1) && hay_siguiente(i_l2))
    {
        TipoElemento te1 = siguiente(i_l1);
        TipoElemento te2 = siguiente(i_l2);
        if(te1->clave > te2->clave) mayorl1++;
        else if(te2->clave > te1->clave)mayorl2++;
        else iguales++;
    }
    free(i_l1);
    free(i_l2);
    if(mayorl1 > mayorl2) return 1;
    else if(mayorl2 > mayorl1) return 2;
    else return 0;
}

//-----------------------------------------------------------------
//----------------------------Ejercicio 3--------------------------
//-----------------------------------------------------------------

ResultadosMul multiplo(Lista l1, Lista l2){
    int resto = 0;
    int escalar = 0;
    ResultadosMul resultado;
    TipoElemento te1 = te_crear(0);
    TipoElemento te2 = te_crear(0);
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    te1 = siguiente(ite1);
    te2 = siguiente(ite2);

    int auxEscalar = te2->clave / te1->clave;
    resultado.esMultiplo = true;
    resultado.escalar = true;

    while(hay_siguiente(ite1) && hay_siguiente(ite2)){
        resto = te2->clave % te1->clave;
        if(resto != 0){
            resultado.esMultiplo = false;
            resultado.escalar = false;
            resultado.numEscalar = 0;
            break;
        }
        escalar = te2->clave / te1->clave;
        if(escalar != auxEscalar && resultado.escalar == true){
            resultado.escalar = false;
            resultado.numEscalar = 0;
        }
        te1 = siguiente(ite1);
        te2 = siguiente(ite2);
    }

    if(resultado.escalar == true){
        resultado.numEscalar = escalar;
    }

    return resultado;
}

//-----------------------------------------------------------------
//--------------------------------EJ6------------------------------
//-----------------------------------------------------------------


bool esSublista(Lista l1,Lista l2){
    TipoElemento X;
    TipoElemento buscar;
    Iterador i = iterador(l1);
    
    if(l_longitud(l2) > l_longitud(l1)){
        return false;
    }
    
    while(hay_siguiente(i))
    {
        
        X = siguiente(i);
        buscar = l_buscar(l1,X->clave);
        
       if(buscar == NULL)
       {
           
           return false;
           
       }
        
    }
    
    return true;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
