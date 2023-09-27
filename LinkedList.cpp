#include "LinkedList.h"
LinkedList::LinkedList(){
	primer = 0;
	ultimo = 0;
	tamano = 0;
}
LinkedList::~LinkedList(){
	if(primer){
		delete primer;
	}if(ultimo){
		delete ultimo;
	}
}
bool LinkedList::append(Object* value){
	return insertar(value, tamano + 1);
}
Object* LinkedList::anterior(int pos) {
	if (pos< 1 || pos > tamano)
		return nullptr;
	if (pos == 1 || tamano == 0)
		return nullptr;
	int index = tamano;
	Nodo* temp = ultimo;
	while (index >= pos) {
		temp = temp->getprevio();
		index--;
	}
	return temp->valor;

}
Object* LinkedList::next(int pos){
	if (pos < 0 || primer == nullptr || pos == tamano)
		return nullptr;
	Nodo* nodo = primer;
	for (int i = 1; i <= pos; i++) {
		nodo = nodo->getproximo();
	}
	return nodo->valor;
}
void LinkedList::Anular(){
	while (primer != nullptr) {
		Nodo* temp = primer->getproximo();
		primer->setproximo(nullptr);
		delete primer;
		primer = temp;
	}
}
void LinkedList::imprimir(){
	Nodo* nodo = primer;
	auto cont = 0;
	cout <<dynamic_cast<Alumno*>(nodo->valor)->toString()<< endl;
	nodo = nodo->getproximo();
	cont++;
}
bool LinkedList::empty(){
	return primer == nullptr;
}
int LinkedList::getsize(){
	return tamano;
}
Object* LinkedList::primero(){
	return tamano == 0 ? nullptr : primer->valor;
}
