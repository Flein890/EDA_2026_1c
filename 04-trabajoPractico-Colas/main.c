#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libs/validaciones/headers/tp_validaciones.h"
#include "tp_colas.h"

//------//
int mostrarmenu_principal();
void c_mostrar_2(Cola c);
void p_mostrar_2(Pila p);
void mostrarcarga_cola(Cola c);
void mostrarcarga_pila(Pila p);
void mostrarListaValor(Lista l);
void respuesta_menu(int seleccion);
void pasointermedio_submenu();
void respuesta_submenu(int seleccion);
void limpiar_terminal_c();
void limpiar_c();
//=========//

int main()
{
    srand(time(NULL));
    int seleccion;
    do
    {
        seleccion = mostrarmenu_principal(); 
        if (seleccion != 8)
        {
            respuesta_menu(seleccion);
        }
    }while (seleccion != 8);
    return 0;
}
//==//
void ejecutar2_1()
{
    Cola c = c_crear();
    mostrarcarga_cola(c);

    int clave;
    printf("[!]: Ingrese la clave a buscar:\n");
    IngresarEntero(SIGNO_NO_IMPORTA, false, &clave);
    bool rest = c_ej2_existeclave(c, clave);
    printf("[RESPUESTA]: En la Cola %sexiste la clave %d", rest ? "":"NO ", clave);
}

void ejecutar2_2()
{
    Cola c = c_crear();
    mostrarcarga_cola(c);

    int elementos = c_ej2_contarelementos(c);
    int clave, pos;

    int limite = (elementos < TAMANIO_MAXIMO) ? (elementos + 1) : TAMANIO_MAXIMO;

    do
    {
        printf("\n[!]: Ingrese la posicion ordinal donde se insertara la clave [1 a %d]:\n", limite);
        IngresarEntero(SIGNO_POSITIVO, false, &pos);

        if (pos < 1 || pos > limite) {
            printf("[ERROR]: Posicion invalida. Ingrese un numero entre 1 y %d.\n", limite);
        }
    } while (pos < 1 || pos > limite);

    printf("\n[!]: Ingrese la clave a cargar:\n");
    IngresarEntero(SIGNO_NO_IMPORTA, false, &clave);

    TipoElemento x = te_crear(clave);
    c_ej2_colarelemento(c, pos, x);

    if (elementos == TAMANIO_MAXIMO) {
        printf("\n[ADVERTENCIA]: La cola estaba llena. El elemento se inserto, pero el ultimo de la fila se perdio.\n");
    }
    printf("\n[RESULTADO]: Se ha ingresado el valor %d en la pos %d.\n", clave, pos);
    c_mostrar_2(c); 
}

void ejecutar2_3()
{
    Cola c = c_crear();
    mostrarcarga_cola(c);
    int clave;
    printf("[!]: Ingrese la clave a retirar:\n");
    IngresarEntero(SIGNO_NO_IMPORTA, false, &clave);
    Cola rest = c_ej2_sacarelemento(c, clave);

    printf("[RESULTADO]: \n");
    c_mostrar_2(rest);
}

void ejecutar2_4()
{
    Cola c = c_crear();
    mostrarcarga_cola(c);
    printf("[RESPUESTA]: La cola posee %d elementos.\n", c_ej2_contarelementos(c));
}
void ejecutar2_5()
{
    Cola c = c_crear();
    mostrarcarga_cola(c);
    Cola c2 = c_ej2_copiar(c);
    printf("\n\n[RESULTADO]: (COLA COPIADA)");
    c_mostrar_2(c2);
}
void ejecutar2_6()
{
    Cola c = c_crear();
    mostrarcarga_cola(c);
    Cola c2 = c_ej2_invertir(c);
    limpiar_terminal_c();
    printf("\n[RESPUESTA]: Original:");
    c_mostrar_2(c);
    printf("\n\n[RESPUESTA]: Invertida:");
    c_mostrar_2(c2);
}

void ejecutar3()
{
    Cola c = c_crear();
    mostrarcarga_cola(c);
    printf("[!]: SE REQUIERE CARGAR UNA COLA ADICIONAL\n\n");
    Cola c2 = c_crear();
    mostrarcarga_cola(c2);
    limpiar_terminal_c();
    bool rest = c_ej3_iguales(c, c2);

    printf("\n[RESULTADO] - COLA 1");
    c_mostrar_2(c);
    printf("\n[RESULTADO] - COLA 2");
    c_mostrar_2(c2);

    printf("[RESULTADO]: Las colas C1 y C2 son %s", rest ? "IGUALES" : "DESIGUALES");
}
void ejecutar4()
{
    printf("4");
}
void ejecutar5()
{
    printf("5");
}
void ejecutar6()
{
    Cola c1 = c_crear();
    mostrarcarga_cola(c1);
    Pila p1 = p_crear();
    mostrarcarga_pila(p1);

    Lista comunes = c_ej6_comunesapilaycola(p1, c1);

    if(l_es_vacia(comunes)) printf("\n[RESPUESTA]: Ningun elemento comun, la lista es vacia.\n");
    mostrarListaValor(comunes);

    printf("\n[!] Cola Devuelta: \n");
    c_mostrar_2(c1);
    printf("[!]: Pila Devuelta: "); 
    p_mostrar_2(p1);
}
void ejecutar7()
{
    printf("7");
}

