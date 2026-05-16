#pragma once
#ifndef _ANIMACION_H_
#define _ANIMACION_H_

#include "pch.h"

void animarBienvenida();        // titulo animado al iniciar
void animarLanzamiento();       // "lanzando dado..." con puntitos suspense
void animarVictoria();          // cuando GANO
void animarDerrota();           // cuando PERDIO o TE_PASASTE
void animarCarga(String^, int); // barra de carga generica

#endif
