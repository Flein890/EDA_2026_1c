#include "../headers/tp_validaciones.h"

const char* c_prohibidos = " \t\"',:;[]{}&~";

const char* TipoDatoToString(TipoDatoIngresado tipo)
{
    switch(tipo)
    {
        case TIPO_VACIO:               return "TIPO_VACIO";
        case TIPO_SOLO_LETRAS:         return "TIPO_SOLO_LETRAS";
        case TIPO_ALFANUMERICO:        return "TIPO_ALFANUMERICO";
        case TIPO_ENTERO_POSITIVO:     return "TIPO_ENTERO_POSITIVO";
        case TIPO_ENTERO_NEGATIVO:     return "TIPO_ENTERO_NEGATIVO";
        case TIPO_FLOTANTE_POSITIVO:   return "TIPO_FLOTANTE_POSITIVO";
        case TIPO_FLOTANTE_NEGATIVO:   return "TIPO_FLOTANTE_NEGATIVO";
        case TIPO_DESCONOCIDO:         return "TIPO_DESCONOCIDO";
        default:                       return "TIPO_GAGA";
    }
}

void eliminarCaracter(char cadena[], int posicion)
{
    int i = posicion;

    while (cadena[i] != '\0')
    {
        cadena[i] = cadena[i + 1];
        i++;
    }
}

const char* SignoToString(ReglaSigno tipo)
{
    switch(tipo)
    {
        case SIGNO_POSITIVO:         return " positivo";
        case SIGNO_NEGATIVO:         return " negativo";
        default:                     return "";
    }
}


TipoDatoIngresado IdentificarTipoDato(char cadena[])
{
    int posicion = 0;
    int cantidadPuntos = 0;
    int posicionPunto = -1;
    int cantidadSignos = 0;

    bool soloLetras = true;
    bool soloDigitos = true;
    bool esNegativo = false;

    if (cadena[0] == '\0') return TIPO_VACIO;
    if (cadena[0] == '-') esNegativo = true;

    while (cadena[posicion] != '\0')
    {
        char c = cadena[posicion];
        if (c == '+' || c == '-')
        {
            if (posicion > 0) return TIPO_DESCONOCIDO;
            cantidadSignos++;
        }
        else if (c == '.')
        {
            if (soloLetras == true && soloDigitos == false) return TIPO_DESCONOCIDO;
            if (cantidadPuntos == 1) return TIPO_DESCONOCIDO;
            posicionPunto = posicion;
            cantidadPuntos++;
        }
        else if (strchr(c_prohibidos, c) || cantidadSignos > 1) return TIPO_DESCONOCIDO;
        else if (isalnum(c))
        {
            if (isalpha(c)) soloDigitos = false;
            else if (isdigit(c)) soloLetras = false;
            else return TIPO_DESCONOCIDO;
        }
        posicion++;
    }
    if (!soloDigitos && !soloLetras) return TIPO_ALFANUMERICO;
    if (soloLetras && !soloDigitos) return TIPO_SOLO_LETRAS;
    //==// Decimal -.-
    if (cantidadPuntos == 1 && posicionPunto > 0 && posicionPunto < strlen(cadena) - 1 &&
        isdigit(cadena[posicionPunto - 1]) && isdigit(cadena[posicionPunto + 1]))

    {return esNegativo ? TIPO_FLOTANTE_NEGATIVO : TIPO_FLOTANTE_POSITIVO;}
    //==// Entero
    if (soloDigitos && !soloLetras && cantidadPuntos == 0) return esNegativo ? TIPO_ENTERO_NEGATIVO : TIPO_ENTERO_POSITIVO;
    return TIPO_DESCONOCIDO;
}

bool LeerBuffer(char *buffer, size_t size, bool permitirExit)
{
    if (fgets(buffer, size, stdin) == NULL)
        return false;

    buffer[strcspn(buffer, "\n")] = '\0';
    if (permitirExit && strcmp(buffer, "exit") == 0)
        return false;

    return true;
}

/*int IngresarEntero(ReglaSigno signo)
{
    int tipoEsperado, rest;
    char buffer[256];
    TipoDatoIngresado tipoDatoIngresado;
    int primerIntento = 1;

    if(signo == SIGNO_NEGATIVO) tipoEsperado  = TIPO_ENTERO_NEGATIVO;
    else if(signo == SIGNO_POSITIVO) tipoEsperado  = TIPO_ENTERO_POSITIVO;
    do
    {
        if(primerIntento == 1) printf("\n[!]: >> Ingrese un numero entero%s: ", SignoToString(signo));
        else printf("\n[!]: >> <ERROR: Ingreso invalido> - Ingrese un numero entero%s: ", SignoToString(signo));
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        tipoDatoIngresado = IdentificarTipoDato(buffer);
        primerIntento = 0;

        } while ((tipoDatoIngresado != TIPO_ENTERO_POSITIVO &&tipoDatoIngresado != TIPO_ENTERO_NEGATIVO) // SI NO ES DEL TIPO ESPERADO
                ||  (signo != SIGNO_NO_IMPORTA && tipoDatoIngresado != tipoEsperado)); // SI NO ES DEL SIGNO ESPERADO
    char* fin;
    long valor = strtol(buffer, &fin, 10);
    return (int)valor;
}*/

