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

int main()
{
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	char rpt;
	int dato;
	
	do{
		cout<<"\n Captura un dato para agregarlo a la cola: ";
		cin>>dato;
		insertarCola(frente,fin,dato);
		fflush(stdin);
		cout<<"\tDeseas capturar otro dato (s/n): ";
		cin>>rpt;
	} while(rpt == 'S' || rpt=='s');
	cout<<endl;
	cout<<endl;
	return 0;
}

void insertarCola(Nodo *&frente, Nodo *& fin, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
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
