/*
Juanpablo Escobar
Carlos Ito
16/06/23
.h de la clase Bebida
*/

#ifndef BEBIDA_H
#define BEBIDA_H

#include "alimento.h"

class Bebida : public Alimento {
public:
    //Constructores y destructor
    Bebida();
    Bebida(const string&, const double&, const double&, const string&);
    Bebida(const Bebida&);
    ~Bebida();
};

#endif