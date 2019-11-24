//
// Created by paco on 10/11/19.
//

#ifndef MONOPOLI__CASILLA_H
#define MONOPOLI__CASILLA_H
#include <new>
#include <cstring>
#include <stdio.h>
#include <string>
using namespace std;

class Casilla {

public:
    void set_nombre(string name);
    void set_posicion(int i);
    string get_nombre();
    int get_posicion();
    Casilla(string name, int pos);
    Casilla();

private:
    string nombre;
    int posicion;

};


#endif //MONOPOLI__CASILLA_H