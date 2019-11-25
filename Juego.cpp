//
// Created by paco on 10/11/19.
//

#include "Juego.h"


//////////////////////////////////////////////////////////JUEGO//////////////////////////////////////////////////////////
void Juego::registrar_jugadores() {
    jugadores.reserve(numero_de_jugadores);
    string name;

    tabla.llenar_casillas();
    for (int i = 0; i < numero_de_jugadores  ; ++i) {
        cout << "Nombre del jugador " << (i+1) << endl;
        cin >> name;
        User aux = User(tabla.get_casilla(39), name, i);
        jugadores.push_back(aux);
    }
    cout<<"Registro exitoso" << endl;
}

void Juego::inicio() {

    //Numero maximo de jugadores
    cout << "Inicio de monopoli" << endl;
    cout << "Numero de jugadores: (Maximo 4 jugadores)" << endl;
    cin >> numero_de_jugadores;

}

Juego::Juego() {
    Cartas();
    Cartas_de_propiedades();
    inicio();
    registrar_jugadores();
    juego();
}

void Juego::juego() {

    int contador = 0;
    int d1, d2, casilla_nueva;
    Casilla cas_aux;//usada para el control de


    while(true){
        for (int jugador = 0; jugador < numero_de_jugadores ; ++jugador) {
            i = jugador;
            cout << jugadores[i].get_nombre() << " con " << jugadores[i].get_Dinero_de_usuario() << " tira dados" << endl;
            //El utuario tira los dados
            d1 = dado1.tirar_dado();
            d2 = dado2.tirar_dado();
            cout << "Total: " << (d1+d2) << " " << endl;
            sleep(.5);
            casilla_nueva = (jugadores[i].get_estado_actual()).get_posicion() + (d1+d2);


            ////////////////////////////////////////////////////////RESET DE TABLERO CUANDO YA SE DIO LA VUELTA////////////////////////////////////////
            //Validando la casilla que no se pase de 40
            //Si se pasa de 39 los manda a las primeras casillas.
            if(casilla_nueva > 39){
                casilla_nueva = casilla_nueva - 40;
                jugadores[i].suma_1000_por_pasar_el_inicio();
                jugadores[i].ya_puede_comprar();
            }
            cas_aux = tabla.get_casilla((casilla_nueva));
            //Muestra el estado actual de los jugadores
            jugadores[i].set_estado_actual(cas_aux);
            cout << "El jugador " << jugadores[i].get_nombre() << " se encuentra en " << (jugadores[i].get_estado_actual()).get_nombre() << " " << (jugadores[i].get_estado_actual()).get_posicion() << endl;
            estado_actual = jugadores[i].get_estado_actual().get_posicion();



            ///////////////////////////////////////////////////////////COMPRAAAAASSSSSS////////////////////////////////////////////////////////////
                COMPRAR();// se evalua si la casilla tiene dueño, sino se oferta al jugador que tiro y llego a esa casilla, en caso
                          // de que no la quiera el jugador, se seguira ofertando al siguiente jugador que caiga en ella

            ///////////////////////////////////////////////////////////RENTAAASSSS////////////////////////////////////////////////////////////
                 RENTAR();//le quita dinero al usuario que cae en la casilla actual y tiene dueño, el costo de la renta varie entre cuantas casas tiene y si tiene hotel.

            ///////////////////////////////////////////////////////////CARTAS CHANCE Y CARTAS COMUNITY CHEST//////////////////////////////////////
                CHANCE();
                COMUNITY_CHEST();



            sleep(.5);
            contador++;
        }
    }

}

///////////////////////////////////////////////////////COMPRASSSSS//////////////////////////////////////////////////////

