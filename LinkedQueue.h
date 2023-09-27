#pragma once
#include "Nodo.h"
#include "Object.h"
#include "Alumno.h"
class LinkedQueue{
	public:
		LinkedQueue();
		~LinkedQueue();
		LinkedQueue(Nodo*);
		virtual Object* frente();
		
		virtual void imprime_cola();
		
		virtual void anula();
		
		//Dequeue
		virtual void saca_de_cola(); 
		
		//Queue
		virtual void pone_en_cola(Object*);
		
		virtual bool vacia();
	protected:
		Nodo* front;
		Nodo* final;
};

