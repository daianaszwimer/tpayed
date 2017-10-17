#include<iostream>
#include<cstdio>
#include<stdlib.h>  	//para la funcion random
#include<string.h>
#include<time.h>		//el random se basa en la hora actual

#define VEL 40 			//Velocidad promedio del movil
#define INF 10000		//Definimos "Infinito" para el valor inicial de los pesos

using namespace std;

struct NODO{
	string descripcion;		//Descripcion para ver que colegio es
	NODO *adyacente[4];		//Vector de punteros que apuntan a los colegios siguientes
	float distancia[4];		//Distancia entre colegios (en cuadras)
	bool etiqueta;			//Va a estar en true si ya pasamos por ese colegio, caso contrario, false
	float pesoAcumulado;	//Distancia + demora + peso anterior
};

void crearMapa(NODO *&P);	//En esta funcion creamos todos los nodos y los interconectamos como pide la consigna
void actualizarPesos(NODO *&actual, int i);		//Actualizamos los pesos de los vertices adyacentes de a donde apunta el puntero
NODO* dijkstra(NODO *&puntero, int j);				//Compara los pesos de los adyacentes, y actualiza el lugar a donde apunta el puntero
bool chequearAdyacentes(NODO *C, string descripcionActual);		//Devuelve true si tiene por lo menos un colegio adyacente con etiqueta=true sin contar el colegio actual

int main(){
	srand(time(NULL));		//Basamos el random en la hora actual
	NODO *puntero=NULL;		//Puntero que va a ir apuntando a cada colegio a medida que avanzemos por el camino
	crearMapa(puntero);
	NODO *camino[9];		//Esta variable es la que vamos a mostrar por pantalla con el recorrido que hay que hacer
	
	camino[0] = puntero;
	//int j=0;
	//while (puntero->descripcion != "Centro de Computos"){
	for(int j=1;j<9;j++){	
		camino[j] = dijkstra(puntero, j);	
	//	j++;
	}
	
	cout<<"El camino es:"<<endl;
	for(int k=0;k<9;k++){
		cout<<camino[k]->descripcion<<endl;
	}
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
	
	CL->etiqueta=true;
	C1->etiqueta=false;
	C2->etiqueta=false;
	C3->etiqueta=false;
	C4->etiqueta=false;
	C5->etiqueta=false;
	C6->etiqueta=false;
	C7->etiqueta=false;
	CC->etiqueta=false;
	
	CL->pesoAcumulado=0;
	C1->pesoAcumulado=INF;
	C2->pesoAcumulado=INF;
	C3->pesoAcumulado=INF;
	C4->pesoAcumulado=INF;
	C5->pesoAcumulado=INF;
	C6->pesoAcumulado=INF;
	C7->pesoAcumulado=INF;
	CC->pesoAcumulado=INF;
	
	CL->distancia[0]=4+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de CL a C1
	CL->distancia[1]=2+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de CL a C2
	C1->distancia[0]=CL->distancia[0];	//Distancia de C1 a CL
	C1->distancia[1]=3+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C1 a C2
	C1->distancia[2]=4+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C1 a C3
	C2->distancia[0]=CL->distancia[1];	//Distancia de C2 a CL
	C2->distancia[1]=C1->distancia[1];	//Distancia de C2 a C1
	C2->distancia[2]=5+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C2 a C3
	C2->distancia[3]=10+(((float) rand() / (RAND_MAX))*VEL);				//Distancia de C2 a C4
	C3->distancia[0]=C1->distancia[2];	//Distancia de C3 a C1
	C3->distancia[1]=C2->distancia[2];	//Distancia de C3 a C2
	C3->distancia[2]=1+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C3 a C4
	C3->distancia[3]=8+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C3 a C5
	C4->distancia[0]=C2->distancia[3];	//Distancia de C4 a C2
	C4->distancia[1]=C3->distancia[2];	//Distancia de C4 a C3
	C4->distancia[2]=9+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C4 a C5
	C5->distancia[0]=C3->distancia[3];	//Distancia de C5 a C3
	C5->distancia[1]=C4->distancia[2];	//Distancia de C5 a C4
	C5->distancia[2]=5+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C5 a C6
	C5->distancia[3]=6+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C5 a C7
	C6->distancia[0]=C5->distancia[2];	//Distancia de C6 a C5
	C6->distancia[1]=4+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C6 a C7
	C6->distancia[2]=2+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C6 a CC
	C7->distancia[0]=C5->distancia[3];	//Distancia de C7 a C5
	C7->distancia[1]=C6->distancia[1];	//Distancia de C7 a C6
	C7->distancia[2]=3+(((float) rand() / (RAND_MAX))*VEL);					//Distancia de C7 a CC
	CC->distancia[0]=C6->distancia[2];	//Distancia de CC a C6
	CC->distancia[1]=C7->distancia[2];	//Distancia de CC a C7
		
	CL->adyacente[0]=C1;				//Conexion CL-C1
	CL->adyacente[1]=C2;				//Conexion CL-C2
	CL->adyacente[2]=NULL;
	CL->adyacente[3]=NULL;
	C1->adyacente[0]=CL;				//Conexion C1-CL
	C1->adyacente[1]=C2;				//Conexion C1-C2
	C1->adyacente[2]=C3;				//Conexion C1-C3
	C1->adyacente[3]=NULL;
	C2->adyacente[0]=CL;				//Conexion C2-CL
	C2->adyacente[1]=C1;				//Conexion C2-C1
	C2->adyacente[2]=C3;				//Conexion C2-C3
	C2->adyacente[3]=C4;				//Conexion C2-C4
	C3->adyacente[0]=C1;				//Conexion C3-C1
	C3->adyacente[1]=C2;				//Conexion C3-C2
	C3->adyacente[2]=C4;				//Conexion C3-C4
	C3->adyacente[3]=C5;				//Conexion C3-C5
	C4->adyacente[0]=C2;				//Conexion C4-C2
	C4->adyacente[1]=C3;				//Conexion C4-C3
	C4->adyacente[2]=C5;				//Conexion C4-C5
	C4->adyacente[3]=NULL;
	C5->adyacente[0]=C3;				//Conexion C5-C3
	C5->adyacente[1]=C4;				//Conexion C5-C4
	C5->adyacente[2]=C6;				//Conexion C5-C6
	C5->adyacente[3]=C7;				//Conexion C5-C7
	C6->adyacente[0]=C5;				//Conexion C6-C5
	C6->adyacente[1]=C7;				//Conexion C6-C7
	C6->adyacente[2]=CC;				//Conexion C6-CC
	C6->adyacente[3]=NULL;
	C7->adyacente[0]=C5;				//Conexion C7-C5
	C7->adyacente[1]=C6;				//Conexion C7-C6
	C7->adyacente[2]=CC;				//Conexion C7-CC
	C7->adyacente[3]=NULL;
	CC->adyacente[0]=C6;				//Conexion CC-C6
	CC->adyacente[1]=C7;				//Conexion CC-C7	
	CC->adyacente[2]=NULL;
	CC->adyacente[3]=NULL;
	P=CL;								//El puntero empieza en el centro de logistica
}

