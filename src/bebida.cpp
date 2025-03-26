/*
Juanpablo Escobar
Carlos Ito
16/06/23
.cpp de la clase Bebida
*/

#include "../include/bebida.h"

//Constructores
Bebida::Bebida(){
    nombre = " ";
    cantidad = 0;
    calorias = 0;
    tipo = "bebida";
}
Bebida::Bebida(const string& nombre, const double& cantidad, const double& calorias, const string& tipo){
    this->nombre = nombre;
    this->cantidad = cantidad;
    this->calorias = calorias;
    this->tipo = tipo;
}
Bebida::Bebida( const Bebida& a){
    this->nombre = a.nombre;
    this->cantidad = a.cantidad;
    this->calorias = a.calorias;
    this->tipo = tipo;
}

//Destructor
Bebida::~Bebida(){}