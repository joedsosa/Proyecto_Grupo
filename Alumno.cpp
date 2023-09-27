#include "Alumno.h"
Alumno::Alumno(string& nombre, string& cuenta): nombre(nombre), cuenta(cuenta){}
Alumno::Alumno(){}
bool Alumno::equals(Alumno& other) {
	//Implementar logica de comparacion
	Alumno* otroAlumno = dynamic_cast<Alumno*>(&other);
	if (!otroAlumno) {
		return false;
		}
	return this->nombre == otroAlumno->nombre && this->cuenta == otroAlumno->cuenta;

}
//bool Alumno::equals(Alumno& other){
//	// Compara los campos relevantes para determinar si dos Alumnos son iguales
//	return this->nombre == other.nombre && this->cuenta == other.cuenta;
//}
string Alumno::toString() {
	return "Nombre: " + nombre + ", Cuenta: " + cuenta;
}