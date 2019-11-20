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
    User(Casilla cas);

private:
    string nombre;
    Casilla lugar;

};


#endif //MONOPOLI__USER_H