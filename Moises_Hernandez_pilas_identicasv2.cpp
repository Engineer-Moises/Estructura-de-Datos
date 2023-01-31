//Escribe un programa que verifique que el contenido de las dos pilas son indenticas
//Moisés Hernández Cruz
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void insertarPila(Nodo *&,int);
void eliminarPila(Nodo *&,int &);
void mostrarPila(Nodo *);

void insertarPila2(Nodo *&,int);
void eliminarPila2(Nodo *&,int &);
void mostrarPila2(Nodo *);

bool pilas_Semejantes(Nodo *&, Nodo *&);
void compararPilas(Nodo *&,Nodo *&);

int main() {
	Nodo *pila = NULL;
	Nodo *pila2 = NULL;
	int dato;
	char rpt;
	
	do{
		cout<<"\n Captura un dato para agregar a la pila 1: ";
		cin>>dato;
		insertarPila(pila, dato);
		cout<<"\n deseas capturar otro dato (S/N) ";
		cin>>rpt;
		
	} while(rpt == 's' || rpt == 'S');
	cout<<endl;
	do{
		cout<<"\n Captura un dato para agregar a la pila 2: ";
		cin>>dato;
		insertarPila2(pila2, dato);
		cout<<"\n deseas capturar otro dato (S/N) ";
		cin>>rpt;
		
	} while(rpt == 's' || rpt == 'S');
	
	mostrarPila(pila);
	mostrarPila2(pila2);
	compararPilas(pila,pila2);

	getch();
	return 0;
}
//Pila 1
void insertarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	cout<<" Se ha capturado el dato";
}

void mostrarPila(Nodo *pila){
	Nodo *aux = pila;
	cout<<endl;
	cout<<"=== Pila 1 ==="<<endl;
	while(aux != NULL){
		cout<<"\n "<<aux->dato<<endl;
		aux = aux->siguiente;
	}
	cout<<endl;
}

void eliminarPila(Nodo *&pila,int &a){
	Nodo *aux = pila;
	a = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
//Pila 2
void insertarPila2(Nodo *&pila2,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila2;
	pila2 = nuevo_nodo;
	cout<<" Se ha capturado el dato";
}

void mostrarPila2(Nodo *pila2){
	Nodo *aux = pila2;
	cout<<endl;
	cout<<"=== Pila 2 ==="<<endl;
	while(aux != NULL){
		cout<<"\n "<<aux->dato<<endl;
		aux = aux->siguiente;
	}
	cout<<endl;
}

void eliminarPila2(Nodo *&pila2,int &b){
	Nodo *aux = pila2;
	b = aux->dato;
	pila2 = aux->siguiente;
	delete aux;
}
//Otros
bool pilas_Semejantes(Nodo *&pila,Nodo *&pila2){
	bool band;
	int cont_p1 = 0;
	int cont_p2 = 0;
	Nodo *aux = pila;
	Nodo *aux2 = pila2;
	if(pila == NULL && pila2 == NULL){
		cout<<"\n **Pilas Vacias**"<<endl;
		band = false;
	}
	else{
		while(aux != NULL){
			cont_p1++;
			aux = aux->siguiente;
		}
		while(aux2 != NULL){
			cont_p2++;
			aux2 = aux2->siguiente;
		}
		if(cont_p1 == cont_p2){
			band = true;
		}
		else{
			band = false;
		}
	}
	return band;
}

void compararPilas(Nodo *&pila,Nodo *&pila2){
	Nodo *aux = pila;
	int a,b;
	bool iguales = false;
	if(pilas_Semejantes(pila,pila2)){
		iguales = true;
		while(aux != NULL && iguales){
			eliminarPila(pila,a);
			eliminarPila2(pila2,b);
			aux = pila;
			if(a == b){
			}
			else{
				iguales = false;
				while(aux!=NULL){
					eliminarPila(pila,a);
					eliminarPila2(pila2,b);
					aux = pila;
				}
			}
		}
	}
	if(iguales){
		cout<<"\n\t (((Las pilas son IDENTICAS)))"<<endl;
	}
	else{
		cout<<"\n\t ***Las pilas son DIFERENTES***"<<endl;
	}
}
