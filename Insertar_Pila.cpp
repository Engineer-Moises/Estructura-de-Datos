//Insertar Elemntos a la Pila
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&, int);

int main() {
	
	Nodo *pila =NULL;
	int dato;
	char resp;
	
	do{
		cout << "\n Captura dato a agregar a la pila: ";
		cin>>dato;
		agregarPila (pila,dato);
		cout<<" ¿Desea capturar otro elemento? (s/n): ";
		cin>>resp;
	} while(resp == 's' || resp == 'S');
	
	getchar();
	return 0;
}


void agregarPila(Nodo *&pila, int n){
	
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila= nuevo_nodo;
	cout<<"\t Se ha capturado el dato en la pila";
}
