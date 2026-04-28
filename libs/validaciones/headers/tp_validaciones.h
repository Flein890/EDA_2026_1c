#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Modificado por última vez 27/04 - Cris
*/ 

//===========================================================================//

// Tipos de valores VALIDABLES.
typedef enum {
    TIPO_ENTERO_POSITIVO,
    TIPO_ENTERO_NEGATIVO,
    TIPO_FLOTANTE_POSITIVO,
    TIPO_FLOTANTE_NEGATIVO,
    TIPO_SOLO_LETRAS,
    TIPO_SOLO_DIGITOS,
    TIPO_ALFANUMERICO,
    TIPO_VACIO,
    TIPO_DESCONOCIDO,
    TIPO_GAGA
} TipoDatoIngresado;

// Signos.

typedef enum {
    SIGNO_NO_IMPORTA,
    SIGNO_POSITIVO,
    SIGNO_NEGATIVO
} ReglaSigno;
//===========================================================================//

// ==== Funciones.

//  Auxiliares
const char* TipoDatoToString(TipoDatoIngresado tipo);           // Devuelve el nombre del tipo de dato ingresado como string.
void eliminarCaracter(char cadena[], int posicion);             // Sin uso. Elimina un caracter en una posición especifica.
const char* SignoToString(ReglaSigno tipo);                     // Devuelve el signo correspondiente como string.

// Carga de Datos.

//* [!!] LOS ELEMENTOS IDENTIFICADOS COMO "INVÁLIDOS" SE CONTROLAN DESDE UN STRING EN EL .C DE VALIDACIONES

TipoDatoIngresado IdentificarTipoDato(char cadena[]);           // Clasifica un strin ingresado según TipoDatoIngresado (USO INTERNO).
//int IngresarEntero(ReglaSigno signo);                           // Permite y valida el ingreso de enteros. (Puede ser RESTRICTIVO: Unicamente Positivos, Negativos o ambos). Controlado por ReglaSigno.
bool IngresarEntero(ReglaSigno signo, bool permitirExit, int *valor); 
/*
    Sobre IngresarEntero:

    Reasignado a BOOL para poder ser utilizado como funcion de corte en caso de ser necesario.

    Signo: Restringe el signo del numero a cargar. (+ - o indiferente)

    permitirExit: 
                  True / False, controla SI ES UTILIZADO COMO FUNCION DE CORTE, al ingresar EXIT, retorna false. 
                  Permitiendo ser utilizado como control de carga. En caso de false, funciona como antes, hasta q no se
                  ingresa el valor correcto, no corta.

    *valor: Dado a que la funcion ahora es un bool, la variable donde se almacenará el valor comprobado ahora deberá ser pasada por
            referencia.

*/
double IngresarDecimal(ReglaSigno signo);                       // Permite y valida el ingreso de decimales. (Puede ser RESTRICTIVO: Unicamente Positivos, Negativos o ambos). Controlado por ReglaSigno.
//---------------------------------------------------------//
// [!] SE DEBE USAR FREE UNA VEZ YA NO SE UTILICEN MÁS [!]
char* IngresarSoloLetras();                                     // Permite y valida el ingreso de únicamente letras.
char* IngresarAlfanumerico();                                   // Permite y valida el ingreso de caracteres alfanumericos. 
//---------------------------------------------------------//