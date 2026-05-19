#include "pch.h"
#include "partida.h"
#include "juego.h"
#include "animacion.h"
#include "utils.h"


int pedirNumeroPartidas() {
    int cantidad = 0;
    String^ entrada;

    do {
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::Write("\n  ^Cuantas partidas desea jugar? (minimo 1) : ");
        Console::ForegroundColor = ConsoleColor::White;
        entrada = Console::ReadLine();

        bool esValido = false;
        if (entrada->Length > 0) {
            esValido = true;
            for (int i = 0; i < entrada->Length; i++) {
                if (!Char::IsDigit(entrada[i])) {
                    esValido = false;
                    break;
                }
            }
            if (esValido)
                cantidad = Int32::Parse(entrada);
        }

        if (!esValido || cantidad < 1) {
            Console::ForegroundColor = ConsoleColor::Red;
            Console::WriteLine("  Entrada invalida. Ingrese un numero mayor a 0.");
            Console::ResetColor();
            cantidad = 0;
        }
    } while (cantidad < 1);

    Console::ResetColor();
    return cantidad;
}


RegistroJuego inicializarRegistro(int totalPartidas) {
    RegistroJuego r;
    r.totalPartidas = totalPartidas;
    r.victorias = 0;
    r.derrotas = 0;
    return r;
}

void actualizarRegistro(RegistroJuego& r, ResultadoPartida resultado) {
    if (resultado == GANO)
        r.victorias++;
    else
        r.derrotas++;
}


void mostrarMarcador(RegistroJuego registro, int partidaActual) {
    Console::ForegroundColor = ConsoleColor::DarkCyan;
    Console::WriteLine();
    mostrarLinea(40, '-');
    Console::WriteLine("  MARCADOR  (despues de partida " +
        partidaActual.ToString() + ")");
    Console::ForegroundColor = ConsoleColor::Green;
    Console::WriteLine("  Victorias : " + registro.victorias.ToString());
    Console::ForegroundColor = ConsoleColor::Red;
    Console::WriteLine("  Derrotas  : " + registro.derrotas.ToString());
    Console::ForegroundColor = ConsoleColor::DarkCyan;
    mostrarLinea(40, '-');
    Console::ResetColor();
}

void mostrarGanadorFinal(RegistroJuego registro) {
    limpiarPantalla();
    mostrarTitulo();

    Console::ForegroundColor = ConsoleColor::Yellow;
    mostrarLinea(50, '*');
    Console::WriteLine("         RESULTADO FINAL DEL JUEGO");
    mostrarLinea(50, '*');
    Console::ResetColor();

    Console::WriteLine();
    Console::ForegroundColor = ConsoleColor::White;
    Console::WriteLine("  Total de partidas jugadas : " +
        registro.totalPartidas.ToString());
    Console::ForegroundColor = ConsoleColor::Green;
    Console::WriteLine("  Victorias                 : " +
        registro.victorias.ToString());
    Console::ForegroundColor = ConsoleColor::Red;
    Console::WriteLine("  Derrotas                  : " +
        registro.derrotas.ToString());
    Console::WriteLine();

    if (registro.victorias > registro.derrotas) {
        animarVictoria();
        Console::ForegroundColor = ConsoleColor::Green;
        Console::WriteLine("  iCONCLUSION: Ganaste la sesion de juego!");
    }
    else if (registro.victorias == registro.derrotas) {
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::WriteLine("  CONCLUSION: Empate! Estuviste muy parejo.");
    }
    else {
        animarDerrota();
        Console::ForegroundColor = ConsoleColor::Red;
        Console::WriteLine("  CONCLUSION: La sesion fue dificil.");
        Console::WriteLine("  Sigue practicando y mejora tu estrategia.");
    }

    Console::ResetColor();
    Console::WriteLine();

    int porcentaje = 0;
    if (registro.totalPartidas > 0)
        porcentaje = (registro.victorias * 100) / registro.totalPartidas;

    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::Write("  Efectividad: [");

    int barrasVerde = porcentaje / 5;
    for (int i = 0; i < 20; i++) {
        if (i < barrasVerde) {
            Console::ForegroundColor = ConsoleColor::Green;
            Console::Write("#");
        }
        else {
            Console::ForegroundColor = ConsoleColor::DarkGray;
            Console::Write(".");
        }
    }

    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::WriteLine("] " + porcentaje.ToString() + "%");
    Console::ResetColor();
    Console::WriteLine();
    mostrarLinea(50, '*');
    esperarEnter();
}

void ejecutarTodasLasPartidas() {
    int total = pedirNumeroPartidas();
    RegistroJuego reg = inicializarRegistro(total);

    animarCarga("Preparando los dados", 800);

    for (int i = 1; i <= total; i++) {
        ResultadoPartida resultado = ejecutarPartida(i, total);
        actualizarRegistro(reg, resultado);

        if (i < total) {
            mostrarMarcador(reg, i);
            esperarEnter();
        }
    }

    mostrarGanadorFinal(reg);
}