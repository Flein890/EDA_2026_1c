#include "tp_1_recursividad.h"
#include <stdio.h>
#include <string.h>

float division(int m, int n, int d){ 

    if (m < n){
        if (m == 0 || d == 0){  
            return 0;
        }
        return division(m * 10, n,d-1) / 10.0;
    }

    return 1 + division(m - n, n,d);
}

int main() {
    int m, n,d;
    float resultado;
	
    printf("Ingrese el dividendo (m): ");
    if (scanf("%d", &m) != 1) {
        printf("Error: tiene que ingresar un numero\n");
        return 1;
    }

    printf("Ingrese el divisor (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Error: tiene ingresar un numero\n");
        return 1;
    }

    if (n == 0){
        printf("Error: no se puede dividir por cero\n");
        return 1;
    }

	 do{
        printf("Ingresa un numero del 1 al 10 para indicar la cantidad de decimales que quiere: ");
        scanf("%d", &d);
        if (d < 1 || d > 10){
            printf("Error: debe estar entre 1 y 10\n");
        }
    } while (d < 1 || d > 10);
	
    resultado = division(m, n,d);

    printf("Resultado: %f\n", resultado);

    return 0;
}
