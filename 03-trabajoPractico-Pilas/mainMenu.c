#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_pilas.h"
#include "utilidades.h"

void mostrarMenu();
void controlador();

int main(){
    system("cls");
    controlador();
    printf("Fin del programa...\n");
    return 0;
}

void mostrarMenu(){
    printf("Menu principal\n");
    printf("------------------\n");
    printf("Ejecutar ejercicio 2.a (ingresar 21)\n");
    printf("Ejecutar ejercicio 2.b (ingresar 22)\n");
    printf("Ejecutar ejercicio 2.c (ingresar 23)\n");
    printf("Ejecutar ejercicio 2.d (ingresar 24)\n");
    printf("Ejecutar ejercicio 2.e (ingresar 25)\n");
    printf("Ejecutar ejercicio 2.f (ingresar 26)\n");
    printf("Ejecutar ejercicio 3 (ingresar 3)\n");
    printf("Ejecutar ejercicio 4 (ingresar 4)\n");
    printf("Ejecutar ejercicio 5 (ingresar 5)\n");
    printf("Ejecutar ejercicio 6 (ingresar 6)\n");
    printf("Ejecutar ejercicio 7 (ingresar 7)\n");
    printf("Ejecutar ejercicio 8 (ingresar 8)\n");
    printf("Salir (ingresar 0)\n");
}

void controlador(){
    TipoElemento te;
    Pila p,p2;
    bool resultado;
    char* punteroString = malloc(sizeof(char*));
    int opcion,num,num2;
    mostrarMenu();
    printf("\nIngrese una opcion: ");
    scanf("%i",&opcion);
    while(opcion != 0){ 
        switch(opcion){
            case 21:
                p = ingresarPila();
                if(p_ej2_existeclave(p, ingresarEntero())){
                    printf("Si existe esa clave en la pila\n");
                }
                else{printf("No existe esa clave en la pila\n");}
                free(p);
                break;
            case 22:
                p = ingresarPila();
                printf("Ingresar clave del elemento: \n");
                te = te_crear(ingresarEntero());
                printf("Ingresar posicion: \n");
                p_mostrar(p_ej2_colocarelemento(p, ingresarEntero(), te));
                break;
            case 23:
                p = ingresarPila();                            
                p_mostrar(p_ej2_eliminarclave(p, ingresarEntero()));
                free(p);
                break;
            case 24:
                p = ingresarPila();  
                printf("Ingresar posiciones: \n");              
                p_mostrar(p_ej2_intercambiarposiciones(p, ingresarEntero(), ingresarEntero()));
                free(p);
                break;
            case 25:
                p = ingresarPila();
                p_mostrar(p_ej2_duplicar(p));
                free(p);
                break;
            case 26:
                p = ingresarPila();
                printf("\nLa longitud es %i\n",p_ej2_cantidadelementos(p));
                free(p);
                break;
            case 3:
                p = ingresarPila();
                p2 = ingresarPila();
                resultado = p_ej3_iguales(p, p2);
                if(resultado){
                    printf("\nSus contenidos son iguales\n");  
                }
                else{printf("\nSus contenidos NO son iguales\n");}
                free(p);
                free(p2);
                break;
            case 4:
                num = ingresarEntero();
                printf("\nIngrese la base: ");  
                num2 = ingresarEntero();
                punteroString = p_ej4_cambiarbase(num, num2);
                printf("\nRespuesta: %s\n", punteroString);
                break;
            case 5:
                p = ingresarPila();
                p2 = p_ej5_invertir(p);
                printf("\nPila original:\n");
                p_mostrar(p);
                printf("\nPila invertida:\n");
                p_mostrar(p2);
                free(p);
                free(p2);
                break;
            case 6:
                p = ingresarPila();
                p2 = p_ej6_eliminarclave(p, ingresarEntero());
                printf("\nPila original:\n");
                p_mostrar(p);
                printf("\nPila sin el numero ingresado:\n");
                p_mostrar(p2);
                free(p);
                free(p2);
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            
            default:
                printf("\nOpcion no valida");
        }
        mostrarMenu();
        printf("\nIngrese una opcion: ");
        scanf("%i",&opcion);
    }
}