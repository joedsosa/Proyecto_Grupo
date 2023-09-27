#pragma once
#include "Object.h"
#include <vector>
#include <iostream>
#include "Alumno.h"
using namespace std;
class ArrayList {
private:
	vector<Alumno*> elements;
public:
	ArrayList();
	~ArrayList();
	void insert(Alumno* item, int position);
	void remove(int position);
	int search(Alumno& item);
	void print();
	bool isEmpty();
	void clear();
	Alumno* getbypos(int position);
	Alumno* getNext(int position);
	Alumno* getPrev(int position);
	void insert(Alumno* item);
};

