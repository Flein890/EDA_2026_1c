#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_conjunto.h"
#include "utilidades.h"
#include "ejercicios.h"

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
    printf("Ejecutar ejercicio 2 union (ingresar 21)\n");
    printf("Ejecutar ejercicio 2 interserccion (ingresar 22)\n");
    printf("Ejecutar ejercicio 2 diferencia (ingresar 23)\n");
    printf("Ejecutar ejercicio 3 union (ingresar 31)\n");
    printf("Ejecutar ejercicio 3 interseccion (ingresar 32)\n");
    printf("Ejecutar ejercicio 4 (ingresar 4)\n");
    printf("Ejecutar ejercicio 5 (ingresar 5)\n");
    printf("Ejecutar ejercicio 6 (ingresar 6)\n");
    printf("Ejecutar ejercicio 7 (ingresar 7)\n");
    printf("Ejecutar ejercicio 8 (ingresar 8)\n");
    printf("Salir (ingresar 0)\n");
}

void controlador(){
    TipoElemento te;
    Conjunto c1,c2,c3;
    Lista l;
    bool resultado;
    int opcion,num,num2;
    mostrarMenu();
    printf("\nIngrese una opcion: ");
    scanf("%i",&opcion);
    while(opcion != 0){ 
        switch(opcion){
            case 21:
                printf("\nIngrese el primer conjunto: ");
                c1 = ingresarConjunto();
                printf("\nIngrese el segundo conjunto: ");
                c2 = ingresarConjunto();
                c3 = c_ej2_union(c1, c2);
                printf("\nResultado: ");
                cto_mostrar(c3);
                break;
            case 22:
                printf("\nIngrese el primer conjunto: ");
                c1 = ingresarConjunto();
                printf("\nIngrese el segundo conjunto: ");
                c2 = ingresarConjunto();
                c3 = c_ej2_interseccion(c1,c2);
                printf("\nResultado: ");
                cto_mostrar(c3);
                break;
            case 23:
                printf("\nIngrese el primer conjunto: ");
                c1 = ingresarConjunto();
                printf("\nIngrese el segundo conjunto: ");
                c2 = ingresarConjunto();
                c3 = c_ej2_diferencia(c1,c2);
                printf("\nResultado: ");
                cto_mostrar(c3);
                break;
            case 31:
                l = ingresarListaDeConjuntos();
                c3 = c_ej3_uniones(l);
                printf("\nResultado: ");
                cto_mostrar(c3);
                break;
            case 32:
                l = ingresarListaDeConjuntos();
                c3 = c_ej3_intersecciones(l);
                printf("\nResultado: ");
                cto_mostrar(c3);
                break;
            case 4:
                printf("\nIngrese el primer conjunto: ");
                c1 = ingresarConjunto();
                printf("\nIngrese el segundo conjunto: ");
                c2 = ingresarConjunto();
                printf("\nIngrese el tercer conjunto: ");
                c3 = ingresarConjunto();
                resultado = c_ej4_transitividad(c1,c2,c3);
                if(resultado){
                    printf("Se cumple la transitividad");
                }
                else{printf("No se cumple la transitividad");}
                break;
            case 5:
                printf("\nIngrese el primer conjunto: ");
                c1 = ingresarConjunto();
                printf("\nIngrese el segundo conjunto: ");
                c2 = ingresarConjunto();
                c3 = c_ej5_dif_simetrica(c1,c2);
                printf("\nResultado: ");
                cto_mostrar(c3);
                break;
            case 6:
                printf("\nIngrese el primer conjunto: ");
                c1 = ingresarConjunto();
                printf("\nIngrese el segundo conjunto: ");
                c2 = ingresarConjunto();
                resultado = c_ej6_subconjuntopropio(c1,c2);
                if(resultado){
                    printf("Se cumple que un conjunto es subconjunto del otro");
                }
                else{printf("Ninguno de los conjuntos es subconjunto del otro");}
                break;
            case 7:
                printf("\nIngrese el primer conjunto: ");
                c1 = ingresarConjunto();
                printf("\nIngrese el segundo conjunto: ");
                c2 = ingresarConjunto();
                printf("\nIngrese el tercer conjunto: ");
                c3 = ingresarConjunto();
                c_ej7_subconjtotalparcial(c1,c2,c3);
                break;
            case 8:
                printf("\nIngrese el primer conjunto: ");
                c1 = ingresarConjunto();
                printf("\nIngrese el segundo conjunto: ");
                c2 = ingresarConjunto();
                resultado = c_ej8_soniguales(c1,c2);
                if(resultado){
                    printf("Son iguales");
                }
                else{printf("No son iguales");}
                break; 
            default:
                printf("\nOpcion no valida");
        }
        mostrarMenu();
        printf("\nIngrese una opcion: ");
        scanf("%i",&opcion);
    }
}