#include <iostream>

using namespace std;

main(){

	

	int tam=0,*p_notas;

	char s;

	p_notas = new int[tam];

	

	do{

		cout<<"Ingrese Nota["<<tam<<"] :";

		cin>>p_notas[tam];

		tam++;

	cout<<"Desea Ingresar Otro Valor (s/n):";

	cin>>s;

	}while(s=='s'||s=='S');

	cout<<" --------- Mostrar Datos ---------"<<endl;

	for (int i = 0;i<tam;i++){

		cout<<"Nota ["<<i<<"]:"<<*p_notas<<endl;

		p_notas++;

	}

	delete[] p_notas;

	

}
