#include "../libs/validaciones/headers/tp_validaciones.h"
#include "tp_2_listas.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/*
    Modificado por última vez 27/04 - Cris
*/ 

//===========// Prototipos MENU.
void respuesta_menu(int seleccion, Lista l1, Lista l2);
void respuesta_submenu(int seleccion, Lista l1, Lista l2);
void mostrarmenu_principal(Lista l1, Lista l2);
void mostrarmenu_submenu(Lista l1, Lista l2);
void cargar_lista(Lista l1);
void limpiar_terminal_c();
void limpiar_c();
void verlista_estilizado(Lista l1);
//=========================//
void ejecutar_2A(Lista l1, Lista l2)
{
    Lista rest = verElementosQueNoSeRepiten(l1, l2);
    printf("\n[RESPUESTA]: La lista de elementos de L1 que no se repiten en L2 es:\n");
    if(l_es_vacia(rest)) printf(" LISTA VACIA - No hay elementos que no se repitan.");
    else l_mostrar(rest);
}
void ejecutar_2B(Lista l1, Lista l2)
{
    Lista rest = verElementosQueNoSeRepiten(l2, l1);
    printf("\n[RESPUESTA]: La lista de elementos L2 que no se repiten en L1 es:\n");
    if(l_es_vacia(rest)) printf(" LISTA VACIA - No hay elementos que no se repitan.");
    else l_mostrar(rest);
}
void ejecutar_2C(Lista l1, Lista l2)
{
    Lista rest = verElementosRepetidos(l1, l2);
    printf("\n[RESPUESTA]: La lista de elementos que se repiten en L1 y L2:\n");
    if(l_es_vacia(rest)) printf(" LISTA VACIA - No hay elementos que no se repitan.");
    else l_mostrar(rest);
}

void ejecutar_2D(Lista l1, Lista l2)
{
    if(l_es_vacia(l1) || l_es_vacia(l2)) printf("\n[ERROR] Atencion: Una(s) de las listas esta vacia, deberan tener al menos una clave.\n");
    else
    {
        float prom1 = promedio(l1);
        float prom2 = promedio(l2);
        printf("\n[RESPUESTA]: El promedio de ambas listas es: %2.f (Prom L1: %2.f - Prom L2: %2.f)", (prom1+prom2)/2, prom1, prom2);
    }
}

void ejecutar_2E(Lista l1, Lista l2)
{
   if(l_es_vacia(l1) || l_es_vacia(l2)) printf("[!] Atencion: Una de las listas esta vacia, deberan tener al menos una clave.\n");
   else
   {
        ResultadoValorMinimo rest = valorMinimo(l1, l2);
        printf("\n[RESPUESTA]: Lista 1 (Valor min: %d - Pos: %d) [-] Lista 2 (Valor min: %d - Pos: %d)", rest.valor, rest.pos, rest.valor_2, rest.pos_2);
   }
}

void mostrarmenu_principal(Lista l1, Lista l2)
{
    int seleccion;
    printf("===================================================================================\n ");
    printf("\t\t\t\t >> TP 2: Listas - Grupo 3\n\n");
    printf("\n\t\t [!] > Elija que ejercicio ejecutar < [!]");
    printf("\n\n\t\t [1]: Ejercicios Punto 2.\n\t\t [2]: Multiplo.\n\t\t [3]: Comparar Listas.");
    printf("\n\t\t [4]: Polinomio.\n\t\t [5]: Sublista.");
    printf("\n\n [!] Seleccione '6' o '7' para modificar cada lista desde este menu [!]");
    printf("\n\n [6] L1 - ");
    verlista_estilizado(l1);
    printf(" [7] L2 - ");
    verlista_estilizado(l2);
    printf("===================================================================================\n ");
    do
    {
        printf(" [!]: Ingrese una opcion. (1 - 7)");
        IngresarEntero(SIGNO_POSITIVO, false, &seleccion);
    } while (seleccion == 0 || seleccion > 7);
    respuesta_menu(seleccion, l1, l2);
}
void respuesta_menu(int seleccion, Lista l1, Lista l2)
{
    switch(seleccion)
    {
        case 1:
        {
            limpiar_c();
            mostrarmenu_submenu(l1,l2);
            break;
        }
        case 2:
        {
            limpiar_c();
            mostrarmenu_principal(l1,l2);
            break;
        }
        case 3:
        {
            limpiar_c();
            mostrarmenu_principal(l1,l2);
            break;
        }
        case 4:
        {
            limpiar_c();
            mostrarmenu_principal(l1,l2);
            break;
        }
        case 5:
        {
            limpiar_c();
            mostrarmenu_principal(l1,l2);
            break;
        }
        case 6:
        {
            cargar_lista(l1);
            limpiar_c();
            mostrarmenu_principal(l1,l2);
            break;
        }
        case 7:
        {
            cargar_lista(l2);
            limpiar_c();
            mostrarmenu_principal(l1,l2);
            break;
        }
        default: mostrarmenu_principal(l1,l2);
    }
}

