#include <iostream>
#include <conio.h>
using namespace std;

struct calendario{
	char mes[12];
	int dia;
	int anio;
}fecha;

int main() {
	
	cout<<"\n Captura el nombre del mes: ";
	cin.getline(fecha.mes,12,'\n');
	cout<<" Captura el d�a: ";
	cin>>fecha.dia;
	cout<<" Captura el a�o: ";
	cin>>fecha.anio;
	
	cout<<"\n\t ...IMPRIMIENDO LOS DATOS...\n"<<endl;
	cout<<" Tu fecha de nacimiento es "<<fecha.dia<<" de "<<fecha.mes<<" de "<<fecha.anio;
	
	return 0;
}
