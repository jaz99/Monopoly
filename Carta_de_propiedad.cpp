//
// Created by paco on 24/11/19.
//

#include "Carta_de_propiedad.h"

Carta_de_propiedad::Carta_de_propiedad(string nombre, string color, int posicio, long precio) {

    this->precio = precio;
    this->nombre = nombre;
    this->color = color;
    this->posicion = posicion;
    this->numero_de_casas = 0;
    this->hotel = false;

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

int Carta_de_propiedad::get_renta_de_casas_y_hotel() {
    return ((precio/2) +125) + 50;
}

int Carta_de_propiedad::get_renta_sin_casas() {
    return 75;
}

long Carta_de_propiedad::get_renta_por_casa(int n, long p) {
    long renta = 0;

    cout << p << endl;

    if(n == 0){
        renta = (p) + 25;
    }
    if(n == 1){
        renta = (p) + 50;
    }
    if(n == 2){
        renta = (p) + 75;
    }
    if(n == 3){
        renta = (p) + 100;
    }
    if(n == 4){
        renta = (long)(p) + 125;
    }
    return renta;
}

Carta_de_propiedad::Carta_de_propiedad() {

}

int Carta_de_propiedad::get_precio_de_casa() {
    return precio_de_cada_casa;
}

