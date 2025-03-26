/*
Juanpablo Escobar
Carlos Ito
16/06/23
.cpp de la clase Catalogo
*/

#include "../include/catalogo.h"

//Constructores
Catalogo::Catalogo(){}
Catalogo::Catalogo(const vector<Comida*>& leguminosas, const vector<Comida*>& frutasyverduras, const vector<Comida*>& cereales, const vector<Comida*>& proteinas, const vector<Bebida*>& bebidas){
    this->leguminosas = leguminosas;
    this->frutasyverduras = frutasyverduras;
    this->cereales = cereales;
    this->proteinas = proteinas;
    this->bebidas = bebidas;
}
Catalogo::Catalogo(const Catalogo& c){
    leguminosas = c.leguminosas;
    frutasyverduras = c.frutasyverduras;
    cereales = c.cereales;
    proteinas = c.proteinas;
    bebidas = c.bebidas;
}

//Destructor
Catalogo::~Catalogo(){}

//Getters
const vector<Comida*>& Catalogo::getLeguminosas(){
    return leguminosas;
}
const vector<Comida*>& Catalogo::getFrutasyverduras(){
    return frutasyverduras;
}
const vector<Comida*>& Catalogo::getCereales(){
    return cereales;
}
const vector<Comida*>& Catalogo::getProteinas(){
    return proteinas;
}
const vector<Bebida*>& Catalogo::getBebidas(){
    return bebidas;
}

//Carga desde Archivos
void Catalogo::cargarLeguminosas(const string& nombreArchivo){
    ifstream miArchivo(nombreArchivo);

    if (!miArchivo){
        cout << "Failed to open the file for reading. Error: " << strerror(errno) << endl;
    }
    else{
        string nombre;
        double calorias, cantidad;
        while (!miArchivo.eof()){
            miArchivo >> nombre >> cantidad >> calorias;
            Comida* comida = new Comida(nombre, cantidad, calorias, "comida");
            leguminosas.push_back(comida);
        }
    }
}
void Catalogo::cargarFrutasyverduras(const string& nombreArchivo){
    ifstream miArchivo(nombreArchivo);

    if (!miArchivo){
        cout << "Failed to open the file for reading. Error: " << strerror(errno) << endl;
    }
    else{
        string nombre;
        double calorias, cantidad;
        while (!miArchivo.eof()){
            miArchivo >> nombre >> cantidad >> calorias;
            Comida* comida = new Comida(nombre, cantidad, calorias, "comida");
            frutasyverduras.push_back(comida);
        }
    }
}
void Catalogo::cargarCereales(const string& nombreArchivo){
    ifstream miArchivo(nombreArchivo);

    if (!miArchivo){
        cout << "Failed to open the file for reading. Error: " << strerror(errno) << endl;
    }
    else{
        string nombre;
        double calorias, cantidad;
        while (!miArchivo.eof()){
            miArchivo >> nombre >> cantidad >> calorias;
            Comida* comida = new Comida(nombre, cantidad, calorias, "comida");
            cereales.push_back(comida);
        }
    }
}
void Catalogo::cargarProteinas(const string& nombreArchivo){
    ifstream miArchivo(nombreArchivo);

    if (!miArchivo){
        cout << "Failed to open the file for reading. Error: " << strerror(errno) << endl;
    }
    else{
        string nombre;
        double calorias, cantidad;
        while (!miArchivo.eof()){
            miArchivo >> nombre >> cantidad >> calorias;
            Comida* comida = new Comida(nombre, cantidad, calorias, "comida");
            proteinas.push_back(comida);
        }
    }
}
void Catalogo::cargarBebidas(const string& nombreArchivo){
    ifstream miArchivo(nombreArchivo);

    if (!miArchivo){
        cout << "Failed to open the file for reading. Error: " << strerror(errno) << endl;
    }
    else{
        string nombre;
        double calorias, cantidad;
        while (!miArchivo.eof()){
            miArchivo >> nombre >> cantidad >> calorias;
            Bebida* bebida = new Bebida(nombre, cantidad, calorias, "bebida");
            bebidas.push_back(bebida);
        }
    }
}

//Prints para vectores
void Catalogo::printLeguminosas() {
    cout << "-----Leguminosas-----" << endl;
    int index = 0;
    for (auto alimento : leguminosas) {
        index = index + 1;
        cout << index << " ";
        cout << *alimento << endl;
    }
}
void Catalogo::printFrutasyverduras() {
    cout << "-----Frutas y Verduras-----" << endl;
    int index = 0;
    for (auto alimento : leguminosas) {
        index = index + 1;
        cout << index << " ";
        cout << *alimento << endl;
    }
}
void Catalogo::printCereales() {
    cout << "-----Cereales-----" << endl;
    int index = 0;
    for (auto alimento : cereales) {
        index = index + 1;
        cout << index << " ";
        cout << *alimento << endl;
    }
}
void Catalogo::printProteinas() {
    cout << "-----Proteinas-----" << endl;
    int index = 0;
    for (auto alimento : proteinas) {
        index = index + 1;
        cout << index << " ";
        cout << *alimento << endl;
    }
}
void Catalogo::printBebidas() {
    cout << "-----Bebidas-----" << endl;
    int index = 0;
    for (auto alimento : bebidas) {
        index = index + 1;
        cout << index << " ";
        cout << *alimento << endl;
    }
}