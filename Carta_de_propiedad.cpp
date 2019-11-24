//
// Created by paco on 24/11/19.
//

#include "Carta_de_propiedad.h"

Carta_de_propiedad::Carta_de_propiedad(string nombre, string color, int posicio, long precio) {
this->nombre = nombre;
this->color = color;
this->posicion = posicion;
this->numero_de_casas = 0;
this->hotel = false;
this->precio = precio;
}

string Carta_de_propiedad::get_nombre() {
    return this->nombre;
}

string Carta_de_propiedad::get_color() {
    return this->color;
}

int Carta_de_propiedad::get_posicion() {
    return this->posicion;
}


string Carta_de_propiedad::get_nombre_de_propietario() {
    return this->propietario;
}

int Carta_de_propiedad::get_ID_de_propietario() {
    return this->ID_de_propietario;
}

void Carta_de_propiedad::set_nombre_de_propietario(string name) {
    this->propietario = name;
}

void Carta_de_propiedad::set_ID_de_propietario(int i) {
    this->ID_de_propietario = i;
}

long Carta_de_propiedad::get_precio_de_propiedad() {
    return this->precio;
}

int Carta_de_propiedad::get_costo_de_casas_y_hotel() {
    return this->costo_de_casas_y_hotel;
}