void Juego::COMPRAR() {
    char compra;
    if(jugadores[i].puede_comprar() == true && tabla.get_casilla(estado_actual).get_precio_de_propiedad() != 0 && tabla.get_casilla(estado_actual).get_Nombre_de_propietario() == "Ninguno"){

        cout << "Deseas comprar la propiedad: " << (jugadores[i].get_estado_actual()).get_nombre() << " costo: $" << tabla.get_casilla(estado_actual).get_precio_de_propiedad() << endl;
        cout << "s " << "para comprar" << "n " << "para rechazar" << endl;
        //cin >> compra;
            switch ('s'){
                case 'S':
                    jugadores[i].comprar_propieda(cartas_de_propiedades[jugadores[i].get_estado_actual().get_posicion()]);

                    cartas_de_propiedades[estado_actual].set_nombre_de_propietario(jugadores[i].get_nombre());
                    cartas_de_propiedades[estado_actual].set_ID_de_propietario(jugadores[i].get_User_ID());
                    tabla.set_nombre_de_propietario(estado_actual, jugadores[i].get_nombre());
                    tabla.set_ID_de_propietario(estado_actual, jugadores[i].get_User_ID());

                    cout << tabla.get_casilla(estado_actual).get_Nombre_de_propietario() << tabla.get_casilla(estado_actual).get_ID_de_propietario() << endl;
                    break;
                case 's':
                    jugadores[i].comprar_propieda(cartas_de_propiedades[jugadores[i].get_estado_actual().get_posicion()]);

                    cartas_de_propiedades[estado_actual].set_nombre_de_propietario(jugadores[i].get_nombre());
                    cartas_de_propiedades[estado_actual].set_ID_de_propietario(jugadores[i].get_User_ID());
                    tabla.set_nombre_de_propietario(estado_actual, jugadores[i].get_nombre());
                    tabla.set_ID_de_propietario(estado_actual, jugadores[i].get_User_ID());

                    cout << tabla.get_casilla(estado_actual).get_Nombre_de_propietario() << tabla.get_casilla(estado_actual).get_ID_de_propietario() << endl;
                    break;
                case 'N':
                    break;
                case 'n':
                    break;
            }

    } else if(jugadores[i].puede_comprar() == true && tabla.get_casilla(estado_actual).get_precio_de_propiedad() != 0 && tabla.get_casilla(estado_actual).get_Nombre_de_propietario() ==  jugadores[i].get_nombre() && tabla.get_casilla(estado_actual).get_numero_de_casas() < 4){
        cout << "Deseas comprar una casa?" << endl;
        char eleccion;
       cin >> eleccion;
        switch (eleccion){
        case 's': case 'S':
            tabla.get_casilla(estado_actual).incrementar_numero_de_casas(1);
                cout << "El costo en " << tabla.get_casilla(estado_actual).get_nombre() << " es de " << cartas_de_propiedades[estado_actual].get_precio_de_casa() << endl;
                        jugadores[i].restar_Dinero_de_usuario( cartas_de_propiedades[estado_actual].get_precio_de_casa()*(-1));

                        cout << tabla.get_casilla(estado_actual).get_numero_de_casas() << " " << jugadores[i].get_nombre() << " " << jugadores[i].get_Dinero_de_usuario() << endl;
                break;

        }
     //sleep(3);
    } else if(jugadores[i].puede_comprar() == true && tabla.get_casilla(estado_actual).get_precio_de_propiedad() != 0 && tabla.get_casilla(estado_actual).get_Nombre_de_propietario() ==  jugadores[i].get_nombre() && tabla.get_casilla(estado_actual).get_numero_de_casas() == 4){
        cout << "Deseas comprar un hotel?" << endl;
    }
}

/////////////////////////////////////////////////////////////////RENTAS/////////////////////////////////////////////////
void Juego::RENTAR() {
    Casilla auxiliar;

    int n_de_casas;
    long precio_de_propiedad;
    int renta;
    if(tabla.get_casilla(estado_actual).get_precio_de_propiedad() != 0 && tabla.get_casilla(estado_actual).get_Nombre_de_propietario() != "Ninguno" && tabla.get_casilla(estado_actual).get_Nombre_de_propietario() != jugadores[i].get_nombre()){
        auxiliar = tabla.get_casilla(estado_actual);
            if(!auxiliar.get_renta_de_hotel()) {

                n_de_casas = auxiliar.get_numero_de_casas();
                precio_de_propiedad = auxiliar.get_precio_de_propiedad();
                renta = jugadores[auxiliar.get_ID_de_propietario()].get_Carta_de_propiedad(estado_actual).get_renta_por_casa(n_de_casas, precio_de_propiedad);

                cout << auxiliar.get_nombre() << " Propiedad de " << auxiliar.get_Nombre_de_propietario() << " con "
                     << tabla.get_casilla(estado_actual).get_numero_de_casas() << " casas. " << "Consto de la renta: " << renta << endl;

                renta = renta * (-1);
                jugadores[i].restar_Dinero_de_usuario(renta);
                cout << jugadores[i].get_nombre() << " " << jugadores[i].get_Dinero_de_usuario() << endl;
                renta = renta * (-1);
                jugadores[auxiliar.get_ID_de_propietario()].sumar_Dinero_de_usuario(renta);
                cout << jugadores[auxiliar.get_ID_de_propietario()].get_nombre() << " " << jugadores[auxiliar.get_ID_de_propietario()].get_Dinero_de_usuario() << endl;

            } else if(auxiliar.get_renta_de_hotel()){

                renta = jugadores[auxiliar.get_ID_de_propietario()].get_Carta_de_propiedad(estado_actual).get_renta_de_casas_y_hotel();

                cout << auxiliar.get_nombre() << " Propiedad de " << auxiliar.get_Nombre_de_propietario() << " con "
                     << auxiliar.get_numero_de_casas() << " casas y hotel. " << "Consto de la renta: " << renta << endl;

                renta = renta * (-1);
                jugadores[i].restar_Dinero_de_usuario(renta);
                cout << jugadores[i].get_nombre() << " " << jugadores[i].get_Dinero_de_usuario() << endl;
                renta = renta * (-1);
                jugadores[auxiliar.get_ID_de_propietario()].sumar_Dinero_de_usuario(renta);
                cout << jugadores[auxiliar.get_ID_de_propietario()].get_nombre() << " " << jugadores[auxiliar.get_ID_de_propietario()].get_Dinero_de_usuario() << endl;

            }

    }
}

