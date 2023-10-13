#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::anxLista(Elemento elem){
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
}

void Lista::insListaOrdenada(Elemento elem){
	Nodo* nuevo, *tmp;
	nuevo = new Nodo;
	nuevo->dato = elem;
	nuevo->sig= NULL;
	bool flag = true;
 if(act != NULL){
  tmp = act;
    while(flag){
			if(tmp->sig == NULL){
				tmp->sig = nuevo;
				flag = false;
			}
			else if(tmp->dato < elem && act == tmp){
				nuevo->sig = act;
				act = nuevo;
				flag = false;
			}
			else if(tmp->sig->dato < elem){
				nuevo->sig = tmp->sig;
				tmp->sig = nuevo;
				flag = false;
			}
      else{
				tmp = tmp->sig;
			}
  }
}
else{
	act = nuevo;
}
}


void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
	tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
  }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}

