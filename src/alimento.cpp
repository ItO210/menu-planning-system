/*
Juanpablo Escobar
Carlos Ito
16/06/23
.cpp de la clase Alimento
*/

#include "../include/alimento.h"
#include <iostream>

//Constructores
Alimento::Alimento(){
    nombre = " ";
    cantidad = 0;
    calorias = 0;
}
Alimento::Alimento(const string& nombre, const double& cantidad, const double& calorias, const string& tipo){
    this->nombre = nombre;
    this->cantidad = cantidad;
    this->calorias = calorias;
    this->tipo = tipo;
}
Alimento::Alimento( const Alimento& a){
    this->nombre = a.nombre;
    this->cantidad = a.cantidad;
    this->calorias = a.calorias;
    this->tipo = a.tipo;
}

//Destructor
Alimento::~Alimento(){}

//Getters
const string Alimento::getNombre(){
    return nombre;
}
const double Alimento::getCantidad(){
    return cantidad;
}
const double Alimento::getCalorias(){
    return calorias;
}
const string Alimento::getTipo(){
    return tipo;
}

//Setters
void Alimento::setNombre(const string& nombre){
    this->nombre = nombre;
}
void Alimento::setCantidad(const double& cantidad){
    this->cantidad = cantidad;
}
void Alimento::setCalorias(const double& calorias){
    this->calorias = calorias;
}
void Alimento::setTipo(const string& tipo){
    this->tipo = tipo;
}

//Sobrecarga del operador <<
ostream& operator<<(ostream&out, Alimento a){
    out << a.getNombre() << endl << "Cantidad: " << a.getCantidad() << endl << "Calorias: " <<a.getCalorias() << endl << "Tipo: " << a.getTipo() << endl;
    return out;
}