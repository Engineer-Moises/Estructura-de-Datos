#include <iostream>
#include <conio.h>
using namespace std;

struct estudiante {
	char nombre[40];
	char matricula[10];
	int semestre;
	char division_academica[100];
	char materia[30];
	int calificacion;
}alumno[2];

int main() {
	int i=0;
	for(i=0;i<2;i++){
		fflush(stdin);//Vaciar el buffer para llenar valores
		cout<<"\n Captura el nombre del alumo: ";
		cin.getline(alumno[i].nombre,40,'\n');
		cout<<" Captura la matricula: ";
		cin.getline(alumno[i].matricula,10,'\n');
		cout<<" Captura el semestre: ";
		cin>>alumno[i].semestre;
		fflush(stdin);//Vaciar el buffer para llenar valores
		cout<<" Captura la división académica: ";
		cin.getline(alumno[i].division_academica,100,'\n');
		cout<<" Captura la materia: ";
		cin.getline(alumno[i].materia,30,'\n');
		cout<<" Captura la calificación: ";
		cin>>alumno[i].calificacion;
		cout<<endl;
	}
	
	for(i=0;i<2;i++){
		cout<<"\n\t*** IMPRIMIENDO LOS DATOS ***\n"<<endl;
		cout<<" NOMBRE DEL ALUMNO: "<<alumno[i].nombre<<endl;
		cout<<" MATRICULA: "<<alumno[i].matricula<<endl;
		cout<<" SEMESTRE: "<<alumno[i].semestre<<endl;
		cout<<" DIVISION ACADEMICA: "<<alumno[i].division_academica<<endl;
		cout<<" MATERIA: "<<alumno[i].materia<<endl;
		cout<<" CALIFICACION: "<<alumno[i].calificacion<<endl;
		cout<<endl;
	}
	
	return 0;
}
