#include <iostream>
#include "lista.h"
using namespace std;

int main(){
	Lista lis;


	for(int i=1;i<=lis.longLista();i++){
		cout << lis.infoLista(i) << " ";
	}
	cout << endl;
	
	

	lis.insListaOrdenada(4);
	lis.insListaOrdenada(5);
	for(int i=1;i<=lis.longLista();i++){
		cout << lis.infoLista(i) << " ";
	}

	return 0;
}


