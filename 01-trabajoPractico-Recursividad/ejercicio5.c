#include "tp_1_recursividad.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void auxr(char cadena[], char aux[], int i,int j,int tamaño){
	int faltan;
	if (cadena[i] == '\0' ){
		aux[j]= '\0';
		return;
	}

	
		aux[j] = cadena[i];
		faltan = tamaño-i-1;

		if ((faltan > 0) && (faltan % 3 == 0)){
			aux[j+1] ='.';
			auxr (cadena, aux,  i+1, j+2, tamaño);
		}else
		{
			auxr (cadena, aux,  i+1, j+1, tamaño);
		}


	}

char * agregarSeparadorMiles(char numero[]){
    static char aux[100];
    auxr(numero, aux, 0, 0, strlen(numero));
    return aux;
}

int main() {
    char cadena[50];

    printf("Ingrese cadena (maximo 49 caracteres): ");
    scanf("%49s", cadena);

    if (strlen(cadena) == 0) {
        printf("error: cadena vacia\n");
        return 1;
    }

    if (strlen(cadena) >= sizeof(cadena)) {
        printf("Error: cadena demasiado larga\n");
        return 1;
    }


    printf("Resultado: %s\n", agregarSeparadorMiles(cadena));

    return 0;
}
