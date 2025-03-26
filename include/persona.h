/*
Juanpablo Escobar
Carlos Ito
16/06/23
.h de la clase Persona
*/

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona{

    protected:
        //Atributos
        string nombre;
        int edad;
        double peso;
        double altura;
        string sexo;

    public:
        //Constructores y destructor
        Persona();
        Persona( const string&, const int&, const double&, const double&, const string&);
        Persona( const Persona&);
        ~Persona();

        //Getters
        const string& getNombre();;
        const int& getEdad();
        const double& getPeso();
        const double& getAltura();
        const string& getSexo();

        //Setters
        void setNombre(const string&);
        void setEdad(const int&);
        void setPeso(const double&);
        void setAltura(const double&);
        void setSexo(const string&);
};

#endif