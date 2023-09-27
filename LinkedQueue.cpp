#include "LinkedQueue.h"
#include "Object.h"
#include "Nodo.h"
#include "Alumno.h"
#define NULL 0
LinkedQueue::LinkedQueue(){
    front = NULL;
    final = NULL;
}

LinkedQueue::~LinkedQueue(){
    if (final)  
        delete final;
}

LinkedQueue::LinkedQueue(Nodo* front) : front(front){
	final = NULL;
}

Object* LinkedQueue::frente(){
	if(front != NULL){
		return front;
	}
	else{
		return NULL;
	}
}
		
void LinkedQueue::imprime_cola(){
	while(front != NULL){//si no esta vacia imprime
		cout << "Alumno: " << dynamic_cast<Alumno*>(front->valor)->toString() << "\n\n";
		front = front->getprevio();
	}

}
		
void LinkedQueue::anula(){
	while(front != NULL){
		saca_de_cola();//saca todo de la cola por el ciclo
	}
}
		
//Dequeue
void LinkedQueue::saca_de_cola(){
	if(front != NULL){
		//sacar del frente y el anterior se vuelve el frente
		Nodo* anterior = front->getprevio();
		delete front;
		front = anterior;
	}
} 
		
//Queue
void LinkedQueue::pone_en_cola(Object* NuevoNodo){
	if(front == NULL){//cuando esta vacia y se agregara el primero
		front = (Nodo*)NuevoNodo;
		return;
	}
	Nodo* adelante = front;
	while(adelante->getprevio() != NULL){//no dejar vacio y correr elementos
		adelante = adelante->getprevio();
	}
	adelante->setprevio((Nodo*)NuevoNodo);
}
		
bool LinkedQueue::vacia(){
	return front == NULL;
}