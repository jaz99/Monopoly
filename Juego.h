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
#include "Carta.h"
using namespace std;

class Juego {

public:
    void inicio();
    void registrar_jugadores();
    void juego();
    void Cartas();
    Juego();
    void CHANCE(int);
    void COMUNITY_CHEST(int);
    int Generar_numero_aleatorio_para_cartas(int, int);

private:
    vector<User> jugadores;
    vector<Carta> cartas;
    Tablero tabla;
    Dado dado1, dado2;
    int numero_de_jugadores;


};


#endif //MONOPOLI__JUEGO_H