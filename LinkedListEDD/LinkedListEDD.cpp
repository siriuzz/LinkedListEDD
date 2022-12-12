/*
Enunciado: Escriba un programa C++ que encuentre los primeros n términos de la Serie de Fibonacci.

Participantes:
1- John Luis Del Rosario Sánchez - ID 1106940
2- Ashly Marisell Paula Ynoa - ID 1108023
3- Elián Matos Díaz - ID 1106901
4- Juan Daniel Ubiera Méndez - ID 1107248
5- Kelvin Arístides García Espinal - ID 1107646

Fecha de entrega: 12/12/2022
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//declaracion estructura nodo
struct Nodo {
	int dato;
	Nodo* siguiente;
};

#pragma region metodos y funciones
//Declaracion de la estructura Nodo

bool checkIfEmpty(Nodo*& lista) { //retorna true si la lista esta vacia
	return (lista == NULL);
}

//Funcion Insertar entero a la lista
void Insertar(Nodo*& lista, int n) {
	Nodo* nuevo_nodo = new Nodo(); //reservar espacio en memoria
	nuevo_nodo->dato = n; //asignar n al parametro dato del nuevo nodo

	Nodo* aux1 = lista; //los nodos auxiliares sirven para insertar el elemento en el lugar correspondiente
	Nodo* aux2 = NULL;

	while ((aux1 != NULL) && (aux1->dato < n)) { //coloca los nodos auxiliares en su posicion para insertar el dato
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}

	if (lista == aux1) { //caso en el que la lista esta vacia o el ultimo dato es mayor que el insertado
		lista = nuevo_nodo;
	}
	else { //caso para insertar el dato en entre dos datos
		aux2->siguiente = nuevo_nodo;
	}

	nuevo_nodo->siguiente = aux1;
}


//Buscar elemento en la lista
void Buscar(Nodo* lista, int n) {
	if (checkIfEmpty(lista)) { //revisar si la lista esta vacia
		cout << "Lista vacia, primero inserte datos en la lista." << endl;
		return;
	}

	bool bandera = false; //variable que dice si existe o no el dato en la lista

	Nodo* actual = new Nodo(); //reservar espacio en memoria
	actual = lista; //se empieza desde el principio de la lista

	while ((actual != NULL) && (actual->dato <= n)) { //se busca el elemento en la lista
		if (actual->dato == n) { //si se encuentra
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
	if (checkIfEmpty(lista)) { //revisar si la lista esta vacia
		cout << "Lista vacia, primero inserte datos en la lista." << endl;
		return;
	}

	Nodo* aux; //declaracion nodo auxiliar
	Nodo* anterior = NULL; //anterior al auxiliar
	aux = lista; //aux empieza por el principio de la lista

	while ((aux != NULL) && (aux->dato != n)) {
		anterior = aux;
		aux = aux->siguiente;
	}

	if (aux == NULL) { //no se encuentra el dato en la lista
		cout << "Elemento no encontrado, intente de nuevo" << endl;
		return;
	}
	else if (anterior == NULL) { //el elemento se encuentra al principio de la lista
		lista = lista->siguiente;
		delete aux;
	}
	else { //se encuentra entre dos elementos
		anterior->siguiente = aux->siguiente;
		delete aux;
	}
	cout << "Elemento " << n << " eliminado exitosamente." << endl;
}

//Mostrar todos los datos de la lista enlazada
void MostrarDatos(Nodo* lista) {
	if (checkIfEmpty(lista)) { //revisar si la lista esta vacia
		cout << "NULL (La lista esta vacia)" << endl;
		return;
	}

	Nodo* actual = new Nodo(); //reservar espacio en memoria
	actual = lista; //se empieza por el principio de la lista

	while (actual != NULL) { //imprimir cada dato de los nodos de la lista
		cout << "|" << actual->dato << "|" << "->";
		if (actual->siguiente == NULL) cout << " NULL" << endl;
		actual = actual->siguiente;
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

#pragma endregion

int main()
{
	string strOpcion;
	int opcion;
	Nodo* lista = NULL;
	string dato; //dato a insertar

	do {
		opcion = 0; //seleccion nula

		//menu y pedir opcion
		cout << "Seleccione la accion a realizar:\n(1)Insertar\n(2)Buscar\n(3)Eliminar\n(4)Mostrar lista enlazada\n(5)Salir\n>>";
		cin >> strOpcion;

		if (ValidarNumero(strOpcion) != strOpcion) { //si se inserta un tipo de dato diferente de un entero
			cout << "Tipo de dato incorrecto, solo se permiten numeros del 1 al 5, intente de nuevo" << endl;
			system("PAUSE");
			system("CLS");

			continue;
		}
		opcion = stoi(strOpcion);

		switch (opcion) //casos del menu
		{
		case 1://Insertar
			cout << "Digite el numero que desea insertar: ";
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
			}
			else {
				cout << "Tipo de dato invalido, solo se permiten numeros, intente de nuevo." << endl;
			}

			break;

		case 4://Mostrar
			MostrarDatos(lista);
			break;

		case 5://Salir
			cout << "ADIOS!!" << endl;
			exit(0);
			break;
		default:
			cout << "Opcion fuera del listado, intente de nuevo" << endl;

			break;
		}
		system("PAUSE");
		system("CLS");
	} while (opcion != 5);
}
