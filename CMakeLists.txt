cmake_minimum_required(VERSION 3.15)
project(Monopoly)

set(CMAKE_CXX_STANDARD 14)

set(COMMON "main.cpp" "Casilla.cpp" "Dado.cpp" "Juego.cpp" "Tablero.cpp" "User.cpp" "Carta.cpp" "Carta_de_propiedad.cpp")

add_executable(Monopoly ${COMMON})