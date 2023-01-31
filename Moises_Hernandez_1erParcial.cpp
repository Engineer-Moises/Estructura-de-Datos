#include <iostream>
#include <conio.h>
using namespace std;

struct musica {
	char nombre[50];
	char album[100];
	float duracion;
	char artista[100];
	char fecha[40];
	char genero[50];
}cancion[2];

int main() {
	int i=0;
	for(i=0;i<2;i++){
		fflush(stdin);//Vaciar el buffer para llenar valores
		cout<<"\n Captura el nombre de la cancion: ";
		cin.getline(cancion[i].nombre,50,'\n');
		cout<<" Captura el nombre del artista: ";
		cin.getline(cancion[i].artista,100,'\n');
		cout<<" Captura el genero: ";
		cin.getline(cancion[i].genero,50,'\n');
		//fflush(stdin);//Vaciar el buffer para llenar valores
		cout<<" Captura la duracion de la cancion (minutos): ";
		cin>>cancion[i].duracion;
		fflush(stdin);//Vaciar el buffer para llenar valores
		cout<<" Captura el nombre del album: ";
		cin.getline(cancion[i].album,100,'\n');
		cout<<" Captura la fecha de lanzamiento: ";
		cin.getline(cancion[i].fecha,40,'\n');
		cout<<endl;
	}
	
	for(i=0;i<2;i++){
		cout<<"\n\t*** IMPRIMIENDO LOS DATOS ***\n"<<endl;
		cout<<" NOMBRE DE LA CANCION: "<<cancion[i].nombre<<endl;
		cout<<" ARTISTA: "<<cancion[i].artista<<endl;
		cout<<" DURARCION: "<<cancion[i].duracion<<" minutos"<<endl;
		cout<<" ALBUM: "<<cancion[i].album<<endl;
		cout<<" FECHA: "<<cancion[i].fecha<<endl;
		cout<<" GEMERO: "<<cancion[i].genero<<endl;
		cout<<endl;
	}
	
	return 0;
}
