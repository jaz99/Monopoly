//
// Created by paco on 10/11/19.
//

#ifndef MONOPOLI__USER_H
#define MONOPOLI__USER_H

#include <new>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <string>
#include "Casilla.h"
#include "Carta_de_propiedad.h"
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
    bool puede_comprar();
    void ya_puede_comprar();
    void comprar_propieda(Carta_de_propiedad card);
    int get_User_ID();
    User(Casilla cas, string name, int ID);

private:
    string nombre;
    Casilla lugar;
    long dinero = 2000;
    bool compras = false;
    vector <Carta_de_propiedad> mis_propiedades;
    int ID;

};


#endif //MONOPOLI__USER_H