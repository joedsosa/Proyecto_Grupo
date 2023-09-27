#pragma once
#include "Object.h"
#include <sstream>
class Simbolo : public Object {
private:
	char valor;
public:
	Simbolo(char); // constructor

	~Simbolo(); // destructor

	char getValor(); // retorna c

	void setValor(char); // cambia c

	bool equals(Object& other) override;
	string toString() override;
};