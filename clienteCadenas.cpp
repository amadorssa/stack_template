#include <iostream>
#include <string>
#include "Pila.hpp"


using namespace std;

int main() {

    Pila<string> miPila;
    string respuesta;
    string valor;

    // Agregar elementos a la pila
    try {
        cout << "********** Agregar elementos a la pila **********\n\n";
        
        do {
            cout << "Valor a agregar: ";
            getline(cin, valor);
            miPila.Agregar(valor);
            cout << "Elemento agregado. Ahora la pila tiene " << miPila.ObtenerTam() << " elemento(s)\n\n";
            miPila.Imprimir();
            cout << "\n\n";

            do {
                cout << "\250Quiere agregar otro elemento? (s/n): ";
                cin >> respuesta;

                if (respuesta.length() == 1 && (respuesta[0] == 's' || respuesta[0] == 'n')) {
                    respuesta[0] = tolower(respuesta[0]);
                } else {
                    cout << "Entrada invalida. Por favor ingrese 's' o 'n'.\n";
                    respuesta = "";
                }
            } while (respuesta != "s" && respuesta != "n");
            cin.ignore();
        } while(respuesta == "s");
    
    } catch(const char *msn) {
        cerr << "Error: " << msn << endl;
    }

    try {
        cout << "********** Operaciones con la pila **********\n\n";

        // Obtener el tope de la pila
        cout << "\nEl tope de la pila es: " << miPila.ObtenerTope() << endl;

        // Obtener el tamaño de la pila
        cout << "\nLa pila tiene " << miPila.ObtenerTam() << " elemento(s)\n\n";

        // Obtener la capacidad de la pila
        cout << "La pila tiene capacidad para " << miPila.ObtenerCap() << " elemento(s)\n\n";

        // Crear una copia de la pila
        Pila<string> miPilaCopia(miPila);
        cout << "Copia de la pila:\n";
        miPilaCopia.Imprimir();
        cout << "\n\n";

        // Asignar la pila a otra pila
        Pila<string> miPilaAsignada;
        miPilaAsignada = miPila;
        cout << "Pila asignada:\n";
        miPilaAsignada.Imprimir();
        cout << "\n\n";
        
    
    } catch(const char *msn) {
        cerr << "Error: " << msn << endl;
    }


    // Eliminar elementos de la pila
    try {
        cout << "********** Eliminar elementos de la pila **********\n\n";
        do {
            cout << "Elemento a eliminar: " << miPila.ObtenerTope() << endl;
            miPila.Eliminar();
            cout << "Elemento eliminado. Ahora la pila tiene " << miPila.ObtenerTam() << " elemento(s)\n\n";
            miPila.Imprimir();
            cout << "\n\n";

            do {
                cout << "\250Quiere eliminar otro elemento? (s/n): ";
                cin >> respuesta;

                if (respuesta.length() == 1 && (respuesta[0] == 's' || respuesta[0] == 'n')) {
                    respuesta[0] = tolower(respuesta[0]);
                } else {
                    cout << "Entrada invalida. Por favor ingrese 's' o 'n'.\n";
                    respuesta = "";  
                }
            } while (respuesta != "s" && respuesta != "n");
        } while(respuesta == "s");

    } catch(const char *msn) {
        cerr << "Error: " << msn << endl;
    }

    // Verificar si la pila está vacía
    cout << "\nLa pila " << (miPila.EstaVacia() ? "est\240 vac\241a" : "no est\240 vac\241a") << "\n\n";

    // Vaciar la pila
    try {
        miPila.Vaciar();
        cout << "La pila ha sido vaciada. Ahora la pila tiene " << miPila.ObtenerTam() << " elemento(s)\n\n";
        miPila.Imprimir();
        cout << "\n\n";
    } catch(const char *msn) {
        cerr << "Error: " << msn << endl;
    }

    // Verificar si la pila está vacía
    cout << "La pila " << (miPila.EstaVacia() ? "est\240 vac\241a" : "no est\240 vac\241a") << "\n\n";
    

    return 0;
}