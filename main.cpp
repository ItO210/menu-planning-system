#include "./src/catalogo.cpp"
#include "./src/usuario.cpp"

class Planeador
{
    public:
        void start()
        {
           
            int edad;
            string name, sexo;
            double peso, altura;

            Catalogo c;
            c.cargarLeguminosas("./data/leguminosas.txt");
            c.cargarFrutasyverduras("./data/fyv.txt");
            c.cargarCereales("./data/cereales.txt");
            c.cargarProteinas("./data/proteinas.txt");
            c.cargarBebidas("./data/bebidas.txt");
            

            cout << "Bienvenido al planeador de menus" << endl;
            cout << "Para comenzar necesitamos tus datos" << endl;
            cout << "Ingresa tu nombre: ";
            cin >> name;
            cout << "Ingresa tu edad: ";
            cin >> edad;
            cout << "Ingresa tu peso (kg): ";
            cin >> peso;
            cout << "Ingresa tu altura (cm)";
            cin >> altura;
            cout << "Eres Mujer (F) o Hombre (H)";
            while (true){
                char MH;
                cin >> MH;
                if ( MH == 'H'){
                    sexo = "masculino";
                    break;
                }else if (MH == 'F'){
                    sexo = "femenino";
                    break;
                }else{
                    cout << "Ingresa un valor valido";
                }
            }
            Usuario u(name, edad, peso, altura, sexo, 0);
            
            cout << "El limite de calorias recomendado es de: " << u.getCaloriasRecomendadas() << endl;
            cout << "Desea utilizar este limite de calorias? (y/n)";
            while (true){
            char a;
            cin >> a;
            if ( a == 'y'){
                u.setLimiteCalorias(u.getCaloriasRecomendadas());
                break;
            }else if (a == 'n'){
                double limite;
                cout << "Ingresa limite de calorias: ";
                cin >> limite;
                u.setLimiteCalorias(limite);
                break;
            }else{
                cout << "Ingresa un valor valido";
            }
            }

            int i = 0, j = 0, m = 0;
            time_t tiempo;

            while(i == 0){
                //muestra menu y pide un valor
                cout << "*********************************************************************\n";
                cout << "1) Crear Menu\n" << "2) Info de usuario\n" << "3) Ver Menus Creados\n" << "4) Mostrar Calorias Totales de Todos los Menus\n" << "5) Exit\n";
                cout << "*********************************************************************\n";
                int n;
                cin >> n;
                //ingresamos el valor en nuestro switch
                switch (n)
                {
                case 1:
                    while(j == 0){
                        cout << "*********************************************************************\n";
                        cout << "1) Agregar a Menu\n" << "2) Ver Menu Actual\n" << "3) Agregar Menu\n" << "4) Ver Menus Creados\n" << "5) Volver\n";
                        cout << "*********************************************************************\n";
                        int k;
                        cin >> k;
                        switch (k)
                        {
                        case 1:
                            cout << "*********************************************************************\n";
                            cout << "1) Ver Catalogo Leguminosas\n" << "2) Ver Catalogo Cereales\n" << "3) Ver Catalogo Proteinas\n" << "4) Ver Catalogo Frutas y Verduras\n" << "5) Ver Bebidas\n" << "6) Volver\n" ;
                            cout << "*********************************************************************\n";
                            int l;
                            cin >> l;
                            switch (l)
                            {
                            case 1:
                                while (m == 0){
                                    c.printLeguminosas();
                                    cout << "*********************************************************************\n";
                                    cout << "1) Agregar Alimento\n" << "2) Volver\n";
                                    cout << "*********************************************************************\n";
                                    int r;
                                    cin >> r;
                                    if(r == 1){
                                        int index;
                                        cout << "Ingrese indice: "<< endl;
                                        cin >> index;
                                        if (index - 1 > c.getLeguminosas().size()){
                                            cout << "Indice invalido";
                                            break;
                                        } else{
                                            vector<Comida*> leguminosas;
                                            leguminosas = c.getLeguminosas();
                                            u.addToMenu(leguminosas[index-1]->getNombre(), leguminosas[index-1]->getCantidad(), leguminosas[index-1]->getCalorias(), leguminosas[index-1]->getTipo());
                                            break;
                                        }
                                    }else if (r == 2)
                                    {
                                        break;
                                    }else{
                                        cout << "Ingresa un valor valido" << endl;
                                    }
                                case 2:
                                    c.printCereales();
                                    cout << "*********************************************************************\n";
                                    cout << "1) Agregar Alimento\n" << "2) Volver\n";
                                    cout << "*********************************************************************\n";
                                    cin >> r;
                                    if(r == 1){
                                        int index;
                                        cout << "Ingrese indice: "<< endl;
                                        cin >> index;
                                        if (index - 1 > c.getCereales().size()){
                                            cout << "Indice invalido";
                                            break;
                                        } else{
                                            vector<Comida*> cereales;
                                            cereales = c.getCereales();
                                            u.addToMenu(cereales[index-1]->getNombre(), cereales[index-1]->getCantidad(), cereales[index-1]->getCalorias(), cereales[index-1]->getTipo());
                                            break;
                                        }
                                    }else if (r == 2)
                                    {
                                        break;
                                    }else{
                                        cout << "Ingresa un valor valido" << endl;
                                    }
                                case 3:
                                    c.printProteinas();
                                    cout << "*********************************************************************\n";
                                    cout << "1) Agregar Alimento\n" << "2) Volver\n";
                                    cout << "*********************************************************************\n";
                                    cin >> r;
                                    if(r == 1){
                                        int index;
                                        cout << "Ingrese indice: "<< endl;
                                        cin >> index;
                                        if (index - 1 > c.getProteinas().size()){
                                            cout << "Indice invalido";
                                            break;
                                        } else{
                                            vector<Comida*> proteinas;
                                            proteinas = c.getProteinas();
                                            u.addToMenu(proteinas[index-1]->getNombre(), proteinas[index-1]->getCantidad(), proteinas[index-1]->getCalorias(), proteinas[index-1]->getTipo());
                                            break;
                                        }
                                    }else if (r == 2)
                                    {
                                        break;
                                    }else{
                                        cout << "Ingresa un valor valido" << endl;
                                    }
                                case 4:
                                    c.printFrutasyverduras();
                                    cout << "*********************************************************************\n";
                                    cout << "1) Agregar Alimento\n" << "2) Volver\n";
                                    cout << "*********************************************************************\n";
                                    cin >> r;
                                    if(r == 1){
                                        int index;
                                        cout << "Ingrese indice: "<< endl;
                                        cin >> index;
                                        if (index - 1 > c.getFrutasyverduras().size()){
                                            cout << "Indice invalido";
                                            break;
                                        } else{
                                            vector<Comida*> frutasyverduras;
                                            frutasyverduras = c.getFrutasyverduras();
                                            u.addToMenu(frutasyverduras[index-1]->getNombre(),frutasyverduras[index-1]->getCantidad(), frutasyverduras[index-1]->getCalorias(), frutasyverduras[index-1]->getTipo());
                                            break;
                                        }
                                    }else if (r == 2)
                                    {
                                        break;
                                    }else{
                                        cout << "Ingresa un valor valido" << endl;
                                    }
                                case 5:
                                    c.printBebidas();
                                    cout << "*********************************************************************\n";
                                    cout << "1) Agregar Alimento\n" << "2) Volver\n";
                                    cout << "*********************************************************************\n";
                                    cin >> r;
                                    if(r == 1){
                                        int index;
                                        cout << "Ingrese indice: "<< endl;
                                        cin >> index;
                                        if (index - 1 > c.getBebidas().size()){
                                            cout << "Indice invalido";
                                            break;
                                        } else{
                                            vector<Bebida*> bebidas;
                                            bebidas = c.getBebidas();
                                            u.addToMenu(bebidas[index-1]->getNombre(), bebidas[index-1]->getCantidad(), bebidas[index-1]->getCalorias(), "bebida");
                                            break;
                                        }
                                    }else if (r == 2)
                                    {
                                        break;
                                    }else{
                                        cout << "Ingresa un valor valido" << endl;
                                    }
                                case 6:
                                    m = 1;
                                    break;
                                default:
                                    cout << "Ingresa un valor valido\n";
                                    break;
                                }
                                break;
                            }
                        case 2:
                            u.printMenu();
                            break;
                        case 3:
                            u.agregarMenu();
                            tiempo = std::time(nullptr);
                            u.agregarTiempo(tiempo);
                            cout << "El menu fue agregado" << endl;
                            break;
                        case 4:
                            u.printMenus();
                            break;
                        case 5:
                            j = 1;
                            break;
                        default:
                            cout << "Ingresa un valor valido\n";
                            break;
                        }
                    }
                    break;
                case 2:
                    cout << "-----RESUMEN-----" << endl;
                    cout << u;
                    break;
                case 3:
                    u.printMenus();
                    break;
                case 4:
                    cout << "Calorias: " << u.calcularCaloriasMenus() << endl;
                    break;
                case 5:
                    //Salir
                    //en caso de que se quiera salir
                    cout << "Hasta Luego!!!\n";
                    //cambiamos el valor para terminar con el loop
                    i = 1;
                    break;
                default:
                    //en caso de que no se ingrese un valor que coincida con alguno de los casos
                    cout << "Ingresa un valor valido\n";
                    break;
                }
            }
        }
};

int main()
{
    Planeador p;
    p.start();
    return 0;
}
