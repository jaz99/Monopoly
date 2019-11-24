//
// Created by paco on 10/11/19.
//

#ifndef MONOPOLI__USER_H
#define MONOPOLI__USER_H

#include <new>
#include <cstring>
#include <stdio.h>
#include <string>
#include "Casilla.h"

using namespace std;

class User {

public:
    void set_estado_actual(Casilla cas);
    Casilla get_estado_actual();
    void manda_al_inicio(string name, int i);
    string get_nombre();
    void set_nombre(string name);
    long get_Dinero_de_usuario();
    void restar_Dinero_de_usuario(long n);
    void sumar_Dinero_de_usuario(long n);
    void suma_1000_por_pasar_el_inicio();
    User(Casilla cas, string name);

private:
    string nombre;
    Casilla lugar;
    long dinero = 2000;

};


#endif //MONOPOLI__USER_H