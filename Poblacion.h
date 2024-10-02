// Definicion de la clase Poblacion
#ifndef Poblacion_h
#define Poblacion_h
#include "Evaluado.h"
#include <iostream>
#include <vector>
#include <string>

class Poblacion{
private: // Atributos privados
    int edad;
    vector < Evaluado > listaEvaluados;
    Evaluado evaluado;

public: // Metodos publicos
    Poblacion(); // Constructor por defecto
    Poblacion(int); // Constructor parametrizado

    int getEdad();

    void setEvaluado(string, char, string, char);
    void setEdad(int);

    // Funcionalidades
    void leerFichero(string);
    int cantEvaluados();
    int contarGraduados();
    float porcentajeSexoM();
    float porcentajeSexoH();
    float porcentajeTotalGraduados();

    ~Poblacion(); // Destructor
};

#endif // Poblacion_h