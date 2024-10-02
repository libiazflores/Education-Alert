// Definicion de la clase Zona
#ifndef Zona_h
#define Zona_h
#include "Poblacion.h"
#include <string>
#include <iostream>
using namespace std;

class Zona{
private: // Atributos privados
    string nombreZona;
    string estado;
    Poblacion poblacion;

public: // Metodos publicos
    Zona(); // Constructor por defecto
    Zona(string, string); // Constructor parametrizado

    string getNombreZona();
    string getEstado();

    // Funcionalidades
    void leerDatosPoblacion(string);

    string nivelAlerta();
    void printReporte();

    ~Zona(); // Destructor
};

#endif // Zona_h