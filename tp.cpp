#include<iostream>
#include<cstdio>
#include<stdlib.h>  	//para la funcion random
#include<string.h>
#include<time.h>		//el random se basa en la hora actual

#define VEL 40 			//Velocidad promedio del movil

using namespace std;

struct NODO{
	string descripcion;		//Descripcion para ver que colegio es
	NODO *adyacente[4];		//Vector de punteros que apuntan a los colegios siguientes
	int distancia[4];		//Distancia entre colegios (en cuadras)
	float demora[4];		//Demora entre colegios
};

void crearMapa(NODO *&P);	//En esta funcion creamos todos los nodos y los interconectamos como pide la consigna

int main(){
	srand(time(NULL));		//Basamos el random en la hora actual
	NODO *Puntero=NULL;		//Puntero que va a ir apuntando a cada colegio a medida que avanzemos por el camino
	crearMapa(Puntero);
	return 0;
}

void crearMapa(NODO *&P){
	NODO *CL = new NODO();
	NODO *C1 = new NODO();
	NODO *C2 = new NODO();
	NODO *C3 = new NODO();
	NODO *C4 = new NODO();
	NODO *C5 = new NODO();
	NODO *C6 = new NODO();
	NODO *C7 = new NODO();
	NODO *CC = new NODO();
	
	CL->descripcion="Centro de Logistica";
	C1->descripcion="Colegio Nro. 1";
	C2->descripcion="Colegio Nro. 2";
	C3->descripcion="Colegio Nro. 3";
	C4->descripcion="Colegio Nro. 4";
	C5->descripcion="Colegio Nro. 5";
	C6->descripcion="Colegio Nro. 6";
	C7->descripcion="Colegio Nro. 7";
	CC->descripcion="Centro de Computos";
	
	CL->distancia[0]=4;					//Distancia de CL a C1
	CL->distancia[1]=2;					//Distancia de CL a C2
	C1->distancia[0]=CL->distancia[0];	//Distancia de C1 a CL
	C1->distancia[1]=3;					//Distancia de C1 a C2
	C1->distancia[2]=4;					//Distancia de C1 a C3
	C2->distancia[0]=CL->distancia[1];	//Distancia de C2 a CL
	C2->distancia[1]=C1->distancia[1];	//Distancia de C2 a C1
	C2->distancia[2]=5;					//Distancia de C2 a C3
	C2->distancia[3]=10;				//Distancia de C2 a C4
	C3->distancia[0]=C1->distancia[2];	//Distancia de C3 a C1
	C3->distancia[1]=C2->distancia[2];	//Distancia de C3 a C2
	C3->distancia[2]=1;					//Distancia de C3 a C4
	C3->distancia[3]=8;					//Distancia de C3 a C5
	C4->distancia[0]=C2->distancia[3];	//Distancia de C4 a C2
	C4->distancia[1]=C3->distancia[2];	//Distancia de C4 a C3
	C4->distancia[2]=9;					//Distancia de C4 a C5
	C5->distancia[0]=C3->distancia[3];	//Distancia de C5 a C3
	C5->distancia[1]=C4->distancia[2];	//Distancia de C5 a C4
	C5->distancia[2]=5;					//Distancia de C5 a C6
	C5->distancia[3]=6;					//Distancia de C5 a C7
	C6->distancia[0]=C5->distancia[2];	//Distancia de C6 a C5
	C6->distancia[1]=4;					//Distancia de C6 a C7
	C6->distancia[2]=2;					//Distancia de C6 a CC
	C7->distancia[0]=C5->distancia[3];	//Distancia de C7 a C5
	C7->distancia[1]=C6->distancia[1];	//Distancia de C7 a C6
	C7->distancia[2]=3;					//Distancia de C7 a CC
	CC->distancia[1]=C6->distancia[2];	//Distancia de CC a C6
	CC->distancia[2]=C7->distancia[2];	//Distancia de CC a C7
	
	CL->demora[0]=((float) rand() / (RAND_MAX))*VEL;					
	CL->demora[1]=((float) rand() / (RAND_MAX))*VEL;				
	C1->demora[0]=((float) rand() / (RAND_MAX))*VEL;	
	C1->demora[1]=((float) rand() / (RAND_MAX))*VEL;					
	C1->demora[2]=((float) rand() / (RAND_MAX))*VEL;					
	C2->demora[0]=((float) rand() / (RAND_MAX))*VEL;	
	C2->demora[1]=((float) rand() / (RAND_MAX))*VEL;	
	C2->demora[2]=((float) rand() / (RAND_MAX))*VEL;					
	C2->demora[3]=((float) rand() / (RAND_MAX))*VEL;				
	C3->demora[0]=((float) rand() / (RAND_MAX))*VEL;	
	C3->demora[1]=((float) rand() / (RAND_MAX))*VEL;	
	C3->demora[2]=((float) rand() / (RAND_MAX))*VEL;					
	C3->demora[3]=((float) rand() / (RAND_MAX))*VEL;					
	C4->demora[0]=((float) rand() / (RAND_MAX))*VEL;	
	C4->demora[1]=((float) rand() / (RAND_MAX))*VEL;	
	C4->demora[2]=((float) rand() / (RAND_MAX))*VEL;					
	C5->demora[0]=((float) rand() / (RAND_MAX))*VEL;	
	C5->demora[1]=((float) rand() / (RAND_MAX))*VEL;	
	C5->demora[2]=((float) rand() / (RAND_MAX))*VEL;					
	C5->demora[3]=((float) rand() / (RAND_MAX))*VEL;					
	C6->demora[0]=((float) rand() / (RAND_MAX))*VEL;	
	C6->demora[1]=((float) rand() / (RAND_MAX))*VEL;					
	C6->demora[2]=((float) rand() / (RAND_MAX))*VEL;					
	C7->demora[0]=((float) rand() / (RAND_MAX))*VEL;	
	C7->demora[1]=((float) rand() / (RAND_MAX))*VEL;	
	C7->demora[2]=((float) rand() / (RAND_MAX))*VEL;					
	CC->demora[1]=((float) rand() / (RAND_MAX))*VEL;	
	CC->demora[2]=((float) rand() / (RAND_MAX))*VEL;
		
	CL->adyacente[0]=C1;				//Conexi�n CL-C1
	CL->adyacente[1]=C2;				//Conexi�n CL-C2
	C1->adyacente[0]=CL;				//Conexi�n C1-CL
	C1->adyacente[1]=C2;				//Conexi�n C1-C2
	C1->adyacente[2]=C3;				//Conexi�n C1-C3
	C2->adyacente[0]=CL;				//Conexi�n C2-CL
	C2->adyacente[1]=C1;				//Conexi�n C2-C1
	C2->adyacente[2]=C3;				//Conexi�n C2-C3
	C2->adyacente[3]=C4;				//Conexi�n C2-C4
	C3->adyacente[0]=C1;				//Conexi�n C3-C1
	C3->adyacente[1]=C2;				//Conexi�n C3-C2
	C3->adyacente[2]=C4;				//Conexi�n C3-C4
	C3->adyacente[3]=C5;				//Conexi�n C3-C5
	C4->adyacente[0]=C2;				//Conexi�n C4-C2
	C4->adyacente[1]=C3;				//Conexi�n C4-C3
	C4->adyacente[2]=C5;				//Conexi�n C4-C5
	C5->adyacente[0]=C3;				//Conexi�n C5-C3
	C5->adyacente[1]=C4;				//Conexi�n C5-C4
	C5->adyacente[2]=C6;				//Conexi�n C5-C6
	C5->adyacente[3]=C7;				//Conexi�n C5-C7
	C6->adyacente[0]=C5;				//Conexi�n C6-C5
	C6->adyacente[1]=C7;				//Conexi�n C6-C7
	C6->adyacente[2]=CC;				//Conexi�n C6-CC
	C7->adyacente[0]=C5;				//Conexi�n C7-C5
	C7->adyacente[1]=C6;				//Conexi�n C7-C6
	C7->adyacente[2]=CC;				//Conexi�n C7-CC
	CC->adyacente[1]=C6;				//Conexi�n CC-C6
	CC->adyacente[2]=C7;				//Conexi�n CC-C7	
	
	P=CL;								//El puntero empieza en el centro de log�stica
}
