//
// Created by paco on 24/11/19.
//

#include "Carta.h"

Carta::Carta(int ID, string regla, long dinero){
    this->ID = ID;
    this->regla = regla;
    this->dinero_que_quita_o_gana = dinero;
}
Carta::Carta(int ID, string regla, int numero_extra_de_casillas){
    this->ID = ID;
    this->regla = regla;
    this->numero_de_casillas_que_retrocede = numero_extra_de_casillas;
}

int Carta::get_Casillas_a_avanzar_o_retoceder() {
    return this->numero_de_casillas_que_retrocede;
}

long Carta::get_Dinero() {
    return this->dinero_que_quita_o_gana;
}

string Carta::get_Regla() {
    return this->regla;
}

int Carta::get_ID() {
    return this->ID;
}

void Carta::set_Dinero(int n){
    this->dinero_que_quita_o_gana = 0;
}
