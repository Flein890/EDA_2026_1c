	#include <stdlib.h>
	#include "tp_1_recursividad.h"
	#define max_elementos 10 //defino un maximo en el que la funcion va a trabajar
	#define max_resultados (1<<max_elementos) // defino un maximo de resultados (2^n resultados)

	//Prototipos de funciones
	int ** subconjuntosQueSumanN(int conjunto[],int n);
	int ** Aux_subconjuntosQueSumanN(int conjunto[],int n, int suma, int indice, int **resultados, int subconjunto_act[],int tamano_sub_conjunto,int *cant_resultados);

	//Funcion principal
	int ** subconjuntosQueSumanN(int conjunto[],int n){
		int suma=0;
		int subconjunto_act[max_elementos]={0};
		int tamano_sub_conjunto=0;	
		int **resultados= malloc (max_resultados*sizeof(int *)); //Declaro resultados y reservo x numero de memoria para max numero de punteros 
		for (int i = 0; i < max_resultados; i++){
		resultados[i] = NULL; //inicializo todo puntero en NULL
	}
		int cant_resultados=0;
		Aux_subconjuntosQueSumanN(conjunto,n,suma,max_elementos-1 ,resultados,subconjunto_act,tamano_sub_conjunto,&cant_resultados);
		return resultados;
	}
	// funcion recursiva auxiliar
	int ** Aux_subconjuntosQueSumanN(int conjunto[],int n, int suma, int indice, int **resultados, int subconjunto_act[],int tamano_sub_conjunto,int *cant_resultados){
		if (indice<0){
			return resultados; //corte de rama y backtrack al llegar al indice negativo 
		}
		if (suma==n){
			resultados[*cant_resultados]= malloc(tamano_sub_conjunto * sizeof(int)); //Reservo memoria para el tamaño del vector tamano_sub_conjunto
			for (int i=0; i<tamano_sub_conjunto; i++){
				resultados[*cant_resultados][i]=subconjunto_act[i];
			}
		(*cant_resultados)++;
		return resultados;	
		}
		if (suma>n){
			return resultados; //Corte y backtrack si suma supera N
		}
		if (suma<n){
			subconjunto_act[tamano_sub_conjunto]=conjunto[indice];
			Aux_subconjuntosQueSumanN(conjunto,n,suma+subconjunto_act[tamano_sub_conjunto],indice-1,resultados,subconjunto_act,tamano_sub_conjunto+1, cant_resultados); //Rama recursiva incluyendo el numero actual
			Aux_subconjuntosQueSumanN(conjunto,n,suma,indice-1,resultados,subconjunto_act,tamano_sub_conjunto, cant_resultados); //Rama recursiva excluyendo el numero actual
		}
	}


	int main(){
		int conjunto[6]= {10, 3, 1, 7, 4, 2};
		int n=7;
		int **resultados= subconjuntosQueSumanN(conjunto, n);
		return 0;
	}
			
