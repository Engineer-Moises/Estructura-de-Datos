//Insertar elementos en la lista de manera ascendentes y descendentes a través de un menú
//Moisés Hernández Cruz

#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

void insertarLista_Ascen(Nodo *&,int);
void mostrarLista_Ascen(Nodo *);
void eliminarLista_Ascen(Nodo *&,int);
void buscarLista_Ascen(Nodo *&, int);

void insertarLista_Descen(Nodo *&,int);
void mostrarLista_Descen(Nodo *);
void eliminarLista_Descen(Nodo *&,int);
void buscarLista_Descen(Nodo *&, int);

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

void buscarLista_Ascen(Nodo *&lista_Asc,int n){
	bool band = false;
	Nodo *buscar = lista_Asc;
	
	while((buscar != NULL) && (buscar -> dato <= n)){
		if(buscar -> dato == n){
			band = true;
		}
		buscar = buscar -> siguiente;
	};
	if(band == true){
		cout<<endl;
		cout<<" El elemento "<<n<<" si se encuentra en la lista"<<endl;
		cout<<endl;
		cout<<endl;
	}
	else{
		cout<<endl;
		cout<<" El elemento "<<n<<" No se encuentra en la lista"<<endl;
		cout<<endl;
		cout<<endl;
	}
}

//Lista Descendente
void insertarLista_Descen(Nodo *&lista_Desc, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista_Desc;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato > n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista_Desc == aux1){
		lista_Desc = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void mostrarLista_Descen(Nodo *lista_Desc){
	Nodo *mostrar = lista_Desc;
	while(mostrar != NULL){
		cout<<"\n"<<mostrar->dato;
		mostrar = mostrar->siguiente;
	}
}

void eliminarLista_Descen(Nodo *&lista_Desc,int n){
	Nodo *aux = lista_Desc;
	n = aux -> dato;
	lista_Desc = lista_Desc -> siguiente;
	delete aux;
}

void buscarLista_Descen(Nodo *&lista_Desc,int n){
	bool band = false;
	Nodo *buscar = lista_Desc;
	
	while((buscar != NULL) && (buscar -> dato >= n)){
		if(buscar -> dato == n){
			band = true;
		}
		buscar = buscar -> siguiente;
	};
	if(band == true){
		cout<<endl;
		cout<<" El elemento "<<n<<" si se encuentra en la lista"<<endl;
		cout<<endl;
		cout<<endl;
	}
	else{
		cout<<endl;
		cout<<" El elemento "<<n<<" No se encuentra en la lista"<<endl;
		cout<<endl;
		cout<<endl;
	}
}

void menu(){
	Nodo *lista_Asc = NULL;
	Nodo *lista_Desc = NULL;
	int dato,opc;
	char rpt;
	do{
		cout<<"\n\t B I E N V E N I D O"<<endl;
		cout<<" 1.- Insertar lista de manera ascendente"<<endl;
		cout<<" 2.- Mostrar lista ascendente"<<endl;
		cout<<" 3.- Buscar elemento en la lista"<<endl;
		cout<<" 4.- Eliminar lista ascendente"<<endl;
		cout<<endl;
		cout<<" 5.- Insertar lista de manera descendente"<<endl;
		cout<<" 6.- Mostrar lista descendente"<<endl;
		cout<<" 7.- Buscar elemento en la lista"<<endl;
		cout<<" 8.- Eliminar lista descendente"<<endl;
		cout<<endl;
		cout<<" 9.- Salir"<<endl;
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
			cout<<" Ingrese el dato a buscar: ";
			cin>>dato;
			buscarLista_Ascen(lista_Asc,dato);
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
			cout<<"\n\t LISTA DESCENDENTE";
			do{
				cout<<"\n Captura un numero para agregar a la lista: ";
				cin>>dato;
				insertarLista_Descen(lista_Desc,dato);
				
				cout<<"\t ¿Desea capurar otro dato S/N?: ";
				cin>>rpt;
				
			} while(rpt == 's' || rpt == 'S');
			cout<<endl;
			system("pause");
			system("cls");
		break;
		case 6:
			if(lista_Desc ==  NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
				cout<<endl;
				cout<<endl;
			}
			else{
				cout<<endl;
				cout<<" === LISTA DESCENDENTE ===";
				mostrarLista_Descen(lista_Desc);
				cout<<endl;
				cout<<endl;
			}
			system("pause");
			system("cls");
		break;
		case 7:
			cout<<endl;
			cout<<" Ingrese el dato a buscar: ";
			cin>>dato;
			buscarLista_Descen(lista_Desc,dato);
			cout<<endl;
			system("pause");
			system("cls");
		break;
		case 8:
			if(lista_Desc ==  NULL){
				cout<<endl;
				cout<<" La lista esta vacia";
				cout<<endl;
				cout<<endl;
			}
			else{
				while(lista_Desc != NULL){
					eliminarLista_Descen(lista_Desc,dato);
				};
				cout<<endl;
				cout<<" === Lista Eliminada ===";
				cout<<endl;
				cout<<endl;
			}
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
