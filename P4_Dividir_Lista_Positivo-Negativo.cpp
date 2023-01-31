//4.- Escriba un programa que, dada una lista que contiene números, la divida en 
//dos listas independientes, una formada por los números positivos y otra por los 
//números negativos
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

void insertarLista_2(Nodo *&,int);
void mostrarLista_2(Nodo *);
void eliminarLista_2(Nodo *&,int &);

void dividirLista(Nodo *&,Nodo *&);
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

//Lista 2
void insertarLista_2(Nodo *&lista_2, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista_2;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista_2 == aux1){
		lista_2 = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void mostrarLista_2(Nodo *lista_2){
	Nodo *mostrar = lista_2;
	while(mostrar != NULL){
		cout<<"\n "<<mostrar->dato;
		mostrar = mostrar->siguiente;
	}
}

void eliminarLista_2(Nodo *&lista_2,int &n){
	Nodo *aux = lista_2;
	n = aux -> dato;
	lista_2 = lista_2 -> siguiente;
	delete aux;
}

//Dividir Lista
void dividirLista(Nodo *&lista_1,Nodo *&lista_2){
	int x;
	Nodo *aux = lista_1;
	while(aux != NULL){
		if(aux->dato < 0){
			Nodo *aux2 = aux;
			x = aux->dato;
			insertarLista_2(lista_2,x);
			lista_1 = aux->siguiente;
			aux = aux->siguiente;
			delete aux2;
		}
		else{
			aux = aux->siguiente;
		}
	}
}

void menu(){
	Nodo *lista_1 = NULL;
	Nodo *lista_2 = NULL;
	int dato,opc;
	char rpt;
	do{
		cout<<"\n\t B I E N V E N I D O"<<endl;
		cout<<" 1.- Insertar lista"<<endl;
		cout<<" 2.- Mostrar lista"<<endl;
		cout<<" 3.- Eliminar listas"<<endl;
		cout<<" 4.- Dividir lista"<<endl;
		cout<<endl;
		cout<<" 5.- Salir"<<endl;
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
				while(lista_2 != NULL){
					eliminarLista_2(lista_2,dato);
				};
				cout<<endl;
				cout<<" === Lista 1 y 2 Eliminada ===";
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
				cout<<endl;
				cout<<endl;
			}
			else{
				dividirLista(lista_1,lista_2);
				cout<<endl;
				cout<<"\t LISTA DIVIDIDA"<<endl;
				cout<<" == LISTA 1 ==";
				mostrarLista_1(lista_1);
				cout<<"\n == LISTA 2 ==";
				mostrarLista_2(lista_2);
			}
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout<<"\n\t A D I O S :)";
			break;
		default:
			system("cls");
			break;
		}
	} while(opc != 5);
}
