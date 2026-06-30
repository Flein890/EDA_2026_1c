#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tp_conjunto.h"

//==============================EJERCICIO 2=================================

Conjunto c_ej2_union(Conjunto A, Conjunto B)
{
    return cto_union(A, B);
}

Conjunto c_ej2_interseccion(Conjunto A, Conjunto B)
{
    return cto_interseccion(A, B);
}

Conjunto c_ej2_diferencia(Conjunto A, Conjunto B)
{
    return cto_diferencia(A, B);
}

Conjunto c_ej2_pertenece(Conjunto A, int clave)
{
    return cto_pertenece(A, clave);
}
//==============================EJERCICIO 3=================================

Conjunto c_ej3_uniones(Lista l_de_conjuntos)
{
    Conjunto resultado = cto_crear();

    Iterador it = iterador(l_de_conjuntos);

    while(hay_siguiente(it))
    {
        TipoElemento x = siguiente(it);
        Conjunto actual = (Conjunto)x->valor;

        Conjunto aux = cto_union(resultado, actual);

        resultado = aux;
    }

    free(it);

    return resultado;
}


Conjunto c_ej3_intersecciones(Lista l_de_conjuntos)
{
    if(l_es_vacia(l_de_conjuntos))
        return cto_crear();

    Iterador it = iterador(l_de_conjuntos);

    TipoElemento x = siguiente(it);

    Conjunto resultado = (Conjunto)x->valor;

    while(hay_siguiente(it))
    {
        x = siguiente(it);

        Conjunto actual = (Conjunto)x->valor;

        resultado = cto_interseccion(resultado, actual);
    }

    free(it);

    return resultado;
}

//==============================EJERCICIO 4=================================

bool esSubconjunto(Conjunto A, Conjunto B)
{
    Conjunto dif = cto_diferencia(A, B);

    bool resultado = cto_es_vacio(dif);

    return resultado;
}

bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C)
{
    if(esSubconjunto(A, B) && esSubconjunto(B, C))
        return esSubconjunto(A, C);

    return false;
}

//complejidad ej4: cto_diferencia() tiene complejidad O(n²) ,esSubconjunto() realiza una sola diferencia, por lo que también es O(n²).
//la complejidad final es de O(n²) + O(n²) = O(n²)



//==============================EJERCICIO 5=================================

Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B)
{
    Conjunto AB = cto_diferencia(A, B);
    Conjunto BA = cto_diferencia(B, A);

    return cto_union(AB, BA);
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

bool esSubconjuntoParcial(Conjunto A, Conjunto B, bool *total)
{
    Conjunto dif = cto_diferencia(A, B);

    int cantA = cto_cantidad_elementos(A);
    int faltantes = cto_cantidad_elementos(dif);

    int comunes = cantA - faltantes;

    if(comunes == cantA)
    {
        *total = true;
        return true;
    }

    if(comunes >= (cantA + 1) / 2)
    {
        *total = false;
        return true;
    }

    return false;
}

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C)
{
    Conjunto conjuntos[3] = {A,B,C};
    char *nombre[3] = {"A","B","C"};

    bool existe = false;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                continue;

            bool total;

            if(esSubconjuntoParcial(conjuntos[i], conjuntos[j], &total))
            {
                existe = true;

                if(total)
                    printf("El conjunto %s es subconjunto TOTAL del conjunto %s\n",
                            nombre[i], nombre[j]);
                else
                    printf("El conjunto %s es subconjunto PARCIAL del conjunto %s\n",
                            nombre[i], nombre[j]);
            }
        }
    }

    if(!existe)
        printf("No existen subconjuntos parciales ni totales.\n");
}

//Complejidad ej7: cto_diferencia() utiliza búsquedas lineales, por lo que cuesta O(n²).


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

