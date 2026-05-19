#include "pch.h"
#include "juego.h"
#include "animacion.h"
#include "utils.h"

void mostrarEncabezadoPartida(int numeroPartida, int totalPartidas) {
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::WriteLine();
    mostrarLinea(42, '-');
    Console::WriteLine("  PARTIDA " + numeroPartida.ToString() +
        " de " + totalPartidas.ToString());
    mostrarLinea(42, '-');
    Console::ResetColor();
}

void mostrarEstadoPuntaje(int suma, int lanzamientos) {
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::WriteLine();
    Console::WriteLine("  Dados lanzados : " + lanzamientos.ToString());

    Console::Write("  Puntaje actual : [");
    int barras = suma;
    if (barras > 15) barras = 15;

    for (int i = 0; i < barras; i++) {
        if (i < 10)
            Console::ForegroundColor = ConsoleColor::Green;
        else
            Console::ForegroundColor = ConsoleColor::Red;
        Console::Write("|");
    }

    Console::ForegroundColor = ConsoleColor::DarkGray;
    for (int i = barras; i < 15; i++)
        Console::Write(".");

    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::Write("] ");
    Console::ForegroundColor = ConsoleColor::White;
    Console::WriteLine(suma.ToString() + " / 15");
    Console::ResetColor();
    Console::WriteLine();
}

bool pedirOtroDado() {
    String^ entrada;
    bool quiereSi = false;
    bool entradaOk = false;

    do {
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::Write("  Desea lanzar otro dado? (s = si / n = no) : ");
        Console::ForegroundColor = ConsoleColor::White;
        entrada = Console::ReadLine()->Trim()->ToLower();

        if (entrada == "s") {
            quiereSi = true;
            entradaOk = true;
        }
        else if (entrada == "n") {
            quiereSi = false;
            entradaOk = true;
        }
        else {
            Console::ForegroundColor = ConsoleColor::Red;
            Console::WriteLine("  Entrada invalida. Ingrese 's' o 'n'.");
            Console::ResetColor();
        }
    } while (!entradaOk);

    Console::ResetColor();
    return quiereSi;
}

ResultadoPartida evaluarResultado(int suma) {
    if (suma > 15)
        return TE_PASASTE;
    if (suma >= 10 && suma <= 15)
        return GANO;
    return PERDIO_BAJO_PUNTAJE;
}

void mostrarResultadoPartida(ResultadoPartida resultado, int suma) {
    Console::WriteLine();
    mostrarLinea(42, '=');

    if (resultado == GANO) {
        animarVictoria();
        Console::ForegroundColor = ConsoleColor::Green;
        Console::WriteLine("  Ganaste con " + suma.ToString() + " puntos!");
    }
    else if (resultado == PERDIO_BAJO_PUNTAJE) {
        animarDerrota();
        Console::ForegroundColor = ConsoleColor::Red;
        Console::WriteLine("  Perdiste por bajo puntaje: " + suma.ToString());
    }
    else {
        animarDerrota();
        Console::ForegroundColor = ConsoleColor::Red;
        Console::WriteLine("  Te pasaste con " + suma.ToString() + ". Perdiste.");
    }

    Console::ResetColor();
    mostrarLinea(42, '=');
}


ResultadoPartida ejecutarPartida(int numeroPartida, int totalPartidas) {
    limpiarPantalla();
    mostrarTitulo();
    mostrarEncabezadoPartida(numeroPartida, totalPartidas);

    animarCuentaRegresiva();
    limpiarPantalla();
    mostrarTitulo();
    mostrarEncabezadoPartida(numeroPartida, totalPartidas);

    int suma = 0;
    int numDado = 0;
    bool juegoActivo = true;
    ResultadoPartida resultado;

    while (juegoActivo) {
        animarLanzamiento();
        Dado d = lanzarDado();
        numDado++;

        Console::ForegroundColor = ConsoleColor::White;
        Console::WriteLine("\n  --- Dado #" + numDado.ToString() + " ---");
        dibujarDado(d);

        Console::ForegroundColor = ConsoleColor::White;
        Console::Write("  Valor  : ");
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::WriteLine(d.valor.ToString());

        suma += d.valor;
        mostrarEstadoPuntaje(suma, numDado);

        if (suma > 15) {
            // suma supera 15 → termina automaticamente
            resultado = TE_PASASTE;
            juegoActivo = false;
        }
        else if (suma == 15) {
            // exactamente 15 → victoria automatica
            resultado = GANO;
            juegoActivo = false;
        }
        else {
            // entre 1 y 14 → pregunta si quiere otro dado
            bool quiereOtro = pedirOtroDado();
            if (!quiereOtro) {
                // respondio 'n' → evalua su puntaje
                resultado = evaluarResultado(suma);
                juegoActivo = false;
            }
            // respondio 's' → el while continua
        }
    }

    mostrarResultadoPartida(resultado, suma);
    esperarEnter();
    return resultado;
}

void mostrarReglas() {
    limpiarPantalla();
    mostrarTitulo();

    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::WriteLine("  REGLAS DEL JUEGO");
    mostrarLinea(50, '-');
    Console::ResetColor();

    Console::ForegroundColor = ConsoleColor::White;
    Console::WriteLine();
    Console::WriteLine("  OBJETIVO:");
    Console::WriteLine("  Acumular puntos sin pasarte de 15.");
    Console::WriteLine();
    Console::WriteLine("  CONDICIONES DE VICTORIA:");
    Console::WriteLine("  - Responde 'n' con suma entre 10 y 15 --> GANASTE");
    Console::WriteLine("  - Llegas exactamente a 15             --> GANASTE");
    Console::WriteLine();
    Console::WriteLine("  CONDICIONES DE DERROTA:");
    Console::WriteLine("  - Suma supera 15                      --> TE PASASTE");
    Console::WriteLine("  - Responde 'n' con suma menor a 10    --> PERDISTE");
    Console::ResetColor();
    Console::WriteLine();

    mostrarLinea(50, '-');
    esperarEnter();
}