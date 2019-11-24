//
// Created by paco on 10/11/19.
//

#include "Juego.h"

void Juego::registrar_jugadores(int no_de_jugadores) {
    jugadores.reserve(no_de_jugadores);
    string name;
    tabla.llenar_casillas();
    for (int i = 0; i < no_de_jugadores  ; ++i) {
        cout << "Nombre del jugador " << (i+1) << endl;
        cin >> name;
        jugadores[i].set_nombre(name);
        jugadores[i].set_estado_actual(tabla.get_casilla(0));
    }

    cout<<"Registro exitoso" << endl;
}

void Juego::inicio() {

    int numero_de_jugadores, d1, d2, pausa;
    Casilla cas_aux;
    cout << "Inicio de monopoli" << endl;
    cout << "Numero de jugadores: (Maximo 4 jugadores)" << endl;
    cin >> numero_de_jugadores;
    /* if(numero_de_jugadores > 4){
         inicio();
     }*/
    registrar_jugadores(numero_de_jugadores);
    while(1){
        for (int i = 0; i < numero_de_jugadores ; ++i) {
            cout << jugadores[i].get_nombre() << " tira dados" << endl;
            d1 = dado1.tirar_dado();
            d2 = dado2.tirar_dado();
            cout << "Dado 1: " << d1 << " Dado 2: " << d2 << " Total: " << (d1+d2) << endl;
            sleep(1.5);
            cas_aux = tabla.get_casilla((jugadores[i].get_estado_actual().get_posicion()) + (d1+d2));
            jugadores[i].set_estado_actual(cas_aux);
            cout << (jugadores[i].get_estado_actual()).get_nombre() << " " << (jugadores[i].get_estado_actual()).get_posicion() << endl;
            //cin >> pausa;
        }
    }

}
