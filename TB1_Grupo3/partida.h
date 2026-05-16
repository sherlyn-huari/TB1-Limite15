#pragma once

#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include "juego.h"

struct RegistroJuego {
	int totalPartidas;
	int victorias;
	int derrotas;
};

void mostrarEstadisticas(RegistroJuego);
void actualizarRegistro(RegistroJuego&, ResultadoPartida);

#endif 