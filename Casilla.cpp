//
// Created by paco on 10/11/19.
//

#include "Casilla.h"

void Casilla::set_color(string c) {
    this->color = c;
}

void Casilla::set_posicion(int i) {
    this->posicion = i;
}

int Casilla::get_posicion() {
    return this->posicion;
}

string Casilla::get_color() {
    return this->color;
}

Casilla::Casilla(string nombre, int pos, long precio) {
    this->nombre = nombre;
    this->posicion = pos;
    this->numero_de_casas = 0;
    this->precio = precio;
    this->propietario = "Ninguno";
}

Casilla::Casilla() {

}

void Casilla::set_nombre(string nombre) {
    this->nombre = nombre;
}

string Casilla::get_nombre() {
    return nombre;
}

void Casilla::set_numero_de_casas(int n) {
this->numero_de_casas = n;
}

int Casilla::get_numero_de_casas() {
    return numero_de_casas;
}

void Casilla::mostrar_datos() {
    cout << nombre + " " + color << " precio" << precio << " numero de casas" << numero_de_casas << " posicion" << posicion << endl;
}

long Casilla::get_precio_de_propiedad() {
    return this->precio;
}

string Casilla::get_Nombre_de_propietario() {
    return this->propietario;
}

void Casilla::set_Nombre_de_propietario(string name) {
    this->propietario = name;
}

int Casilla::get_ID_de_propietario() {
    return this->ID_de_propietario;
}

void Casilla::set_ID_de_propietario(int ID) {
    this->ID_de_propietario = ID;
}

