#include "pch.h"
#include "menu.h"
#include "juego.h"
#include "partida.h"
#include "animacion.h"
#include "utils.h"

int main(cli::array<System::String^>^ args) {
    Console::Title = "Dados Acumulados - Limite 15 - TB1_Grupo3 UPC";
    Console::CursorVisible = false;

    srand((unsigned int)time(nullptr));

    animarBienvenida();
    pausar(500);

    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        opcion = mostrarMenuPrincipal();

        switch (opcion) {
        case 1:
            ejecutarTodasLasPartidas();
            break;
        case 2:
            mostrarReglas();
            break;
        case 3:
            limpiarPantalla();
            mostrarTitulo();
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::WriteLine();
            Console::WriteLine("  Gracias por jugar Dados Acumulados - Limite 15.");
            Console::WriteLine("  iHasta la proxima!");
            Console::ResetColor();
            Console::WriteLine();
            pausar(1500);
            continuar = false;
            break;
        }
    }

    return 0;
}