///////////////////////////////////////////////////////////////////CHANCE(CARD)/////////////////////////////////////////
void Juego::CHANCE(){
    int dinero;
    int numero_de_carta = Generar_numero_aleatorio_para_cartas(0,13);
    if((jugadores[i].get_estado_actual()).get_posicion() == 7 || (jugadores[i].get_estado_actual()).get_posicion() == 22 || (jugadores[i].get_estado_actual()).get_posicion() == 36) {

        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t CHANCE" << endl;

        cout << cartas[numero_de_carta].get_Regla() << endl;

        //Se da dinero al usuario
        if (numero_de_carta >= 00 && numero_de_carta <= 5) {
            dinero = cartas[numero_de_carta].get_Dinero();
            jugadores[i].sumar_Dinero_de_usuario(dinero);
        }

        //Se quita dinero al usuario
        if (numero_de_carta > 5 && numero_de_carta <= 13) {
            dinero = cartas[numero_de_carta].get_Dinero();
            jugadores[i].restar_Dinero_de_usuario(dinero);
        }

        cout << "\n\n\n\n" << endl;
        sleep(.5);
    }

}

///////////////////////////////////////////////////////////////////COMUNITY_CHEST(CARD)//////////////////////////////////////
void Juego::COMUNITY_CHEST(){
    int dinero;
    int numero_de_carta = Generar_numero_aleatorio_para_cartas(14,21);
    if((jugadores[i].get_estado_actual()).get_posicion() == 2 || (jugadores[i].get_estado_actual()).get_posicion() == 17 || (jugadores[i].get_estado_actual()).get_posicion() == 33) {
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t COMUNITY CHEST" << endl;

        cout << cartas[numero_de_carta].get_Regla() << endl;

        //Retrocede casillas
        if (numero_de_carta >= 14 && numero_de_carta <= 18) {
            int retroceso = (jugadores[i].get_estado_actual()).get_posicion() -
                            cartas[numero_de_carta].get_Casillas_a_avanzar_o_retoceder();
            jugadores[i].set_estado_actual(tabla.get_casilla(retroceso));
        }

        //Se va a la carcel
        if (numero_de_carta > 18 && numero_de_carta <= 21) {
            jugadores[i].set_estado_actual(tabla.get_casilla(10));
        }

        cout << "\n\n\n\n" << endl;
        sleep(.5);

    }

}


