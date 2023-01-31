//1.- Programa que calcule el número de elementos de una lista enlazada
//Moisés Hernández Cruz

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

void insertarLista_Ascen(Nodo *&,int);
void mostrarLista_Ascen(Nodo *);
void eliminarLista_Ascen(Nodo *&,int);
int numElementos(Nodo *);

void menu();

int main() {
	
	menu();
	
	getch();
	return 0;
}

//Lista Ascendente
void insertarLista_Ascen(Nodo *&lista_Asc, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista_Asc;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista_Asc == aux1){
		lista_Asc = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void mostrarLista_Ascen(Nodo *lista_Asc){
	Nodo *mostrar = lista_Asc;
	while(mostrar != NULL){
		cout<<"\n"<<mostrar->dato;
		mostrar = mostrar->siguiente;
	}
}

void eliminarLista_Ascen(Nodo *&lista_Asc,int n){
	Nodo *aux = lista_Asc;
	n = aux -> dato;
	lista_Asc = lista_Asc -> siguiente;
	delete aux;
}

int numElementos(Nodo *lista_Asc){
	int c=0;
	Nodo *aux = lista_Asc;
	while(aux != NULL){
		c++;
		aux = aux->siguiente;
	}
	return c;
}

void menu(){
	Nodo *lista_Asc = NULL;
	int dato,opc;
	char rpt;
	do{
		cout<<"\n\t B I E N V E N I D O"<<endl;
		cout<<" 1.- Insertar lista de manera ascendente"<<endl;
		cout<<" 2.- Mostrar lista ascendente"<<endl;
		cout<<" 3.- Mostrar numero de elementos en la lista"<<endl;
		cout<<" 4.- Eliminar lista ascendente"<<endl;
		cout<<endl;
		cout<<" 5.- Salir"<<endl;
		cout<<" Escoga una opcion: ";
		cin>>opc;
		switch(opc){
		case 1:
			cout<<"\n\t LISTA ASCENDENTE";
			do{
				cout<<"\n Captura un numero para agregar a la lista: ";
				cin>>dato;
				insertarLista_Ascen(lista_Asc,dato);
				
				cout<<"\t ¿Desea capurar otro dato S/N?: ";
				cin>>rpt;
			} while(rpt == 's' || rpt == 'S');
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 2:
			if(lista_Asc ==  NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
				cout<<endl;
				cout<<endl;
			}
			else{
				cout<<endl;
				cout<<" === LISTA ASCENDENTE ===";
				mostrarLista_Ascen(lista_Asc);
				cout<<endl;
				cout<<endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout<<endl;
			if(lista_Asc == NULL){
				cout<<"La lista no tiene elementos";
			}
			else{
				cout<<"La lista contiene "<<numElementos(lista_Asc)<<" elementos";
			}
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 4:
			if(lista_Asc ==  NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
				cout<<endl;
				cout<<endl;
			}
			else{
				while(lista_Asc != NULL){
					eliminarLista_Ascen(lista_Asc,dato);
				};
				cout<<endl;
				cout<<" === Lista Eliminada ===";
				cout<<endl;
				cout<<endl;
			}
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
