//
// Created by paco on 10/11/19.
//

#include "Tablero.h"

int Tablero::get_numero_de_casilla(int numero_de_casilla) {
    return casillas[numero_de_casilla].get_posicion();
}

string Tablero::get_color_de_Casilla(int numero_de_casilla){
    return casillas[numero_de_casilla].get_color();
}

void Tablero::llenar_casillas() {
    string s, x;
    casillas.reserve(40);
    int cont = 0;
    long precio;
    ifstream archivo;
    archivo.open("/home/paco/Escritorio/Distribuidas/Practicas_pal_ukraniofest/Monopoly/Nombres_de_casillas.txt", ios::in);

    ///Nombres
    if(!archivo.fail()) {
        while (!archivo.eof()) {
            getline(archivo, s, '\n');
            getline(archivo, x, '\n');
            precio = atoi(x.c_str());
            Casilla cas = Casilla(s, cont, precio);
            casillas.push_back(cas);
        }
    }

    for (int k = 0; k < 40 ; ++k) {
        casillas[k].set_posicion(k);
        /*getline(archivo, s, '\0');
        casillas[k].set_nombre(s);*/
    }

    ///Colores
    for (int i = 0; i < 40 ; ++i) {
        s = "nombre";
        if(i == 2 || i == 4 || i == 5 || i == 7 || i == 12 || i == 15 || i == 17 || i == 22 || i == 25 || i == 28 || i == 33 || i == 35 || i == 36 || i == 38){
            casillas[i].set_color("sin_color");
        }
        if((i % 10) == 0 ){
            casillas[i].set_color("Blanco");
        }
        if(i == 1 || i == 3){
            casillas[i].set_color("Morado");
        }
        if(i == 9 || i == 8 || i == 6){
            casillas[i].set_color("Azul_cielo");
        }
        if(i == 11 || i == 13 || i == 14){
            casillas[i].set_color("Rosa");
        }
        if(i == 19 || i == 18 || i == 16){
            casillas[i].set_color("Anaranjado");
        }
        if(i == 21 || i == 23 || i == 24){
            casillas[i].set_color("Rojo");
        }
        if(i == 29 || i == 27 || i == 26){
            casillas[i].set_color("Amarillo");
        }
        if(i == 31 || i == 32 || i == 34){
            casillas[i].set_color("Verde");
        }
        if(i == 37 || i == 39){
            casillas[i].set_color("Azul");
        }

    }

    /*for (int j = 0; j < 40; ++j) {
       casillas[j].mostrar_datos();
    }*/

}

Tablero::Tablero() {
    llenar_casillas();
}

Casilla Tablero::get_casilla(int i) {
    return casillas[i];
}
