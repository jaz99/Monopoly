//
// Created by paco on 10/11/19.
//

#include "Casilla.h"

void Casilla::set_nombre(string name) {
    this->nombre = name;
}

void Casilla::set_posicion(int i) {
    this->posicion = i;
}

int Casilla::get_posicion() {
    return this->posicion;
}

string Casilla::get_nombre() {
    return this->nombre;
}

Casilla::Casilla(string name, int pos) {
    this->nombre = name;
    this->posicion = pos;
}

Casilla::Casilla() {

}