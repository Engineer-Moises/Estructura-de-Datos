//Insertar Elemntos a la Pila
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

void agregarPila (Nodo *&, int);
void mostrarPila (Nodo *);

int main()
{
	
	Nodo *pila =NULL;
	int dato;
	char resp;
	
	do
	{
		cout << "\n Captura dato para agregar a la pila: ";
		cin>>dato;
		agregarPila (pila,dato);
		cout<<" ¿Desea capturar otro elemento? (s/n): ";
		cin>>resp;
	} while(resp == 's' || resp == 'S');
	
	cout<<endl;
	cout<<endl;
	cout<<"\t Los elementos que contiene la pila son:"<<endl;
	mostrarPila(pila);
	cout<<endl;
	getchar();
	return 0;
}


void agregarPila(Nodo *&pila, int n)
{
	
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila= nuevo_nodo;
	cout<<"\t Se ha capturado el dato en la pila";
}

void mostrarPila(Nodo *pila)
{
	Nodo *auxiliar = pila;
	while (auxiliar != NULL)
	{
		cout <<"\n "<<auxiliar -> dato<<endl;
		auxiliar = auxiliar ->siguiente;
	}
}
