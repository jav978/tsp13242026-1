/**
M: 1, U: 1, O: 1
En una Institución Educativa le piden resolver el problema de verificar si dado 2
números complejos su suma y multiplicación son iguales.
La suma de un número real y un número imaginario (que es un múltiplo real de la
unidad imaginaria, que se indica con la letra i). Los números complejos se utilizan en
todos los campos de las matemáticas, en muchos de la física (y notoriamente en la
mecánica cuántica) y en ingeniería, especialmente en la electrónica y las
telecomunicaciones, por su utilidad para representar las ondas electromagnéticas y la
corriente eléctrica.
Definiremos cada complejo z como un par ordenado de números reales (a, b) ó
(Re(z), Im(z)), en el que se definen las siguientes operaciones:
* Suma
(a, b) + (c, d) = (a+c) + (b+d)i
* Multiplicación
(a, b) * (c, d) = (ac - bd) + (ad + cb)i
* Igualdad
(a, b) = (c, d)ÍÎ a = c y b = d
Realice un programa en C++ que verifique que dado los dos números complejos
su suma y su multiplicación son iguales.

Programador: José Vásquez
Fecha: 22-03-2026

*/
#include <iostream>
#include <windows.h>  // ← Necesario para SetConsoleOutputCP
using namespace std;


// Estructura para representar un número complejo
struct Complejo {
    double real;      // Parte real
    double imaginario; // Parte imaginaria
};

// Función para sumar dos complejos  Suma (a, b) + (c, d) = (a+c) + (b+d)i
Complejo sumar(Complejo z1, Complejo z2) {
    Complejo resultado;
    resultado.real = z1.real + z2.real;
    resultado.imaginario = z1.imaginario + z2.imaginario;
    return resultado;
}

// Función para multiplicar dos complejos
Complejo multiplicar(Complejo z1, Complejo z2) {
    Complejo resultado;
    // Fórmula: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    resultado.real = (z1.real * z2.real) - (z1.imaginario * z2.imaginario);
    resultado.imaginario = (z1.real * z2.imaginario) + (z1.imaginario * z2.real);
    return resultado;
}

// Función para verificar si dos complejos son iguales
bool sonIguales(Complejo z1, Complejo z2) {
    return (z1.real == z2.real) && (z1.imaginario == z2.imaginario);
}

// Función para mostrar un complejo
void mostrar(const char* mensaje, Complejo z) {
    cout << mensaje;
    if (z.imaginario >= 0)
        cout << z.real << " + " << z.imaginario << "i" << endl;
    else
        cout << z.real << " - " << -z.imaginario << "i" << endl;
}

int main() {
	// Configurar consola para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    Complejo z1, z2;
    
    // Entrada de datos
    cout << "=== VERIFICACIÓN DE NÚMEROS COMPLEJOS ===" << endl << endl;
    
    cout << "Primer número complejo:" << endl;
    cout << "  Parte real: ";
    cin >> z1.real;
    cout << "  Parte imaginaria: ";
    cin >> z1.imaginario;
    
    cout << "\nSegundo número complejo:" << endl;
    cout << "  Parte real: ";
    cin >> z2.real;
    cout << "  Parte imaginaria: ";
    cin >> z2.imaginario;
    
    // Mostrar los números ingresados
    cout << "\n--- Números ingresados ---" << endl;
    mostrar("Z1 = ", z1);
    mostrar("Z2 = ", z2);
    
    // Calcular suma y multiplicación
    Complejo suma = sumar(z1, z2);
    Complejo producto = multiplicar(z1, z2);
    
    // Mostrar resultados
    cout << "\n--- Resultados ---" << endl;
    mostrar("SUMA (Z1 + Z2) = ", suma);
    mostrar("MULTIPLICACIÓN (Z1 × Z2) = ", producto);
    
    // Verificar igualdad 
    cout << "\n--- Verificación ---" << endl;
    if (sonIguales(suma, producto)) {
        cout << "✓ ¡LA SUMA Y MULTIPLICACIÓN SON IGUALES!" << endl;
    } else {
        cout << "✗ La suma y multiplicación NO son iguales." << endl;
    }
    
    return 0;
}