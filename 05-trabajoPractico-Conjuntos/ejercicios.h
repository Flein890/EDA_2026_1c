#ifndef EJERCICIOS_H
#define EJERCICIOS_H

#include <string.h>
#include <stdbool.h>
#include "tp_conjunto.h"

Conjunto c_ej2_union(Conjunto A, Conjunto B);
Conjunto c_ej2_interseccion(Conjunto A, Conjunto B);
Conjunto c_ej2_diferencia(Conjunto A, Conjunto B);
bool c_ej2_pertenece(Conjunto A, int clave);
Conjunto c_ej3_uniones(Lista l_de_conjuntos);
Conjunto c_ej3_intersecciones(Lista l_de_conjuntos);
bool esSubconjunto(Conjunto A, Conjunto B);
bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C);
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B);
bool  c_ej6_subconjuntopropio (Conjunto A, Conjunto B);
bool esSubconjuntoParcial(Conjunto A, Conjunto B, bool *total);
void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C);
bool c_ej8_soniguales(Conjunto A, Conjunto B);

#endif
