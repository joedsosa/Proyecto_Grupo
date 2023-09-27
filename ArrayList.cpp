#include "ArrayList.h"
#include <iostream>

ArrayList::ArrayList() {}
ArrayList:: ~ArrayList() {
	clear();
}

void ArrayList::insert(Alumno* item, int position) {
	if (position >= 0 && position <= elements.size()) {
		elements.insert(elements.begin() + position, item);
	}
}

void ArrayList::remove(int position) {
	if (position >= 0 && position < elements.size()) {
		delete elements[position];
		elements.erase(elements.begin() + position);
	}
}
int ArrayList::search(Alumno& item) {
	for (int i = 0; i < elements.size(); i++){
		if (elements[i]->equals(item)) {
			return i;
		}
	}
	return -1;
}
void ArrayList::print() {
	for (Alumno* alum : elements) {
		cout << alum->toString() << endl;
	}
}
bool ArrayList::isEmpty() {
	return elements.empty();
}
void ArrayList::clear() {
	for (Alumno* alum : elements) {
		delete alum;
	}
	elements.clear();
}
Alumno* ArrayList::getbypos(int position) {
	if (position < 0 || position >= elements.size()) {
		cerr << "Posicion invalida para mostrar elemento" << endl;
		return nullptr;
	}
	return elements[position];
}
Alumno* ArrayList::getNext(int position) {
	if (position >= 0 && position < elements.size() - 1) {
		return elements[position + 1];
	}
	return nullptr;
}
Alumno* ArrayList::getPrev(int position) {
	if (position > 0 && position < elements.size()) {
		return elements[position - 1];
	}
	return nullptr;
}