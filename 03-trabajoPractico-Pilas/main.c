#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libs/validaciones/headers/tp_validaciones.h"
#include "tp_pilas.h"

//------//
int mostrarmenu_principal(Pila p1);
void respuesta_menu(int seleccion, Pila p1);
void pasointermedio_submenu(Pila p1);
void respuesta_submenu(int seleccion, Pila p1);
void mostrarcarga(Pila p, Pila p2, bool restrictivo, int max); 
void carga_manual_l(Pila a, int elementos);
void carga_manual_sl(Pila a);
/* 
    - p: Pila destino. sobre ella se actuara
    - p2 - Pila origen (clonar), utilizada para la opcion de clonacion. se toma como pila a clonar en p. 
    - restrictivo (flag control), permite la clonacion y/o la carga limitada. 
    - max: limite de elementos a cargar. [-1 HABILITA UN AVISO EN CASO DE CARGAR UNA PILA 2]
*/
void p_aux(Pila a, Pila b);
void copiar_pila(Pila origen, Pila destino);
void limpiar_terminal_c();
void limpiar_c();
void mostrar_pila_formateada(Pila p); // Formato EJ 8

//======================================//
int main()
{
    srand(time(NULL));
    Pila p1 = p_crear();
    int seleccion;
    mostrarcarga(p1, p1, false, -1);
    do
    {
        seleccion = mostrarmenu_principal(p1); 
        if (seleccion != 9)
        {
            respuesta_menu(seleccion, p1);
        }
    }while (seleccion != 9);
    printf("\nSaliendo del programa...\n");
    return 0;
}
//======================//

// - Ejecucion de Ejercicios

void ejecutar_2_1(Pila p1)
{
    printf("21");
}
void ejecutar_2_2(Pila p1)
{
    printf("22");
}
void ejecutar_2_3(Pila p1)
{
    printf("23");
}
void ejecutar_2_4(Pila p1)
{
    printf("24");
}
void ejecutar_2_5(Pila p1)
{
    printf("25");
}
void ejecutar_2_6(Pila p1)
{
    printf("26");
}
void ejecutar_3(Pila p1)
{
    Pila p2 = p_crear();
    printf("Carga de la Pila 2: \n");
    carga_manual_sl(p2);
    bool res = p_ej3_iguales(p1,p2);
    printf("\n");
    printf("%s",res?"Las pilas comparadas son IGUALES":"Las pilas comparadas son DIFERENTES");
    printf("\n");
}
void ejecutar_4(Pila p1)
{
    printf("4");
}
void ejecutar_5(Pila p1)
{
    Pila p = p_ej5_invertir(p1);
    printf("Pila Invertida:\n");
    p_mostrar(p);
    printf("\n");
}
void ejecutar_6(Pila p1)
{
    int * clave;
    printf("Ingrese clave a borrar: \n");
    IngresarEntero(0, false, clave);
    Pila p = p_ej6_eliminarclave(p1,*clave);
    printf("Elemento eliminado: \n");
    p_mostrar(p);


}
void ejecutar_7(Pila p)
{
    Pila p2 = p_crear();
    printf("Carga de la pila 2: \n");
    carga_manual_sl(p2);
    Pila con =  p_ej7_elementoscomunes(p,p2);
    printf("\n\nCoincidencias: \n\n");
    p_mostrar(con);


}
void ejecutar_8(Pila p1)
{
    Pila rep = p_ej8_sacarrepetidos(p1);
    printf("\nRepeticiones:\n");
    while(!p_es_vacia(rep))
    {
      TipoElemento Y = p_desapilar(rep);

      printf("%d:%d ", Y->clave, *((int*)Y->valor));
    }
    printf("\n\n");
}

//

//============================// >> Cargas de Datos
void cargarpilarand(Pila a, int elementos)
{
    for(int i = 0; i < elementos; i++)
    {
        int numero_aleatorio = (rand() % 201) - 100; 
        
        TipoElemento x = te_crear(numero_aleatorio);
        p_apilar(a, x);
    }
}

// Carga una pila con valores manuales, con un LIMITE preestablecido.
void carga_manual_l(Pila a, int elementos)  
{
    for(int i = 0; i < elementos; i++)
    {
        printf("[!]: Ingrese un valor entero como clave. [Restantes a cargar: %d]\n",elementos-i);
        int valor;
        IngresarEntero(SIGNO_NO_IMPORTA, false, &valor);
        TipoElemento x = te_crear(valor);
        p_apilar(a, x);
    }
    printf("[!]: Carga manual finalizada.\n");
}

