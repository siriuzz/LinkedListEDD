// LinkedListEDD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
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

	while ((aux1 != NULL) && (aux1->dato < n)) {
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
void Buscar(Nodo* lista, int n) {
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

//Eliminar dato de la lista enlazada
void EliminarDato(Nodo*& lista, int n) {
	if (lista != NULL) {
		Nodo* aux{};
		Nodo* anterior = NULL;

		while ((aux != NULL) && (aux->dato != n)) {
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
	else {
		cout << "Lista vacia, primero inserte datos en la lista." << endl;

	}
}

//Mostrar todos los datos de la lista enlazada
void MostrarDatos(Nodo* lista) {
	if (lista != NULL) {
		Nodo* actual = new Nodo();
		actual = lista;

		while (actual != NULL) {
			cout << "|" << actual->dato << "|" << "->";
			actual = actual->siguiente;
		}
	}
	else {
		cout << "Lista vacia, primero inserte datos en la lista." << endl;
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
	string strOpcion;
	Nodo* lista = NULL;
	int opcion;
	string dato;

	do {
		opcion = 0;

		cout << "Seleccione la accion a realizar:\n(1)Insertar\n(2)Buscar\n(3)Eliminar\n(4)Mostrar lista enlazada\n(5)Salir\n\n>>";
		cin >> strOpcion;

		if (ValidarNumero(strOpcion) != strOpcion) {
			cout << "Tipo de dato incorrecto, solo se permiten numeros del 1 al 5, intente de nuevo" << endl;
			system("PAUSE");
			system("CLS");

			continue;
		}
		else {
			opcion = stoi(strOpcion);
		}

		switch (opcion)
		{
		case 1://Insertar
			cout << "Digite el numero que desea insertar :";
			cin >> dato;

			if (ValidarNumero(dato) == dato) {
				Insertar(lista, stoi(dato));
				cout << "Dato " << dato << " insertado con exito." << endl;
			}
			else {
				cout << "Tipo de dato invalido, solo se permiten numeros, intente de nuevo." << endl;
			}
			break;

		case 2://Buscar
			cout << "Digite el numero que desea buscar en la lista enlazada: ";
			cin >> dato;
			if (ValidarNumero(dato) == dato) {
				Buscar(lista, stoi(dato));
			}
			else {
				cout << "Tipo de dato invalido, solo se permiten numeros, intente de nuevo." << endl;
			}
			break;

		case 3://Eliminar
			cout << "Digite el numero que desea eliminar de la lista enlazada: ";
			cin >> dato;

			if (ValidarNumero(dato) == dato) {
				EliminarDato(lista, stoi(dato));
				cout << "Elemento " << dato << " eliminado exitosamente." << endl;
			}
			else {
				cout << "Tipo de dato invalido, solo se permiten numeros, intente de nuevo." << endl;
			}

			break;

		case 4://Mostrar
			MostrarDatos(lista);
			break;
		default:
			cout << "Opcion fuera del listado, intente de nuevo" << endl;

			break;
		}
		system("PAUSE");
		system("CLS");
	} while (opcion != 5);
}
