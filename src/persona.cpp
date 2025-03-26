/*
Juanpablo Escobar
Carlos Ito
16/06/23
.cpp de la clase Persona
*/

#include "../include/persona.h"

//Constructores
Persona::Persona(){
    nombre = " ";
    edad = 0;
    peso = 0;
    altura = 0;
    sexo = "";
}
Persona::Persona( const string& nombre, const int& edad, const double& peso, const double& altura, const string& sexo){
    this->nombre = nombre;
    this->edad = edad;
    this->peso = peso;
    this->altura = altura;
    this ->sexo = sexo;
}
Persona::Persona( const Persona& p){
    this->nombre = p.nombre;
    this->edad = p.edad;
    this->peso = p.peso;
    this->altura = p.altura;
    this->sexo = p.sexo;
}

//Destructor
Persona::~Persona(){}

//Getters
const string& Persona::getNombre(){
    return nombre;
}
const int& Persona::getEdad(){
    return edad;
}
const double& Persona::getPeso(){
    return peso;
}
const double& Persona::getAltura(){
    return altura;
}
const string& Persona::getSexo(){
    return sexo;
}

//Setters
void Persona::setNombre(const string& nombre){
    this->nombre = nombre;
}
void Persona::setEdad(const int& edad){
    this->edad = edad;
}
void Persona::setPeso(const double& peso){
    this->peso = peso;
}
void Persona::setAltura(const double& altura){
    this->altura = altura;
}
void Persona::setSexo(const string& sexo){
    this->sexo = sexo;
}

//Sobrecarga del operador <<
ostream& operator<<(ostream&out, Persona p){
    out << "Nombre: " << p.getNombre() << endl << "Edad: " << p.getEdad() << endl << "Peso: " << p.getPeso() << endl << "Altura: " << p.getAltura() << endl;
    return out;
}