// Carga una pila con valores manuales SIN LIMITE (Lim: tam max Implementacion)
void carga_manual_sl(Pila a)
{
    bool seguir;
    int cargados = 0;
    do
    {
        int valor;
        TipoElemento x;
        seguir = IngresarEntero(SIGNO_NO_IMPORTA, true, &valor);
        if(seguir)
        { 
            x = te_crear(valor);
            p_apilar(a, x);
            cargados++;
            if(cargados != 0) printf("[!]: Elemento cargado [Totales: %d]", cargados);
        }
    }
    while(seguir && cargados < TAMANIO_MAXIMO);
}

// Carga una pila automaticamente - Con limite fijo (Manual o automatico)
void cargar_pila_auto(Pila p, int max)
{
    while (!p_es_vacia(p)) p_desapilar(p);   
    if(max != -1)
    {
        cargarpilarand(p, max);
        printf("[!]: Pila cargada.");
        limpiar_c();
    }
    else
    {
        printf("[!]: Ingrese el numero de elementos aleatorios a cargar. Deben estar entre [1 y %d]", TAMANIO_MAXIMO);
        int valor;
        do
        {
            IngresarEntero(SIGNO_POSITIVO, false, &valor);
        } while (valor <= 0 || valor > TAMANIO_MAXIMO);
        cargarpilarand(p, valor);
        printf("[!]: Pila cargada.");
        limpiar_c();
    }

}

// Intermedio entre menu y tipo de carga
void cargar_manual(Pila p, int max)
{
    while (!p_es_vacia(p)) p_desapilar(p);
    if(max == -1)
    {
        printf("[!]: Atencion, comenzara la carga de la pila (Valores Maximos: %d).\n[!]: Ingrese 'exit' sin un valor previo para cargar una lista vacia o para terminar la carga.", TAMANIO_MAXIMO);
        carga_manual_sl(p);
    }  
    else carga_manual_l(p, max);
        limpiar_terminal_c();

}

//======// - Menus
// -- MENU CARGA
void mostrarcarga(Pila p, Pila p2, bool restrictivo, int max)
{
    /*
        p: Pila destino, sobre ella se operara.
        p2: Pila "Opcional", utilizada como destino de la pila a clonar.
        restrictivo: Determina si un ejercicio permite la clonacion de una pila o carga de datos limitados.max
        max: Determinara cual sera el maximo de datos a cargar.
    
    */
    limpiar_terminal_c();
    printf("===================================================================================\n ");
    printf("\t\t\t\t >> TP: 3 Pilas - Grupo 3\n\n");
    printf("\n\t\t [!] > Elija como desea cargar la pila < [!]\n\t\t [1]: Carga manual.\n\t\t [2]: Carga aleatoria.");
    if(restrictivo){
        printf("\n\t\t [3]: Copiar pila 1 en pila 2\n");
        if(max!=-1) printf("\n[IMPORTANTE]: Dado a que esta P2 debe tener la misma longitud que P1, no se le permite ingresar una pila mas larga.\n");
    }
    printf("\n\n [!] Podra cambiar la pila posteriormente de ser requerido. [!]\n");
    printf("===================================================================================\n ");
    int opcion;
    int omax = restrictivo ? 3 : 2;

    do
    {
        printf("[!]: Ingrese una opcion. (1 - %d)\n", omax);
        IngresarEntero(SIGNO_POSITIVO, false, &opcion);
    } while (opcion < 1  ||  opcion > omax);

    if(opcion == 1) cargar_manual(p, max);
    else if(opcion == 2) cargar_pila_auto(p, max);
    else
    {
        copiar_pila(p2, p);
        printf("[!]: Pila copiada.\n");
        limpiar_c();
    }
}

//-- Menu Principal
int mostrarmenu_principal(Pila p1)
{
    limpiar_terminal_c();
    int seleccion;
    printf("===================================================================================\n ");
    printf("\t\t\t\t >> TP 3: Pilas - Grupo 3\n\n");
    p_mostrar(p1);
    printf("\n\t\t [!] > Elija que ejercicio ejecutar < [!]");
    printf("\n\n\t\t [2]: Ejercicios Punto 2.\n\t\t [3]: Comparar pilas.\n\t\t [4]: Cambio de base.");
    printf("\n\t\t [5]: Invertir pila.\n\t\t [6]: Eliminar clave.\n\t\t [7]: Elementos comunes.\n\t\t [8]: Sacar repetidos.\n\t\t\n\t\t [1]: Cambiar pila.\n\t\t [9]: Salir.\n\n");
    printf("===================================================================================\n ");
    do
    {
        printf(" [!]: Ingrese una opcion. (1 - 9)");
        IngresarEntero(SIGNO_POSITIVO, false, &seleccion);
    } while (seleccion > 9);
    return seleccion;
}