//////////////////////////////////////////////////////////////////CARTAS(vector)////////////////////////////////////////
void Juego::Cartas() {


////////////////////////DINERO//////////////////////////////////////////////////////////////////////////////////////////
    int contador = 0;
    long varo;
    int casillas_a_retroceder;
    string Regla, dinero;

    cartas.reserve(22);

    ifstream sumar_dinero, restar_dinero, retroceso_de_casillas, carcel;

    sumar_dinero.open("/home/paco/Escritorio/Distribuidas/Practicas_pal_ukraniofest/Monopoly/Cartas_de_dinero/Reglas_de_Cartas_que_DAN_dinero.txt", ios::in);

    ///SUMA DE DINERO
    if(!sumar_dinero.fail()) {
        while (!sumar_dinero.eof()) {
            getline(sumar_dinero, Regla, '\n');
            getline(sumar_dinero, dinero, '\n');

            varo = atoi(dinero.c_str());

            Carta card = Carta(contador, Regla, varo);
            cartas.push_back(card);
            contador++;
        }

        /*for (int i = 0; i < 6; ++i) {
            cout << cartas[i].get_Regla() << " " << cartas[i].get_Dinero() << " " << cartas[i].get_ID() << endl;
        }*/
    }

    sumar_dinero.close();


    ////RESTA DE DINERO
    restar_dinero.open("/home/paco/Escritorio/Distribuidas/Practicas_pal_ukraniofest/Monopoly/Cartas_de_dinero/Reglas_de_Cartas_que_quitan_dinero.txt", ios::in);
    if(!restar_dinero.fail()) {
        while (!restar_dinero.eof()) {
            getline(restar_dinero, Regla, '\n');
            getline(restar_dinero, dinero, '\n');

            varo = atoi(dinero.c_str());
            varo = varo * (-1);
            //cout << varo << " ";
            Carta card = Carta(contador, Regla, varo);
            cartas.push_back(card);
            contador++;
        }

       /* for (int i = 0; i < contador; ++i) {
            cout << cartas[i].get_Regla() << " " << cartas[i].get_Dinero() << " " << cartas[i].get_ID() << endl;
        }*/
    }

    restar_dinero.close();

    //////////////////////////////////////////////////CARTAS QUE TE HACEN RETORCEDER////////////////////////////////////
    retroceso_de_casillas.open("/home/paco/Escritorio/Distribuidas/Practicas_pal_ukraniofest/Monopoly/Cartas_Retroceso_de_casillas/Reglas_que_te_hacen_retoceder.txt", ios::in);
    if(!retroceso_de_casillas.fail()) {
        while (!retroceso_de_casillas.eof()) {
            getline(retroceso_de_casillas, Regla, '\n');
            getline(retroceso_de_casillas, dinero, '\n');

            casillas_a_retroceder = atoi(dinero.c_str());
            //cout << casillas_a_retroceder << " ";
            Carta card = Carta(contador, Regla, casillas_a_retroceder*-1);
            card.set_Dinero(0);
            cartas.push_back(card);
            contador++;
        }

        /*for (int k = 0; k < contador; ++k) {
             cout << cartas[k].get_Regla() << " " << cartas[k].get_Casillas() << " " << cartas[k].get_ID() << endl;
         }*/
    }

    retroceso_de_casillas.close();

    /////////////////////////////////////////////////CARTAS QUE TE SAVAN DE LA CARCEL///////////////////////////////////
    carcel.open("/home/paco/Escritorio/Distribuidas/Practicas_pal_ukraniofest/Monopoly/Cartas_que_te_sacan_o_mandan_CARCEL/Reglas_que_te_MANDAN_ALV.txt", ios::in);
    if(!carcel.fail()) {
        while (!carcel.eof()) {
            getline(carcel, Regla, '\n');
            getline(carcel, dinero, '\n');

            casillas_a_retroceder = atoi(dinero.c_str());
           // cout << casillas_a_retroceder << " ";
            Carta card = Carta(contador, Regla, casillas_a_retroceder);
            card.set_Dinero(0);
            cartas.push_back(card);
            contador++;
        }

        /*for (int k = 0; k < contador; ++k) {
            cout << cartas[k].get_Regla() << " " << cartas[k].get_Casillas() << " " << cartas[k].get_ID() << endl;
        }*/
    }

    carcel.close();

    carcel.open("/home/paco/Escritorio/Distribuidas/Practicas_pal_ukraniofest/Monopoly/Cartas_que_te_sacan_o_mandan_CARCEL/Reglas_que_te_salvan_el_qlito.txt", ios::in);
    if(!carcel.fail()) {
        while (!carcel.eof()) {
            getline(carcel, Regla, '\n');
            getline(carcel, dinero, '\n');

            casillas_a_retroceder = atoi(dinero.c_str());
            // cout << casillas_a_retroceder << " ";
            Carta card = Carta(contador, Regla, casillas_a_retroceder);
            card.set_Dinero(0);
            cartas.push_back(card);
            contador++;
        }

        /*for (int k = 0; k < contador; ++k) {
            cout << cartas[k].get_Regla() << " " << cartas[k].get_Casillas_a_avanzar_o_retoceder() << " " << cartas[k].get_ID() << endl;
        }*/
    }
    carcel.close();
}

int Juego::Generar_numero_aleatorio_para_cartas(int inicio, int fin){
    {
        static std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis(0, 21);
        return dis(gen);
    }
}

void Juego::Cartas_de_propiedades() {
 cout << "adasadd" << endl;

 cartas_de_propiedades.reserve(28);

    for (int i = 0; i < 40; ++i) {
        //if((tabla.get_casilla(i)).get_precio_de_propiedad() != 0){
            Carta_de_propiedad card_pro = Carta_de_propiedad(tabla.get_casilla(i).get_nombre(), tabla.get_casilla(i).get_color(), tabla.get_casilla(i).get_posicion(), tabla.get_casilla(i).get_precio_de_propiedad());
            cartas_de_propiedades.push_back(card_pro);

        //}
    }

   /* for (int j = 0; j < 28 ; ++j) {
        cout << cartas_de_propiedades[j].get_nombre() << " " << cartas_de_propiedades[j].get_color() << " " << cartas_de_propiedades[j].get_precio_de_propiedad() << " " << cartas_de_propiedades[j].get_precio_de_propiedad() << endl;
    }*/


}



