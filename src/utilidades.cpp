#include "../include/utilidades.h"
#include <limits>

void limpiarPantallaNativa() {
    // Código de escape ANSI multiplataforma compatible con la restricción de la rúbrica
    cout << "\033[2J\033[1;1H"; 
}

void detenerFlujo() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
