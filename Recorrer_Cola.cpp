//Insertar y mostrar los elementos de una cola
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

void insertarCola(Nodo *&, Nodo*&, int);
bool cola_vacia(Nodo *);
void recorrerCola(Nodo *);
void eliminar_elemCola(Nodo *&,Nodo *&, int &);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato;
	char rpt;
	
	cout<<"Desea capturar un dato? (s/n): ";
	cin>>rpt;
	while(rpt == 's' || rpt=='S')
	{
		cout<<"\nCaptura un dato para agregar a la cola: ";
		cin>>dato;
		insertarCola(frente,fin,dato);
		cout<<"Desea capturar otro dato? (s/n): ";
		cin>>rpt;
	}
	cout<<endl;
	cout<<endl;
	cout<<"Los elementos que contiene la cola son"<<endl;
	recorrerCola(frente);
	
	while(frente != NULL)
	{
		eliminar_elemCola(frente,fin,dato);
	}
	
	getch();
	return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente =NULL;
	if (cola_vacia(frente))
	{
		frente = nuevo_nodo;
	}
	else
	{
		fin -> siguiente = nuevo_nodo;
	}
}

bool cola_vacia(Nodo *frente)
{
	if (frente == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void recorrerCola(Nodo *frente)
{
	Nodo *auxiliar = frente;
	while(auxiliar != NULL)
	{
		cout<<"\n "<<auxiliar -> dato<<endl;
		auxiliar = auxiliar ->siguiente;
	}
}

void eliminar_elemCola(Nodo *&frente, Nodo *&fin, int &n)
{
	n = frente->dato;
	Nodo *auxiliar = frente;
	if(frente == fin)
	{
		frente = NULL;
		fin = NULL;
	}
	else
	{
		frente = frente->siguiente;
	}
	delete auxiliar;
}
