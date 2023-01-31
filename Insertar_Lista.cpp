//Insertar elementos en la lista

#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);

int main() {
	
	Nodo *lista = NULL;
	int dato;
	char rpt;
	
	do{
		cout<<"\n Captura un numero para agregar a la lista: ";
		cin>>dato;
		insertarLista(lista,dato);
		
		cout<<"\t ¿Desea capurar otro dato S/N?: ";
		cin>>rpt;
		
	} while(rpt == 's' || rpt == 'S');
	cout<<endl;
	
	if(lista ==  NULL){
		cout<<" La lista esta vacia";
	}
	else{
		mostrarLista(lista);
	}
	
	getch();
	return 0;
}

void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void mostrarLista(Nodo *lista){
	Nodo *mostrar = lista;
	while(mostrar != NULL){
		cout<<mostrar->dato<<" ";
		mostrar = mostrar->siguiente;
	}
}
