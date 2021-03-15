#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void abrir();
void ingresar();
void modificar();
void buscar_id();
void buscar_codigo();
void eliminar();
main(){
	
	int sw;
	char continuar;
	do{	
	cout<<"************************************"<<endl;
	cout<<"Ingrese la opcion que desee"<<endl;
	cout<<"1. Leer archivo"<<endl;
	cout<<"2. Registrar Estudiante"<<endl;
	cout<<"3. Modificar datos del Estudiante"<<endl;
	cout<<"4. Buscar Estudiante por ID"<<endl;
	cout<<"5. Buscar Estudiante por codigo"<<endl;
	cout<<"6. Eliminar Dato de estudiante"<<endl;
	cout<<"  ";
	cin>>sw;
    
	switch(sw){
		
	
case 1:	abrir(); break;
case 2:	ingresar(); break;
case 3:	modificar(); break;
case 4:	buscar_id(); break;
case 5:	buscar_codigo();break;
case 6: eliminar();break;
}
cout<<"Desea realizar otra operacion (s/n):";
		cin>>continuar;
} while (continuar=='s' || continuar=='S');
}
void abrir(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id= 0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"id |"<<"Codigo |"<<"Nombres   |"<<"Apellidos   |"<<"Telefono"<<endl;
	do{
	cout<<id<<" |"<<estudiante.codigo<<" |"<<estudiante.nombres<<"  |"<<estudiante.apellidos<<"  |"<<estudiante.telefono<<endl;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	} while(feof(archivo) ==0);
	fclose(archivo);
}
void ingresar(){
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese Los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese Los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);

	fclose(archivo);
	abrir();
}
void modificar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id=0;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingrese el ID a Modificar:";
	cin>>id;
	fseek(archivo,id*sizeof(Estudiante),SEEK_SET);
	cout<<"Modificar el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Modificar Los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Modificar Los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Modificar el Telefono:";
		cin>>estudiante.telefono;
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		fclose(archivo);
		abrir();
}
void buscar_id(){
	FILE* archivo = fopen(nombre_archivo,"rb");	
	int id;
	cout<<"Ingrese el ID que desea ver: ";
	cin>>id;
	fseek(archivo,id*sizeof(Estudiante),SEEK_SET);
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombres: "<<estudiante.nombres<<endl;
	cout<<"Apellidos: "<<estudiante.apellidos<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	fclose(archivo);
}
void buscar_codigo(){
	FILE* archivo = fopen(nombre_archivo,"rb");	
	int codigo;
	cout<<"Ingrese el Codigo: ";
	cin>>codigo;
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	do{
		if(estudiante.codigo == codigo){
			cout<<"______________________"<<endl;
			cout<<"Codigo: "<<estudiante.codigo<<endl;
			cout<<"Nombres: "<<estudiante.nombres<<endl;
			cout<<"Apellidos: "<<estudiante.apellidos<<endl;
			cout<<"Telefono: "<<estudiante.telefono<<endl;
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
	} while (feof(archivo)==0);
	fclose(archivo);
}
void eliminar(){
	int conta;
	int limiteid=0;
	int remplazo;
    int id;
	FILE* archivo = fopen(nombre_archivo,"rb");

	cout<<limiteid;

     cout<<"Escriba el ID del dato a eliminar"<<endl;
     cin>>id;
     remplazo=id+1;
     
     fseek(archivo,remplazo*sizeof(Estudiante),SEEK_SET);
     Estudiante estudiante;
	fread(&estudiante,remplazo*sizeof(Estudiante),1,archivo);
    
     fseek(archivo,id*sizeof(Estudiante),SEEK_SET);
     
     fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	
	
}
