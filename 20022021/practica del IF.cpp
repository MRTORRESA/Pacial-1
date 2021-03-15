#include <iostream>
using namespace std;
main(){
/*	int num = 0;
	cout<<"Ingrese numero";
	cin>>num;
	if (num>0){
		cout<<"Positivo"<<endl;
	}else{
		cout<<"Negativo"<<endl;
		if (num==0){
			cout<<"Neutro"<<endl;
		}
	}*/
	char lapiz,lapicero,cuaderno;
	cout<<"Trae un Lapiz: (s/n): ";
	cin>>lapiz;
	cout<<"Trae un Lapicero (s/n): ";
	cin>> lapicero;
	cout<<"Trae cuaderno (s/n):";
	cin>>cuaderno;
	
	if (lapiz=='s'|| lapicero=='s' && cuaderno =='s'){
		cout<<"Entra"<<endl;
	}else{
		cout<<"NO entra"<<endl;
		
	}
	
	
	
	
	
	system("pause");
	
}
