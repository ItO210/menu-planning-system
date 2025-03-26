/*
Juanpablo Escobar
Carlos Ito
16/06/23
.h de la clase Catalogo
*/

#ifndef CATALOGO_H
#define CATALOGO_H

#include <iostream>
#include <fstream>
#include "../src/alimento.cpp"
#include "../src/comida.cpp"
#include "../src/bebida.cpp"

using namespace std;

class Catalogo{

    private:
        //Atributos
        vector<Comida*> leguminosas;
        vector<Comida*> frutasyverduras;
        vector<Comida*> cereales;
        vector<Comida*> proteinas;
        vector<Bebida*> bebidas;
 
    public:
        //Constructores y destructor
        Catalogo();
        Catalogo(const vector<Comida*>&, const vector<Comida*>&, const vector<Comida*>&, const vector<Comida*>&, const vector<Bebida*>&);
        ~Catalogo();
        Catalogo(const Catalogo&);

        //Getters
        const vector<Comida*>& getLeguminosas();
        const vector<Comida*>& getFrutasyverduras();
        const vector<Comida*>& getCereales();
        const vector<Comida*>& getProteinas();
        const vector<Bebida*>& getBebidas();

        //Setters
        void cargarLeguminosas(const string&);
        void cargarFrutasyverduras(const string&);
        void cargarCereales(const string&);
        void cargarProteinas(const string&);
        void cargarBebidas(const string&);

        //Metodos para imprimir
        void printLeguminosas();
        void printFrutasyverduras();
        void printCereales();
        void printProteinas();
        void printBebidas();
};

#endif