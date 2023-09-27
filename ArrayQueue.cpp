#include "ArrayQueue.h"
ArrayQueue::ArrayQueue(int capacity) {
	this->capacity = capacity;
	queueArray = new Alumno[capacity];
	front = 0;
	rear = -1;
	size = 0;

}
ArrayQueue::~ArrayQueue() {
	
	delete[] queueArray;
}
bool ArrayQueue::isEmpty(){
	return size == 0;
}
void ArrayQueue::encolar(Alumno& item) {
	if (size < capacity) {
		rear = (rear + 1) % capacity;
		queueArray[rear] = item;
		size++;
		cout << "Alumno encolado correctamente" << endl;
	}else {
		cout << "La cola esta llena. No se puede encolar mas alumnos" << endl;
	}
}
void ArrayQueue::desencolar() {
	if (!isEmpty()) {
		front = (front + 1) & capacity;
		size--;
		cout << "Alumno desencolado correctamente " << endl;
	}
	else {
		cout << "La Cola esta vacia. No se puede desencolar" << endl;
	}
}
Alumno ArrayQueue::verFrente() {
	if (!isEmpty()) {
		return queueArray[front];
	}
	else {
		throw runtime_error("La cola esta vacia. No se puede obtener el frente.");
	}

}
void ArrayQueue::imprimirElementos() {
	if (!isEmpty()) {
		int index = front;
		cout << "Elementos en la cola: " << endl;
		for (int i = 0; i < size; i++) {
			cout << queueArray[index].toString() << endl;
			index = (index + 1) % capacity;
		}
	}
	else {
		cout << "La cola esta vacia." << endl;
	}
	
}
void ArrayQueue::clear() {
	front = 0;
	rear = -1;
	size = 0;
	cout << "La cola ha sido borrado correctamente" << endl;
		 
}