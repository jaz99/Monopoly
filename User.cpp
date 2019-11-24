
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


User::User(Casilla cas, string name) {
    lugar.set_nombre(cas.get_nombre());
    lugar.set_posicion(cas.get_posicion());
    this->nombre = name;
}

void User::restar_Dinero_de_usuario(long n) {
    this->dinero = this->dinero + n;
}

long User::get_Dinero_de_usuario() {
    return this->dinero;
}

void User::sumar_Dinero_de_usuario(long n) {
    this->dinero = this->dinero + n;
}

void User::suma_1000_por_pasar_el_inicio() {
    this->dinero = this->dinero + 1000;
}
