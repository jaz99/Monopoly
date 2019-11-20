//
// Created by paco on 10/11/19.
//

#include "Dado.h"

int Dado::tirar_dado() {
    static std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);

    return dis(gen);
}