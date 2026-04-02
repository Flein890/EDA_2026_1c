#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>
#ifndef TP_Recursividad
#define TP_Recursividad



//Archivo de cabecera del trabajo practico "Nro 1: Recursividad".

//PUNTO 1
bool palindromo(char *cad,int inicio,int fin);
bool cadenaValida(char *cad);
void cadenaMinusculas(char *cad);

//PUNTO 2
int ProductoEnSumas(int m, int n,int resultado,bool negativo);

//PUNTO 3
int terminoSeridFibonacci(int k);

//PUNTO 4
double fun_decimales(int dividendo, int divisor);
double Division(int dividendo,int divisor,double resultado,bool negativo);

//PUNTO 5
char* separador_miles(char* numero, int largo, int indice_numero, int indice_array, char array[]);
void invertirCadena(char cadena[]);

//PUNTO 6
char *ondaDigital(char seniales[]);
void convertir(char *cadena, char seniales[]);
void cadenaMinusculas(char *cad);
bool cadenaValida(char *cad);

//PUNTO 7
char* reunionMafia(int nivel);

//PUNTO 8
void imprimirSubconjunto(int *subconjunto, int tam); 
void encontrarSubconjuntos(int conjunto[], int tam, int *subconjunto, int subTam, int suma, int n, int **resultados, int *tamanios);
int **subconjuntosQueSumanN(int conjunto[], int tam, int n, int **tamanios);
void numeroValido(int* num);

//PUNTO 9
bool divisiblePor7(int n);

//PUNTO 10
int* explosion(int n, int b);
void pedazos(int num, int bomb, int *explotaqueexplo, int *index);

#endif
