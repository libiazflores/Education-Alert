// Implementacion de la clase Poblacion
#include "Poblacion.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Poblacion::Poblacion(){ // Constructor por defecto
    edad = 25;
}

Poblacion::Poblacion(int cEdad){ // Constructor parametrizado
    edad = cEdad;
}

// Metodos get
int Poblacion::getEdad(){
    return edad;
}

// Metodos set
void Poblacion::setEvaluado(string cNombre, char cSexo, string cCurp, char cGraduado){
    Evaluado eva(cNombre, cSexo, cCurp, cGraduado);
    listaEvaluados.push_back(eva);
}
void Poblacion::setEdad(int cEdad){
    edad = cEdad;
}

// Funcionalidades
void Poblacion::leerFichero(string cFichero){ // Lee fichero
    ifstream info;
    info.open(cFichero);
    if(!info.is_open()){
        cout<<"Error al abrir "<<cFichero<<endl;
        exit(EXIT_FAILURE);
    }
    int N;
    info>>N;
    info.ignore();
    info>>edad;
    info.ignore();

    for(int i=0; i<N; i++){
        string fNombre;
        char fSexo;
        string fCurp;
        char fGraduado;

        getline(info, fNombre);
        info>>fSexo>>fCurp>>fGraduado;
        info.ignore();

        setEvaluado(fNombre, fSexo, fCurp, fGraduado);
    }

    info.close();
}

int Poblacion::cantEvaluados(){ // Regresa la cantidad de evaluados dentro de la lista
    return listaEvaluados.size();
}

int Poblacion::contarGraduados(){ // Cuenta y regresa la cantidad de evaluados graduados
    int sumaGrad = 0;

    for(int i=0; i<listaEvaluados.size(); i++){ 
        if(listaEvaluados[i].getGraduado() == '1'){
            sumaGrad+=1;
        }
    }

    return sumaGrad;
}

float Poblacion::porcentajeSexoM(){ // Calcula y regresa el porcentaje de mujeres evaluadas graduadas
    int sumaMuj = 0;
    int sumaMujGrad = 0;

    for(int i=0; i<listaEvaluados.size(); i++){ 
        if(listaEvaluados[i].getSexo() == 'M'){
            sumaMuj+=1;
        }

        if((listaEvaluados[i].getSexo() == 'M') && (listaEvaluados[i].getGraduado() == '1')){
            sumaMujGrad+=1;
        }
    }

    return ((float)sumaMujGrad/sumaMuj)*100;
}

float Poblacion::porcentajeSexoH(){ // Calcula y regresa el porcentaje de hombres evaluados graduados
    int sumaHom = 0; 
    int sumaHomGrad = 0;

    for(int i=0; i<listaEvaluados.size(); i++){
        if(listaEvaluados[i].getSexo() == 'H'){
            sumaHom+=1;
        }

        if((listaEvaluados[i].getSexo() == 'H') && (listaEvaluados[i].getGraduado() == '1')){
            sumaHomGrad+=1;
        }
    }

    return ((float)sumaHomGrad/sumaHom)*100;
}

float Poblacion::porcentajeTotalGraduados(){ // Calcula y regresa el porcentaje de los evaluados graduados
    int sumaTotGrad= 0; 

    for(int i=0; i<listaEvaluados.size(); i++){
        if(listaEvaluados[i].getGraduado() == '1'){
            sumaTotGrad+=1;
        }
    }
    
    return ((float)sumaTotGrad/listaEvaluados.size())*100;
}

Poblacion::~Poblacion(){} // Destructor