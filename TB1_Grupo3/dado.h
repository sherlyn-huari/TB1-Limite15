#pragma once
#ifndef _DADO_H_
#define _DADO_H_

#include "pch.h"

struct Dado {
    int valor;        // resultado 1-6
    int cara[7][7];   // matriz con 0s y 1s
};

String^ toClrD(string s);
Dado lanzarDado();
void cargarCara(Dado& d, int valor);
void dibujarDado(Dado d);
void dibujarBordeSuperior();   
void dibujarBordeInferior();   

#endif