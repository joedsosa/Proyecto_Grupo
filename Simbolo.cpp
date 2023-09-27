#include "Simbolo.h"

Simbolo::Simbolo(char c) {
	valor = c;
}

Simbolo::~Simbolo() {
}

char Simbolo::getValor() {
	return valor;
}

void Simbolo::setValor(char c) {
	valor = c;
}
bool Simbolo::equals(Object& other) {
    Simbolo* otherSimbolo = dynamic_cast<Simbolo*>(&other);

    if (!otherSimbolo) {
        return false;
    }
    return valor == otherSimbolo->valor;
}
string Simbolo::toString() {
    
    stringstream ss;
    ss << valor;
    return ss.str();
}