#include "../Headers/Headers.h"
char * agregarSeparadorMiles(char*);

int main (void){
    //EL SIGUIENTE DESARROLLO NO ES RECURSIVO,LO HICE PARA RECORDAR COMO SE PONIAN LOS PUNTOS DE MILES
//     char * numString = "12345";
//     int tam = strlen(numString);
   

//     int puntos = (tam-1) / 3;
//     int nuevoTam = tam + puntos + 1; //+1 por el '\0'

//     char * aux = malloc(nuevoTam);

//     int j = nuevoTam -1;
//     aux[j] = '\0';
//     j--;

//     int cont = 0;
//     for(int i = tam-1;i>=0;i--){
//          aux[j] = numString[i];
//          cont++;
//          if(cont ==3 && i> 0){
//             j--;
//             aux[j] = '.';
//             cont = 0;
//          }
//         j--;
//     }



// printf("%s",aux);
// return 0;

}


char * agregarSeparadorMiles(char* strNum){
    int tam = strlen(strNum);
    int cantPuntos = (tam-1) / 3;

    char * aux = malloc(cantPuntos);
    char * strN2 = malloc(cantPuntos);

    if(tam < 1){
        return aux;
    }
a  terminar

    return agregarSeparadorMiles();

}