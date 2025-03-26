/*
Juanpablo Escobar
Carlos Ito
16/06/23
.h de la clase Usuario
*/

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <math.h>
#include <ctime>
#include "../src/persona.cpp"
#include "alimento.h"

using namespace std;

class Usuario : public Persona {

private:
    //Atributos
    double imc;
    double caloriasRecomendadas;
    double limiteCalorias;
    string rangoIMC;
    vector<Alimento*> menu;
    vector< vector<Alimento*> > menus;
    vector<time_t> tiempos;
    
public:
    //Constructores y Destructor
    Usuario();
    Usuario( const string&, const int&, const double&, const double&, const string&, const double&);
    Usuario( const Usuario&); //Constructor copia
    ~Usuario();

    //Getters
    const double& getImc();
    const double& getCaloriasRecomendadas();
    const double& getLimiteCalorias();
    const string& getRangoIMC();

    //Setters
    void setImc(const double&);
    void setCaloriasRecomendadas(const double&);
    void setLimiteCalorias(const double&);
    void setRangoIMC(const string&);
    void addToMenu(const string&, const double&, const double&, const string&);

    //Funiciones
    const double calcularIMC();
    const string obtenerRangoIMC(double);
    const double calcularCaloriasRecomendadas();
    const double calcularCaloriasMenu();
    const double calcularCaloriasMenus();
    void printMenu();
    void printMenus();
    void agregarMenu();
    void agregarTiempo(const time_t&);
};
#endif