void respuesta_menu(int seleccion, Pila p1)
{
    switch(seleccion)
    {
        case 1: 
        {
            mostrarcarga(p1, p1, false, -1);
            break;
        }
        case 2:
        {
            pasointermedio_submenu(p1);
            break;
        }
        case 3:
        {
            ejecutar_3(p1);
            break;
        }
        case 4:
        {
            ejecutar_4(p1);
            break; 
        }
        case 5:
        {
            ejecutar_5(p1);
            break;
        }
        case 6:
        {
            ejecutar_6(p1);
            break;
        }
        case 7:
        {
            ejecutar_7(p1);
            break;
        }
        case 8:
        {
            ejecutar_8(p1);
            break;
        }
        default: mostrarmenu_principal(p1);
    }
    limpiar_c();
}

//-- SubMenu
int mostrarmenu_submenu(Pila p1)
{
    limpiar_terminal_c();
    int seleccion;
    printf("===================================================================================\n ");
    printf("\t\t\t\t >> TP 3: Pilas - Ejercicio 2- Grupo 3\n\n");
    p_mostrar(p1);
    printf("\n\t\t [!] > Elija que ejercicio ejecutar < [!]");
    printf("\n\n\t\t [2]: Existe clave.\n\t\t [3]: Colocar elemento.\n\t\t [4]: Eliminar clave.");
    printf("\n\t\t [5]: Intercambiar posiciones.\n\t\t [6]: Duplicar.\n\t\t [7]: Cantidad de elementos.\n\t\t\n\n\t\t [1]: Cambiar Pila\n\t\t [8]: Volver al Menu Principal.\n\n");
    printf("===================================================================================\n ");
    do
    {
        printf(" [!]: Ingrese una opcion. (1 - 8)");
        IngresarEntero(SIGNO_POSITIVO, false, &seleccion);
    } while (seleccion == 0 || seleccion > 8);
    return seleccion;
}

void pasointermedio_submenu(Pila p1) {  // EVITA RECURSION INDIRECTA EN LOS SUBMENUS
    int seleccion;
    do
    {
        seleccion = mostrarmenu_submenu(p1); 
        if (seleccion != 8)
        {
            respuesta_submenu(seleccion,p1);
        }
    } while (seleccion != 8); 
}

void respuesta_submenu(int seleccion, Pila p1)
{
    switch(seleccion)
    {
        case 1: 
        {
            mostrarcarga(p1, p1, false, -1);
            break;
        }
        case 2:
        {
            ejecutar_2_1(p1);
            break;
        }
        case 3:
        {
            ejecutar_2_2(p1);
            break;
        }
        case 4:
        {
            ejecutar_2_3(p1);
            break;
        }
        case 5:
        {
            ejecutar_2_4(p1);
            break;
        }
        case 6:
        {
            ejecutar_2_5(p1);
            break;
        }
        case 7:
        {
            ejecutar_2_6(p1);
            break;
        }
        default: mostrarmenu_submenu(p1);
    }
    limpiar_c();
}
//======// - Auxiliares
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
void mostrar_pila_formateada(Pila p)
{
    Pila aux = p_crear();
    printf("[RESPUESTA]: ");
    while (!p_es_vacia(p))
    {
        TipoElemento n = p_desapilar(p);
        p_apilar(aux, n);
        printf("(%d:%d) ", n->clave, *((int*)(n->valor)));
    }
    p_aux(aux, p);
    printf("\n");
}
// [!]: Agregar
void p_aux(Pila a, Pila b)
{
    while(!p_es_vacia(a))
    {
        TipoElemento x = p_desapilar(a);
        p_apilar(b, x);
    }
}
void copiar_pila(Pila origen, Pila destino)
{
    Pila aux = p_crear(); 
    while (!p_es_vacia(origen)) {
        TipoElemento te = p_desapilar(origen);
        p_apilar(aux, te); 
    }
    while (!p_es_vacia(aux)) {
        TipoElemento te = p_desapilar(aux);
        p_apilar(origen, te); 
        p_apilar(destino, te); 
    }
}
//======================================================================//
