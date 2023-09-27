#include <iostream>
#include "ArrayStack.h"
#include "Simbolo.h"
using namespace std;

ArrayStack::ArrayStack() {
}

ArrayStack::~ArrayStack() {
	for (int i = 0; i < size; i++) {
		delete pila[i];
	}
}

void ArrayStack::push(Object* objeto) {
	if (size < 1000)
		this->pila[size++] = objeto;
}

Object* ArrayStack::top() {
	if (!isEmpty())
		return pila[size - 1];
	return nullptr;
}

Object* ArrayStack::pop() {
	if (!isEmpty()) {
		Object* temp = pila[--size];
		pila[size] = nullptr;
		return temp;
	}
	return nullptr;
}

bool ArrayStack::isEmpty() {
	return (size == 0);
}

void ArrayStack::print() {
	for (int i = size - 1; i >= 0; i--)
		cout << "[" << i << "] " << dynamic_cast<Simbolo*>(pila[i])->getValor() << endl;
}

void ArrayStack::clear() {
	while (!isEmpty()) {
		delete pila[--size];
		pila[size] = nullptr;
	}
}