//-- Menu Principal
int mostrarmenu_principal()
{
    int seleccion;
    printf("===================================================================================\n ");
    printf("\t\t\t\t >> TP 3: Pilas - Grupo 3\n\n");
    printf("\n\t\t [!] > Elija que ejercicio ejecutar < [!]");
    printf("\n\n\t\t [2]: Ejercicios punto 2.\n\t\t [3]: Colas Iguales.\n\t\t [4]: Cola No Repetidos.");
    printf("\n\t\t [5]: Divisor Total.\n\t\t [6]: Valores en Comun (Cola y Pila).\n\t\t [7]: Atender Clientes.\n\t\t\n\n\t\t [8]: Salir.\n\n");
    printf("===================================================================================\n ");
    do
    {
        printf(" [!]: Ingrese una opcion. (2 - 8)");
        IngresarEntero(SIGNO_POSITIVO, false, &seleccion);
    } while (seleccion > 8 || seleccion < 2 );
    return seleccion;
}

void respuesta_menu(int seleccion)
{
    switch(seleccion)
    {
        case 2:
        {
            pasointermedio_submenu();
            break;
        }
        case 3:
        {
            ejecutar3();
            break;
        }
        case 4:
        {
            ejecutar4();
            break; 
        }
        case 5:
        {
            ejecutar5();
            break;
        }
        case 6:
        {
            ejecutar6();
            break;
        }
        case 7:
        {
            ejecutar7();
            break;
        }
        default: mostrarmenu_principal();
    }
    limpiar_c();
}

//-- SubMenu
int mostrarmenu_submenu()
{
    limpiar_terminal_c();
    int seleccion;
    printf("===================================================================================\n ");
    printf("\t\t\t\t >> TP 3: Pilas - Ejercicio 2- Grupo 3\n\n");
    printf("\n\t\t [!] > Elija que ejercicio ejecutar < [!]");
    printf("\n\n\t\t [2]: Comprobar clave.\n\t\t [3]: Insertar Elemento.\n\t\t [4]: Sacar Elemento.");
    printf("\n\t\t [5]: Contar elementos.\n\t\t [6]: Copiar Cola.\n\t\t [7]: Invertir Cola.\n\t\t\n\n\t\t [8]: Volver al Menu Principal.\n\n");
    printf("===================================================================================\n ");
    do
    {
        printf(" [!]: Ingrese una opcion. (2 - 8)");
        IngresarEntero(SIGNO_POSITIVO, false, &seleccion);
    } while (seleccion < 2 || seleccion > 8);
    return seleccion;
}

void pasointermedio_submenu() { 
    int seleccion;
    do
    {
        seleccion = mostrarmenu_submenu(); 
        if (seleccion != 8)
        {
            respuesta_submenu(seleccion);
        }
    } while (seleccion != 8); 
}

