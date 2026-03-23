#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Nodo {
    char valor;
    Nodo* izq;
    Nodo* der;
    Nodo(char v) : valor(v), izq(NULL), der(NULL) {}
};

Nodo* construir(string pre, string ino) {
    if (pre.empty()) return NULL;
    char raiz  = pre[0];
    int  pos   = ino.find(raiz);
    Nodo* nodo = new Nodo(raiz);
    nodo->izq  = construir(pre.substr(1, pos),  ino.substr(0, pos));
    nodo->der  = construir(pre.substr(1 + pos), ino.substr(pos + 1));
    return nodo;
}

string obtenerPostorden(Nodo* nodo) {
    if (!nodo) return "";
    return obtenerPostorden(nodo->izq)
         + obtenerPostorden(nodo->der)
         + nodo->valor;
}

int altura(Nodo* nodo) {
    if (!nodo) return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void dibujarArbol(Nodo* raiz) {
    if (!raiz) return;

    int h     = altura(raiz);
    int ancho = (1 << h) - 1;
    int celda = 3;

    // ── CAMBIO CLAVE: usar pair<Nodo*,int> en vez de structured binding ──
    queue< pair<Nodo*, int> > cola;
    cola.push(make_pair(raiz, 1));

    cout << "\n+----------------------------------------------+" << endl;
    cout << "|              ARBOL BINARIO                   |" << endl;
    cout << "+----------------------------------------------+" << endl;

    for (int nivel = 0; nivel < h; nivel++) {
        int nodosNivel = 1 << nivel;
        int espacioIzq = (ancho / (nodosNivel * 2)) * celda;
        int espacioMed = (ancho / nodosNivel) * celda - celda;

        // ── Recoger fila actual ──────────────────────────────────
        vector< pair<Nodo*, int> > fila;
        int nEnCola = cola.size();
        for (int i = 0; i < nEnCola; i++) {
            fila.push_back(cola.front());
            cola.pop();
        }

        // ── Cola del siguiente nivel ─────────────────────────────
        queue< pair<Nodo*, int> > siguiente;

        // ── Imprimir nodos ───────────────────────────────────────
        cout << string(max(0, espacioIzq), ' ');
        int posEsperada = 1;

        for (int f = 0; f < (int)fila.size(); f++) {
            // ── ACCESO sin structured binding ────────────────────
            Nodo* nodo = fila[f].first;
            int   pos  = fila[f].second;

            while (posEsperada < pos) {
                cout << "   " << string(max(0, espacioMed), ' ');
                posEsperada++;
            }

            if (nodo)
                cout << "[" << nodo->valor << "]";
            else
                cout << "   ";

            cout << string(max(0, espacioMed), ' ');
            posEsperada++;

            if (nivel + 1 < h) {
                siguiente.push(make_pair(nodo ? nodo->izq : NULL, pos * 2 - 1));
                siguiente.push(make_pair(nodo ? nodo->der : NULL, pos * 2));
            }
        }
        cout << "\n";

        // ── Imprimir ramas / \ ───────────────────────────────────
        if (nivel + 1 < h) {
            int ramas = 1 << nivel;
            int espR  = (ancho / (ramas * 2)) * celda;
            int sepR  = (ancho / ramas) * celda - 1;

            for (int r = 1; r <= 3; r++) {
                cout << string(max(0, espR - r), ' ');
                for (int i = 0; i < ramas; i++) {
                    cout << "/" << string(r * 2 - 1, ' ') << "\\";
                    if (i < ramas - 1)
                        cout << string(max(0, sepR - r * 2), ' ');
                }
                cout << "\n";
            }
        }

        cola = siguiente;   // ahora 'siguiente' está en scope correcto
    }
}

void liberar(Nodo* nodo) {
    if (!nodo) return;
    liberar(nodo->izq);
    liberar(nodo->der);
    delete nodo;
}

int main() {
    string preorden, inorden;

    cout << "===========================================" << endl;
    cout << "  ARBOL BINARIO - PRE + INORDEN + DIBUJO  " << endl;
    cout << "===========================================" << endl;

    cout << "Ingrese recorrido en PREORDEN: ";
    cin  >> preorden;
    cout << "Ingrese recorrido en INORDEN:  ";
    cin  >> inorden;

    if (preorden.length() != inorden.length()) {
        cout << "\n[Error] Los recorridos deben tener la misma longitud." << endl;
        return 1;
    }

    Nodo*  arbol   = construir(preorden, inorden);
    string postord = obtenerPostorden(arbol);

    dibujarArbol(arbol);

    cout << "\n--- Recorridos ---"           << endl;
    cout << "  Preorden:  " << preorden      << endl;
    cout << "  Inorden:   " << inorden       << endl;
    cout << "  Postorden: " << postord       << endl;
    cout << "  Altura:    " << altura(arbol) << " niveles" << endl;
    cout << "===========================================" << endl;

    liberar(arbol);
    return 0;
}