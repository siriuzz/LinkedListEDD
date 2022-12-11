// LinkedListEDD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

//Declaracion de la estructura Nodo
struct Nodo {
	int dato;
	Nodo* siguiente;
};

//Funcion Insertar entero a la lista
void Insertar(Nodo*& lista, int n) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;

	Nodo* aux1 = lista;
	Nodo* aux2 = NULL;

	while ((aux1 != NULL) && (aux1->dato > n)) {
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}

	if (lista == aux1) {
		lista = nuevo_nodo;
	}
	else {
		aux2->siguiente = nuevo_nodo;
	}

	nuevo_nodo->siguiente = aux1;
}


//Buscar elemento en la lista
void Buscar(Nodo * lista, int n) {
	bool bandera = false;

	Nodo* actual = new Nodo();
	actual = lista;

	while ((actual != NULL) && (actual->dato <= n)) {
		if (actual->dato == n) {
			bandera = true;
		}
		actual = actual->siguiente;
	}

	if (bandera == true) {
		cout << "El elemento " << n << " SI fue encontrado en la lista" << endl;
	}
	else {
		cout << "El elemento " << n << " NO fue encontrado en la lista" << endl;
	}
}

void EliminarDato(Nodo*& lista, int n) {
	if (lista != NULL) {
		Nodo* aux{};
		Nodo* anterior = NULL;

		while((aux != NULL) && (aux->dato != n)) {
			anterior = aux;
			aux = aux->siguiente;
		}

		if (aux == NULL) {
			cout << "Elemento no encontrado, intente de nuevo";
			system("PAUSE");
			return;
		}
		else if (anterior == NULL) {
			lista = lista->siguiente;
			delete aux;
		}
		else {
			anterior->siguiente = aux->siguiente;
			delete aux;
		}
	}
}

//Funcion para validar entrada de un numero
string ValidarNumero(string str)
{
	bool notNum = false;
	int i = 0; 
	while ((str[i] != '\0') && notNum != true) //'\0' es el character que marca el final del string
	{
		if (isdigit(str[i]) == false)
		{
			str = "";
			notNum = true;
			break;
		}
		i++;
	}
	return str; //devuelve un str igual si no se encontraron letras
}

int main()
{
	
}
