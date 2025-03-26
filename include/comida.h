/*
Juanpablo Escobar
Carlos Ito
16/06/23
.h de la clase Comida
*/

#ifndef COMIDA_H
#define COMIDA_H

#include "alimento.h"

class Comida : public Alimento {
public:
    //Constructores y Destructor
    Comida();
    Comida(const string&, const double&, const double&, const string&);
    Comida(const Comida&);
    ~Comida();
};

#endif