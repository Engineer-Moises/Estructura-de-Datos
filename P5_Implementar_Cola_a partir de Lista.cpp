//5.- Escriba un programa para implementar una estructura tipo cola mediante una lista
//Moisés Hernández Cruz

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

void insertarLista_1(Nodo *&,int);
void mostrarLista_1(Nodo *);
void eliminarLista_1(Nodo *&,int &);

void insertarCola(Nodo *&, Nodo*&,Nodo *&);
bool cola_vacia(Nodo *);
void mostrarCola(Nodo *);
void recorrerCola(Nodo *&,Nodo *&);

void menu();

int main() {
	
	menu();
	
	getch();
	return 0;
}

//Lista 1
void insertarLista_1(Nodo *&lista_1, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista_1;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista_1 == aux1){
		lista_1 = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void mostrarLista_1(Nodo *lista_1){
	Nodo *mostrar = lista_1;
	while(mostrar != NULL){
		cout<<"\n "<<mostrar->dato;
		mostrar = mostrar->siguiente;
	}
}

void eliminarLista_1(Nodo *&lista_1,int &n){
	Nodo *aux = lista_1;
	n = aux -> dato;
	lista_1 = lista_1 -> siguiente;
	delete aux;
}

//Cola
void insertarCola(Nodo *&frente, Nodo *& fin,Nodo *&lista_1)
{
	int n;
	Nodo *aux = lista_1;
	n = aux->dato;
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
	fin = nuevo_nodo;
	lista_1 = lista_1->siguiente;
	delete aux;
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

void recorrerCola(Nodo *&frente,Nodo *&fin)
{
	if(cola_vacia(frente))
	{
		
	}
	else
	{
		Nodo *aux = frente;
		frente = frente->siguiente;
		delete aux;
	}
}
	
void menu(){
	Nodo *lista_1 = NULL;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato,opc;
	char rpt;
	do{
		cout<<"\n\t B I E N V E N I D O"<<endl;
		cout<<" 1.- Insertar lista"<<endl;
		cout<<" 2.- Mostrar lista"<<endl;
		cout<<" 3.- Eliminar lista"<<endl;
		cout<<" 4.- Crear Cola a partir de lista"<<endl;
		cout<<" 5.- Mostrar Cola"<<endl;
		cout<<endl;
		cout<<" 6.- Salir"<<endl;
		cout<<" Escoga una opcion: ";
		cin>>opc;
		switch(opc){
		case 1:
			cout<<"\n\t LISTA";
			do{
				cout<<"\n Captura un numero para agregar a la lista: ";
				cin>>dato;
				insertarLista_1(lista_1,dato);
				
				cout<<"\t ¿Desea capurar otro dato S/N?: ";
				cin>>rpt;
				
			} while(rpt == 's' || rpt == 'S');
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 2:
			if(lista_1 ==  NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
				cout<<endl;
				cout<<endl;
			}
			else{
				cout<<endl;
				cout<<" === LISTA 1 ===";
				mostrarLista_1(lista_1);
				cout<<endl;
				cout<<endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			if(lista_1 ==  NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
				cout<<endl;
				cout<<endl;
			}
			else{
				while(lista_1 != NULL){
					eliminarLista_1(lista_1,dato);
				};
				cout<<endl;
				cout<<" === Lista Eliminada ===";
				cout<<endl;
				cout<<endl;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if(lista_1 == NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
			}
			else{
				while(frente != NULL){
					recorrerCola(frente,fin);
				}
				while(lista_1 != NULL){
					insertarCola(frente,fin,lista_1);
				}
				cout<<endl;
				cout<<" == COLA =="<<endl;
				mostrarCola(frente);
			}
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout<<endl;
			cout<<" == COLA =="<<endl;
			mostrarCola(frente);
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 6:
			cout<<"\n\t A D I O S :)";
			break;
		default:
			system("cls");
			break;
		}
	} while(opc != 6);
}
