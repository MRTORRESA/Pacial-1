#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Empleado{
	int codigo;
	char nombres[50];
	char apellidos[50];
	char puesto[50];
	float salario, boni, total;
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
	cout<<"2. Registrar Empleado"<<endl;
	cout<<"3. Modificar datos del Empleado"<<endl;
	cout<<"4. Buscar Empleado por ID"<<endl;
	cout<<"5. Buscar Empleado por codigo"<<endl;
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
	Empleado empleado;
	int id= 0;
	fread(&empleado,sizeof(Empleado),1,archivo);
	cout<<"id |"<<"Codigo |"<<"Nombres   |"<<"Apellidos   |"<<"Puesto   |"<<"salario     |"<< "bonificacion   |"<< "Total      |"  <<endl;
	do{
	cout<<id<<" |"<<empleado.codigo<<" |"<<empleado.nombres<<"  |"<<empleado.apellidos<<"  |"<<empleado.puesto<<"  |"<<empleado.salario<<"    |"<<empleado.boni<<"    |"<<empleado.total<<"    |"<< endl;
	fread(&empleado,sizeof(Empleado),1,archivo);
		id+=1;
	} while(feof(archivo) ==0);
	fclose(archivo);
}
void ingresar(){
	FILE* archivo = fopen(nombre_archivo,"ab");
	Empleado empleado;
	string nombre,apellido,puesto;
	
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
		cin.ignore();
		cout<<"Ingrese Los Nombres: ";
		getline(cin,nombre);
		strcpy(empleado.nombres,nombre.c_str());
		cout<<"Ingrese Los Apellidos: ";
		getline(cin,apellido);
		strcpy(empleado.apellidos,apellido.c_str());
		cout<<"Ingrese el Puesto:";
		getline(cin,apellido);
		strcpy(empleado.puesto,puesto.c_str());
		cout<<"Ingrese el Salario:";
		cin>>empleado.salario;
		cout<<"Ingrese el Bonificacion:";
		cin>>empleado.boni;
		empleado.total= empleado.salario+empleado.boni;
		fwrite(&empleado,sizeof(Empleado),1,archivo);

	fclose(archivo);
	abrir();
}
void modificar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id=0;
	Empleado empleado;
	string nombre,apellido,puesto;
	cout<<"Ingrese el ID a Modificar:";
	cin>>id;
	fseek(archivo,id*sizeof(Empleado),SEEK_SET);
	cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
		cin.ignore();
		cout<<"Ingrese Los Nombres: ";
		getline(cin,nombre);
		strcpy(empleado.nombres,nombre.c_str());
		cout<<"Ingrese Los Apellidos: ";
		getline(cin,apellido);
		strcpy(empleado.apellidos,apellido.c_str());
		cout<<"Ingrese el Puesto:";
		strcpy(empleado.puesto,puesto.c_str());
		cout<<"Ingrese el Salario:";
		cin>>empleado.salario;
		cout<<"Ingrese el Bonificacion:";
		cin>>empleado.boni;
		empleado.total= empleado.salario+empleado.boni;
		fwrite(&empleado,sizeof(Empleado),1,archivo);
		fclose(archivo);
		abrir();
}
void buscar_id(){
	FILE* archivo = fopen(nombre_archivo,"rb");	
	int id;
	cout<<"Ingrese el ID que desea ver: ";
	cin>>id;
	fseek(archivo,id*sizeof(Empleado),SEEK_SET);
	Empleado empleado;
	fread(&empleado,sizeof(Empleado),1,archivo);
	cout<<"Codigo: "<<empleado.codigo<<endl;
	cout<<"Nombres: "<<empleado.nombres<<endl;
	cout<<"Apellidos: "<<empleado.apellidos<<endl;
	cout<<"puesto: "<<empleado.puesto<<endl;
	cout<<"Salario: "<<empleado.salario<<endl;
	cout<<"Bonificacion: "<<empleado.boni<<endl;
	cout<<"Total: "<<empleado.total<<endl;
	fclose(archivo);
}
void buscar_codigo(){
	FILE* archivo = fopen(nombre_archivo,"rb");	
	int codigo;
	cout<<"Ingrese el Codigo: ";
	cin>>codigo;
	Empleado empleado;
	fread(&empleado,sizeof(Empleado),1,archivo);
	do{
		if(empleado.codigo == codigo){
			cout<<"Codigo: "<<empleado.codigo<<endl;
	        cout<<"Nombres: "<<empleado.nombres<<endl;
        	cout<<"Apellidos: "<<empleado.apellidos<<endl;
	        cout<<"puesto: "<<empleado.puesto<<endl;
	        cout<<"Salario: "<<empleado.salario<<endl;
	        cout<<"Bonificacion: "<<empleado.boni<<endl;
	        cout<<"Total: "<<empleado.total<<endl;
		}
		fread(&empleado,sizeof(Empleado),1,archivo);
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
     cout<<"Escriba el ID del dato a Empleado"<<endl;
     cin>>id;
     remplazo=id+1;
    fseek(archivo,remplazo*sizeof(Empleado),SEEK_SET);
    Empleado empleado;
    fread(&empleado,remplazo*sizeof(Empleado),1,archivo);
    fseek(archivo,id*sizeof(Empleado),SEEK_SET);
    fwrite(&empleado,sizeof(Empleado),1,archivo);
	fclose(archivo);
	
	
}
