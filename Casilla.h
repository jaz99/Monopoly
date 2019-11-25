//
// Created by paco on 10/11/19.
//

#ifndef MONOPOLI__CASILLA_H
#define MONOPOLI__CASILLA_H
#include <new>
#include <cstring>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Casilla {

public:
    void set_nombre(string nombre);
    string get_nombre();
    void set_color(string c);
    void set_posicion(int i);
    string get_color();
    int get_posicion();
    void incrementar_numero_de_casas(int n);
    int get_numero_de_casas();
    void mostrar_datos();
    long get_precio_de_propiedad();
    string get_Nombre_de_propietario();
    void set_Nombre_de_propietario(string name);
    int get_ID_de_propietario();
    void set_ID_de_propietario(int ID);
    bool get_renta_de_hotel();
    void set_compra_de_hotel();
   // Casilla(string color, int pos, string color);
    Casilla(string nombre, int pos, long precio);
    Casilla();

private:
    string color;
    int posicion;
    string nombre;
    int numero_de_casas = 0;
    bool hotel = false ;
    long precio;
    string propietario = " ";
    int ID_de_propietario;
    int numero_real_de_casas = 0;

};


#endif //MONOPOLI__CASILLA_H