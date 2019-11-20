//
// Created by paco on 10/11/19.
//

#ifndef MONOPOLI__JUEGO_H
#define MONOPOLI__JUEGO_H
#include <cstring>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <unistd.h>
#include "Dado.h"
#include "User.h"
#include "Tablero.h"
using namespace std;

class Juego {

public:
    void inicio();
    void registrar_jugadores(int no_de_jugadores);


private:
    vector<User> jugadores;
    Tablero tabla;
    Dado dado1, dado2;

};


#endif //MONOPOLI__JUEGO_H