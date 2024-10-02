// Definicion de la clase Evaluado
#ifndef Evaluado_h
#define Evaluado_h 
#include <string>
using namespace std;

class Evaluado{
private: // Atributos privados
    string nombre;
    char sexo;
    string curp;
    char graduado;

public: // Metodos publicos
    Evaluado(); // Constructor por defecto
    Evaluado(string, char, string, char); // Constructor parametrizado

    char getSexo();
    char getGraduado();

    ~Evaluado(); // Destructor
};

#endif // Evaluado_h
