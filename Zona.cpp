// Implementacion de la clase Zona
#include "Zona.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Zona::Zona(){ // Constructor por defecto
    nombreZona = "NA";
    estado = "NA";
}

Zona::Zona(string cNombreZona, string cEstado){ // Constructor parametrizado
    nombreZona = cNombreZona;
    estado = cEstado;
}

// Metodos get
string Zona::getNombreZona(){
    return nombreZona;
}
string Zona::getEstado(){
    return estado;
}

// Funcionalidades
void Zona::leerDatosPoblacion(string fichero){ // Lee la informacion del fichero de la clase Poblacion
    poblacion.leerFichero(fichero);
}

string Zona::nivelAlerta(){ // Calcula y regresa el nivel de alerta
    string grave= "Grave";
    string alto= "Alto";
    string bajo= "Bajo";
    string muyBajo= "Muy Bajo";

    if(poblacion.porcentajeTotalGraduados() < 20){
        return grave;
    } 
    else if((poblacion.porcentajeTotalGraduados() >= 20) && (poblacion.porcentajeTotalGraduados() < 50)){
        return alto;
    }
    else if((poblacion.porcentajeTotalGraduados() >= 50) && (poblacion.porcentajeTotalGraduados() < 80)){
        return bajo;
    }
    else{
        return muyBajo;
    }
}

void Zona::printReporte(){ // Imprime en pantalla el reporte con los resultados
    cout<<"Resultados de la evaluacion: \n"<<endl;
    cout<<"Zona: "<<getNombreZona()<<endl;
    cout<<"Estado: "<<getEstado()<<endl;
    cout<<"Grupo de edad: "<<poblacion.getEdad()<<endl;
    cout<<"Numero de personas evaluadas: "<<poblacion.cantEvaluados()<<endl;
    cout<<"\nEl "<<poblacion.porcentajeTotalGraduados()<<" % "<<"del total de los evaluados se ha graduado de sus estudios universitarios.\n"<<endl;
    cout<<"    Del total de las mujeres evaluadas, el "<<poblacion.porcentajeSexoM()<<" % "<<"se ha graduado de sus estudios universitarios."<<endl;
    cout<<"    Del total de los hombres evaluados, el "<<poblacion.porcentajeSexoH()<<" % "<<"se ha graduado de sus estudios universitarios."<<endl;
    cout<<"\nEl nivel de alerta de la zona es: "<<nivelAlerta()<<endl;
}

Zona::~Zona(){} // Destructor