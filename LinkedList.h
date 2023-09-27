#pragma once
#include "Nodo.h"
#include "Alumno.h"
#include <iostream>
using namespace std;
class LinkedList {
private:
    Nodo* primer;
    Nodo* ultimo;
    int tamano = 0;
public:
    LinkedList();
    ~LinkedList();
    bool insertar(Object*, int);
    void Anular();
    Object* recupera(int pos);
    int localize(Object* obj);
    bool suprimir(int pos);
    Object* primero();
    Object* anterior(int pos);
    void imprimir();
    bool empty();
    Object* next(int pos);
    bool append(Object*);
    int getsize();
};
