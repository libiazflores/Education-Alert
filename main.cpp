// Programa principal
#include "Zona.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    Zona zona1("Kino", "Sonora");

    zona1.leerDatosPoblacion("info.txt");
    zona1.printReporte();

    return 0;
}