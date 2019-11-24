//
// Created by paco on 10/11/19.
//

#ifndef MONOPOLI__TABLERO_H
#define MONOPOLI__TABLERO_H
#include <new>
#include <cstring>
#include <stdio.h>
#include "Casilla.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
#define TAM_MAX_DATA  40000
class Tablero {

public:
    int get_numero_de_casilla(int numero_de_casilla);
    string get_color_de_Casilla(int numero_de_casilla);
    Casilla get_casilla(int i);
    void llenar_casillas();
    Tablero();

private:
    vector<Casilla> casillas;
};


#endif //MONOPOLI__TABLERO_H