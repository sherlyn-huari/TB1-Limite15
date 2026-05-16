#pragma once
#ifndef _JUEGO_H_
#define _JUEGO_H_

#include "dado.h"

enum ResultadoPartida {
    GANO,
    PERDIO_BAJO_PUNTAJE,
    TE_PASASTE
};

void mostrarEncabezadoPartida(int partida, int total);
void mostrarEstadoPuntaje(int suma, int lanzamientos);  // muestra suma actual y cuantos dados lleva
bool pedirOtroDado();                                   // pregunta 's' o 'n'
ResultadoPartida evaluarResultado(int suma, bool sePlanto);
void mostrarResultadoPartida(ResultadoPartida r, int suma);
ResultadoPartida ejecutarPartida();                     //  while loop 

void mostrarReglas();

#endif