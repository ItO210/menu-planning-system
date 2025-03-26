/*
Juanpablo Escobar
Carlos Ito
16/06/23
.h de la clase Alimento
*/

#ifndef ALIMENTO_H
#define ALIMENTO_H

#include <iostream>
using namespace std;

class Alimento {
protected:
    //Atributos
    string nombre;
    double cantidad;
    double calorias;
    string tipo;
public:

    //Constructores y Destructor
    Alimento();
    Alimento(const string&, const double&, const double&, const string&);
    Alimento(const Alimento&);
    ~Alimento();

    //Getters
    const string getNombre();
    const double getCantidad();
    const double getCalorias();
    const string getTipo();
    
    //Setters
    void setNombre(const string&);
    void setCantidad(const double&);
    void setCalorias(const double&);
    void setTipo(const string&);
};

#endif