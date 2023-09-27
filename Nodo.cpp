#include "Nodo.h"
#include<iostream>
using namespace std;
Nodo::Nodo(Object* valor) : valor(valor), Proximo(nullptr), Previo(nullptr) {
}

Nodo::Nodo(Object* valor, Nodo* previo) : valor(valor), Proximo(nullptr), Previo(previo) {
}

Nodo::Nodo(Object* valor, Nodo* proximo, Nodo* previo) : valor(valor), Proximo(proximo), Previo(previo) {
}
Nodo::~Nodo() {
	if (Proximo != nullptr) {
		delete Proximo;

	}
}
Nodo* Nodo::getproximo() {
	if (Proximo != nullptr) {
		return Proximo;
	}
	return nullptr;
}
Nodo* Nodo::getprevio() {
	if (Previo != nullptr) {
		return Previo;
	}
	return nullptr;
}
void Nodo::setproximo(Nodo* Proximo) {
	this->Proximo = Proximo;
}
void Nodo::setprevio(Nodo* Previo) {
	this->Previo = Previo;
}