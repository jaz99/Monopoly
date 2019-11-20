
#include "User.h"
Casilla User::get_estado_actual() {
    return lugar;
}

void User::set_estado_actual(Casilla cas) {
    lugar.set_nombre(cas.get_nombre());
    lugar.set_posicion(cas.get_posicion());
}

void User::manda_al_inicio(string name, int i) {
    lugar.set_posicion(i);
    lugar.set_nombre(name);
}

string User::get_nombre() {
    return this->nombre;
}

void User::set_nombre(string name) {
    this->nombre = name;
}


User::User(Casilla cas) {
    lugar.set_nombre(cas.get_nombre());
    lugar.set_posicion(cas.get_posicion());
}