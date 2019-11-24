//
// Created by paco on 10/11/19.
//

#ifndef MONOPOLI__DADO_H
#define MONOPOLI__DADO_H
#include <new>
#include <cstring>
#include <stdio.h>
#include <string>
#include <random>
using namespace std;

class Dado {
public:
    int tirar_dado();
private:
    int numero;

};


#endif //MONOPOLI__DADO_H