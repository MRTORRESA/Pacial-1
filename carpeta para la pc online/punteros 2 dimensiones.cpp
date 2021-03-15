#include <iostream>
using namespace std;
main(){
	int fila=0, columna=0,**pm_notas;
	cout<<"Cuantos Estudiantes Desea Ingresar: ";
	cin>>fila;
	cout<<"Cuantas Notas por Estudiantes desea Ingresar: ";
	cin>>columna;
	pm_notas= new int *[fila];
	for(int i=0;i<fila;i++){
		pm_notas[i]=new int [columna];
	}
	cout<<"----------------------------Ingreso de Notass -----------"<<endl;
	for(int i=0;i<fila;i++){
		for (int ii=0;ii<columna;ii++){
			cout<<"Estudiante ["<<i+1<<"] ,Nota["<<ii+1<<"] :";
			cin>>*(*(pm_notas+i)+ii);
		}
	}
	
	
	
	
	
	
}
