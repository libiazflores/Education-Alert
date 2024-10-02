// Implementacion de la clase Evaluado
#include "Evaluado.h"
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

Evaluado::Evaluado(){ // Constructor por defecto
    nombre = "";
    sexo ='_';
    curp = "";
    graduado=0;
}
Evaluado::Evaluado( string cNombre, char cSexo, string cCurp, char cGraduado){ // Constructor parametrizado
    nombre = cNombre;
    sexo = cSexo;
    curp = cCurp;
    graduado = cGraduado;
    
}

char Evaluado::getSexo() { 
    return sexo;
}
char Evaluado::getGraduado(){
    return graduado; 
}

Evaluado::~Evaluado(){} // Destructor
