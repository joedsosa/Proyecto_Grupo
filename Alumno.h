#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

#pragma once
#include <string>

class Alumno {
public:
    Alumno(string& nombre, string& cuenta);
    bool equals(Alumno& other); 
    string toString();
    Alumno();
    

private:
    string nombre;
    string cuenta;
};