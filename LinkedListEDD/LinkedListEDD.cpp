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
	Nodo* aux2;

		
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
