#pragma once
#include "Object.h"

class ArrayStack {
	Object* pila[1000];
	int size = 0;
public:
	ArrayStack(); // constructor

	~ArrayStack(); // destructor

	void push(Object*); // agrega un elemento a la parte superior de la pila

	Object* top(); // regresa el elemento en la parte superior de la pila sin quitarlo

	Object* pop(); // quita el elemento en la parte superior de la pila 

	bool isEmpty(); // verifica si la pila esta vacia

	void print(); // imprime los elementos de la pila

	void clear(); // borra todos los elementos de la pila
};