#pragma once
#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

using namespace System;

int  leerEnteroRango(String^ mensaje, int minVal, int maxVal);
char leerCaracter(String^ mensaje);
void dibujarDado(int valor);
int  lanzarDado();
bool deseaContinuar();
void mostrarEstado(int suma);
void evaluarResultado(int suma);

#endif
