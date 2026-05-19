#pragma once
#ifndef _JUEGO_H_
#define _JUEGO_H_

#include "dado.h"

enum ResultadoPartida {
    GANO,
    PERDIO_BAJO_PUNTAJE,
    TE_PASASTE
};

void mostrarEncabezadoPartida(int numeroPartida, int totalPartidas);
void mostrarEstadoPuntaje(int suma, int lanzamientos);
bool pedirOtroDado();
ResultadoPartida evaluarResultado(int suma);
void mostrarResultadoPartida(ResultadoPartida r, int suma);
ResultadoPartida ejecutarPartida(int numeroPartida, int totalPartidas);
void mostrarReglas();

#endif