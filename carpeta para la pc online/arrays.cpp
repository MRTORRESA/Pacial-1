#include <iostream>
using namespace std;
main(){
int fila =0,columna=0;
cout<<"Ingrese Filas:";
cin>>fila;
cout<<"Ingrese Columnas:";
cin>>columna;

int tabla[fila][columna];
for(int i=0;i<fila;i++){
	cout<<"--- FIla ["<<i<<"] ---"<<endl;
	for(int ii=0;ii<columna;ii++){
		int valor=0;
		cout<<"Celda ["<<i<<"],["<<ii<<"]: ";
		cin>>valor;
		tabla[i][ii]=valor;	
	}
}
	cout<<"Datos de Tabla"<<endl;
	for (int i=0;i<fila;i++){
		cout<<"--- FIla ["<<i<<"] ---"<<endl;
		for(int ii=0;ii<columna;ii++){
			cout<<"Celda ["<<i<<"],["<<ii<<"]: "<<tabla[i][ii]<<endl;	
		}
	}
	
	
	
}
