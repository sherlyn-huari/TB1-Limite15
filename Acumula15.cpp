#include "pch.h"
#include "Opciones.h"

void mostrarMenu() {
    Console::WriteLine("\n\t=== MENU PRINCIPAL ===\n");
    Console::WriteLine("  1. Jugar Dados Acumulados - Limite 15");
    Console::WriteLine("  0. Salir\n");
}

int main(cli::array<System::String^>^ args) {
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEnteroRango("  Ingrese opcion: ", 0, 1);
        switch (opcion) {
        case 1: jugarLimite15(); break;
        case 0: Console::WriteLine("\n  Hasta luego!\n"); break;
        }
        if (opcion != 0) {
            Console::WriteLine("  Presione cualquier tecla...");
            Console::ReadKey();
            Console::Clear();
        }
    } while (opcion != 0);
    return 0;
}
