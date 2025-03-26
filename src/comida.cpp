/*
Juanpablo Escobar
Carlos Ito
16/06/23
.cpp de la clase Comida
*/

#include "../include/comida.h"

//Constructores
Comida::Comida(){
    nombre = " ";
    cantidad = 0;
    calorias = 0;
    tipo = "comida";
}
Comida::Comida(const string& nombre, const double& cantidad, const double& calorias, const string& tipo){
    this->nombre = nombre;
    this->cantidad = cantidad;
    this->calorias = calorias;
    this->tipo = tipo;
}
Comida::Comida( const Comida& a){
    this->nombre = a.nombre;
    this->cantidad = a.cantidad;
    this->calorias = a.calorias;
    this->tipo = tipo;
}

//Destructor
Comida::~Comida(){}