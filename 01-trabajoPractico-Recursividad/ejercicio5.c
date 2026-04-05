#include "tp_1_recursividad.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char auxr(char cadena[], char aux[], int i,int j,int tamaño){
	int faltan;
	if (cadena['\0'] ){
		aux[j]= '\0';
		return;
	}

	
		aux[j] = cadena[i];
		faltan = tamaño-1;

		if ((faltan > 0) && (faltan % 3 == 0)){
			aux[j+1] ='.';
			auxr (cadena, aux,  i+1, j+1, tamaño);
		}else
		{
			auxr (cadena, aux,  i+1, j+1, tamaño);
		}


	}
