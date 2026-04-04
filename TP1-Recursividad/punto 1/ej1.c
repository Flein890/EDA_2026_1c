#include "../Headers/Headers.h"

int main()
{
    char cadena[30];
    bool esValido;

    do{
        printf("Ingresa una palabra para saber si es un palindromo: ");
        
        fgets(cadena,sizeof(cadena),stdin);
        cadena[strcspn(cadena,"\n")] = '\0';  //Elimino el salto de linea

        esValido=cadenaValida(cadena);  //Validacion de datos

        if(esValido){   
            printf("Se ingresaron caracteres invalidos, ingrese otra palabra:\n");
        }
    } 
    while(esValido);
    
    cadenaMinusculas(cadena);  
    
    int tam=strlen(cadena);
    
    bool pali=palindromo(cadena,0,tam-1);

    printf("%s",pali ? "Verdadero. La palabra es palindormo." : "Falso. La palabra NO es palindromo.");
        
    
return 0;
}

void cadenaMinusculas(char *cad)   //Funcion convierte cadena a minusculas
{
    for (int i=0; i<strlen(cad); i++){
        cad[i]=tolower(cad[i]);
    }
}

bool cadenaValida(char *cad)      //Funcion para validad 
{
    for (int i = 0; i < strlen(cad); i++){
        if (isalpha(cad[i])){
            return false;
        }
    }
    return true;
}

  
bool palindromo(char *cad,int inicio,int fin){
	   
    if (inicio >= fin){
        return true;
    }

    if (cad[inicio] != cad[fin]) {
        return false;
    }

    return palindromo(cad,inicio+1,fin-1);
}
