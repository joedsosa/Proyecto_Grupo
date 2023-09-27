#pragma once
#include "Object.h"
#include "Alumno.h"
#include <iostream>
#include "Object.h"
using namespace std;
class ArrayQueue{
private:
	Alumno* queueArray;
	int capacity;
	int front;
	int rear;
	int size;
public:
	ArrayQueue(int size);
	~ArrayQueue();

	void encolar(Alumno& item);
	void desencolar();
	bool isEmpty();
	Alumno verFrente();
	void imprimirElementos();
	void clear();
};