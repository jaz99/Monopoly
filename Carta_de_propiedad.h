//
// Created by paco on 24/11/19.
//

#ifndef MONOPOLY_CARTA_DE_PROPIEDAD_H
#define MONOPOLY_CARTA_DE_PROPIEDAD_H
#include <cstring>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class Carta_de_propiedad {
private:
    string color;
    int posicion;
    string nombre;
    int costo_de_casas_y_hotel = 200;
    int numero_de_casas;
    bool hotel;
    long precio;
    string propietario;
    int ID_de_propietario;

public:
    Carta_de_propiedad(string nombre, string color, int posicion, long precio);
    string get_nombre();
    string get_color();
    int get_posicion();
    string get_nombre_de_propietario();
    int get_ID_de_propietario();
    long get_precio_de_propiedad();
    int get_costo_de_casas_y_hotel();

    void set_nombre_de_propietario(string name);
    void set_ID_de_propietario(int i);
};


#endif //MONOPOLY_CARTA_DE_PROPIEDAD_H
