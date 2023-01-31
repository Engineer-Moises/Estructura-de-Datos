//Insertar Elemntos a la Pila
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//Estructuras
struct Nodo
{
	int dato;
	Nodo *siguiente;
};

//Prototipos de funciones
void agregarPila (Nodo *&, int); //En los parametros solo se pone el tipo de dato (y un & en caso de que se pase por referencia)
void mostrarPila (Nodo *);
void eliminarPila (Nodo *&, int &);

//Programa Principal
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
	
	cout<<"\t ===== Eliminando elementos ====="<<endl;
	do
	{
		eliminarPila(pila,dato);
	} while( pila != NULL);
	mostrarPila (pila);
	cout<<"\t         Pila Eliminada"<<endl;
	
	return 0;
}

//Funciones
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

void eliminarPila (Nodo *&pila, int &n)
{
	Nodo *aux = pila;
	n = aux -> dato;
	pila = aux ->siguiente;
	delete aux;
}
