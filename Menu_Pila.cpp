#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void insertarPila(Nodo *&,int);
void eliminarPila(Nodo *&,int &);
void mostrarPila(Nodo *);
void menu();


int main() {
	menu();
	
	getch();
	return 0;
}

void insertarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	cout<<" Se ha capturado el dato";
}
	
void mostrarPila(Nodo *pila){
	Nodo *aux = pila;
	while(aux != NULL){
		cout<<"\n "<<aux->dato<<endl;
		aux = aux->siguiente;
	}
}

void eliminarPila(Nodo *&pila,int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

void menu(){
	Nodo *pila = NULL;
	int opc,dato;
	char rpt;
	do{
		cout<<"\t M E N U \n";
		cout<<"1.- INSERTAR PILA "<<endl;
		cout<<"2.- MOSTRAR PILA "<<endl;
		cout<<"3.- ELIMINA PILA "<<endl;
		cout<<"4.- SALIR "<<endl;
		cout<<endl;
		cin>>opc;
		switch(opc){
		case 1:
			do{
				cout<<"\n Captura un dato para agregar a la pila: ";
				cin>>dato;
				insertarPila(pila, dato);
				cout<<"\n deseas capturar otro dato (S/N) ";
				cin>>rpt;
				
			} while(rpt == 's' || rpt == 'S');
			system("pause");
			system("cls");
		break;
		
		case 2:
			if(pila == NULL){
				cout<<"La pila esta vacia"<<endl;
				cout<<endl;
			}
			else{
				cout<<endl;
				cout<<"Mostrando la pila"<<endl;
				mostrarPila(pila);
			}
			system("pause");
			system("cls");
		break;
		
		case 3:
			while(pila != NULL){
				eliminarPila(pila,dato);
			}
			cout<<"\t La pila ya se elimino "<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cls");
		break;
		
		case 4:
			cout<<"\t Gracias por usar el programa ";
		break;
		}
	} while(opc != 4);
}
