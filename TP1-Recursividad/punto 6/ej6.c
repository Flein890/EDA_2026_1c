#include "./TP_recur/TP_Recursividad.h"

char * ondaDigital(char seniales[]);
void convertir(char *cadena, char seniales[]); 
void cadenaMinusculas(char *cad);
bool cadenaValida(char *cad);

int main (void){

    char seniales[] = "HLHLhhlHLHL";
    char * micad = ondaDigital(seniales);
    printf("%s\n",micad);

    return 0;
}

char * ondaDigital(char seniales[]){
    
    int esValido = cadenaValida(seniales);

    if(esValido == 0){
        return "No valido";
    }


    int tam = (strlen(seniales) + 1);
    char * res =(char*) malloc((2*tam)+1);

    
    convertir(res,seniales);
    
    return res;

};

void convertir(char *cadena, char seniales[]){
    //si tengo una L = _   si tengo una H = -     construccion recursiva -> funcion convertir
    
    if(*seniales == '\0'){ //caso base
        *cadena = '\0';
        return;
    }
   
    if(*seniales == 'h'){

       *cadena = '-';              //ambos condicionales son equivalentes en su interior
                                     // solo que el segundo usa un puntero auxiliar
    } else if(*seniales == 'l'){   //el primero no lo usa porque en la recursion ya estoy apuntando al sig
        char * p = cadena;
        *p = '_';
        p++;
    }

    if(*seniales != *(seniales+1) && *(seniales+1) != '\0'){
        cadena++;   
        *cadena = '|';
    
   }

    return convertir(cadena+1,seniales+1);

}; 
   

bool cadenaValida(char *cad){
    bool esValido = 1; //true
    cadenaMinusculas(cad);
    int tam = strlen(cad);
    for(int i= 0;i<tam;i++){
        if(cad[i] != 'l' && cad[i] != 'h'){
            esValido = false;
        }
    }
return esValido;

}

void cadenaMinusculas(char *cad){
    int tam = strlen(cad);
    for(int i = 0;i<tam;i++){
        if(cad[i] >= 'A' && cad[i] <= 'Z'){
        cad[i] = i[cad] + 32;// *(cad + i) 
        }
    }
};