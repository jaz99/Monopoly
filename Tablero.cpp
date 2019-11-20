//
// Created by paco on 10/11/19.
//

#include "Tablero.h"

int Tablero::get_numero_de_casilla(int numero_de_casilla) {
    return casillas[numero_de_casilla].get_posicion();
}

string Tablero::get_nombre_de_Casilla(int numero_de_casilla){
    return casillas[numero_de_casilla].get_nombre();
}

void Tablero::llenar_casillas() {
    string s, x;
    casillas.reserve(40);
    for (int i = 0; i < 40 ; ++i) {
        s = "nombre";
        Casilla cas = Casilla(s, i);

        casillas.push_back(cas);
    }

    /* for (int j = 0; j < 40 ; ++j) {
         cout << casillas[j].get_nombre() << endl;
     }*/
}

Tablero::Tablero() {
    llenar_casillas();
}

Casilla Tablero::get_casilla(int i) {
    return casillas[i];
}
