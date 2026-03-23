#include <iostream>
#include <list>
#include <climits>

using namespace std;

int main() {
    list<int> numeros;
    int n, valor;

    // Solicitar cantidad de elementos
    cout << "======================================" << endl;
    cout << "   LISTA DE NUMEROS - MIN Y MAX       " << endl;
    cout << "======================================" << endl;
    cout << "Cuantos numeros desea ingresar? ";
    cin >> n;

    // Llenar la lista
    cout << "\n--- Ingreso de datos ---" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "  Numero [" << i << "]: ";
        cin >> valor;
        numeros.push_back(valor);
    }

    // Calcular menor y mayor recorriendo la lista
    int menor = INT_MAX;
    int mayor = INT_MIN;

    for (int num : numeros) {
        if (num < menor) menor = num;
        if (num > mayor) mayor = num;
    }

    // Mostrar la lista almacenada
    cout << "\n--- Lista almacenada ---" << endl;
    cout << "  [ ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << "]" << endl;

    // Mostrar resultados
    cout << "\n--- Resultados ---" << endl;
    cout << "  Numero MENOR: " << menor << endl;
    cout << "  Numero MAYOR: " << mayor << endl;
    cout << "======================================" << endl;

    return 0;
}