void actualizarPesos(NODO *&actual){
	int i = 0;
	while(actual->adyacente[i]!= NULL && i<4){
		if(actual->adyacente[i]->etiqueta==false){
    		if(actual->pesoAcumulado + actual->distancia[i] < actual->adyacente[i]->pesoAcumulado){
        		actual->adyacente[i]->pesoAcumulado = actual->pesoAcumulado + actual->distancia[i];
    		}
		}
		i++;
	}
}

bool chequearAdyacentes(NODO *C, string descripcionActual){
	int i = 0;
	while(C->adyacente[i]!= NULL && i<4){
		if (C->adyacente[i]->etiqueta == true && C->adyacente[i]->descripcion != descripcionActual){
			return true;
		}
		i++;
	}
	return false;
}

NODO* dijkstra(NODO *&P, int j){	
	int i=0;
	NODO *sgte;
	NODO *camino;
	bool adyacencia = false;
	actualizarPesos(P);
	for (int h=0; h<4; h++){
		if(P->adyacente[i]->etiqueta==true){
			i++;
		}
	}
	camino = P->adyacente[i];
	sgte = P->adyacente[i+1];
	while(sgte!=NULL && i<4){
		if(sgte->etiqueta==false){
			if (chequearAdyacentes(sgte, P->descripcion)){
				adyacencia = true;
				if(sgte->pesoAcumulado < camino->pesoAcumulado || !chequearAdyacentes(camino, P->descripcion)){
					//chequeo que camino tenga algún centro adyacente porque cuando lo seteo por default
					//nada me garantiza que se cumpla
					camino = sgte;
				}
			}
		}
		i++;
		sgte = P->adyacente[i];
	}
	if (!adyacencia){
		//No hay ningún centro cuyos adyacentes hayan sido visitados por lo menos una vez 
		//Busco entonces, el más cercano
		while(sgte!=NULL && i<4){
			if(sgte->etiqueta==false){
				if(sgte->pesoAcumulado < camino->pesoAcumulado){
					camino = sgte;
				}
			}
			i++;
			sgte = P->adyacente[i];
		}
	}
	camino->etiqueta=true;
	
	P = camino;
	return camino;
}