void respuesta_submenu(int seleccion)
{
    switch(seleccion)
    {
        case 2:
        {
            ejecutar2_1();
            break;
        }
        case 3:
        {
            ejecutar2_2();
            break;
        }
        case 4:
        {
            ejecutar2_3();
            break;
        }
        case 5:
        {
            ejecutar2_4();
            break;
        }
        case 6:
        {
            ejecutar2_5();
            break;
        }
        case 7:
        {
            ejecutar2_6();
            break;
        }
        default: mostrarmenu_submenu();
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
void c_mostrar_2(Cola cola) {
    printf("\n----------------------------------------------------------\n");
    printf("Contenido de la Cola:\n\n");
    if (c_es_vacia(cola)) {
        printf("\n[!] COLA VACIA !!! \n");
        printf("\n----------------------------------------------------------\n");
        return;
    }
    Cola Caux = c_crear();
    TipoElemento X;
    int contador = 0;
    printf("  Valores:  ");
    while (!c_es_vacia(cola)) {
        X = c_desencolar(cola);
        printf("[%4d] ", X->clave); 
        c_encolar(Caux, X);
        contador++;
    }
    printf("\n");
    printf("  Posicion: ");
    for (int i = 1; i <= contador; i++) {
        printf("   %2d  ", i); 
    }
    printf("\n----------------------------------------------------------\n");

    while (!c_es_vacia(Caux)) {
        X = c_desencolar(Caux);
        c_encolar(cola, X);
    }

    free(Caux); 
}

void p_mostrar_2(Pila pila) {
    printf("\n----------------------------------------------------------\n");
    printf("Contenido de la Pila\n\n");
    
    if (p_es_vacia(pila)) {
        printf("  [!] PILA VACIA !!! \n");
        printf("----------------------------------------------------------\n");
        return;
    }
    Pila Paux = p_crear();
    TipoElemento X;
    int contador = 0;
    printf("  Valores:  ");
    while (!p_es_vacia(pila)) {
        X = p_desapilar(pila);
                printf("[%4d] ", X->clave); 
        
        p_apilar(Paux, X);
        contador++;
    }
    printf("\n");
    printf("  Posicion: ");
    for (int i = 1; i <= contador; i++) {
        printf("   %2d  ", i); 
    }
    printf("\n----------------------------------------------------------\n");
    while (!p_es_vacia(Paux)) {
        X = p_desapilar(Paux);
        p_apilar(pila, X);
    }
    free(Paux); 
}

void mostrarListaValor(Lista l)
{
    if (l_es_vacia(l)) {
        printf("\n[!] No se encontraron valores en comun entre la Pila y la Cola.\n");
        return;
    }

    printf("\n----------------------------------------------------------\n");
    printf(" Valores Comunes Encontrados (Pila y Cola) \n");
    printf("----------------------------------------------------------\n");
    printf("   Valor   |  Posicion Pila  |  Posicion Cola \n");
    printf("----------------------------------------------------------\n");

    Iterador it = iterador(l);
    while(hay_siguiente(it))
    {
        TipoElemento elemento = siguiente(it);
        int posPila = 0, posCola = 0;
                sscanf((char *)elemento->valor, "%d:%d", &posPila, &posCola);
        printf("  [%4d]   |       %2d        |       %2d \n", elemento->clave, posPila, posCola);
    }
    printf("----------------------------------------------------------\n\n");
}

// Sistema de Carga

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

// ================= Colas

void cargarcolarand(Cola a, int elementos)
{
    for(int i = 0; i < elementos; i++)
    {
        int numero_aleatorio = (rand() % 201) - 100; 
        
        TipoElemento x = te_crear(numero_aleatorio);
        c_encolar(a, x);
    }
}
// Carga una cola con valores manuales, con un LIMITE preestablecido.
void cargar_cola_ml(Cola a, int elementos)  
{
    for(int i = 0; i < elementos; i++)
    {
        printf("[!]: Ingrese un valor entero como clave. [Restantes a cargar: %d]\n",elementos-i);
        int valor;
        IngresarEntero(SIGNO_NO_IMPORTA, false, &valor);
        TipoElemento x = te_crear(valor);
        
        c_encolar(a, x); 
    }
    printf("[!]: Carga manual finalizada.\n");
}

// Carga una cola con valores manuales SIN LIMITE (Lim: tam max Implementacion)
void cargar_cola_sl(Cola a)
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
            c_encolar(a, x);
            cargados++;
            if(cargados != 0) printf("[!]: Elemento cargado [Totales: %d]\n", cargados);
        }
    }
    while(seguir && cargados < TAMANIO_MAXIMO);
}

// Carga una cola automaticamente - Con limite fijo (Manual o automatico)
void cargar_cola_auto(Cola c, int max)
{
    if(max != -1)
    {
        cargarcolarand(c, max);
        printf("[!]: Cola cargada.");
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
        
        cargarcolarand(c, valor);
        printf("[!]: Cola cargada.");
        limpiar_c();
    }
}

void mostrarcarga_cola(Cola c)
{
    printf("[!]: Atencion, debera cargar una COLA para ejecutar este ejercicio. Seleccione la forma: (1) MANUAL - (2): ALEATORIA\n");
    int select, cant;
    do
    {
        IngresarEntero(SIGNO_POSITIVO, false, &select);
    } while (select > 2);
    if(select == 1) cargar_cola_sl(c);
    else
    {
        do
        {
            printf("[!]: Ingrese la cantidad de claves a cargar. (1 a %d)\n", TAMANIO_MAXIMO);
            IngresarEntero(SIGNO_POSITIVO, false, &cant);
        } while(cant == 0 || cant > TAMANIO_MAXIMO);
        cargarcolarand(c, cant);
    }
    limpiar_c();
    c_mostrar_2(c);
}

void mostrarcarga_pila(Pila p)
{
    printf("[!]: Atencion, debera cargar una PILA para ejecutar este ejercicio. Seleccione la forma: (1) MANUAL - (2): ALEATORIA\n");
    int select, cant;
    do
    {
        IngresarEntero(SIGNO_POSITIVO, false, &select);
    } while (select > 2);
    if(select == 1) carga_manual_sl(p);
    else
    {
        do
        {
            printf("[!]: Ingrese la cantidad de claves a cargar. (1 a %d)\n", TAMANIO_MAXIMO);
            IngresarEntero(SIGNO_POSITIVO, false, &cant);
        } while(cant == 0 || cant > TAMANIO_MAXIMO);
        cargarpilarand(p, cant);
    }
    limpiar_c();
    p_mostrar(p);
}