void mostrarmenu_submenu(Lista l1, Lista l2)
{
    int seleccion;
    printf("===================================================================================\n ");
    printf("\t\t\t\t >> TP 2: Listas - Ejercicio 2- Grupo 3\n\n");
    printf("\n\t\t [!] > Elija que ejercicio ejecutar < [!]");
    printf("\n\n\t\t [1]: NO Repetidos (L1 en L2).\n\t\t [2]: NO Repetidos (L2 en L1).\n\t\t [3]: Valores en comun.");
    printf("\n\t\t [4]: Promedio L1 y L2\n\t\t [5]: Valores Minimos.\n\t\t\n\t\t[6]: Volver al Menu Principal.");
    //printf("\n\n [!] Cada ejercicio requerira la carga individual de sus parametros. [!]\n");
    printf("\n\n [!] L1 - ");
    verlista_estilizado(l1);
    printf(" [!] L2 - ");
    verlista_estilizado(l2);
    printf("===================================================================================\n ");
    do
    {
        printf(" [!]: Ingrese una opcion. (1 - 6)");
        IngresarEntero(SIGNO_POSITIVO, false, &seleccion);
    } while (seleccion == 0 || seleccion > 6);
    respuesta_submenu(seleccion, l1, l2);
}
void respuesta_submenu(int seleccion, Lista l1, Lista l2)
{
    switch(seleccion)
    {
        case 1:
        {
            ejecutar_2A(l1, l2);
            limpiar_c();
            mostrarmenu_submenu(l1, l2);
            break;
        }
        case 2:
        {
            ejecutar_2B(l1, l2);
            limpiar_c();
            mostrarmenu_submenu(l1, l2);
            break;
        }
        case 3:
        {
            ejecutar_2C(l1, l2);
            limpiar_c();
            mostrarmenu_submenu(l1, l2);
            break;
        }
        case 4:
        {
            ejecutar_2D(l1, l2);
            limpiar_c();
            mostrarmenu_submenu(l1, l2);
            break;
        }
        case 5:
        {
            ejecutar_2E(l1, l2);
            limpiar_c();
            mostrarmenu_submenu(l1, l2);
            break;
        }
        case 6:
        {
            mostrarmenu_principal(l1, l2);
            break;
        }
        default: mostrarmenu_submenu(l1, l2);
    }
}
//===//
void limpiar_terminal_c() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

void limpiar_c()
{
    printf("\n\nPresione [ENTER] para continuar.\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    srand(time(NULL));
    mostrarmenu_principal(l1, l2);
}

//==========//
// Funciones de carga.
void limpiar_lista(Lista l)
{
    while(!l_es_vacia(l))
    {
        l_eliminar(l, 1);
    }
}

void cargar_lista(Lista l)
{ 
    int selec;
    if(!l_es_vacia(l)) limpiar_lista(l);

    do
    {
        printf("[!]: Por favor, seleccione el modo de carga\n\n\t\t [1]: Carga Manual.\n\t\t [2]: Carga automatica.");
        IngresarEntero(SIGNO_POSITIVO, false, &selec);
    } while(selec == 0 || selec > 2);

    if(selec == 1)
    {
        int valor;
        bool sigue;
        printf("[!]: Para cancelar la carga, ingrese 'exit', por favor, ingrese un valor entero.");
        do
        {
            sigue = IngresarEntero(SIGNO_NO_IMPORTA, true, &valor);
            if(sigue) l_agregar(l, te_crear(valor));
        } while (sigue);
    }
    else
    {
        int claves, max, min;
        printf("\n[!]: Debera ingresar los siguientes valores: Claves a generar (MAX 100), valor de clave maximo y minimo.");
        do
        {
            printf("\n[!]: Ingrese el MAXIMO DE CLAVES a generar (MAX 100)");
            IngresarEntero(SIGNO_POSITIVO, false, &claves);
        } while (claves > 100);

        printf("\n[!]: Ingrese el valor MAXIMO para las claves:");
        IngresarEntero(SIGNO_NO_IMPORTA, false, &max);

        do
        {
            printf("\n[!]: Ingrese el valor MINIMO para las claves (MAX (%d) > MIN): ", max);
            IngresarEntero(SIGNO_NO_IMPORTA, false, &min);
        } while (min > max);

        for(int i = 0; i < claves; i++)
        {
            l_agregar(l, te_crear(rand() % (max - min + 1) + min));
        }
        
    }
}

void verlista_estilizado(Lista l1)
{
    if(l_es_vacia(l1)) printf(" Lista vacia. \n");

    Iterador it = iterador(l1);
    while(hay_siguiente(it))
    {
        TipoElemento te = siguiente(it);
        printf(" %d", te->clave);    
    }
    printf("\n");   
}