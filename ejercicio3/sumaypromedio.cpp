#include <iostream>
#include <list>
#include <limits>
using namespace std;

// Función para leer un entero positivo con validación
int leerEnteroPositivo(string mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [Error] Debe ingresar un numero entero. Intente de nuevo." << endl;
        } else if (valor <= 0) {
            cout << "  [Error] La cantidad debe ser mayor a cero. Intente de nuevo." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

// Función para leer un número real con validación
double leerReal(string mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [Error] Debe ingresar un numero real valido. Intente de nuevo." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

int main() {
    list<double> numeros;
    int n;
    double valor;
    double suma     = 0.0;
    double promedio = 0.0;

    cout << "======================================" << endl;
    cout << "   LISTA DE REALES - SUMA Y PROMEDIO  " << endl;
    cout << "======================================" << endl;

    // Leer cantidad con validación
    n = leerEnteroPositivo("Cuantos numeros desea ingresar? ");

    // Leer cada número con validación
    cout << "\n--- Ingreso de datos ---" << endl;
    for (int i = 1; i <= n; i++) {
        valor = leerReal("  Numero [" + to_string(i) + "]: ");
        numeros.push_back(valor);
    }

    // Verificar que la lista no esté vacía antes de operar
    if (numeros.empty()) {
        cout << "\n[Error] La lista esta vacia. No se puede calcular." << endl;
        return 1;
    }

    // Calcular suma
    for (double num : numeros) {
        suma += num;
    }

    // Calcular promedio — protección contra división por cero
    if (n > 0) {
        promedio = suma / n;
    } else {
        cout << "\n[Error] No se puede calcular el promedio con cero elementos." << endl;
        return 1;
    }

    // Mostrar lista almacenada
    cout << "\n--- Lista almacenada ---" << endl;
    cout << "  [ ";
    for (double num : numeros) {
        cout << num << " ";
    }
    cout << "]" << endl;

    // Mostrar resultados
    cout << "\n--- Resultados ---"           << endl;
    cout << "  Cantidad de numeros: " << n        << endl;
    cout << "  Suma total:          " << suma      << endl;
    cout << "  Promedio:            " << promedio  << endl;
    cout << "======================================" << endl;

    return 0;
}
