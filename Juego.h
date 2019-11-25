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
#include "Carta_de_propiedad.h"
using namespace std;

class Juego {

public:

    int Generar_numero_aleatorio_para_cartas(int, int);
    void inicio();
    void registrar_jugadores();
    void juego();
    void Cartas();
    void Cartas_de_propiedades();
    Juego();
    void CHANCE();
    void COMUNITY_CHEST();
    void COMPRAR();
    void RENTAR();

private:
    vector<User> jugadores;
    vector<Carta> cartas;
    vector <Carta_de_propiedad> cartas_de_propiedades;
    Tablero tabla;
    Dado dado1, dado2;
    int numero_de_jugadores;
    int estado_actual;
    int i; //variable que indicara el turno del participante (jugador 0, jugador 1, jugador 2 o jugador 3)



};


#endif //MONOPOLI__JUEGO_H