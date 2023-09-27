#include <iostream>
#include <vector>
#include <string>
#include "Alumno.h"
#include "Object.h"
#include "Simbolo.h"
#include "ArrayList.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
using namespace std;

void menuPilas();
void MenuPrincipal();
void menuListas();
void menuLinkedStack();
void menuArrayStack();
void menuLinkedQueue();
void menuArrayQueue();
void menuColas();
void menuLinkedList();
void menuArrayList();

ArrayQueue arrayQueue(50);
ArrayStack arrayPila;
ArrayList arraylist;
//LinkedStack linkedStack;
//LinkedList* linkedList = new LinkedList();
//LinkedQueue* lqueue = new LinkedQueue();

void MenuPrincipal() {
    int opcion;
    do {
        cout << "Menu Principal" << endl;
        cout << "1. Trabajar con Listas" << endl;
        cout << "2. Trabajar con Pilas" << endl;
        cout << "3. Trabajar con Colas" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            menuListas();
            break;
        case 2:
            menuPilas();
            break;
        case 3:
            menuColas();
            break;
        case 4:
            cout << "Saliendo del Programa" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 4);
}

void menuListas() {
    int opcionLista;
    do {
        cout << "Menu Tipo de Lista" << endl;
        cout << "1. Trabajar con ArrayList" << endl;
        cout << "2. Trabajar con LinkedList" << endl;
        cout << "3. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionLista;
        switch (opcionLista) {
        case 1:
            menuArrayList();
            break;
        case 2:
            menuLinkedList();
            break;
        case 3:
            cout << "Regresando al Menu principal de Listas" << endl;
            MenuPrincipal();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcionLista != 3);
}

void menuArrayList() {
    int opcionArray;
    do {
        cout << "Menu ArrayList" << endl;
        cout << "1. Insertar Elemento" << endl;
        cout << "2. Imprimir Elementos" << endl;
        cout << "3. Buscar Elementos" << endl;
        cout << "4. Borrar Elementos" << endl;
        cout << "5. Ver si esta vacia" << endl;
        cout << "6. Obtener Elementos por posicion" << endl;
        cout << "7. Obtener Siguiente" << endl;
        cout << "8. Obtener Anterior" << endl;
        cout << "9. Borrar todos los elementos" << endl;
        cout << "10.Regresar al Menu Anterior " << endl;

        cin >> opcionArray;
        switch (opcionArray) {

        case 1: {
            char respuesta;
            do {
                cout << "" << endl;
                cin.ignore();
                string nombre;
                string cuenta;
                int pos;
                cout << "Ingrese el nombre del alumno : " << endl;
                getline(cin, nombre);

                cout << "Ingrese el numero de cuenta del alumno: " << endl;
                cin >> cuenta;
                cout << "Ingrese la posicion a insertarlo" << endl;
                cin >> pos;
                Alumno* alumno = new Alumno(nombre, cuenta);
                arraylist.insert(alumno,pos);
                cout << "Alumno insertado correctamente\n";

                cout << "Desea insertar otro alumno ? (S / N) ";
                cin >> respuesta;
            } while (respuesta == 'S' || respuesta == 's');
            break;
            
        }
        case 2:
            cout << "Lista de Alumnos" << endl;
            arraylist.print();
            break;
        case 3: {
            cin.ignore();
            string nombre;
            string cuenta;
            cout << "Ingrese el nombre del alumno a buscar: " << endl;
            getline(cin, nombre);
            cout << "Ingrese el numero de cuenta del alumno: "<< endl;
            cin >> cuenta;
            Alumno searchAl(nombre, cuenta);
            int pos = arraylist.search(searchAl);
            if (pos != -1) {
                cout << "El alumno se encuentra en la posicion " << pos << endl;
            } else {
                cout << "El alumno no fue encontrado" << endl;
            }
            break;
        }
        case 4: {
            int pos;
            cout << "Ingrese la posicion del alumno a borrar: " << endl;
            cin >> pos;
            arraylist.remove(pos);
            cout << "Alumno borrado exitosamente" << endl;
        }
            break;
        case 5: 
            if (arraylist.isEmpty()) {
                cout << "La lista esta vacia" << endl;
            } else {
                cout << "La lista tiene elementos dentro" << endl;
            }
        
            break;
        case 6: {
            int pos;
            cout << "Ingrese la posicion del alumno a obtener: ";
            cin >> pos;
            Alumno* getAl = arraylist.getbypos(pos);
            if (getAl != nullptr) {
                cout << "Alumno en la posicion " << pos << ": " << getAl->toString() << endl;
            }

            break;
        }
        case 7: {
            int pos;
            cout << "Ingrese la posicion del alumno: " << endl;
            cin >> pos;
            Alumno* siguienteAlumno = arraylist.getNext(pos);
            if (siguienteAlumno != nullptr) {
                cout << "Siguiente alumno: " << siguienteAlumno->toString() << endl;
            }
            else {
                cout << "No hay siguiente alumno en la posicion dada" << endl;
            }
            break;
        }   
        case 8: {
            int pos;
            cout << "Ingrese la posicion del alumno: " << endl;
            cin >> pos;
            Alumno* prevAl = arraylist.getPrev(pos);
            if (prevAl != nullptr) {
                cout << "Alumno anterior: " << prevAl->toString() << endl;
            }
            else {
                cout << "No hay un alumno anterior en la posicion dada" << endl;
            }

            break;
        }

            
        case 9:
            arraylist.clear();
            cout << "Todos los elementos han sido borrados" << endl;
            break;
        case 10:
            menuListas();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcionArray != 10);
}

void menuLinkedList() {
    int opcionLinked;
    do {
        cout << "Menu LinkedList" << endl;
        cout << "1. Insertar Elemento" << endl;
        cout << "2. Imprimir Elementos" << endl;
        cout << "3. Buscar Elementos" << endl;
        cout << "4. Borrar Elementos" << endl;
        cout << "5. Ver si esta vacia" << endl;
        cout << "6. Obtener Elementos por posicion" << endl;
        cout << "7. Obtener Siguiente" << endl;
        cout << "8. Obtener Anterior" << endl;
        cout << "9. Borrar todos los elementos" << endl;
        cout << "10.Regresar al Menu Anterior " << endl;

        cin >> opcionLinked;
        switch (opcionLinked) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:
            menuListas();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcionLinked != 10);
}

void menuColas() {
    int opcionCola;
    do {
        cout << "Menu Tipo de Cola" << endl;
        cout << "1. Trabajar con ArrayQueue" << endl;
        cout << "2. Trabajar con LinkedQueue" << endl;
        cout << "3. Regresar al Menu Principal" << endl;
        cin >> opcionCola;
        switch (opcionCola) {
        case 1:
            menuArrayQueue();
            break;
        case 2:
            menuLinkedQueue();
            break;
        case 3:
            cout << "Regresando al Menu principal de Colas" << endl;
            MenuPrincipal();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcionCola != 3);
}

void menuArrayQueue() {
    int opcionArrQueue;
     

    do {
        cout << "Menu ArrayQueue" << endl;
        cout << "1. Encolar " << endl;
        cout << "2. Desencolar" << endl;
        cout << "3. Ver Frente" << endl;
        cout << "4. Verificar si está vacía" << endl;
        cout << "5. Imprimir Elementos" << endl;
        cout << "6. Borrar todos los Elementos" << endl;
        cout << "7. Regresar al Menú Anterior " << endl;
        cin >> opcionArrQueue;

        switch (opcionArrQueue) {
        case 1: {
            cin.ignore();
            string nombre;
            string cuenta;
            cout << "Ingrese el nombre del alumno: ";
            getline(cin, nombre);
            cout << "Ingrese el número de cuenta del alumno: ";
            cin >> cuenta;
            Alumno alumno(nombre, cuenta);
            arrayQueue.encolar(alumno); 
            cout << "Alumno encolado correctamente\n";
            break;
        }

        case 2: {
            arrayQueue.desencolar(); 
            cout << "Alumno desencolado\n";
            break;
        }
        case 3: {
            try {
                Alumno peekFront = arrayQueue.verFrente(); // 
                cout << "Alumno en el frente: " << peekFront.toString() << endl;
            }
            catch (const std::runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            if (arrayQueue.isEmpty()) {
                cout << "La cola está vacía" << endl;
            }
            else {
                cout << "La cola tiene elementos dentro" << endl;
            }
            break;
        }

        case 5: {
            arrayQueue.imprimirElementos(); 
            break;
        }
        case 6: {
            arrayQueue.clear(); 
            cout << "Todos los elementos han sido borrados." << endl;
            break;
        }
        case 7:
            menuColas(); 
            break;
        default:
            cout << "Opción no válida" << endl;
        }
    } while (opcionArrQueue != 7);
}

void menuLinkedQueue() {
    int opcionLinkedQueue;
    do {
        cout << "Menu LinkedQueue" << endl;
        cout << "1. Encolar " << endl;
        cout << "2. Desencolar" << endl;
        cout << "3. Ver Frente" << endl;
        cout << "4. Verificiar si esta vacia" << endl;
        cout << "5. Imprimir Elementos" << endl;
        cout << "6. Borrar todos los Elementos" << endl;
        cout << "7. Regresar al Menu Anterior " << endl;
        cin >> opcionLinkedQueue;

        switch (opcionLinkedQueue) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7: {
            menuColas();
            break;
        }
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcionLinkedQueue != 7);
}

void menuPilas() {
    int opcionPila;
    do {
        cout << "Menu Tipo de Pila" << endl;
        cout << "1. Trabajar con ArrayStack" << endl;
        cout << "2. Trabajar con LinkedStack" << endl;
        cout << "3. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionPila;
        switch (opcionPila) {
        case 1:
            menuArrayStack();
            break;
        case 2:
            menuLinkedStack();
            break;
        case 3:
            cout << "Regresando al Menu principal de Pilas" << endl;
            MenuPrincipal();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcionPila != 3);
}

void menuArrayStack() {
    bool flag = true;
	while (flag) {
		cout << "Menu ArrayStack" << endl
			<< "1. Empujar" << endl
			<< "2. Sacar" << endl
			<< "3. Ver tope" << endl
			<< "4. Verificar si esta vacia" << endl
			<< "5. Imprimir elementos" << endl
			<< "6. Borrar todos los elementos" << endl
			<< "7. Regresar" << endl
			<< "Opcion: ";
		int op;
		cin >> op;
		switch (op){
			case 1:
				char c;
				cout << "Ingrese un simbolo: ";
				cin >> c;
				arrayPila.push(new Simbolo(c));
				cout << "Simbolo agregado con exito!" << endl;
				break;
			case 2:
				if (!arrayPila.isEmpty())
					cout << "Simbolo sacado: " << dynamic_cast<Simbolo*>(arrayPila.pop())->getValor() << endl;
				else
					cout << "La pila esta vacia!" << endl;
				break;
			case 3:
				if (!arrayPila.isEmpty())
					cout << "Tope: " << dynamic_cast<Simbolo*>(arrayPila.top())->getValor() << endl;
				else
					cout << "La pila esta vacia!" << endl;
				break;
			case 4:
				if (arrayPila.isEmpty())
					cout << "La pila esta vacia!" << endl;
				else
					cout << "La pila No esta vacia!" << endl;
				break;
			case 5:
				if (!arrayPila.isEmpty()) {
					cout << "Pila: " << endl;
					arrayPila.print();
				}
				else
					cout << "La pila esta vacia." << endl;
				break;
			case 6:
				arrayPila.clear();
				cout << "Se ha vaciado la pila!" << endl;
				break;
			case 7: flag = false;
				break;
			default: cout << "Opcion invalida." << endl;
				break;
		}
	}
}

void menuLinkedStack() {
    int opcionLinkedStack;
    do {
        cout << "Menu LinkedStack" << endl;
        cout << "1. Empujar" << endl;
        cout << "2. Sacar" << endl;
        cout << "3. Ver Tope" << endl;
        cout << "4. Verificiar si esta vacia" << endl;
        cout << "5. Imprimir Elementos" << endl;
        cout << "6. Borrar todos los Elementos" << endl;
        cout << "7. Regresar al Menu Anterior " << endl;
        cin >> opcionLinkedStack;

        switch (opcionLinkedStack) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            menuPilas();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcionLinkedStack != 7);
}

int main() {
    MenuPrincipal(); 
} 