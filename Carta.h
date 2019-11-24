//
// Created by paco on 24/11/19.
//

#ifndef MONOPOLY_CARTA_H
#define MONOPOLY_CARTA_H

#include <new>
#include <cstring>
#include <stdio.h>
#include <string>
#include "Casilla.h"

using namespace std;

class Carta {
private:
    int ID;
    string regla;
    long dinero_que_quita_o_gana;
    int numero_de_casillas_que_retrocede;

public:

    Carta(int ID, string regla, long dinero);
    Carta(int ID, string regla, int numero_extra_de_casillas);
    int get_ID();
    string get_Regla();
    long get_Dinero();
    int get_Casillas_a_avanzar_o_retoceder();
    void set_Dinero(int);

};


#endif //MONOPOLY_CARTA_H
