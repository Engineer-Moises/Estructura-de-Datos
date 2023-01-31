//3.- Escriba un programa que lea dos listas que se encuentran ordenadas de forma 
//ascendente  y formen una tercera que resulte de la mezcla de los elementos de ambas listas
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

void insertarLista_3(Nodo *&,int);
void mostrarLista_3(Nodo *);
void eliminarLista_3(Nodo *&,int &);
void combinarListas(Nodo *&,Nodo *&,Nodo *&,int n);

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

//Lista 3
void insertarLista_3(Nodo *&lista_3, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista_3;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista_3 == aux1){
	lista_3 = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void mostrarLista_3(Nodo *lista_3){
	Nodo *mostrar = lista_3;
	while(mostrar != NULL){
		cout<<"\n "<<mostrar->dato;
		mostrar = mostrar->siguiente;
	}
}

void eliminarLista_3(Nodo *&lista_3,int &n){
	Nodo *aux = lista_3;
	n = aux -> dato;
	lista_3 = lista_3 -> siguiente;
	delete aux;
}

void combinarListas(Nodo *&lista_1,Nodo *&lista_2,Nodo *&lista_3,int n){
	int x;
	while(lista_1 != NULL){
		eliminarLista_1(lista_1,x);
		insertarLista_3(lista_3,x);
	}
	while(lista_2 != NULL){
		eliminarLista_2(lista_2,x);
		insertarLista_3(lista_3,x);
	}
}
	

void menu(){
	Nodo *lista_1 = NULL;
	Nodo *lista_2 = NULL;
	Nodo *lista_3 = NULL;
	int dato,opc;
	char rpt;
	do{
		cout<<"\n\t B I E N V E N I D O"<<endl;
		cout<<" 1.- Insertar lista 1"<<endl;
		cout<<" 2.- Mostrar lista 1"<<endl;
		cout<<" 3.- Eliminar lista 1"<<endl;
		cout<<endl;
		cout<<" 4.- Insertar lista 2"<<endl;
		cout<<" 5.- Mostrar lista 2"<<endl;
		cout<<" 6.- Eliminar lista 2"<<endl;
		cout<<endl;
		cout<<" 7.- Combinar listas"<<endl;
		cout<<" 8.- Mostrar combinación"<<endl;
		cout<<endl;
		cout<<" 9.- Salir"<<endl;
		cout<<" Escoga una opcion: ";
		cin>>opc;
		switch(opc){
		case 1:
			cout<<"\n\t LISTA 1";
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
				cout<<" === Lista 1 Eliminada ===";
				cout<<endl;
				cout<<endl;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			cout<<"\n\t LISTA 2";
			do{
				cout<<"\n Captura un numero para agregar a la lista: ";
				cin>>dato;
				insertarLista_2(lista_2,dato);
				
				cout<<"\t ¿Desea capurar otro dato S/N?: ";
				cin>>rpt;
				
			} while(rpt == 's' || rpt == 'S');
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 5:
			if(lista_2 ==  NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
				cout<<endl;
				cout<<endl;
			}
			else{
				cout<<endl;
				cout<<" === LISTA 2 ===";
				mostrarLista_2(lista_2);
				cout<<endl;
				cout<<endl;
			}
			system("pause");
			system("cls");
			break;
		case 6:
			if(lista_2 ==  NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
				cout<<endl;
				cout<<endl;
			}
			else{
				while(lista_2 != NULL){
					eliminarLista_2(lista_2,dato);
				};
				cout<<endl;
				cout<<" === Lista 2 Eliminada ===";
				cout<<endl;
				cout<<endl;
			}
			system("pause");
			system("cls");
			break;
		case 7:
			cout<<endl;
			if(lista_3 == NULL){
				combinarListas(lista_1,lista_2,lista_3,dato);
				cout<<" Las listas han sido combinadas";
				mostrarLista_3(lista_3);
			}
			else{
				while(lista_3 != NULL){
					eliminarLista_3(lista_3,dato);
				}
				cout<<" Listas vacias";
			}
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 8:
			cout<<endl;
			cout<<" Combinación";
			mostrarLista_3(lista_3);
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cls");
			break;
		case 9:
			cout<<"\n\t A D I O S :)";
			break;
		default:
			system("cls");
			break;
		}
	} while(opc != 9);
}
