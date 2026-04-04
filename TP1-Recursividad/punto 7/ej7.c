#include "../Headers/Headers.h"

int main(void){
    int num;
    printf("Ingrese un nivel de mafia (numero entero):\n");
   
    int esValido = scanf("%d",&num); //scanf devuelve 0 si hubo un error al capturar el dato, 1 si todo ok
   
    while(esValido == 0){
        printf("Ingrese un nivel de mafia valido(numero entero):\n");
        
        while(getchar() != '\n'); //limpio buffer, capturo caracteres hasta el enter

        esValido = scanf("%d",&num);
       
    }

    char * pe = reunionMafia(num); //validar que se ingrese un num
    printf("%s",pe);
    return 0;
}


char* reunionMafia(int nivel){

if(nivel== 1){
    return "(-.-)";
}
// "(-.-)"
// "(-."
// ".-)"

char * ant = reunionMafia(nivel-1); //se va desapilando hasta llegar al caso base y recien ahi arma cada nivel

char * res = (char * )malloc(strlen(ant) +strlen("(-.")+strlen(".-)") + 1 ); //+1 el car nulo


strcpy(res,"(-."); //establezco res
strcat(res,ant);   //le concateno a res todo lo que tiene ant
strcat(res,".-)"); //le concateno a res al final el medio chinito


return  res;
}
    
    