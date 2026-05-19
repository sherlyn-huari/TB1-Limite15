#pragma once // evita que este archivo  se incluya más de una vez al compilar

//Si _PARTIDA_H_ todavía no está definido
#ifndef _PARTIDA_H_
#define _PARTIDA_H_
//Entonces defínelo y permite leer el contenido del archivo
#include "juego.h"
// incluye archivo llamado juego.h es necesario porque aquí usas: ResultadoPartida
struct RegistroJuego {
	int totalPartidas;
	int victorias;
	int derrotas;
};

/*Uso RegistroJuego como un tipo de dato propio para agrupar el total de partidas, victorias y derrotas.
Uso & en actualizarRegistro porque necesito modificar el registro original y no una copia*/

//creando un nuevo tipo de dato llamado RegistroJuego
int pedirNumeroPartidas();
RegistroJuego inicializarRegistro(int totalPartidas);
// se usa referencia porque se tiene acceder al dato real 
void actualizarRegistro(RegistroJuego& r, ResultadoPartida resultado);
void mostrarMarcador(RegistroJuego registro, int partidaActual);
void mostrarGanadorFinal(RegistroJuego registro);
void ejecutarTodasLasPartidas();

#endif 