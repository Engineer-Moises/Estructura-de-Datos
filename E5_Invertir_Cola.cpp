//Escribir un programa que invierta los elementos de una cola
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
void mostrarCola(Nodo *);
void invertirCola(Nodo *&,Nodo *&,Nodo *&);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	Nodo *pila = NULL;
	int dato;
	char rpt;
	
	do
	{
		cout<<"\n Captura un dato para agregar a la cola: ";
		cin>>dato;
		insertarCola(frente,fin,dato);
		cout<<" Desea capturar otro dato? (s/n): ";
		cin>>rpt;
	}while(rpt == 's' || rpt=='S');
	cout<<endl;
	cout<<endl;
	cout<<" Los elementos que contiene la cola son"<<endl;
	mostrarCola(frente);
	cout<<endl;
	cout<<endl;
	cout<<" Recorriendo la cola..."<<endl;
	invertirCola(frente,fin,pila);
	mostrarCola(frente);
	
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
	fin = nuevo_nodo;
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

void mostrarCola(Nodo *frente)
{
	Nodo *aux = frente;
	while(aux != NULL)
	{
		cout<<" ";
		cout<<aux->dato;
		aux = aux->siguiente;
	};
}

void invertirCola(Nodo *&frente,Nodo *&fin,Nodo *&pila)
{
	if(cola_vacia(frente))
	{
		cout<<" Cola Vacia";
	}
	else
	{
		while(frente != NULL)
		{
			Nodo *nuevo_nodo = new Nodo();
			Nodo *aux = frente;
			nuevo_nodo -> dato = aux->dato;
			if(frente == fin)
			{
				frente = NULL;
				fin = NULL;
			}
			else
			{
				frente = frente->siguiente;
			}
			delete aux;
			nuevo_nodo -> siguiente = pila;
			pila= nuevo_nodo;
		};
		while(pila != NULL)
		{
			int n;
			Nodo *aux = pila;
			n = aux->dato;
			insertarCola(frente,fin,n);
			pila = pila->siguiente;
			delete aux;
		};
	}
}