bool IngresarEntero(ReglaSigno signo, bool permitirExit, int *valor)
{
    char buffer[256];
    TipoDatoIngresado tipoDatoIngresado;
    int primerIntento = 1;
    int tipoEsperado;

    if (signo == SIGNO_NEGATIVO) {tipoEsperado = TIPO_ENTERO_NEGATIVO;
    }else if(signo == SIGNO_POSITIVO){tipoEsperado = TIPO_ENTERO_POSITIVO;
    } else {tipoEsperado = -1;}

    do
    {
        if (primerIntento == 1) printf("\n[!]: >> Ingrese un numero entero%s%s: ",SignoToString(signo), permitirExit ? " o escriba exit para salir" : "");
        else printf("\n[!]: >> <ERROR: Ingreso invalido> - Ingrese un numero entero%s%s: ", SignoToString(signo), permitirExit ? " o escriba exit para salir" : "");

        if (!LeerBuffer(buffer, sizeof(buffer), permitirExit)) return false; // CONTROLA SI SEE CORTA O SIGUE (UTIL EN CARGAS)

        tipoDatoIngresado = IdentificarTipoDato(buffer);
        primerIntento = 0;

    } while ((tipoDatoIngresado != TIPO_ENTERO_POSITIVO && tipoDatoIngresado != TIPO_ENTERO_NEGATIVO)|| (signo != SIGNO_NO_IMPORTA && tipoDatoIngresado != tipoEsperado));
    *valor = (int) strtol(buffer, NULL, 10);
    return true;
}

double IngresarDecimal(ReglaSigno signo)
{
    int tipoEsperado, rest;
    char buffer[256];
    TipoDatoIngresado tipoDatoIngresado;
    int primerIntento = 1;

    if(signo == SIGNO_NEGATIVO) tipoEsperado  = TIPO_FLOTANTE_NEGATIVO;
    else if(signo == SIGNO_POSITIVO) tipoEsperado  = TIPO_FLOTANTE_POSITIVO;
    do
    {
        if(primerIntento == 1) printf("\n[!]: >> Ingrese un numero decimal%s (Separador '.'): ", SignoToString(signo));
        else printf("\n[!]: >> <ERROR: Ingreso invalido> - Ingrese un numero decimal%s (Separador '.'): ", SignoToString(signo));
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        tipoDatoIngresado = IdentificarTipoDato(buffer);
        primerIntento = 0;

        } while ((tipoDatoIngresado != TIPO_FLOTANTE_POSITIVO &&tipoDatoIngresado != TIPO_FLOTANTE_NEGATIVO) // SI NO ES DEL TIPO ESPERADO
                ||  (signo != SIGNO_NO_IMPORTA && tipoDatoIngresado != tipoEsperado)); // SI NO ES DEL SIGNO ESPERADO
    char* fin;
    double  valor = strtod(buffer, &fin);
    return valor;
}

char* IngresarAlfanumerico()
{
    int tipoEsperado, rest;
    char buffer[512];
    TipoDatoIngresado tipoDatoIngresado;
    int primerIntento = 1;

    do
    {
        if(primerIntento == 1) printf("\n[!]: >> Ingrese un dato alfanumerico (Sin espacios): ");
        else printf("\n[!]: >> <ERROR: Ingreso invalido> - Ingrese un dato alfanumerico (Sin espacios): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        tipoDatoIngresado = IdentificarTipoDato(buffer);
        primerIntento = 0;

        } while (tipoDatoIngresado != TIPO_ALFANUMERICO); 
    char* resultado = malloc(strlen(buffer) + 1);
    strcpy(resultado, buffer);
    return resultado;
}

char* IngresarSoloLetras()
{
    int tipoEsperado, rest;
    char buffer[512];
    TipoDatoIngresado tipoDatoIngresado;
    int primerIntento = 1;

    do
    {
        if(primerIntento == 1) printf("\n[!]: >> Ingrese solo letras (sin numeros, simbolos o espacios): ");
        else printf("\n[!]: >> <ERROR: Ingreso invalido> - [!]: >> Ingrese solo letras (sin numeros, simbolos o espacios): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        tipoDatoIngresado = IdentificarTipoDato(buffer);
        primerIntento = 0;

        } while (tipoDatoIngresado != TIPO_SOLO_LETRAS); 

    char* resultado = malloc(strlen(buffer) + 1);
    strcpy(resultado, buffer);
    return resultado;
}

//======================//

/*
    Modificado por última vez 27/04 - Cris
*/ 
