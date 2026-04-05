#include "tp_1_recursividad.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

float division(int m, int n, int d){
	 if (m < n ){
        if((m== 0) || (d==0)){
            return 0;
        }

       return division(m*10,n,d-1)/10.0;
    }
   

   

    
    return 1+ division(m-n,n,d);
}

int main() {
    int m, n, d;
    float resultado;

    printf("Ingrese el dividendo (m): ");
    if (scanf("%d", &m) != 1) {
        printf("Error: debe ingresar un numero\n");
        return 1;
    }

    printf("Ingrese el divisor (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Error: debe ingresar un numero\n");
        return 1;
    }

    printf("Ingrese cantidad de decimales (d): ");
    if (scanf("%d", &d) != 1) {
        printf("Error: debe ingresar un numero\n");
        return 1;
    }

    if (n == 0){
        printf("Error: no se puede dividir por cero\n");
        return 1;
    }

    if (d < 0){
        printf("Error: d no puede ser negativo\n");
        return 1;
    }

    if (d > 6){
        printf("Error: demasiados decimales (recomendamos como maximo 6)\n");
        return 1;
    }

    resultado = division(m, n, d);

    printf("Resultado: %.*f\n", d, resultado);

    return 0;
}
