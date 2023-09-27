#pragma once
#include"Object.h"
class Nodo : public Object{
public:
	~Nodo();
	Object* valor;
	Nodo* Proximo;
	Nodo* Previo;
	Nodo* getproximo();
	Nodo* getprevio();
	void setproximo(Nodo*);
	void setprevio(Nodo*);
	Nodo(Object*);
	Nodo(Object*, Nodo*);
	Nodo(Object*,Nodo*,Nodo*);
};

