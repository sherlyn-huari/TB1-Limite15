#include "pch.h"
#include "utils.h"

void limpiarPantalla() {
	Console::Clear();
}

void pausar(int ms) {
	Thread::Sleep(ms);
}

void mostrarLinea(int largo, char caracter) {
    Console::Write("  ");
    for (int i = 0; i < largo; i++)
        Console::Write(caracter);
    Console::WriteLine();
}

void mostrarTitulo() {
    Console::ForegroundColor = ConsoleColor::Cyan;
    mostrarLinea(42, '=');
    Console::WriteLine("     DADOS ACUMULADOS - LIMITE 15   ");
    Console::WriteLine("          TB1_Grupo3 - UPC          ");
    mostrarLinea(42, '=');
    Console::ResetColor();
}

void esperarEnter() {
    Console::ForegroundColor = ConsoleColor::DarkGray;
    Console::WriteLine("\n  Presiona Enter para continuar...");
    Console::ResetColor();
    Console::ReadLine();
}

void mostrarMensajeCentrado(String^ mensaje, char borde) {
    mostrarLinea(42, borde);
    Console::WriteLine("  " + mensaje);
    mostrarLinea(42, borde);
}