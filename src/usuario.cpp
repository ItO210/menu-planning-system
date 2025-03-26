/*
Juanpablo Escobar
Carlos Ito
16/06/23
.cpp de la clase Usuario
*/

#include "../include/usuario.h"

//Constructores
Usuario::Usuario(){
    nombre = " ";
    edad = 0;
    peso = 0;
    altura = 0;
    sexo = "";
    imc = 0;
    caloriasRecomendadas = 0;
    limiteCalorias = 0;
    rangoIMC = "";
}
Usuario::Usuario( const string& nombre, const int& edad, const double& peso, const double& altura, const string& sexo, const double& limiteCalorias){ //Constructor parametrizado
    this->nombre = nombre;
    this->edad = edad;
    this->peso = peso;
    this->altura = altura;
    this->sexo = sexo;
    this->limiteCalorias = limiteCalorias;

    imc = calcularIMC();
    caloriasRecomendadas = calcularCaloriasRecomendadas();
    rangoIMC = obtenerRangoIMC(imc);
}
Usuario::Usuario( const Usuario& u){
    nombre = u.nombre;
    edad = u.edad;
    peso = u.peso;
    altura = u.altura;
    sexo = u.sexo;
    imc = u.imc;
    caloriasRecomendadas = u.caloriasRecomendadas;
    limiteCalorias = u.limiteCalorias;
}

//Destructor
Usuario::~Usuario(){}

//Getters
const double& Usuario::getImc(){
    return imc;
}
const double& Usuario::getCaloriasRecomendadas(){
    return caloriasRecomendadas;
}
const double& Usuario::getLimiteCalorias(){
    return limiteCalorias;
}
const string& Usuario::getRangoIMC(){
    return rangoIMC;
}

//Setters
void Usuario::setImc(const double& imc){
    this->imc = imc;
}
void Usuario::setCaloriasRecomendadas(const double& caloriasRecomendadas){
    this->caloriasRecomendadas = caloriasRecomendadas;
}
void Usuario::setLimiteCalorias(const double& limiteCalorias){
    this->limiteCalorias = limiteCalorias;
}
void Usuario::setRangoIMC(const string& rangoIMC){
    this->rangoIMC = rangoIMC;
}

//Funcion para calcular IMC
const double Usuario::calcularIMC(){
    if (altura <= 0) {
        std::cout << "La altura no puede ser cero o menor." << std::endl;
        return 0;
    }

    return peso / pow(altura/100, 2);
}

//Funcion para obtener rango IMC
const string Usuario::obtenerRangoIMC(const double imc) {
    if (imc < 18.5) {
        return "Bajo peso";
    } else if (imc < 25) {
        return "Normal";
    } else if (imc < 30) {
        return "Sobrepeso";
    } else {
        return "Obeso";
    }
}

//Funcion para calcular calorias recomendadas
const double Usuario::calcularCaloriasRecomendadas(){
    if (sexo == "femenino"){
        return 655 + (9.6 * peso) + (1.8 * altura) - (4.7 * edad);
    } else if (sexo == "masculino"){
        return 66 + (13.7 * peso) + (5 * altura) - (6.75 * edad);
    } else return 0;
}

//Funcion para agregar alimento a menu
void Usuario::addToMenu(const string& nombre, const double& cantidad, const double& calorias, const string& tipo){
    if(tipo == "comida"){
        Alimento* comida = new Comida(nombre, cantidad, calorias, tipo);
        menu.push_back(comida);
    }else if (tipo == "bebida")
    {
        Alimento* comida = new Bebida(nombre, cantidad, calorias, tipo);
        menu.push_back(comida);
    }
}

//Funcion para imprimir menu
void Usuario::printMenu(){
    cout << "Menu" << endl;
    for (auto alimento : menu) {
        cout << "Nombre: " << alimento->getNombre() << endl;
        cout << "Cantidad: " << alimento->getCantidad() << " gramos" << endl;
        cout << "Calorias: " << alimento->getCalorias() << endl;
        cout << "Tipo: " << alimento->getTipo() << endl;
        cout << endl;
    }
}

//Funcion para imprimir menus
void Usuario::printMenus(){
    cout << "-----Menus-----" << endl;
    for (auto menu : menus) {
        cout << "Menu: "<< endl;
        for (auto alimento : menu) {
            cout << "Nombre: " << alimento->getNombre() << endl;
            cout << "Cantidad: " << alimento->getCantidad() << " gramos" << endl;
            cout << "Calorias: " << alimento->getCalorias() << endl;
            cout << "Tipo: " << alimento->getTipo() << endl;
        }
        for (time_t tiempo : tiempos) {
        char cadenaTiempo[100];
        std::strftime(cadenaTiempo, sizeof(cadenaTiempo), "%Y-%m-%d %H:%M:%S", std::localtime(&tiempo));
        cout << "Fecha de creacion: " << cadenaTiempo << std::endl;
        }
        cout << "Calorias totales: "<<calcularCaloriasMenu()<< endl;
    }
}

//Funcion para calcular calorias del menu
const double Usuario::calcularCaloriasMenu(){
    double calorias = 0;
    for (auto alimento : menu) {
        calorias = calorias + alimento->getCalorias();
    }
    return calorias;
}

//Funcion para calcular calorias de los menus
const double Usuario::calcularCaloriasMenus(){
    double calorias = 0;
    for (auto menu : menus) {
        for (auto alimento : menu) {
            calorias = calorias + alimento->getCalorias();
        }
    }
    return calorias;
}

//Funcion para agregar menu
void Usuario::agregarMenu(){
    menus.push_back(menu);
}

//Funcion para agregar tiempo en el que se creo el menu
void Usuario::agregarTiempo(const time_t& tiempo){
    tiempos.push_back(tiempo);
}

//Sobrecarga del operador <<
ostream& operator<<(ostream&out, Usuario u){
    out << "Nombre: " << u.getNombre() << endl << "Edad: " << u.getEdad() << endl << "Peso: " << u.getPeso() << endl << "Altura: " << u.getAltura() << endl << "Sexo: " << u.getSexo() << endl << "IMC: " << u.getImc() << endl << "Calorias Recomendadas: "<< u.getCaloriasRecomendadas() << endl << "Limite de Calorias: " << u.getLimiteCalorias() << endl;
    return out;
}