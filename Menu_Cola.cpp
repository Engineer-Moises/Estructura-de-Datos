//Insertar y mostrar los elementos de una cola
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

void menu();
void insertarCola(Nodo *&, Nodo*&, int);
bool cola_vacia(Nodo *);
void recorrerCola(Nodo *);
void eliminar_elemCola(Nodo *&,Nodo *&, int &);

int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato,opc;
	char rpt;
	do{
		cout<<"\n\t M E N U\n"<<endl;
		cout<<" 1.- Insertar Cola"<<endl;
		cout<<" 2.- Mostrar Cola"<<endl;
		cout<<" 3.- Eliminar Cola"<<endl;
		cout<<" 4.- Salir"<<endl;
		cin>>opc;
		switch(opc){
		case 1:
			cout<<" Desea capturar un dato? (s/n): ";
			cin>>rpt;
			while(rpt == 's' || rpt=='S')
			{
				cout<<"\n Captura un dato para agregar a la cola: ";
				cin>>dato;
				insertarCola(frente,fin,dato);
				cout<<" Desea capturar otro dato? (s/n): ";
				cin>>rpt;
			};
			system("pause");
			system("cls");
		break;
		case 2:
			if(frente == NULL){
				cout<<" La cola esta vacía";
			}
			else{
				cout<<endl;
				cout<<endl;
				cout<<" Los elementos que contiene la cola son"<<endl;
				recorrerCola(frente);
			}
			system("pause");
			system("cls");
		break;
		case 3:
			while(frente != NULL){
				eliminar_elemCola(frente,fin,dato);
				cout<<endl;
			};
			cout<<"\t La cola ya se eliminó"<<endl;
			system("pause");
			system("cls");
		break;
		case 4:
			cout<<" Gracias por usar el programa";
		break;
		}
	} while(opc != 4);
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
