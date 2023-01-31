//Escribir un programa que cree una pila a partir de una cola
//Moisés Hernández Cruz
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void insertarCola(Nodo *&, Nodo*&, int);
bool cola_vacia(Nodo *);
void recorrerCola(Nodo *);
void eliminar_elemCola(Nodo *&,Nodo *&, int &);

void insertarPila(Nodo *&,int);
void mostrarPila(Nodo *);
void crear_Pila(Nodo *&,Nodo *&,Nodo *&);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	Nodo *pila = NULL;
	int dato;
	char rpt;
	do{
		cout<<"\n Captura un dato para agregar a la cola: ";
		cin>>dato;
		insertarCola(frente,fin,dato);
		cout<<" Desea capturar otro dato? (s/n): ";
		cin>>rpt;
	} while(rpt == 's' || rpt=='S');
	
	cout<<endl;
	cout<<endl;
	cout<<"\n ** Elemento de la Cola **"<<endl;
	recorrerCola(frente);
	cout<<"\n == Elemento de la Pila ==";
	crear_Pila(frente,fin,pila);
	mostrarPila(pila);
	cout<<endl;
	
	getch();
	return 0;
}
//Cola
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

void recorrerCola(Nodo *frente)
{
	Nodo *auxiliar = frente;
	cout<<endl;
	while(auxiliar != NULL)
	{
		cout<<" "<<auxiliar -> dato;
		auxiliar = auxiliar ->siguiente;
	}
	cout<<endl;
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
//Pila
void insertarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void mostrarPila(Nodo *pila){
	Nodo *aux = pila;
	cout<<endl;
	while(aux != NULL){
		cout<<"\n "<<aux->dato<<endl;
		aux = aux->siguiente;
	}
	cout<<endl;
}

void crear_Pila(Nodo *&frente,Nodo *&fin,Nodo *&pila){
	int n;
	if(cola_vacia(frente)){
		
	}
	else{
		while(frente != NULL){
			eliminar_elemCola(frente,fin,n);
			insertarPila(pila,n);
		}
	}
}
